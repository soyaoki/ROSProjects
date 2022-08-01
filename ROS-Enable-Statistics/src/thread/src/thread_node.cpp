#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include <boost/thread/thread.hpp>

void do_stuff_b(int* publish_rate)
{
  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>(); // error with std::make_shared<ros::NodeHandle>();
  ros::Publisher pub_b = node->advertise<std_msgs::Empty>("topic_b", 10);

  ros::Rate loop_rate(*publish_rate);
  while (ros::ok())
  {
    std_msgs::Empty msg;
    pub_b.publish(msg);
    loop_rate.sleep();
  }
}

void do_stuff_c(int* publish_rate)
{
  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>(); // error with std::make_shared<ros::NodeHandle>();
  ros::Publisher pub_c = node->advertise<std_msgs::Empty>("topic_c", 10);

  ros::Rate loop_rate(*publish_rate);
  while (ros::ok())
  {
    std_msgs::Empty msg;
    pub_c.publish(msg);
    loop_rate.sleep();
  }
}

void do_stuff_d(int* publish_rate)
{
  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>(); // error with std::make_shared<ros::NodeHandle>();
  ros::Publisher pub_d = node->advertise<std_msgs::String>("topic_d", 10);

  ros::Rate loop_rate(*publish_rate);
  while (ros::ok())
  {
    std::string input;
    std::cin>>input;

    std::cout << "input : " << input << std::endl;

    std_msgs::String msg;
    msg.data = input;
    pub_d.publish(msg);
    loop_rate.sleep();
  }
}


int main(int argc, char** argv)
{
  int rate_b = 1; // 1 Hz
  int rate_c = 2; // 2 Hz
  int rate_d = 5; // 5 Hz

  ros::init(argc, argv, "mt_node");

  // spawn another thread
  boost::thread thread_b(do_stuff_b, &rate_b);
  boost::thread thread_c(do_stuff_c, &rate_c);
  boost::thread thread_d(do_stuff_d, &rate_d);

  ros::NodeHandlePtr node = boost::make_shared<ros::NodeHandle>(); // error with std::make_shared<ros::NodeHandle>();
  ros::Publisher pub_a = node->advertise<std_msgs::Empty>("topic_a", 10);

  ros::Rate loop_rate(10); // 10 Hz
  while (ros::ok())
  {
    std_msgs::Empty msg;
    pub_a.publish(msg);
    loop_rate.sleep();

    // process any incoming messages in this thread
    ros::spinOnce();
  }

  // wait the second thread to finish
  thread_b.join();

  return 0;
}
