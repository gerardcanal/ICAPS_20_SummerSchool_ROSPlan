#include <ros/ros.h>
#include <vector>

#include "rosplan_action_interface/RPActionInterface.h"
#include "std_srvs/Trigger.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#ifndef RPAIMoveBase
#define RPAIMoveBase

/**
 * This file defines an action interface for the Move Base action.
 */
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class RPMoveBaseInterface: public KCL_rosplan::RPActionInterface {

private:
    ros::NodeHandle _nh;
    MoveBaseClient _mb_ac;

public:

    /* constructor */
    RPMoveBaseInterface(ros::NodeHandle &nh);

    /* listen to and process action_dispatch topic */
    bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
};

#endif