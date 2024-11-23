#include <iostream>
#include <vector>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace seneca
{
	size_t Station::m_widthField{ 0 };
	size_t Station::id_generator{ 0 };

	Station::Station()
	{
	}

	Station::Station(const std::string& record)
	{
		id_generator++;
		Utilities util;
		bool more = true;
		size_t pos = 0u;
		std::vector<std::string> tokens;

		while (more)
		{
			if (tokens.size() == 3 && m_widthField < util.getFieldWidth())
			{
				m_widthField = util.getFieldWidth();
			}
			tokens.push_back(util.extractToken(record, pos, more));
		}

		m_id = id_generator;
		m_name = tokens[0];
		m_serial = std::stoi(tokens[1]);
		m_stock = std::stoi(tokens[2]);
		m_desc = tokens[3];

	}


	Station::~Station()
	{
	}

	const std::string& Station::getItemName() const
	{
		return m_name;
		// TODO: insert return statement here
	}

	size_t Station::getNextSerialNumber()
	{
		return m_serial++;
	}

	size_t Station::getQuantity() const
	{
		return m_stock;
	}

	void Station::updateQuantity()
	{
		if (m_stock > 0)
		{
			m_stock--;
		}
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << std::setfill('0') << std::setw(3) << m_id << " | " << std::left << std::setfill(' ') << std::setw(m_widthField) << m_name << " | " << std::right << std::setfill('0') << std::setw(6) << m_serial << " | ";

		if (full)
		{
			os << std::right << std::setfill(' ') << std::setw(4) << m_stock << " | " << m_desc;
		}
		os << std::endl;
	}
}