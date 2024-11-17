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
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "book.h"
#include "settings.h"

using namespace std;

namespace seneca {

    // Constructor
    Book::Book(const std::string& author, const std::string& title, const std::string& country, unsigned short year, double price, const std::string& summary) : MediaItem(title, summary, year), m_author(author), m_country(country), m_price(price)
    {    }



    void Book::display(std::ostream& out) const
    {
        if (g_settings.m_tableView)
        {
            out << "B | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(2) << this->m_country << " | ";
            out << std::setw(4) << this->getYear() << " | ";
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
            out << this->getTitle() << " [" << this->getYear() << "] [";
            out << m_author << "] [" << m_country << "] [" << m_price << "]\n";
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

    // Create Book object dynamically
    Book* Book::createItem(const std::string& strBook)
    {
        if (strBook.empty() || strBook[0] == '#')
        {
            throw "Not a valid book.";
        }

        std::istringstream iss(strBook);
        std::string token;
        std::string tokens[6];
        size_t idx = 0;

        while (idx < 5 && std::getline(iss, token, ','))
        {
            MediaItem::trim(token);
            tokens[idx++] = token;
        }

        std::getline(iss, tokens[idx]);
        MediaItem::trim(tokens[idx]);
        idx++;

        if (idx != 6)
        {
            throw "Not a valid book.";
        }


        return new Book(tokens[0], tokens[1], tokens[2], static_cast<unsigned short>(std::stoi(tokens[4])), std::stod(tokens[3]), tokens[5]);
    }

}
