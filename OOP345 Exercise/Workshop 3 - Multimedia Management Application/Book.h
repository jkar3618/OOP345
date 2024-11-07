#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include <string>
#include "MediaItem.h"

namespace seneca
{
	class Book : public MediaItem
	{
		std::string m_author{};
		std::string m_country{};
		double m_price{};

		Book(const string& author, const string& title, const string& country, double price, unsigned short year, const string& summary);

	public:
		void display(std::ostream& out) const override;
		Book* createItem(const std::string& strBook);

	};

}

#endif

