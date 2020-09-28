#include <ros/ros.h>
#include <vector>

#include "rosplan_action_interface/RPActionInterface.h"
#include "std_srvs/Trigger.h"

#ifndef RPAIPICK
#define RPAIPICK

/**
 * This file defines an action interface for the pick action.
 */

class RPPickInterface: public KCL_rosplan::RPActionInterface {

private:
    ros::NodeHandle _nh;
    ros::ServiceClient _pickclient;

public:

    /* constructor */
    RPPickInterface(ros::NodeHandle &nh);

    /* listen to and process action_dispatch topic */
    bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
};

#endif