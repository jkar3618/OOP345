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
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <string>
#include <list>
#include "tvShow.h"
#include "settings.h"


using namespace std;

namespace seneca
{
    // Constructor
    TvShow::TvShow(const std::string& id, const std::string& title, unsigned short year, const std::string& summary) : MediaItem(title, summary, year), m_id(id) {}

    void TvShow::display(std::ostream& out) const
    {
        if (g_settings.m_tableView)
        {
            out << "S | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(2) << this->m_episodes.size() << " | ";
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
            out << this->getTitle() << " [" << this->getYear() << "]\n";
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
            while (pos < this->getSummary().size())
            {
                out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                pos += g_settings.m_maxSummaryWidth;
            }
            for (auto& item : m_episodes)
            {
                out << std::setfill('0') << std::right;
                out << "    " << 'S' << std::setw(2) << item.m_season
                    << 'E' << std::setw(2) << item.m_numberInSeason << ' ';
                if (item.m_title != "")
                    out << item.m_title << '\n';
                else
                    out << "Episode " << item.m_numberOverall << '\n';

                pos = 0;
                while (pos < item.m_summary.size())
                {
                    out << "            " << item.m_summary.substr(pos, g_settings.m_maxSummaryWidth - 8) << '\n';
                    pos += g_settings.m_maxSummaryWidth - 8;
                }
            }
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
                << std::setfill(' ') << '\n';
        }
    }

    // Create new TvShow object dynamically
    TvShow* TvShow::createItem(const std::string& strShow)
    {
        if (strShow.empty() || strShow[0] == '#')
        {
            throw "Not a valid show.";
        }

        std::istringstream iss(strShow);
        std::string token;
        std::string tokens[4];
        size_t idx = 0;

        while (idx < 3 && std::getline(iss, token, ','))
        {
            MediaItem::trim(token);
            tokens[idx++] = token;
        }

        std::getline(iss, tokens[idx]);
        MediaItem::trim(tokens[idx]);
        idx++;

        if (idx != 4)
        {
            throw "Not a valid show.";
        }

        // id, title, year, summary
        return new TvShow(tokens[0], tokens[1], std::stoi(tokens[2]), tokens[3]);
    }



    // Return average length of episodes
    double TvShow::getEpisodeAverageLength() const
    {
        return std::accumulate(m_episodes.begin(), m_episodes.end(), (double)0,
            [&](double total, const TvEpisode& ep)
            {
                return total + ep.m_length;
            }) / m_episodes.size();

    }



    // Return list of titles of episodes
    std::list<std::string> TvShow::getLongEpisodes() const
    {
        std::list<std::string> longEpisode;

        std::for_each(m_episodes.begin(), m_episodes.end(), [&](const TvEpisode& episode)
            {
                if (episode.m_length >= 3600)
                {
                    longEpisode.push_back(episode.m_title);
                }
            });
        return longEpisode;
    }


}