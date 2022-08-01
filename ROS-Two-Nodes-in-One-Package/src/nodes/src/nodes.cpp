#include "ros/ros.h"
#include "std_msgs/String.h"
#include <boost/thread/thread.hpp>
#include <sstream>

void callback(const std_msgs::String::ConstPtr& msg)
{
	printf("\n");
	ROS_INFO("I heard : [%s]", msg->data.c_str());
	printf("\n");
}

void another_node(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("chatter", 1000, callback);
	ros::spin();
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "speaker");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(10); 
	
	boost::thread thread(another_node, argc, argv);

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
