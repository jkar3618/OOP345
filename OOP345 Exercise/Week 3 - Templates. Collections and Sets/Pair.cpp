#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace seneca
{

	bool Pair::operator==(const Pair& pair) const
	{
		return m_key == pair.m_key;
	}



	std::ostream& operator<<(std::ostream& os, Pair& p)
	{
		os << std::right << std::setw(20) << p.getKey() << ": " << p.getValue();

		return os;
	}



}

