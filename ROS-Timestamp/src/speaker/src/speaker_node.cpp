#include "ros/ros.h"
#include "std_msgs/UInt64.h"
#include <chrono>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "speaker_node");
	ros::NodeHandle n;
	ros::Publisher timestamp_pub = n.advertise<std_msgs::UInt64>("timestamp", 1000);
	ros::Rate loop_rate(10);

	std::chrono::milliseconds ms;
	auto start = std::chrono::system_clock::now();
	
	while (ros::ok())	
	{
		std_msgs::UInt64 msg;
		auto now = std::chrono::system_clock::now();
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
		msg.data = ms.count();
		timestamp_pub.publish(msg);
		loop_rate.sleep();
	}
	return 0;
}
