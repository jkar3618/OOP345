#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H

#include <string>
#include <vector>
#include <list>
#include "MediaItem.h"
#include "Settings.h"

namespace seneca {
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

    class TvShow : public MediaItem {
        unsigned int m_id;
        std::vector<TvEpisode> m_episodes;

        TvShow(unsigned int id, const std::string& title, unsigned short year, const std::string& summary);

    public:
        void display(std::ostream& out) const override;
        TvShow* createItem(const std::string& strShow);
        
        template<typename Collection_t> 
        void addEpisode(Collection_t& col, const std::string& strEpisode);

        double getEpisodeAverageLength() const;
        std::list<std::string> getLongEpisodes() const;
    };
    template<typename Collection_t>
    inline void TvShow::addEpisode(Collection_t& col, const std::string& strEpisode)
    {
    }
}
#endif

