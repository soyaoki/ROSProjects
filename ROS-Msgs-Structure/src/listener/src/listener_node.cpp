#include "ros/ros.h"
#include "std_msgs/String.h"
#include "custom_msgs/signal.h"
#include "custom_msgs/container.h"

#include <sstream>

void callback(const std_msgs::String::ConstPtr& msg)
{
	printf("\n");
	ROS_INFO("I heard : [%s]", msg->data.c_str());
	printf("\n");
}

void callback2(const custom_msgs::container::ConstPtr& msg)
{
	printf("\n");
	int len = msg->vector_len;
	std::cout << "length : " << len << std::endl;
	for (int i=0; i<len; i++)
	{
		ROS_INFO("I heard : [%s]", msg->vector_obj[i].first_name.c_str());
		ROS_INFO("I heard : [%s]", msg->vector_obj[i].last_name.c_str());
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	ros::NodeHandle n;
//	ros::Subscriber sub = n.subscribe("chatter", 1000, callback);
	ros::Subscriber sub_vec = n.subscribe("container", 1000, callback2);
	ros::spin();

	return 0;
 }
