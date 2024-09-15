//FoodOrder.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "FoodOrder.h"

using namespace std;

double g_taxrate = 0;
double g_dailydiscount = 0;

namespace seneca
{
	FoodOrder::FoodOrder() : f_price(0), f_special(false)
	{
		f_name[0] = '\0';
		f_desc[0] = '\0';
	}

	FoodOrder::FoodOrder(const FoodOrder& src)
	{
		strcpy(f_name, src.f_name);
		strcpy(f_desc, src.f_desc);
		f_price = src.f_price;
		f_special = src.f_special;
	}

	FoodOrder::~FoodOrder()
	{

	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& src)
	{
		if (this != &src)
		{
			strcpy(f_name, src.f_name);
			strcpy(f_desc, src.f_desc);
			f_price = src.f_price;
			f_special = src.f_special;
		}

		return *this;
	}



	std::istream& FoodOrder::read(std::istream& is)
	{
		// TODO: insert return statement here
		if (is)
		{
			char daily;

			f_special = false;
			is.getline(f_name, 10, ',');
			is.getline(f_desc, 25, ',');
			is >> f_price;
			is.ignore();
			is.get(daily);
			is.ignore(1000, '\n');

			if (daily == 'Y')
			{
				f_special = true;
			}

		}
		// TODO: insert return statement here
		return is;
	}

	void FoodOrder::display() const
	{
		static int COUNTER = 1;

		cout.fill(' ');
		cout.width(2);
		cout << COUNTER++ << ". ";

		cout.fill(' ');
		cout.width(10); // f_name의 너비 조정
		cout << f_name << " | ";

		cout.fill(' ');
		cout.width(25); // f_desc의 너비 조정
		cout << f_desc << " | ";

		cout.fill(' ');
		cout.width(12);
		cout << fixed << setprecision(2) << (f_price * (1 + g_taxrate)) << " | ";

		if (f_special)
		{
			cout.fill(' ');
			cout.width(12);
			cout << fixed << setprecision(2) << (f_price * (1 + g_taxrate) * (1 - g_dailydiscount)); // 할인 적용
		}

		cout << endl;
	}

	FoodOrder::operator bool() const
	{
		return f_special == 'N';
	}
	std::istream& operator>>(std::istream& is, FoodOrder& order)
	{
		return order.read(is);
	}
	void operator>>(const FoodOrder& order1, FoodOrder& order2)
	{
		order2 = order1;
	}
}