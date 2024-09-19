#include <iostream>
#include "timeMonitor.h"

using namespace std;

namespace seneca
{
    void TimeMonitor::startEvent(const char* name)
    {
        m_eventName = name;

        m_startTime = std::chrono::steady_clock::now();

    }
    Event TimeMonitor::stopEvent()
    {
        Event event(m_eventName, chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - m_startTime));

        return event;
    }
}