#include "ros/ros.h"
#include <demo_pkg/demo_srv.h>
#include <iostream>
#include <sstream>

bool service_callback(demo_pkg::demo_srv::Request &req, demo_pkg::demo_srv::Response &res)
{
	std::stringstream ss;
	ss << "Received Here";
	res.out = ss.str();

	ROS_INFO("From Client [%s], Server says [%s]",req.in.c_str(),res.out.c_str());
	return true;
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"service_server");
	ros::NodeHandle nh;

	ros::ServiceServer service = nh.advertiseService("service",service_callback);
	ROS_INFO("Ready to receive from client.");
	ros::spin();
	return 0;
}