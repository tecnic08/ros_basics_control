#ifndef ROS_TP_THYMIO_SIMU_INTERFACE_BASE_H
#define ROS_TP_THYMIO_SIMU_INTERFACE_BASE_H

#include <ros_basics_control/thymio_interface_base.h>
#include <geometry_msgs/Twist.h>

namespace ros_tp {

    class ThymioSimuInterface : public ThymioInterfaceBase {
    public:
        ThymioSimuInterface(std::shared_ptr<ros::NodeHandle> nh, bool);

        virtual void set_target_velocities(double v, double z);

    protected:
        ros::Publisher _vel_pub;
    };

} // namespace ros_tp

#endif