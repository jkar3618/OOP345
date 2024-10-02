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
		ConfirmationOrder() {};
		ConfirmationOrder(const ConfirmationOrder& co);
		ConfirmationOrder(ConfirmationOrder&& co) noexcept;
		~ConfirmationOrder();

		ConfirmationOrder& operator=(const ConfirmationOrder& co);
		ConfirmationOrder& operator=(ConfirmationOrder&& co) noexcept;
		
		ConfirmationOrder& operator+=(const Toy& toy);
		ConfirmationOrder& operator-=(const Toy& toy);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationOrder& order);
	};

}

#endif

