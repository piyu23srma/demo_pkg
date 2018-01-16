#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

void callback(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("Received [%d]",msg->data);
}


int main(int argc, char **argv)
{
	ros::init(argc,argv,"test_subscriber");
	ros::NodeHandle node_obj;
	ros::Subscriber subscriber = node_obj.subscribe("/num",10,callback);
	ros::spin();
	return 0;
}