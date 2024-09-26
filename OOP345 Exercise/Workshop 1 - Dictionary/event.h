//*****************************************************************************
//<assessment name example : Workshop - #1>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <chrono>

namespace seneca
{
	// Enum for representin different units of time
	enum TimeUnits
	{
		Seconds = 2,
		Milliseconds = 5,
		Microseconds = 8,
		Nanoseconds = 11
	};

	class Event
	{
		std::string m_eventName{};
		std::chrono::nanoseconds m_duration{};

	public:
		Event(); // default constructor
		Event(const char* name, const std::chrono::nanoseconds& duration); // 2 arguments constructor

		friend std::ostream& operator<<(std::ostream& os, const Event& ro);
	};
}

#endif