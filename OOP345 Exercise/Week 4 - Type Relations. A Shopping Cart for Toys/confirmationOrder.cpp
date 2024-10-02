#include <iostream>
#include "confirmationOrder.h"
using namespace std;

namespace seneca
{
	ConfirmationOrder::ConfirmationOrder(const ConfirmationOrder& co)
	{
		*this = co;
	}

	ConfirmationOrder::ConfirmationOrder(ConfirmationOrder&& co) noexcept
	{
		*this = std::move(co);
	}

	ConfirmationOrder::~ConfirmationOrder()
	{
	}

	ConfirmationOrder& ConfirmationOrder::operator=(const ConfirmationOrder& co)
	{
		return *this;
	}

	ConfirmationOrder& ConfirmationOrder::operator=(ConfirmationOrder&& co) noexcept
	{
		return *this;
	}

	ConfirmationOrder& ConfirmationOrder::operator+=(const Toy& toy)
	{
		return *this;
	}

	ConfirmationOrder& ConfirmationOrder::operator-=(const Toy& toy)
	{
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationOrder& order)
	{
		return os;
	}
}