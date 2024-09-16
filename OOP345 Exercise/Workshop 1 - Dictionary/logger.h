#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"

namespace seneca
{
	class Logger
	{
		Event* m_events = nullptr;
		size_t m_size;
		size_t m_capacity{};

	public:
		Logger();

		// copy constructor, assignment delete
		Logger(const Logger& src) = delete;
		Logger& operator=(const Logger& src) = delete;

		Logger(const Logger&& src) noexcept;
		Logger& operator=(Logger&& src) noexcept;

		~Logger();

		void addEvent(const Event& event);
		friend std::ostream operator<<(std::ostream& os, const Logger& ro);


	};

}

#endif