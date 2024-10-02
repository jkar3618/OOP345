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
		delete[] m_toys;
	}

	ConfirmationOrder& ConfirmationOrder::operator=(const ConfirmationOrder& co)
	{
		if (this != &co)
		{
			delete[] m_toys;

			if (co.m_toys != nullptr)
			{
				m_numOfToy = co.m_numOfToy;
				m_toys = new const Toy * [m_numOfToy];

				for (size_t i = 0; i < m_numOfToy; i++)
				{
					m_toys[i] = co.m_toys[i];
				}
			}
		}

		return *this;
	}

	ConfirmationOrder& ConfirmationOrder::operator=(ConfirmationOrder&& co) noexcept
	{
		if (this != &co)
		{
			delete[] m_toys;

			if (co.m_toys != nullptr)
			{
				m_numOfToy = co.m_numOfToy;
				m_toys = co.m_toys;

				m_numOfToy = 0;
				co.m_toys = nullptr;
			}
		}

		return *this;
	}

	ConfirmationOrder& ConfirmationOrder::operator+=(const Toy& toy)
	{
		int index = -1;

		for (size_t i = 0; i < m_numOfToy; i++)
		{
			if (m_toys[i] == &toy)
			{
				index = i;
			}
		}

		if (index == -1)
		{
			const Toy** temp = nullptr;

			temp = new const Toy * [m_numOfToy + 1];

			for (size_t i = 0; i < m_numOfToy; i++)
			{
				temp[i] = m_toys[i];
			}
			temp[m_numOfToy] = &toy;
			delete[] m_toys;

			m_toys = temp;
			m_numOfToy++;
		}

		return *this;
	}

	ConfirmationOrder& ConfirmationOrder::operator-=(const Toy& toy)
	{
		int index = -1;

		for (size_t i = 0; i < m_numOfToy; i++)
		{
			if (m_toys[i] == &toy)
			{
				index = i;
			}
		}

		if (index != -1)
		{
			const Toy** temp = nullptr;

			temp = new const Toy * [m_numOfToy - 1];

			for (size_t i = 0, j = 0; i < m_numOfToy; i++)
			{
				if (i != index)
				{
					temp[j++] = m_toys[i];
				}
			}

			delete[] m_toys;

			m_toys = temp;
			m_numOfToy--;

		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationOrder& order)
	{
		return os;
	}
}