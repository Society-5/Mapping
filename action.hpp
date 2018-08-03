#pragma once 

enum class action_t : int {
	go_straight = 0,
	turn_left = 1,
	turn_right = 2,
	go_back = 3,
};

struct action {
	double seconds;
	action_t type;
};
