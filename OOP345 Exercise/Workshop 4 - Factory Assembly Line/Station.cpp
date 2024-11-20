#include <iostream>
#include "Station.h"

namespace seneca
{
	Station::Station()
	{
	}

	Station::Station(const std::string& record)
	{
	}

	Station::~Station()
	{
	}

	const std::string& Station::getItemName() const
	{
		// TODO: insert return statement here
	}

	size_t Station::getNextSerialNumber()
	{
		return size_t();
	}

	size_t Station::getQuantity() const
	{
		return size_t();
	}

	void Station::updateQuantity()
	{
	}

	void Station::display(std::ostream& os, bool full) const
	{
	}
}