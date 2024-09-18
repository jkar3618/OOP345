#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <chrono>

namespace seneca
{
	enum TimeUnits
	{
		Seconds,
		Milliseconds,
		Microseconds,
		Nanoseconds
	};

	TimeUnits tUnit = TimeUnits::Nanoseconds;

	class Event
	{
		std::string e_eventName {};
		std::chrono::nanoseconds e_duration{};

	public:
		Event();
		Event(const char* name, const std::chrono::nanoseconds& duration);
		friend std::ostream& operator<<(std::ostream& os, const Event& ro);
	};
}

#endif