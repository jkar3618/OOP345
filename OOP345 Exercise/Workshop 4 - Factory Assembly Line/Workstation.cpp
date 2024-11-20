#include <iostream>
#include "Workstation.h"

namespace seneca
{
	Workstation::Workstation()
	{

	}

	Workstation::Workstation(const std::string& src)
	{
	}

	void Workstation::fill(std::ostream& os)
	{
	}

	bool Workstation::attemptToMoveOrder()
	{
		return false;
	}

	void Workstation::setNextStation(Workstation* station)
	{
	}

	Workstation* Workstation::getNextStation() const
	{
		return nullptr;
	}

	void Workstation::display(std::ostream& os) const
	{
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		// TODO: insert return statement here
	}

	Workstation::~Workstation()
	{

	}



}