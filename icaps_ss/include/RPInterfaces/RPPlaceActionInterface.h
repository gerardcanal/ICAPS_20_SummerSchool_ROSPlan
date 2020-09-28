#include <ros/ros.h>
#include <vector>

#include "rosplan_action_interface/RPActionInterface.h"
#include "std_srvs/Trigger.h"

#ifndef RPAIPLACE
#define RPAIPLACE

/**
 * This file defines an action interface for the place action.
 */

class RPPlaceInterface: public KCL_rosplan::RPActionInterface {

private:
    ros::NodeHandle _nh;
    ros::ServiceClient _placeclient;

public:

    /* constructor */
    RPPlaceInterface(ros::NodeHandle &nh);

    /* listen to and process action_dispatch topic */
    bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
};

#endif