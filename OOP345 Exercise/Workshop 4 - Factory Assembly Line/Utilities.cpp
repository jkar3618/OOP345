#include <iostream>
#include <sstream>
#include <algorithm>
#include "Utilities.h"

namespace seneca
{
	char Utilities::m_delimiter = ',';

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		if (next_pos >= str.length())
		{
			more = false;
		}

		size_t delimiter = str.find(m_delimiter, next_pos);

		if (delimiter == next_pos)
		{
			more = false;
			throw "No token until delimiter";
		}

		std::string token;


		return std::string();
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}