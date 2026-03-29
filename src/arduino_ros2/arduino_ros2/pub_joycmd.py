import serial
import time
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

ser = serial.Serial('/dev/ttyArduino', 9600)

rclpy.init()
node = Node('pub_joycmd')

logger = node.get_logger()

pub = node.create_publisher(Twist, '/cmd_vel', 10)

linear_x = 0.0
angular_z = 0.0

while rclpy.ok():
    data = ser.readline().decode().rstrip().split(',')
    
    v_data = float(data[0])
    h_data = float(data[1])

    if(v_data > 1000.0 and h_data < 20.0): # FL
        linear_x = 3.0
        angular_z = 6.0

    elif(v_data > 1000.0 and h_data < 520.0 and h_data > 490.0): # F
        linear_x = 3.0
        angular_z = 0.0

    elif(v_data > 1000.0 and h_data > 1000.0):
        linear_x = 3.0
        angular_z = -6.0

    elif(v_data < 520.0 and v_data > 490.0 and h_data < 10.0):
        linear_x = 0.0
        angular_z = 6.0

    elif(v_data < 520.0 and v_data > 490.0 and h_data < 520.0 and h_data > 490.0):
        linear_x = 0.0
        angular_z = 0.0

    elif(v_data < 520.0 and v_data > 490.0 and h_data > 1000.0):
        linear_x = 0.0
        angular_z = -6.0
        
    elif(v_data < 10.0 and h_data < 10.0):
        linear_x = -3.0
        angular_z = -6.0

    elif(v_data < 10.0 and h_data < 520.0 and h_data > 490.0):
        linear_x = -3.0
        angular_z = 0.0

    elif(v_data < 10.0 and h_data > 1000.0):
        linear_x = -3.0
        angular_z = 6.0

    else:
        pass
    
    msg = Twist()

    msg.linear.x = linear_x
    msg.angular.z = angular_z

    pub.publish(msg)

    logger.info('Serial Data: linear_x={}, angular_z={}'.format(linear_x, angular_z))
    time.sleep(0.001)

node.destroy_node()
rclpy.shutdown()

if __name__ == '__main__':
    main()
    
    
