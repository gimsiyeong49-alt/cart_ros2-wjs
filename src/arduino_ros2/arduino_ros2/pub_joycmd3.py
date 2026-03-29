#!/usr/bin/env python3
import time
import serial
from serial.serialutil import SerialException

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


def main():
    rclpy.init()
    node = Node('pub_joycmd')
    logger = node.get_logger()
    pub = node.create_publisher(Twist, '/cmd_vel', 10)

    port = '/dev/ttyArduino'
    baud = 9600

    linear_x = 0.0
    angular_z = 0.0

    last_log = 0.0
    log_period = 0.5  # 0.5초에 1번만 로그
    last_rx = time.time()
    deadman_sec = 0.5

    ser = None

    def publish_stop():
        nonlocal linear_x, angular_z
        linear_x = 0.0
        angular_z = 0.0
        msg = Twist()
        msg.linear.x = 0.0
        msg.angular.z = 0.0
        pub.publish(msg)

    try:
        # ★ timeout 필수 (끊겼을 때 멈추지 않게)
        ser = serial.Serial(port, baud, timeout=0.05)
        time.sleep(1.5)  # 아두이노 리셋 대기
        try:
            ser.reset_input_buffer()
        except Exception:
            pass

        while rclpy.ok():
            # Ctrl-C, shutdown 반응을 위해 spin_once 한 번
            rclpy.spin_once(node, timeout_sec=0.0)

            try:
                raw = ser.readline()
                if raw:
                    line = raw.decode(errors='ignore').strip()
                    parts = line.split(',')

                    if len(parts) >= 2:
                        v_data = float(parts[0])
                        h_data = float(parts[1])
                        last_rx = time.time()

                        # ---- 기존 로직 ----
                        if (v_data > 1000.0 and h_data < 20.0):  # FL
                            linear_x, angular_z = 3.0, 6.0
                        elif (v_data > 1000.0 and 490.0 < h_data < 520.0):  # F
                            linear_x, angular_z = 3.0, 0.0
                        elif (v_data > 1000.0 and h_data > 1000.0):  # FR
                            linear_x, angular_z = 3.0, -6.0
                        elif (490.0 < v_data < 520.0 and h_data < 10.0):  # L
                            linear_x, angular_z = 0.0, 6.0
                        elif (490.0 < v_data < 520.0 and 490.0 < h_data < 520.0):  # STOP
                            linear_x, angular_z = 0.0, 0.0
                        elif (490.0 < v_data < 520.0 and h_data > 1000.0):  # R
                            linear_x, angular_z = 0.0, -6.0
                        elif (v_data < 10.0 and h_data < 10.0):  # BL
                            linear_x, angular_z = -3.0, -6.0
                        elif (v_data < 10.0 and 490.0 < h_data < 520.0):  # B
                            linear_x, angular_z = -3.0, 0.0
                        elif (v_data < 10.0 and h_data > 1000.0):  # BR
                            linear_x, angular_z = -3.0, 6.0
                        # else: 유지

                # ★ deadman: 데이터 끊기면 정지
                if (time.time() - last_rx) > deadman_sec:
                    publish_stop()
                    continue

                msg = Twist()
                msg.linear.x = float(linear_x)
                msg.angular.z = float(angular_z)
                pub.publish(msg)

                now = time.time()
                if (now - last_log) > log_period:
                    logger.info(f'linear_x={linear_x}, angular_z={angular_z}')
                    last_log = now

            except (ValueError, IndexError):
                # 파싱 실패는 그냥 무시
                continue
            except (SerialException, OSError) as e:
                logger.warn(f"Serial error: {e}")
                publish_stop()
                break

    finally:
        publish_stop()
        if ser is not None:
            try:
                ser.close()
            except Exception:
                pass
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
