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

#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"

namespace seneca
{
	class Logger
	{
		Event* m_events{ nullptr };
		size_t m_size {0};

	public:
		Logger();

		// copy constructor, assignment delete
		Logger(const Logger& src) = delete;
		Logger& operator=(const Logger& src) = delete;

		Logger(Logger&& src) noexcept; // move constructor
		Logger& operator=(Logger&& src) noexcept; // move operator

		~Logger(); // destructor

		void addEvent(const Event& event); // add an event object to logger

		std::ostream& display(std::ostream& os) const; // display the logged events

	};

	std::ostream& operator<<(std::ostream& os, const Logger& ro);

}

#endif