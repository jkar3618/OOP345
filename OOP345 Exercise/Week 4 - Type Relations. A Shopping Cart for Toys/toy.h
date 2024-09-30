#ifndef SENECA_TOY_H
#define SENECA_TOY_H
#include <iostream>
#include <string>

namespace seneca
{
	class Toy
	{
		unsigned int m_id{};
		std::string name{};
		unsigned int numOfItems{};
		double price{};
		double tax{ 0.13 };

	public:
		Toy() {};
		Toy(const std::string& toy);
		~Toy();

		void update(int numItems);

		Toy& operator=(Toy& src);
		friend std::ostream& operator<<(std::ostream& os, const Toy& src);

	};
}

#endif

