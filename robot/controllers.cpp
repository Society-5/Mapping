namespace robosapien {
	class interface {
		public: void turn_right (double seconds)
		{
			#ifdef debug
				#include <iostream>
				std::cout << "The robot is turning right right now.";
				char a;
				std::cin >> a;
				std::cout << "The robot was turning right for " << seconds << "s.";
			#endif
			return;
		}
		public: void go_back (double seconds)
		{
			#ifdef debug
				#include <iostream>
				std::cout << "The robot is going back right now.";
				char a;
				std::cin >> a;
				std::cout << "The robot was going back for " << seconds << "s.";
			#endif
			return;
		}
		public: void go_forward (double seconds)
		{
			#ifdef debug
				#include <iostream>
				std::cout << "The robot is going forward right now.";
				char a;
				std::cin >> a;
				std::cout << "The robot was going forward for " << seconds << "s.";
			#endif
			return;
		}
		public: void turn_left (double seconds)
		{
			#ifdef debug
				#include <iostream>
				std::cout << "The robot is turning left right now.";
				char a;
				std::cin >> a;
				std::cout << "The robot was turning left for " << seconds << "s.";
			#endif
			return;
		}
	};
}
