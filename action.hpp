#pragma once 

enum class action_t : int {
	go_straight = 0,
	turn_left = 1,
	go_back = 2,
	turn_right = 3,
};

struct action {
	double seconds;
	action_t type;

	action (double s, action_t t) : seconds (s), type (t)
	{
	}
};
