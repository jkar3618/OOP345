#include <iostream>
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

namespace seneca
{
	size_t CustomerOrder::m_widthField{};

	CustomerOrder::CustomerOrder(const std::string& record)
	{
		Utilities util;
		bool more = true;
		size_t pos = 0u;
		std::vector<std::string> tokens;

		while (more)
		{
			tokens.push_back(util.extractToken(record, pos, more));
		}

		if (m_widthField < util.getFieldWidth())
		{
			m_widthField = util.getFieldWidth();
		}

		m_name = tokens[0];
		m_product = tokens[1];

		if (tokens.size() > 2)
		{
			m_cntItem = tokens.size() - 2;
			m_lstItem = new Item * [m_cntItem];

			for (size_t i = 0; i < m_cntItem; i++)
			{
				m_lstItem[i] = new Item(tokens[i + 2]);
			}
		}
		else
		{
			m_cntItem = 0;
			m_lstItem = nullptr;
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw "Error";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;

			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0u;
			src.m_lstItem = nullptr;
		}

		return *this;

	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool result = true;

		for (size_t i = 0; i < m_cntItem && result; i++)
		{
			if (m_lstItem[i]->m_isFilled == false) 
			{
				result = false;
			}
		}

		return result;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool result = true;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName) 
			{
				if (!m_lstItem[i]->m_isFilled)
				{
					result = false;
				}
			}
		}

		return result;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool done = false;

		for (size_t i = 0; i < m_cntItem && !done; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled)
			{
				if (station.getQuantity())
				{
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std:: endl;
				}
				else
				{
					os << "    Unable to Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
				}
				done = true;
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] " << std::left << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}
}