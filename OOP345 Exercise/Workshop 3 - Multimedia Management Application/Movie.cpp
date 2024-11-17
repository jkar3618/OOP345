//*****************************************************************************
//<assessment name : Workshop - #3>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "settings.h"
#include "movie.h"

using namespace std;

namespace seneca
{
	// Constructor
	Movie::Movie(const std::string& title, unsigned short year, const std::string& summary) : MediaItem(title, summary, year) {	}

	void Movie::display(std::ostream& out) const
	{
		if (g_settings.m_tableView)
		{
			out << "M | ";
			out << std::left << std::setfill('.');
			out << std::setw(50) << this->getTitle() << " | ";
			out << std::right << std::setfill(' ');
			out << std::setw(9) << this->getYear() << " | ";
			out << std::left;
			if (g_settings.m_maxSummaryWidth > -1)
			{
				if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth)
					out << this->getSummary();
				else
					out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
			}
			else
				out << this->getSummary();
			out << std::endl;
		}
		else
		{
			size_t pos = 0;
			out << this->getTitle() << " [" << this->getYear() << "]\n";
			out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
			while (pos < this->getSummary().size())
			{
				out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
				pos += g_settings.m_maxSummaryWidth;
			}
			out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
				<< std::setfill(' ') << '\n';
		}
	}

	// Create Movie object dynamically
	Movie* Movie::createItem(const std::string& strMovie)
	{
		if (strMovie.empty() || strMovie[0] == '#')
		{
			throw "Not a valid movie.";
		}

		std::istringstream iss(strMovie);
		std::string title, yearStr, summary;
		std::string token;
		std::string tokens[3];
		size_t idx = 0;

		while (idx < 2 && std::getline(iss, token, ','))
		{
			MediaItem::trim(token);
			tokens[idx++] = token;
		}

		std::getline(iss, tokens[idx]);
		MediaItem::trim(tokens[idx]);
		idx++;

		if (idx != 3)
		{
			throw "Not a valid movie.";
		}

		// title, year, summary
		return new Movie(tokens[0], std::stoi(tokens[1]), tokens[2]);
	}

}