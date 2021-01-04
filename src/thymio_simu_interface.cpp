#include <ros_basics_control/thymio_simu_interface.h>

namespace ros_tp {

    ThymioSimuInterface::ThymioSimuInterface(std::shared_ptr<ros::NodeHandle> nh, bool) : ThymioInterfaceBase(nh, true)
    {
        _vel_pub = _nh->advertise<geometry_msgs::Twist>("cmd_vel", 1);
    }

    void ThymioSimuInterface::set_target_velocities(double v, double z)
    {
        geometry_msgs::Twist tw;
        tw.linear.x = v;
        tw.angular.z = z;
        _vel_pub.publish(tw);
    }

} // namespace ros_tp