#include <ros_basics_control/thymio_interface_base.h>

namespace ros_tp {

    ThymioInterfaceBase::ThymioInterfaceBase(std::shared_ptr<ros::NodeHandle> nh, bool advertise) : _nh(nh), _advertise(advertise)
    {
        if (_advertise) {
            _set_velocities_sub = _nh->subscribe("set_velocities", 5, &ThymioInterfaceBase::_set_velocities_cb, this);
        }
    }

    void ThymioInterfaceBase::_set_velocities_cb(const ros_basics_msgs::SimpleVelocities::ConstPtr& msg)
    {
        if (_advertise) {
            set_target_velocities(msg->v, msg->w);
        }
    }

} // namespace ros_tp