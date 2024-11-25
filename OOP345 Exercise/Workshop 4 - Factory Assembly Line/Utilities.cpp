#include <iostream>
#include <sstream>
#include <algorithm>
#include "Utilities.h"

namespace seneca
{
	char Utilities::m_delimiter{};

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

		size_t find = str.find(m_delimiter, next_pos);

		if (find == next_pos)
		{
			more = false;
			throw "No token until delimiter";
		}

		std::string token = str.substr(next_pos, find - next_pos);
		next_pos = find + 1;

		//size_t length = str.length();
		if (find == std::string::npos)
		{
			more = false;
		}
		else 
		{
			if (!token.empty())	more = true;
		}

		token.erase(0, token.find_first_not_of(' '));
		token.erase(token.find_last_not_of(' ') + 1);

		m_widthField = (m_widthField < token.size()) ? token.size() : m_widthField;

		return token;
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