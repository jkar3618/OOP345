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

#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include <chrono>
#include "event.h"

namespace seneca
{
	class TimeMonitor
	{
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		const char* m_eventName{ nullptr };

	public:
		void startEvent(const char* name); // start the timer for an event by storing the event name and start time
		Event stopEvent(); // stop the timer, calculate the event duration and return event object
	};
}

#endif
