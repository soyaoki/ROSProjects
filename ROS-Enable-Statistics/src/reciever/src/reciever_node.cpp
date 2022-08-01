#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include <boost/thread/thread.hpp>

void cb_a(const std_msgs::Empty& msg)
{
   ROS_INFO("Received_a : %f", ros::Time::now().toSec());
}

void cb_b(const std_msgs::Empty& msg)
{
   ROS_INFO("Received_b : %f", ros::Time::now().toSec());
}

void cb_c(const std_msgs::Empty& msg)
{
   ROS_INFO("Received_c : %f", ros::Time::now().toSec());
}

void cb_d(const std_msgs::String& msg)
{
   ROS_INFO("Received_d : %s", msg.data.c_str());
}

void do_stuff_b(int* publish_rate)
{
  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>(); // error with std::make_shared<ros::NodeHandle>();
  ros::Subscriber sub_b = node->subscribe("topic_b",10,cb_b);

  while (ros::ok())
  {
    ros::spinOnce();
  }
}

void do_stuff_c(int* publish_rate)
{
  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>(); // error with std::make_shared<ros::NodeHandle>();
  ros::Subscriber sub_c = node->subscribe("topic_c",10,cb_c);

  while (ros::ok())
  {
    ros::spinOnce();
  }
}

void do_stuff_d(int* publish_rate)
{
  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>(); // error with std::make_shared<ros::NodeHandle>();
  ros::Subscriber sub_d = node->subscribe("topic_d",10,cb_d);

  while (ros::ok())
  {
    ros::spinOnce();
  }
}

int main(int argc, char** argv)
{

  ros::init(argc, argv, "recv_node");

  int rate_b = 1; // 1 Hz
  int rate_c = 2; // 2 Hz
  int rate_d = 5; // 5 Hz

  // spawn another thread
  boost::thread thread_b(do_stuff_b, &rate_b);
  boost::thread thread_c(do_stuff_c, &rate_c);
  boost::thread thread_d(do_stuff_d, &rate_d);

  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>(); // error with std::make_shared<ros::NodeHandle>();
  ros::Subscriber sub_a = node->subscribe("topic_a", 10, cb_a);

  while (ros::ok())
  {
    // process any incoming messages in this thread
    ros::spinOnce();
  }

  // wait the second thread to finish
  thread_b.join();

  return 0;
}
