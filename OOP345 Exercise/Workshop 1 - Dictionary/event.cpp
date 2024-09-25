#include <iostream>
#include <string>
#include <iomanip>
#include "event.h"
#include "settings.h"

using namespace std;

namespace seneca
{

	TimeUnits tUnit = TimeUnits::Nanoseconds;

	Event::Event() : m_eventName{""}, m_duration{0}
	{
	}

	Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_eventName{ name }, m_duration{ duration }
	{
	}

	std::ostream& operator<<(std::ostream& os, const Event& ro)
	{
		static int COUNTER = 1;

		cout << setw(2) << COUNTER++ << ": ";

		cout.fill(' ');
		cout.width(40);
		cout << ro.m_eventName;

		cout << " -> ";

		//cout << setw(tUnit);

		if (g_settings.m_time_units == "microseconds")
		{
			cout <<setw(TimeUnits::Microseconds) << std::chrono::duration_cast<std::chrono::microseconds>(ro.m_duration).count();
		}
		else if (g_settings.m_time_units == "milliseconds")
		{
			cout << setw(TimeUnits::Milliseconds) << std::chrono::duration_cast<std::chrono::milliseconds>(ro.m_duration).count();
		}
		else if (g_settings.m_time_units == "seconds")
		{
			cout << setw(TimeUnits::Seconds) << std::chrono::duration_cast<std::chrono::seconds>(ro.m_duration).count();
		}
		else 
		{
			cout << setw(TimeUnits::Nanoseconds) << std::chrono::duration_cast<std::chrono::nanoseconds>(ro.m_duration).count();
		}

		cout << ' ' << g_settings.m_time_units;

		return os;
	}
}