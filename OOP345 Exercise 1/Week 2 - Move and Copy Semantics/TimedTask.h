#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <string>
#include <chrono>

namespace seneca
{
	class TimedTask
	{
		enum {maxEvent = 10};
		size_t numRecords{ 0u };

		std::chrono::steady_clock::time_point t_startTime;
		std::chrono::steady_clock::time_point t_endTime;

		struct Task
		{
			std::string t_name;
			std::string t_unitTime;
			std::chrono::steady_clock::duration t_duration;
		};

	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char *src);

		friend std::ostream &operator<<(std::ostream & os, const TimedTask & src);
	};
}

#endif // !SENECA_TIMEDTASK_H
