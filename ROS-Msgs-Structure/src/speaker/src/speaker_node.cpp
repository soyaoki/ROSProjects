#include "ros/ros.h"
#include "std_msgs/String.h"
#include "custom_msgs/signal.h"
#include "custom_msgs/container.h"

#include <sstream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "speaker");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	ros::Publisher vec_pub = n.advertise<custom_msgs::container>("container", 1000);
	ros::Rate loop_rate(10); 
	int count = 0;
	custom_msgs::signal str_msg;
	custom_msgs::container vec_msg;
	vec_msg.vector_len = 5;
	
	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
		
		ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);

		str_msg.first_name = std::string("Taro");
		str_msg.last_name = std::string("Sato");
		vec_msg.vector_obj.push_back(str_msg);

		if (vec_msg.vector_obj.size()==vec_msg.vector_len)
		{
			vec_pub.publish(vec_msg);
			vec_msg.vector_obj={};
		}

		ros::spinOnce();
		
		loop_rate.sleep();
		++count;
	}
	return 0;
 }
