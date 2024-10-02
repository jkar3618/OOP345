#ifndef SENECA_TOY_H
#define SENECA_TOY_H
#include <iostream>
#include <string>

namespace seneca
{
	class Toy
	{
		unsigned int m_id{ 0 };
		std::string* m_name{ nullptr };
		unsigned int m_qty{ 0 };
		double m_price{ 0.0 };
		double m_tax{ 0.13 };

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

