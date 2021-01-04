#include <ros_basics_control/gazebo_robot_tracker.h>

#include <ros/ros.h>
#include <tf/tf.h>

namespace ros_tp {
    GazeboRobotTracker::GazeboRobotTracker(std::shared_ptr<ros::NodeHandle> nh) : _nh(nh)
    {
        _odom_sub = _nh->subscribe("odom", 5, &GazeboRobotTracker::_odom_callback, this);
    }

    void GazeboRobotTracker::_odom_callback(const nav_msgs::Odometry::ConstPtr& msg)
    {
        // position
        _pos.x = msg->pose.pose.position.x;
        _pos.y = msg->pose.pose.position.y;
        _pos.z = msg->pose.pose.position.z;

        // orientation, from quaternions to roll, pitch, yaw
        tf::Quaternion q(
            msg->pose.pose.orientation.x,
            msg->pose.pose.orientation.y,
            msg->pose.pose.orientation.z,
            msg->pose.pose.orientation.w);
        tf::Matrix3x3 m(q);
        double roll, pitch, yaw;
        m.getRPY(_rpy.roll, _rpy.pitch, _rpy.yaw);
    }

} // namespace ros_tp