#include "ros/ros.h"
#include <ros_basics_control/thymio.hpp>

#include <ros_basics_control/thymio_interface_base.h>
#include <ros_basics_control/controller_base.hpp>
#include <ros_basics_control/gazebo_robot_tracker.h>

#include <iostream>

using namespace ros_tp;

struct Params {
    struct ControllerParams : public defaults::ControllerParams {
        static constexpr double precision = 0.01;
    };
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "thymio_ctrl_node");
    ros::NodeHandle nh;

    Thymio<ThymioInterfaceBase, ControllerBase<Params>, GazeboRobotTracker> th(std::make_shared<ros::NodeHandle>(nh), false);

    ros::Rate loop_rate(10);
    while (ros::ok()) {
        th.spin_control();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}