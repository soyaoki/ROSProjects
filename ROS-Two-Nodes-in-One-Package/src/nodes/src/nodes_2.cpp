#include "ros/ros.h"
#include "std_msgs/String.h"
#include <boost/thread/thread.hpp>
#include <sstream>

void callback_2(const std_msgs::String::ConstPtr& msg)
{
	printf("\n");
	ROS_INFO("I heard : [%s]", msg->data.c_str());
	printf("\n");
}

void another_node_2(int argc, char **argv)
{
	ros::init(argc, argv, "listener_2");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("chatter_2", 1000, callback_2);
	ros::spin();
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "speaker_2");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter_2", 1000);
	ros::Rate loop_rate(10); 
	
	boost::thread thread_2(another_node_2, argc, argv);

	int count = 0;

	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
		
		ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);

		ros::spinOnce();
		
		loop_rate.sleep();
		++count;
	}

	
	return 0;
 }
