#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H

#include <string>
#include <vector>
#include <list>

namespace seneca
{
	struct Song
	{
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price{};
		int m_year{};
		size_t m_length{};
	};

	class SongCollection
	{
		std::vector<Song> m_song;
		size_t m_total{ 0 };

	public:
		SongCollection(const std::string& fname);
		void display(std::ostream& out) const;
		void sort(std::string src);
		void cleanAlbum();
		bool inCollection(const std::string src) const;
		std::list<Song> getSongsForArtist(const std::string& src) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}
#endif // !SONGCOLLECTION_H




