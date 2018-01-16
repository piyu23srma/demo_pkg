#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "demo_pkg/demo_msg.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
	ros::init(argc,argv,"msg_publisher");
	ros::NodeHandle node_obj;
	ros::Publisher publisher = node_obj.advertise<demo_pkg::demo_msg>("/msg",10);
	ros::Rate loop(10);
	int count = 0;

	while(ros::ok())
	{
		demo_pkg::demo_msg msg;

		std::stringstream ss;
		ss << "Hello World";
		msg.greeting = ss.str();

		msg.number = count;

		ROS_INFO("%d",msg.number);
		ROS_INFO("%s",msg.greeting.c_str());

		publisher.publish(msg);
		ros::spinOnce();
		loop.sleep();
		++count;
	}

	return 0;
}