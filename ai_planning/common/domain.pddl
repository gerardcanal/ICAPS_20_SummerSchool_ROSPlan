(define (domain plan_execution_workshop_domain)

(:requirements :typing :durative-actions)

(:types robot pose box)

(:predicates
    (robot_at_pose ?robot - robot ?pose - pose)
    (box_at_pose ?box - box ?pose - pose)
    (box_on_robot ?box - box ?robot - robot)
    (robot_does_not_have_box ?robot - robot)
)

(:functions
    (move_cost)
    (manipulate_box_cost)
)

(:durative-action move
 :parameters (?robot - robot ?from - pose ?to - pose)
 :duration (= ?duration (move_cost))
 :condition (and
    (at start (robot_at_pose ?robot ?from))
    )
 :effect (and
    (at start (not (robot_at_pose ?robot ?from)))
    (at end (robot_at_pose ?robot ?to))
    )
)

(:durative-action grasp
 :parameters (?robot - robot ?box - box ?pose - pose)
 :duration (= ?duration (manipulate_box_cost))
 :condition (and
    (at start (box_at_pose ?box ?pose))
    (at start (robot_at_pose ?robot ?pose))
    (at start (robot_does_not_have_box ?robot))
    )
 :effect (and
    (at start (not (box_at_pose ?box ?pose)))
    (at end (box_on_robot ?box ?robot))
    (at start (not (robot_does_not_have_box ?robot)))
    )
)

(:durative-action place
 :parameters (?robot - robot ?box - box ?pose - pose)
 :duration (= ?duration (manipulate_box_cost))
 :condition (and
    (at start (box_on_robot ?box ?robot))
    (at start (robot_at_pose ?robot ?pose))
    )
 :effect (and
    (at start (not (box_on_robot ?box ?robot)))
    (at end (box_at_pose ?box ?pose))
    (at end (robot_does_not_have_box ?robot))
    )
)

)

