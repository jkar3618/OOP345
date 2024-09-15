#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

namespace seneca
{
	class TimedTask
	{
		enum {maxEvent = 10};
		size_t numRecords{ 0u };

		std::chrono::steady_clock::time_point t_startTime; // the start time for the current task
		std::chrono::steady_clock::time_point t_endTime; // the end time for the current task

		struct Task
		{
			std::string t_name; // task name
			std::string t_unitTime; // units of time
			std::chrono::steady_clock::duration t_duration; // the duration of the task
		} t_task[maxEvent];

	public:
		TimedTask(); // deault constructor
		void startClock(); // a modifier that starts the timer for task
		void stopClock(); // a modifier that stops the timer for task
		void addTask(const char *src); //update the next time-record in the array

		friend std::ostream &operator<<(std::ostream & os, const TimedTask & src); //display the records of the array in a specific format
	};
}

#endif // !SENECA_TIMEDTASK_H

