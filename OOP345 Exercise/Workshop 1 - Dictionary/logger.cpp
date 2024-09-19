#include <iostream>
#include "logger.h"

using namespace std;

namespace seneca
{
	Logger::Logger()
	{
	}
	Logger::Logger(const Logger&& src) noexcept
	{
		operator=(std::move(src));
	}
	Logger& Logger::operator=(Logger&& src) noexcept
	{
		if (this != &src)
		{
			delete[] m_events;

			m_events = src.m_events;
			m_size = src.m_size;

			src.m_events = nullptr;
			src.m_size = 0;
		}
		return *this;
	}
	Logger::~Logger()
	{
		delete[] m_events;
	}
	void Logger::addEvent(const Event& event)
	{
		Event* temp = new Event[m_size + 1];

		for (size_t i = 0; i < m_size; i++)
		{
			temp[i] = m_events[i];
		}

		temp[m_size] = event;

		delete[] m_events;
		m_events = temp;

		temp = nullptr;
		m_size++;

	}
	std::ostream& Logger::display(std::ostream& os) const
	{
		for (size_t i = 0; i < m_size; i++)
		{
			os << m_events[i] << endl;
		}

		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Logger& ro)
	{
		return ro.display(os);
	}
}