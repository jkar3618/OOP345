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
#include "Workstation.h"

namespace seneca
{
	Workstation::Workstation(const std::string& src) : Station(src)
	{ }

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool result = false;

		if (!m_orders.empty())
		{
			if (m_orders.front().isItemFilled(getItemName()) || !getQuantity())
			{
				if (m_pNextStation)
				{
					*m_pNextStation += std::move(m_orders.front());
					result = true;
				}
			}
		}

		return result;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << getItemName() << " --> " << (m_pNextStation ? m_pNextStation->getItemName() : "End of Line.") << '\n';
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));

		return *this;
	}

}