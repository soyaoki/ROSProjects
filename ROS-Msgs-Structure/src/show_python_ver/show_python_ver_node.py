#!/usr/bin/env python3
import rospy
from custom_msgs.msg import signal, container
import sys
import site

def show_pyver():
    print("python version :")
    print(sys.version)
    print("\n")

def show_path():
    print("python path :")
    print(sys.path)
    print("\n")

def show_pkgs():
    print("python site pkgs :")
    print(site.getsitepackages())
    print("\n")

if __name__ == '__main__':
    try:
        show_pyver()
        show_path()
        show_pkgs()
    except rospy.ROSInterruptException: pass
