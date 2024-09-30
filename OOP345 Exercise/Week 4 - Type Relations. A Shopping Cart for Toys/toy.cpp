#include <iostream>
#include "toy.h"

using namespace std;

namespace seneca
{
	Toy::Toy(const std::string& toy)
	{
	}

	Toy::~Toy()
	{
	}

	void Toy::update(int numItems)
	{
	}

	Toy& Toy::operator=(Toy& src)
	{
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Toy& src)
	{
		return os;
	}
}

