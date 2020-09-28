#include "RPInterfaces/RPMoveBaseActionInterface.h"

RPMoveBaseInterface::RPMoveBaseInterface(ros::NodeHandle &nh) : _nh(nh), _mb_ac("move_base", true) {
    while(!_mb_ac.waitForServer(ros::Duration(5.0))){
        ROS_INFO("Waiting for the move_base action server to come up");
    }

}

bool RPMoveBaseInterface::concreteCallback(
        const rosplan_dispatch_msgs::ActionDispatch_<std::allocator<void>>::ConstPtr &msg) {

    move_base_msgs::MoveBaseGoal goal;

    //we'll send a goal to the robot to move 1 meter forward
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    std::vector<double> position, orientation;
    _nh.getParam("/wps/red_table/position", position);
    _nh.getParam("/wps/red_table/orientation", orientation);

    goal.target_pose.pose.position.x = position[0];
    goal.target_pose.pose.position.y = position[1];
    goal.target_pose.pose.position.z = position[2];
    goal.target_pose.pose.orientation.x = orientation[0];
    goal.target_pose.pose.orientation.y = orientation[1];
    goal.target_pose.pose.orientation.z = orientation[2];
    goal.target_pose.pose.orientation.w = orientation[3];

    ROS_INFO("Sending goal");
    _mb_ac.sendGoal(goal);

    _mb_ac.waitForResult();

    if(_mb_ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("RP_MOVE_BASE: Succeeded.");
        return true;
    ROS_INFO("RP_MOVE_BASE: Failed for some reason");
    return false;
}



/*-------------*/
/* Main method */
/*-------------*/

int main(int argc, char **argv) {
    ros::init(argc, argv, "rp_moveBase_interface", ros::init_options::AnonymousName);
    ros::NodeHandle nh("~");
    // create PDDL action subscriber
    RPMoveBaseInterface rpti(nh);
    rpti.runActionInterface();
    return 0;
}