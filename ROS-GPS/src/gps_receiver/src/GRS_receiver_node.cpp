#include <ros/ros.h>
#include <gps_receiver/gps_message.h>
#include <array>

void calc_average(float val)
{
  // set params
  const int hz = 10;
  const int t = 1;
  const int N = t*hz;
  static float AVE = 0.0;
  static std::array<float, N> array_values;
  // [most past, ..., current]
  
  // update array
  printf("val : %f\n", val);
  printf("size : %d\n", array_values.size());
  for(int i=0; i!=array_values.size()-1; ++i)
  {
     printf("%d\n", i);
     array_values[i] = array_values[i+1];
  }
  
  // add current value
  array_values[array_values.size()-1] = val;
  
  // show array
  for(int i=0; i!=array_values.size(); ++i)
  {
     printf("%f,", array_values[i]);
  }
  printf("\n");

  // DP
  AVE = ((AVE*N) - array_values[0] + val) / N;
  printf("AVE : %f\n", AVE);
  
  // For
  float tmp = 0.0;
  float cut_time = 0;
  for(int i=0; i!=array_values.size()-cut_time*hz; ++i)
  {
     tmp += array_values[i];
  }
  tmp = tmp/N;
  printf("AVE : %f\n", tmp);
}

void Callback(const gps_receiver::gps_message& msg)
{
  static int i = 1;
  const int hz = 10;
  ROS_INFO("subscribe: %f", msg.lat);
  if (i%hz == 0 & msg.lat!=-1)
  {
    calc_average(msg.lat);
    i = 1;
  }else
  {
    ++i;
  }
  printf("%d\n", i);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "GRS_receiver_node");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("gps", 10, Callback);

  ros::spin();
  return 0;
}
