#include <stdio.h>
#include <stdint.h>
#include <climits>
#include <iostream>
#include <bitset>

#include <ros/ros.h>
#include <std_msgs/UInt64.h>

int main(int argc, char **argv){

	// original data
	uint16_t data_16;
	float raw_data = 5.12;
	float res = 0.01;
	float offset = -5.11;

	data_16 = (raw_data - offset) / res;
	printf("raw data (16 bit):\n");
	std::cout << std::bitset<sizeof(data_16) * CHAR_BIT>(data_16) << std::endl;
	printf("\n");

	uint8_t data_8 = uint8_t(data_16);
	printf("raw data in 8 bit :\n");
	std::cout << std::bitset<sizeof(data_8) * CHAR_BIT>(data_8) << std::endl;
	printf("\n");

	uint8_t data_8array[8];
	/*
	for (int i=0; i<8;i++){
		data_8array[i] = 0;
	}
	*/
	printf("8 x 8 array (ini) :\n");
	for (int i=0; i<8;i++){
		std::cout << std::bitset<sizeof(data_8array[i]) * CHAR_BIT>(data_8array[i]) << std::endl;
	}
	printf("\n");
	
	/*
	data_8array[0] = data_8;
	printf("8 x 8 array :\n");
	for (int i=0; i<8;i++){
		std::cout << std::bitset<sizeof(data_8array[i]) * CHAR_BIT>(data_8array[i]) << std::endl;
	}
	printf("\n");
	*/

	printf("array[0] in 64 bit :\n");
	std::cout << std::bitset<sizeof((uint64_t)(data_8array[0])) * CHAR_BIT>((uint64_t)(data_8array[0])) << std::endl;	
	printf("\n");
	printf("array[0] << 8 in 64 bit :\n");
	std::cout << std::bitset<sizeof((uint64_t)(data_8array[0])<<8) * CHAR_BIT>((uint64_t)(data_8array[0])<<8) << std::endl;
	printf("\n");
	printf("array[0] << 16 in 64 bit :\n");
	std::cout << std::bitset<sizeof((uint64_t)(data_8array[0])<<16) * CHAR_BIT>((uint64_t)(data_8array[0])<<16) << std::endl;
	printf("\n");

	uint64_t data_64 = 0;
	for (int i=0;i<8;i++){
		data_64 += (uint64_t)(data_8array[i]);
		if(i != 7){
			data_64 = data_64 << 8;
		}
	}
	printf("64 bit :\n");
	std::cout << std::bitset<sizeof(data_64) * CHAR_BIT>(data_64) << std::endl;
	printf("\n");

	// ROS
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<std_msgs::UInt64>("signal64", 1000);
	ros::Rate loop_rate(10);
	while (ros::ok()){
		std_msgs::UInt64 msg;
		msg.data = data_64;
		pub.publish(msg);
		loop_rate.sleep();
	}
	return 0;
}
