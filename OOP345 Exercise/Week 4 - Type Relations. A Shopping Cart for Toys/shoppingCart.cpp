#include <iostream>
#include "shoppingCart.h"
using namespace std;

namespace seneca
{
	ShoppingCart::ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count)
	{
		m_name = name;
		m_age = age;
		m_numOfToys = count;

		m_toy = new const Toy * [count];
		for (size_t i = 0; i < count; i++)
		{
			m_toy[i] = new const Toy(*toys[i]);
		}
	}

	ShoppingCart::ShoppingCart(const ShoppingCart& cart)
	{
		*this = cart;
	}

	ShoppingCart::ShoppingCart(ShoppingCart&& cart) noexcept
	{
		*this = std::move(cart);
	}

	ShoppingCart::~ShoppingCart()
	{
		for (size_t i = 0; i < m_numOfToys; i++)
		{
			delete m_toy[i];
		}

		delete[] m_toy;
	}

	ShoppingCart& ShoppingCart::operator=(const ShoppingCart& cart)
	{
		if (this != &cart)
		{
			for (size_t i = 0; i < m_numOfToys; i++)
			{
				delete m_toy[i];
			}

			delete[] m_toy;
		}

		m_name = cart.m_name;
		m_age = cart.m_age;
		m_numOfToys = cart.m_numOfToys;
		m_toy = new const Toy * [m_numOfToys];

		for (size_t i = 0; i < cart.m_numOfToys; i++)
		{
			m_toy[i] = new const Toy(*cart.m_toy[i]);
		}

		return *this;
	}

	ShoppingCart& ShoppingCart::operator=(ShoppingCart&& cart) noexcept
	{
		if (this != &cart)
		{
			for (size_t i = 0; i < m_numOfToys; i++)
			{
				delete m_toy[i];
			}

			delete[] m_toy;
		}

		m_name = cart.m_name;
		m_age = cart.m_age;
		m_numOfToys = cart.m_numOfToys;
		m_toy = cart.m_toy;

		cart.m_name = "";
		cart.m_age = 0;
		cart.m_numOfToys = 0;
		cart.m_toy = nullptr;

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ShoppingCart& cart)
	{
		return os;
	}
}