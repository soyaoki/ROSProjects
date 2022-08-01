#!/usr/bin/env python3
## coding: UTF-8

# ROS
import rospy
from std_msgs.msg import String
from gps_receiver.msg import gps_message
from datetime import datetime
# GPS
from gps3 import gps3
# Thread
import threading

# ROS setting
rospy.init_node('gps_receiver')
pub = rospy.Publisher('gps', gps_message, queue_size=1) 
rate = rospy.Rate(10)

# GPS Setting
gps_socket = gps3.GPSDSocket()
data_stream = gps3.DataStream()
gps_socket.connect()
gps_socket.watch()

# Thread Setting
def KeyInput():
    global isAlive
    isAlive = True
    
    while(isAlive):
        if(input()=='q'):
            print("q")
            isAlive = False
        else:
            print("...")

Thread_KeyInput = threading.Thread(target=KeyInput)
Thread_KeyInput.start()

for new_data in gps_socket:
    if new_data:
        data_stream.unpack(new_data)
        # print(data_stream.TPV['time'])
        # print(data_stream.TPV['mode'])
        # print(data_stream.TPV['device'])
        # print(data_stream.TPV['lat'])
        # print(data_stream.TPV['lon'])
        # print(data_stream.TPV['alt'])
        # print(data_stream.TPV['speed'])
        gps_data = gps_message()
        gps_data.header.stamp = rospy.Time.now()
        if(data_stream.TPV['lat'] == 'n/a'):
            gps_data.mode = -1
            gps_data.lat = -1
            gps_data.lon = -1
            gps_data.alt = -1
            gps_data.epx = -1
            gps_data.epy = -1
            gps_data.epv = -1
            gps_data.speed = -1
            gps_data.eps = -1
            gps_data.track = -1
        else:    
            gps_data.mode = data_stream.TPV['mode']
            gps_data.lat = data_stream.TPV['lat']
            gps_data.lon = data_stream.TPV['lon']
            gps_data.speed = data_stream.TPV['speed']

            if(data_stream.TPV['epx'] == 'n/a'):
                gps_data.epx = -1
            else:
                gps_data.epx = data_stream.TPV['epx']

            if(data_stream.TPV['epy'] == 'n/a'):
                gps_data.epy = -1
            else:
                gps_data.epy = data_stream.TPV['epy']

            if(data_stream.TPV['epv'] == 'n/a'):
                gps_data.epv = -1
            else:
                gps_data.epv = data_stream.TPV['epv']

            if(data_stream.TPV['eps'] == 'n/a'):
                gps_data.eps = -1
            else:
                gps_data.eps = data_stream.TPV['eps']

            if(data_stream.TPV['alt'] == 'n/a'):
                gps_data.alt = -1
            else:
                gps_data.alt = data_stream.TPV['alt']

            if(data_stream.TPV['track'] == 'n/a'):
                gps_data.track = -1
            else:
                gps_data.track = data_stream.TPV['track']


        pub.publish(gps_data)
    if(isAlive==False):
        break
