#!/usr/bin/env python3
import socket
import time

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


def clamp(x, lo, hi):
    return lo if x < lo else hi if x > hi else x


def piecewise_unit(delta_raw: float, dead_raw: float, mid_delta_raw: float, mid_unit: float, max_delta_raw: float) -> float:
    sign = 1.0 if delta_raw >= 0.0 else -1.0
    a = abs(delta_raw)

    if a <= dead_raw:
        return 0.0
    if a >= max_delta_raw:
        return sign * 1.0

    mid_unit = clamp(mid_unit, 0.0, 1.0)
    mid_delta_raw = clamp(mid_delta_raw, dead_raw + 1e-6, max_delta_raw - 1e-6)

    if a <= mid_delta_raw:
        u = mid_unit * (a - dead_raw) / (mid_delta_raw - dead_raw)
    else:
        u = mid_unit + (1.0 - mid_unit) * (a - mid_delta_raw) / (max_delta_raw - mid_delta_raw)

    return sign * clamp(u, 0.0, 1.0)


def tilt_unit(delta_raw: float, dead_raw: float, sat_delta_raw: float, expo: float = 1.0) -> float:
    """
    개선된 tilt 매핑(선형+포화) + deadzone 보정 + expo 커브:
    - |delta| <= dead_raw  -> 0
    - deadzone을 뺀 남은 구간에서 0~1로 증가:
        t = (|delta|-dead) / (sat-dead)   (0~1)
        u = t^expo
    - expo > 1 : 중앙 둔하게(미세조작 쉬움), 끝에서만 확 올라감
    """
    a = abs(delta_raw)
    if a <= dead_raw:
        return 0.0

    sign = 1.0 if delta_raw >= 0.0 else -1.0

    # sat은 dead보다 커야 의미가 있음
    sat = max(abs(sat_delta_raw), dead_raw + 1e-6)

    t = (a - dead_raw) / (sat - dead_raw)  # 0~1
    t = clamp(t, 0.0, 1.0)

    expo = max(expo, 1e-6)
    u = t ** expo

    return sign * u


def ramp_update(cur: float, target: float, a_up: float, a_down: float, dt: float) -> float:
    if dt <= 0.0:
        return cur

    accel = (abs(target) > abs(cur)) and ((cur * target) >= 0.0 or abs(cur) < 1e-9)
    a = a_up if accel else a_down

    dmax = a * dt
    return cur + clamp(target - cur, -dmax, dmax)


