#include <stdio.h>
#include <stdint.h>
#include <climits>
#include <iostream>
#include <bitset>

#include <ros/ros.h>
#include <std_msgs/UInt64.h>

void chatterCallback(const std_msgs::UInt64& msg){
	ROS_INFO("Subscribed data : \n");
	std::cout << std::bitset<sizeof(msg.data) * CHAR_BIT>(msg.data) << std::endl;
	printf("\n");
}

int main(int argc, char **argv){
	ros::init(argc, argv, "listener");	
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("signal64", 1000, chatterCallback);
	ros::spin();
	return 0;
}
