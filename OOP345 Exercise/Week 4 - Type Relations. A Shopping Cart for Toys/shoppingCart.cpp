#include <iostream>
#include "shoppingCart.h"
using namespace std;

namespace seneca
{
	ShoppingCart::ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count)
	{
	}

	ShoppingCart::ShoppingCart(const ShoppingCart& cart)
	{
	}

	ShoppingCart::ShoppingCart(ShoppingCart&& cart) noexcept
	{
	}

	ShoppingCart::~ShoppingCart()
	{
	}

	ShoppingCart& ShoppingCart::operator=(const ShoppingCart& cart)
	{
		return *this;
	}

	ShoppingCart& ShoppingCart::operator=(ShoppingCart&& cart) noexcept
	{
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ShoppingCart& cart)
	{
		return os;
	}
}