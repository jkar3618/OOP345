#ifndef SENECA_CONFIRMATIONORDER_H
#define SENECA_CONFIRMATIONORDER_H
#include "toy.h"

namespace seneca
{
	class ConfirmationOrder
	{
		const seneca::Toy** m_toys{ nullptr };
		int m_numOfToy{};

	public:
		ConfirmationOrder(const ConfirmationOrder& co);
		ConfirmationOrder(ConfirmationOrder&& co) noexcept;
		~ConfirmationOrder();

		ConfirmationOrder& operator=(const ConfirmationOrder& co);
		ConfirmationOrder& operator=(ConfirmationOrder&& co) noexcept;
		
		ConfirmationOrder& operator+=(const Toy& toy);
		ConfirmationOrder& operator-=(const Toy& toy);
	};

}

#endif

