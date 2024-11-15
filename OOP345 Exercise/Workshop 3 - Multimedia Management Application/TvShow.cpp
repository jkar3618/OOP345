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

    TvShow* TvShow::createItem(const std::string& strShow)
    {
        // Check for comment line or empty string
        if (strShow[0] == '#' || strShow.empty())
            throw "Not a valid show.";

        std::string tokens[4]{};
        std::stringstream ss(strShow);
        std::string token;
        size_t idx{ 0 };

        // Read tokens from the string
        while (std::getline(ss, token, ',') && idx < 4)
        {
            MediaItem::trim(token); // Remove spaces from token
            tokens[idx++] = token;
        }

        TvShow* temp = new TvShow(tokens[0], tokens[1], static_cast<unsigned short>(std::stoi(tokens[2])), tokens[3]);

        // Create and return TvShow object
        return temp;
    }


    double TvShow::getEpisodeAverageLength() const
    {
        return std::accumulate(m_episodes.begin(), m_episodes.end(), (double)0,
            [&](double total, const TvEpisode& ep)
            {
                return total + ep.m_length;
            }) / m_episodes.size();

    }

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