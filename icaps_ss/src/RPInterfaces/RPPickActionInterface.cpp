#include "RPInterfaces/RPPickActionInterface.h"

RPPickInterface::RPPickInterface(ros::NodeHandle &nh) : _nh(nh) {
    ros::ServiceClient _pickclient = _nh.serviceClient<std_srvs::Trigger>("/pick_gui");
}

bool RPPickInterface::concreteCallback(
        const rosplan_dispatch_msgs::ActionDispatch_<std::allocator<void>>::ConstPtr &msg) {

    std_srvs::Trigger srv;
    _pickclient.call(srv);
    ROS_INFO_STREAM("PICK_INTERFACE: Action completed with success = " << srv.response.success << " and message" <<
                    srv.response.message);
    return srv.response.success;
}



/*-------------*/
/* Main method */
/*-------------*/

int main(int argc, char **argv) {
    ros::init(argc, argv, "rp_pick_interface", ros::init_options::AnonymousName);
    ros::NodeHandle nh("~");
    // create PDDL action subscriber
    RPPickInterface rpti(nh);
    rpti.runActionInterface();
    return 0;
}