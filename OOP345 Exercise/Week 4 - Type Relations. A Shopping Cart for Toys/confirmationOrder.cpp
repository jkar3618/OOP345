#include <iostream>
#include "confirmationOrder.h"
using namespace std;

namespace seneca
{
	ConfirmationOrder::ConfirmationOrder(const ConfirmationOrder& co)
	{
	}

	ConfirmationOrder::ConfirmationOrder(ConfirmationOrder&& co) noexcept
	{
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
}