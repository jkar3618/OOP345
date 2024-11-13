#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H

#include <sstream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include "mediaItem.h"
#include "collection.h"

namespace seneca
{
    class TvShow;

    struct TvEpisode
    {
        const TvShow* m_show{};
        unsigned short m_numberOverall{};
        unsigned short m_season{};
        unsigned short m_numberInSeason{};
        std::string m_airDate{};
        unsigned int m_length{};
        std::string m_title{};
        std::string m_summary{};
    };

    class TvShow : public MediaItem
    {
        std::string m_id;
        std::vector<TvEpisode> m_episodes;

        TvShow(const std::string& id, const std::string& title, unsigned short year, const std::string& summary);

    public:
        static TvShow* createItem(const std::string& strShow);

        template<typename Collection_t>
        static void addEpisode(Collection_t& col, const std::string& strEpisode);
        void display(std::ostream& out) const override;
        double getEpisodeAverageLength() const;
        std::list<std::string> getLongEpisodes() const;
    };

    template<typename Collection_t>
    static void TvShow::addEpisode(Collection_t& col, const std::string& strEpisode)
    {
        if (strEpisode.empty() || strEpisode[0] == '#')
        {
            throw "Not a valid episode.";
        }

        std::istringstream stream(strEpisode);
        std::string id;
        std::string token;
        std::string tokens[8];
        size_t idx = 0;
        TvShow* show = nullptr;

        while (std::getline(stream, token, ',') && idx < 8)
        {
            MediaItem::trim(token);
            tokens[idx++] = token;
        }

        if (idx != 8)
        {
            throw "Not a valid episode.";
        }

        id = tokens[0];
        for (size_t i = 0; i < col.size() && show == nullptr; i++)
        {
            show = dynamic_cast<TvShow*>(col[i]);
            if (show->m_id != id)
            {
                show = nullptr;
            }
        }

        //# Show ID, Episode Number Overall, Season Number, Episode Number in Season, First Air Date, Length, Episode Title, Episode Summary
        if (show)
        {
            TvEpisode episode = { show, std::stoi(tokens[1])
                , tokens[2].empty() ? 1 : std::stoi(tokens[2])
                , std::stoi(tokens[3]), tokens[4] ,std::stoi(tokens[5])
                , tokens[6], tokens[7] };
            show->m_episodes.push_back(episode);
        }

    };

} // namespace seneca

#endif
