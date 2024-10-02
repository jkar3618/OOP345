#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "toy.h"

using namespace std;

namespace seneca
{
	Toy::Toy(const std::string& toy)
	{
		ifstream file;

		if (file.is_open())
		{
			string temp;
			size_t count{ 0 };

			while (getline(file, temp))
			{
				count++;
			}
			
			file.clear();
			file.seekg(0);

			m_id = 0;
			m_qty = 0;
			m_price = 0.0;
			m_tax = 0.13;

			while (getline(file, temp))
			{
				stringstream ss(temp);

				string strID, strName, strNum, strPrice;

				getline(ss, strID, ':');
				getline(ss, strName, ':');
				getline(ss, strNum, ':');
				getline(ss, strPrice);

				m_id = std::stoi(strID);
				int first = strName.find_first_not_of(" ");
				int end = strName.find_last_not_of(" ");
				m_name = strName.substr(first, end);
				m_qty = std::stoi(strNum);
				m_price = std::stod(strPrice);
			}
		}

	}

	// Destructor
	Toy::~Toy()
	{
	}

	// Update number of items
	void Toy::update(int numItems)
	{
		m_qty = numItems;
	}

	//// Copy assignment
	//Toy& Toy::operator=(Toy& src)
	//{
	//	if (this != &src)
	//	{
	//		m_id = src.m_id;
	//		m_name = src.m_name;
	//		m_qty = src.m_qty;
	//		m_price = src.m_price;
	//		m_tax = src.m_tax;
	//	}

	//	return *this;
	//}

	std::ostream& operator<<(std::ostream& os, const Toy& src)
	{
		double subTotal = src.m_price * src.m_qty;
		double tax = subTotal * src.m_tax;
		double total = subTotal + tax;

		os << "Toy " << src.m_id << ":" << src.m_name << " " << src.m_qty << " items @ " << src.m_price << "/item subtotal: " << subTotal << " tax: " << tax << " total: " << total << endl;


		return os;
	}
}

