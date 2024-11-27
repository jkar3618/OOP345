//*****************************************************************************
//<assessment name : Workshop - #4>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************
#include <iostream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

namespace seneca
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream input(file);
		std::string line;
		std::string current, next;
		Utilities util;
		bool more = true;
		size_t pos = 0;

		if (input)
		{
			while (std::getline(input, line))
			{
				current = util.extractToken(line, pos, more);
				next = util.extractToken(line, pos, more);
			}

			auto station = std::find_if(stations.begin(), stations.end(), [current](const Workstation* s)
				{
					return s->getItemName() == current;
				});

			if (station != stations.end() && !next.empty())
			{
				auto nextStation = std::find_if(stations.begin(), stations.end(), [next](const Workstation* s)
					{
						return s->getItemName() == next;
					});
				if (nextStation != stations.end())
				{
					(*station)->setNextStation(*nextStation);
				}
			}

			m_activeLine.push_back(*station);
		}

		auto firstStation = std::find_if(stations.begin(), stations.end(), [&](const Workstation* s1)
			{
				return std::none_of(stations.begin(), stations.end(), [&](const Workstation* s2)
					{
						return s1 == s2->getNextStation();
					});
			});

		m_firstStation = *firstStation;

		m_cntCustomerOrder = g_pending.size();
	}


	void LineManager::reorderStations()
	{
		std::vector<Workstation*> newLine;
		newLine.push_back(m_firstStation);
		int i = 0;

		while (newLine[i]->getNextStation() != nullptr)
		{
			newLine.push_back(newLine[i]->getNextStation());
			i++;
		}
		m_activeLine = newLine;
	}

	bool LineManager::run(std::ostream& os)
	{
		bool result = false;
		static int CNT{ 1 };

		os << "Line Manager Iteration: COUNT" << std::endl;

		m_firstStation = std::move(g_pending.front());
		return result;
	}

	void LineManager::display(std::ostream& os) const
	{
	}
}