#include <iostream>
#include <string>
#include <iomanip>
#include "event.h"

using namespace std;

namespace seneca
{
	Event::Event() : e_eventName{nullptr}, e_duration{0}
	{
	}

	Event::Event(const char* name, const std::chrono::nanoseconds& duration) : e_eventName{name}, e_duration{duration}
	{
	}

	std::ostream& operator<<(std::ostream& os, const Event& ro)
	{
		static int COUNTER = 1;



		cout.fill(' ');
		cout.width(2);
		cout << COUNTER++ << ": ";

		cout.fill(' ');
		cout.width(40);
		cout << ro.e_eventName;

		cout << " -> ";

		switch (tUnit)
		{
		case seneca::Seconds:

			break;
		case seneca::Milliseconds:
			break;
		case seneca::Microseconds:
			break;
		case seneca::Nanoseconds:
			break;
		default:
			break;
		}


		return os;
	}
}