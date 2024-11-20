#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca
{
	CustomerOrder::CustomerOrder(const std::string& record)
	{
	}

	CustomerOrder::CustomerOrder(CustomerOrder&&) noexcept
	{
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&&) noexcept
	{
		// TODO: insert return statement here
	}

	CustomerOrder::~CustomerOrder()
	{
	}

	bool CustomerOrder::isOrderFilled() const
	{
		return false;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		return false;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
	}

	void CustomerOrder::display(std::ostream& os) const
	{
	}

	void CustomerOrder::setWidthField(size_t width)
	{
	}

	size_t CustomerOrder::getWidthField()
	{
		return size_t();
	}
}