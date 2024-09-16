#include <iostream>
#include <string>
#include <iomanip>
#include "TimedTask.h"

using namespace std;

namespace seneca
{
	
	//TimedTask::TimedTask() : count(0) {}

	//void TimedTask::startTime()
	//{
	//	t_startTime = std::chrono::steady_clock::now();
	//}

	//void TimedTask::stopClock()
	//{
	//}

	//void TimedTask::addTask(const char* taskName)
	//{
	//}

	//std::ostream& operator<<(std::ostream& os, const TimedTask& src)
	//{

	//}




























	// deault constructor
	TimedTask::TimedTask() : numRecords(0u), t_startTime{}, t_endTime{}
	{ }

	// a modifier that starts the timer for task
	void TimedTask::startClock()
	{
		t_startTime = std::chrono::steady_clock::now();
	}

	// a modifier that stops the timer for task
	void TimedTask::stopClock()
	{
		t_endTime = std::chrono::steady_clock::now();
	}

	//update the next time-record in the array
	void TimedTask::addTask(const char* src)
	{
		if (numRecords < maxEvent)
		{
			t_task[numRecords].t_name = src;
			t_task[numRecords].t_unitTime = "nanoseconds";
			t_task[numRecords].t_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t_endTime - t_startTime);
			numRecords++;
		}
	}

	//display the records of the array in a specific format
	std::ostream& operator<<(std::ostream& os, const TimedTask& src)
	{
		cout << "Execution Times:" << endl;
		cout << "--------------------------" << endl;

		for (int i = 0; i < src.numRecords; i++)
		{
			os << setw(21) << left << src.t_task[i].t_name;
			os << setw(13) << right << src.t_task[i].t_duration.count();
			os << " " << src.t_task[i].t_unitTime << endl;

		}

		cout << "--------------------------" << endl;



		return os;
	}
}
