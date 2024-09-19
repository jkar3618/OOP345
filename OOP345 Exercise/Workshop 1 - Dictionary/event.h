#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <chrono>

namespace seneca
{
	enum TimeUnits
	{
		Seconds = 2,
		Milliseconds = 5,
		Microseconds = 8,
		Nanoseconds = 11
	};

	TimeUnits tUnit = TimeUnits::Nanoseconds;

	class Event
	{
		std::string m_eventName{};
		std::chrono::nanoseconds m_duration{};
		std::string e_eventName {};
		std::chrono::nanoseconds e_duration{};

	public:
		Event();
		Event(const char* name, const std::chrono::nanoseconds& duration);
		friend std::ostream& operator<<(std::ostream& os, const Event& ro);
	};
}

#endif