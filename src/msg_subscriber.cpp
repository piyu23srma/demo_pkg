#include "ros/ros.h"
#include "demo_pkg/demo_msg.h"
#include "std_msgs/Int32.h"
#include <iostream>



void callback(const demo_pkg::demo_msg::ConstPtr& msg)
{
	ROS_INFO("Received greeting [%s]",msg->greeting.c_str());
	ROS_INFO("Received [%d]",msg->number);
}


int main(int argc, char **argv)
{
	ros::init(argc,argv,"msg_subscriber");
	ros::NodeHandle node_obj;
	ros::Subscriber subscriber = node_obj.subscribe("/msg",10,callback);
	ros::spin();
	return 0;
}