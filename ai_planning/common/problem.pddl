(define (problem plan_execution_workshop_problem)
(:domain plan_execution_workshop_domain)

(:objects
    robot1 - robot
    table1 table2 table3 table4 table5 table6 - pose
    green_box blue_box red_box - box
)


(:init 
    (robot_at_pose robot1 table1)
    (robot_does_not_have_box robot1)
    (box_at_pose green_box table1)
    (box_at_pose blue_box table2)
    (box_at_pose red_box table3)

    ;(not_acting agv1)
    ;(not_acting agv2)
    ;(not_acting agv3)

	
    (= (move_cost) 10)
    (= (manipulate_box_cost) 5)

)

(:goal 
(and
    (box_at_pose green_box table4)
    (box_at_pose blue_box table5)
    (box_at_pose red_box table6)
)
)

(:metric minimize total-time)
)


