#include "RPInterfaces/RPPlaceActionInterface.h"

RPPlaceInterface::RPPlaceInterface(ros::NodeHandle &nh) : _nh(nh) {
    _placeclient = _nh.serviceClient<std_srvs::Trigger>("/place_gui");
    _placeclient.waitForExistence();
}

bool RPPlaceInterface::concreteCallback(
        const rosplan_dispatch_msgs::ActionDispatch_<std::allocator<void>>::ConstPtr &msg) {

    std_srvs::Trigger srv;
    _placeclient.call(srv);
    ROS_INFO_STREAM("PLACE_INTERFACE: Action completed with success = " << srv.response.success << " and message" <<
                    srv.response.message);
    return srv.response.success;
}



/*-------------*/
/* Main method */
/*-------------*/

int main(int argc, char **argv) {
    ros::init(argc, argv, "rp_place_interface", ros::init_options::AnonymousName);
    ros::NodeHandle nh("~");
    // create PDDL action subscriber
    RPPlaceInterface rpti(nh);
    rpti.runActionInterface();
    return 0;
}