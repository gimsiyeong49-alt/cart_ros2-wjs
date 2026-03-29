import serial
import time
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

ser = serial.Serial('/dev/ttyArduino', 9600, timeout=0.05)

rclpy.init()
node = Node('pub_joycmd')
pub = node.create_publisher(Twist, '/cmd_vel', 10)

# ===== 튜닝값(기존 최대치 유지) =====
MAX_LIN = 3.0
MAX_ANG = 6.0

CENTER_V = 512.0
CENTER_H = 512.0

DEAD_ADC = 40.0

# ===== 회전 시 직진 감속(아두이노 TURN_SLOW와 같은 역할) =====
TURN_SLOW = 0.6  # 0~1, 0.6이면 회전 MAX일 때 직진을 최대 60% 감속

def clamp(x, lo, hi):
    return max(lo, min(hi, x))

linear_x = 0.0
angular_z = 0.0

while rclpy.ok():
    line = ser.readline().decode(errors='ignore').strip()
    parts = line.split(',')
    if len(parts) < 2:
        continue

    try:
        v_data = float(parts[0])
        h_data = float(parts[1])
    except ValueError:
        continue

    # 0~1023 -> -1~1로 정규화
    v_norm = (v_data - CENTER_V) / 512.0           # 전진(+) / 후진(-)
    h_norm = (CENTER_H - h_data) / 512.0           # 왼쪽(+) / 오른쪽(-)  ← 기존 부호 유지

    # 데드존
    dead = DEAD_ADC / 512.0
    if abs(v_norm) < dead:
        v_norm = 0.0
    if abs(h_norm) < dead:
        h_norm = 0.0

    # 기본 비례 출력
    linear_x  = MAX_LIN * clamp(v_norm, -1.0, 1.0)
    angular_z = MAX_ANG * clamp(h_norm, -1.0, 1.0)

    # ====== (추가) 회전할 때 직진 속도 줄이기 ======
    # 아두이노 코드의 turn_ratio = abs(diffX)/MAX_PULSE 와 동일한 개념
    turn_ratio = min(1.0, abs(h_norm))                 # 0~1
    slow_factor = 1.0 - TURN_SLOW * turn_ratio         # 1.0 ~ (1-TURN_SLOW)
    linear_x *= slow_factor
    # ==============================================

    msg = Twist()
    msg.linear.x = linear_x
    msg.angular.z = angular_z
    pub.publish(msg)

    time.sleep(0.001)

node.destroy_node()
rclpy.shutdown()

