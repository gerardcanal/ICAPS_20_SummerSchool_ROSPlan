(define (domain plan_execution_workshop_domain)

(:requirements :typing :durative-actions :fluents)

(:types robot wp box)

(:predicates
    (robot_at_wp ?robot - robot ?wp - wp)
    (box_at_wp ?box - box ?wp - wp)
    (box_on_robot ?box - box ?robot - robot)
    (robot_does_not_have_box ?robot - robot)
    (wp_visited ?wp - wp)
)

(:functions
    (distance ?a - wp ?b - wp)
    (manipulate_box_cost)
)

(:durative-action move
 :parameters (?robot - robot ?from - wp ?to - wp)
 :duration (= ?duration 3)
 :condition (and
    (at start (robot_at_wp ?robot ?from))
    )
 :effect (and
    (at start (not (robot_at_wp ?robot ?from)))
    (at start (wp_visited ?to))
    (at end (robot_at_wp ?robot ?to))
    )
)

(:durative-action grasp
 :parameters (?robot - robot ?box - box ?wp - wp)
 :duration (= ?duration (manipulate_box_cost))
 :condition (and
    (at start (box_at_wp ?box ?wp))
    (over all (robot_at_wp ?robot ?wp))
    (at start (box_on_robot ?box ?robot));;
    )
 :effect (and
    (at end (not (box_at_wp ?box ?wp)))
    (at end (box_on_robot ?box ?robot))
    (at end (not (robot_does_not_have_box ?robot)))
    )
)

(:durative-action place
 :parameters (?robot - robot ?box - box ?wp - wp)
 :duration (= ?duration (manipulate_box_cost))
 :condition (and
    (at start (box_on_robot ?box ?robot))
    (over all (robot_at_wp ?robot ?wp))
    )
 :effect (and
    (at end (not (box_on_robot ?box ?robot)))
    (at end (box_at_wp ?box ?wp))
    (at end (robot_does_not_have_box ?robot))
    )
)

)

