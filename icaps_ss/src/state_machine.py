


import rospy


class State:
    START = 0
    MOVE_GRASP = 1
    GRASP = 2
    MOVE_RELEASE = 3
    RELEASE = 4
    COMPLETE = 5



if __name__ == "__main__":
    current_state = State.START



