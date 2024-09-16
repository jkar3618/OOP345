#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <chrono>

namespace seneca
{
	class Event
	{
		std::string eventName;
		std::chrono::nanoseconds duration;

	public:
		Event();
		Event(const char* name, const std::chrono::nanoseconds& duration);
		friend std::ostream operator<<(std::ostream& os, const Event& ro);
	};
}

#endif