#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <visualization_msgs/Marker.h>

ros::NodeHandle nh;

//std_msgs::Int32 int_msg;
//ros::Publisher pub_distance("distance", &int_msg);

visualization_msgs::Marker marker;
ros::Publisher pub_marker("marker", &marker);
uint32_t shape = visualization_msgs::Marker::ARROW;

const int TRIG_PIN = 10;
const int ECHO_PIN = 11;

unsigned long duration;
unsigned int distance;
int input;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  //Serial.begin(9600);
  nh.initNode();
  //nh.advertise(chatter);
  //nh.advertise(pub_distance);
  nh.advertise(pub_marker);
}

void loop() {
  distance = calculateDistance();
  if(distance > 300){
    distance = 0;
  }
  /*
  Serial.print(distance);
  Serial.print(",");
  */

  /*
  int_msg.data = distance;
  pub_distance.publish( &int_msg );
  */
  
  marker.header.frame_id = "/my_frame";
  marker.header.stamp = nh.now();
  marker.type = shape;
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose.position.x = 0;
  marker.pose.position.y = 0;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;
  marker.scale.x = 1.0*distance/100;
  marker.scale.y = .1;
  marker.scale.z = .1;
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = .5;
  
  /*
  switch (shape)
  {
    case visualization_msgs::Marker::CUBE:
      shape = visualization_msgs::Marker::SPHERE;
      break;
    case visualization_msgs::Marker::SPHERE:
      shape = visualization_msgs::Marker::ARROW;
      break;
    case visualization_msgs::Marker::ARROW:
      shape = visualization_msgs::Marker::CYLINDER;
      break;
    case visualization_msgs::Marker::CYLINDER:
      shape = visualization_msgs::Marker::CUBE;
      break;
  }
  */
  
  pub_marker.publish( &marker );
  
  nh.spinOnce();
  delay(100);
}

// [mm]
int calculateDistance(){ 
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration*0.34/2.0;

  return distance;
}
