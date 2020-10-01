#include "RPInterfaces/RPPickActionInterface.h"

RPPickInterface::RPPickInterface(ros::NodeHandle &nh) : _nh(nh) {
    _pickclient = _nh.serviceClient<std_srvs::Trigger>("/pick_gui");
    _pickclient.waitForExistence();
}

bool RPPickInterface::concreteCallback(
        const rosplan_dispatch_msgs::ActionDispatch_<std::allocator<void>>::ConstPtr &msg) {

    std_srvs::Trigger srv;
    std::cout << _pickclient.call(srv) << std::endl;
    ROS_INFO_STREAM("PICK_INTERFACE: Action completed with success = " << srv.response.success << " and message" <<
                    srv.response.message);
    return srv.response.success;
}



/*-------------*/
/* Main method */
/*-------------*/

int main(int argc, char **argv) {
    ros::init(argc, argv, "rosplan_interface_grasp");
    ros::NodeHandle nh("~");
    // create PDDL action subscriber
    RPPickInterface rpti(nh);
    rpti.runActionInterface();
    return 0;
}