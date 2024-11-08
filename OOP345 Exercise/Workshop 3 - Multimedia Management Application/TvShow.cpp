#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "TvShow.h"

using namespace std;

namespace seneca
{
    TvShow::TvShow(unsigned int id, const std::string& title, unsigned short year, const std::string& summary) : MediaItem(title, summary, year), m_id(id) {}

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
        std::string tokens[4]{};

        if (strShow[0] == '#' || strShow.empty())
        {
            throw "Not a valid book.";
        }

        std::stringstream ss(strShow);
        std::string empty;
        size_t idx{ 0 };

        while (std::getline(ss, tokens[idx++], ','))
        {
            MediaItem::trim(tokens[idx]);
        };

        TvShow* temp = new TvShow{tokens[0], tokens[1], tokens[2], std::stoi(tokens[3])};

		return temp;
	}

	double TvShow::getEpisodeAverageLength() const
	{
        double totalLen{0.0};

        return std::accumulate(m_episodes.begin(), m_episodes.end(), (int)0, [&](double total, const TvEpisode& ep) 
            {
                return totalLen + ep.m_length;
            });
	}

	std::list<std::string> TvShow::getLongEpisodes() const
	{
        std::list<std::string> longEpisode;

        std::copy_if(m_episodes.begin(), m_episodes.end(), std::back_inserter(longEpisode), [](const TvEpisode& ep)
            {
                return ep.m_length >= 3600;
            });

		return longEpisode;
	}
}