#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc,argv,"test_publisher");
	ros::NodeHandle node_obj;
	ros::Publisher publisher = node_obj.advertise<std_msgs::Int32>("/num",10);
	ros::Rate loop(10);
	int count = 0;

	while(ros::ok())
	{
		std_msgs::Int32 msg;
		msg.data = count;
		ROS_INFO("%d",msg.data);
		publisher.publish(msg);
		ros::spinOnce();
		loop.sleep();
		++count;
	}

	return 0;
}