class BtJoyCmd(Node):
    def __init__(self):
        super().__init__("bt_joycmd")

        self.addr = self.declare_parameter("addr", "08:3A:F2:B8:F7:6A").value
        self.channel = int(self.declare_parameter("channel", 1).value)

        self.raw_min = float(self.declare_parameter("raw_min", 0.0).value)
        self.raw_max = float(self.declare_parameter("raw_max", 1023.0).value)
        self.half_range = (self.raw_max - self.raw_min) / 2.0

        # 최대 속도
        self.max_v = float(self.declare_parameter("max_v", 6.0).value)
        self.max_w = float(self.declare_parameter("max_w", 3.0).value)

        # 매핑 모드
        self.map_mode = str(self.declare_parameter("map_mode", "tilt").value).lower()

        # piecewise용(유지)
        self.mid_delta = float(self.declare_parameter("mid_delta", 200.0).value)
        self.mid_v = float(self.declare_parameter("mid_v", 3.0).value)
        self.mid_w = float(self.declare_parameter("mid_w", 1.0).value)

        # deadzone
        self.deadzone = float(self.declare_parameter("deadzone", 0.08).value)
        self.deadzone_raw = float(self.declare_parameter("deadzone_raw", 45.0).value)

        # ✅ sat_delta 기본값을 half_range로 (끝까지 꺾어야 max가 기본)
        self.sat_delta_v = float(self.declare_parameter("sat_delta_v", self.half_range).value)
        self.sat_delta_w = float(self.declare_parameter("sat_delta_w", self.half_range).value)

        # ✅ expo: 클수록(1.5~3.0) 중간~후반이 널널해짐
        self.expo_v = float(self.declare_parameter("expo_v", 2.2).value)
        self.expo_w = float(self.declare_parameter("expo_w", 2.0).value)

        # ✅ 후진은 더 둔하게(각도 조금 꺾어도 max 가는 것 방지)
        self.expo_v_rev = float(self.declare_parameter("expo_v_rev", 2.8).value)

        self.stale_timeout = float(self.declare_parameter("stale_timeout", 0.3).value)
        self.pub_hz = float(self.declare_parameter("pub_hz", 30.0).value)

        # 램프 시간 기반(가속도 자동 계산)
        self.ramp_time_up_v = float(self.declare_parameter("ramp_time_up_v", 0.6).value)
        self.ramp_time_down_v = float(self.declare_parameter("ramp_time_down_v", 0.25).value)
        self.ramp_time_up_w = float(self.declare_parameter("ramp_time_up_w", 0.5).value)
        self.ramp_time_down_w = float(self.declare_parameter("ramp_time_down_w", 0.2).value)

        self.a_lin = self.max_v / max(self.ramp_time_up_v, 1e-6)
        self.a_lin_down = self.max_v / max(self.ramp_time_down_v, 1e-6)
        self.a_ang = self.max_w / max(self.ramp_time_up_w, 1e-6)
        self.a_ang_down = self.max_w / max(self.ramp_time_down_w, 1e-6)

        # 미끄러짐 방지 감쇠
        self.w_reduce_with_fwd = float(self.declare_parameter("w_reduce_with_fwd", 0.6).value)
        self.v_reduce_with_turn = float(self.declare_parameter("v_reduce_with_turn", 0.4).value)

        # 후진 제한(최대값 자체도 줄이고 싶으면 <1.0)
        self.rev_scale = float(self.declare_parameter("rev_scale", 1.0).value)

        # 정지 스냅
        self.stop_snap_ratio = float(self.declare_parameter("stop_snap_ratio", 0.03).value)

        # 앞뒤 반전
        self.invert_fwd = bool(self.declare_parameter("invert_fwd", True).value)

        self.pub = self.create_publisher(Twist, "/cmd_vel", 10)

        self.sock = None
        self.buf = b""

        self.center_x = None
        self.center_y = None
        self.calib_samples = []
        self.calib_needed = 25

        self.turn = 0.0
        self.fwd = 0.0
        self.last_input_time = 0.0

        self.v = 0.0
        self.w = 0.0

        self.get_logger().info(
            f"BT RFCOMM target: {self.addr} ch={self.channel} | "
            f"map_mode={self.map_mode} max_v={self.max_v} max_w={self.max_w} "
            f"sat_v={self.sat_delta_v:.1f} sat_w={self.sat_delta_w:.1f} "
            f"expo_v={self.expo_v} expo_v_rev={self.expo_v_rev} expo_w={self.expo_w}"
        )

        self.create_timer(0.01, self.poll_bt)
        self.last_pub_t = time.time()
        self.create_timer(1.0 / self.pub_hz, self.publish_cmd)

    def connect(self):
        if self.sock:
            return
        s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
        s.settimeout(10.0)
        s.connect((self.addr, self.channel))
        s.settimeout(0.0)
        self.sock = s
        self.buf = b""
        self.get_logger().info("BT connected (RFCOMM socket)")

    def close(self):
        try:
            if self.sock:
                self.sock.close()
        except Exception:
            pass
        self.sock = None

    def parse_line(self, line: str):
        parts = line.strip().split(",")
        if len(parts) < 2:
            return
        try:
            x = float(parts[0])
            y = float(parts[1])
        except ValueError:
            return

        if self.center_x is None or self.center_y is None:
            self.calib_samples.append((x, y))
            if len(self.calib_samples) >= self.calib_needed:
                self.center_x = sum(p[0] for p in self.calib_samples) / len(self.calib_samples)
                self.center_y = sum(p[1] for p in self.calib_samples) / len(self.calib_samples)
                self.get_logger().info(f"Calibrated center: ({self.center_x:.1f}, {self.center_y:.1f})")
            return

        dx = x - self.center_x
        dy = y - self.center_y

        dead_raw = self.deadzone_raw if self.deadzone_raw > 0 else (abs(self.deadzone) * self.half_range)

        if self.map_mode == "tilt":
            # sat은 dead보다 커야 하고, 물리 범위(half_range) 넘는 값은 의미 없음
            sat_v = max(min(self.sat_delta_v, self.half_range), dead_raw + 1.0)
            sat_w = max(min(self.sat_delta_w, self.half_range), dead_raw + 1.0)

            # 회전
            self.turn = tilt_unit(dx, dead_raw, sat_w, self.expo_w)

            # 직진(앞뒤 반전)
            fwd_delta = (-dy) if self.invert_fwd else (dy)

            # ✅ 후진일 때 expo 더 크게 (작게 꺾어도 max 빨리 가는 것 방지)
            expo_fwd = self.expo_v_rev if fwd_delta < 0.0 else self.expo_v
            self.fwd = tilt_unit(fwd_delta, dead_raw, sat_v, expo_fwd)

        else:
            max_delta_raw = self.half_range
            mid_v_unit = (self.mid_v / self.max_v) if self.max_v != 0 else 0.0
            mid_w_unit = (self.mid_w / self.max_w) if self.max_w != 0 else 0.0

            self.turn = piecewise_unit(dx, dead_raw, self.mid_delta, mid_w_unit, max_delta_raw)

            fwd_delta = (-dy) if self.invert_fwd else (dy)
            self.fwd = piecewise_unit(fwd_delta, dead_raw, self.mid_delta, mid_v_unit, max_delta_raw)

        self.last_input_time = time.time()

    def poll_bt(self):
        try:
            if self.sock is None:
                self.connect()

            try:
                data = self.sock.recv(256)
                if not data:
                    raise ConnectionError("BT disconnected (empty recv)")
                self.buf += data
            except BlockingIOError:
                return

            while b"\n" in self.buf:
                line, self.buf = self.buf.split(b"\n", 1)
                self.parse_line(line.decode(errors="ignore"))

        except Exception as e:
            self.get_logger().warn(f"BT error: {e}")
            self.close()
            time.sleep(0.1)

    def publish_cmd(self):
        now = time.time()
        dt = now - self.last_pub_t
        self.last_pub_t = now
        if dt <= 0.0:
            return

        if (now - self.last_input_time) > self.stale_timeout:
            v_t = 0.0
            w_t = 0.0
        else:
            v_t = self.max_v * self.fwd
            w_t = self.max_w * self.turn

            v_t *= max(0.0, 1.0 - self.v_reduce_with_turn * abs(self.turn))
            w_t *= max(0.0, 1.0 - self.w_reduce_with_fwd * abs(self.fwd))

            if v_t < 0.0:
                v_t *= self.rev_scale

        self.v = ramp_update(self.v, v_t, self.a_lin, self.a_lin_down, dt)
        self.w = ramp_update(self.w, w_t, self.a_ang, self.a_ang_down, dt)

        v_snap = abs(self.max_v) * self.stop_snap_ratio
        w_snap = abs(self.max_w) * self.stop_snap_ratio
        if abs(v_t) < 1e-9 and abs(self.v) < v_snap:
            self.v = 0.0
        if abs(w_t) < 1e-9 and abs(self.w) < w_snap:
            self.w = 0.0

        msg = Twist()
        msg.linear.x = float(self.v)
        msg.angular.z = float(self.w)
        self.pub.publish(msg)


def main():
    rclpy.init()
    node = BtJoyCmd()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.close()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
