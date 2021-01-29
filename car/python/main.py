 
import math
import rospy
from sensor_msgs.msg import LaserScan
import RPi.GPIO as GPIO
from time import sleep
 
 
def main():
    try:
        setup()
        rospy.init_node('lidar_car')

        sub = rospy.Subscriber('/scan', LaserScan, clbk_laser)

        rospy.spin()
    except KeyboardInterrupt:
        print("KeyboardInterrupt")
        GPIO.cleanup()
        motorR.stop()
        motorL.stop()


if __name__ == '__main__':
    main()
