#ifndef SENECA_SHOPPINGCART_H
#define SENECA_SHOPPINGCART_H
#include <string>
#include "toy.h"

namespace seneca
{
	class ShoppingCart
	{
		std::string m_name{};
		int m_age{};
		const Toy** m_toy{ nullptr };
		int m_numOfToys{};

	public:
		ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count);

		ShoppingCart(const ShoppingCart& cart);
		ShoppingCart(ShoppingCart&& cart) noexcept;
		~ShoppingCart();

		ShoppingCart& operator=(const ShoppingCart& cart);
		ShoppingCart& operator=(ShoppingCart&& cart) noexcept;

		friend std::ostream& operator<<(std::ostream& os, const ShoppingCart& cart);

	};

}
#endif


