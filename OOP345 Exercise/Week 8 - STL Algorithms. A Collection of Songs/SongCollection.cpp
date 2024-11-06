#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <iterator>
#include <numeric>

#include "SongCollection.h"

using namespace std;

namespace seneca
{
	SongCollection::SongCollection(const std::string& fname)
	{
		ifstream file(fname);

		std::vector<std::string> tokens{};

		std::string line;
		std::string title;
		std::string art;
		std::string album;
		std::string year;
		std::string len;
		std::string price;

		if (!file)
		{
			throw "Error";
		}

		while (getline(file, line))
		{

			size_t position{ 0 };
			size_t size{ 25 };

			for (size_t i = 0; i < 6; i++)
			{
				if (i == 3)
				{
					size = 5;
				}
				tokens.push_back(line.substr(position, size));
				position += size;

				tokens[i].erase(0, tokens[i].find_first_not_of(" "));
				tokens[i].erase(tokens[i].find_last_not_of(" ") + 1);
			}

			Song song = { tokens[0],tokens[1],tokens[2]
				,tokens[3].empty() ? 0 : std::stoi(tokens[3])
				,tokens[4].empty() ? 0 : std::stoi(tokens[4])
				,tokens[5].empty() ? 0.0 : std::stod(tokens[5])
			};

			m_song.push_back(song);
			tokens.clear();
		}
	}

	void SongCollection::display(std::ostream& out) const
	{
		int total{ 0 };
		total = std::accumulate(m_song.begin(), m_song.end(), (int)0, [](int tot, const Song& song)
			{
				return tot + song.m_length;
			});

		std::for_each(m_song.begin(), m_song.end(), [&out](const Song& song) {
			out << song << std::endl;
			});
	}

	void SongCollection::sort(std::string src)
	{
		auto compare = [src](Song& origin, Song& other)
		{
			bool result = false;
			if (src == "title")
			{
				result = origin.m_title < other.m_title;
			}
			else if (src == "album")
			{
				result = origin.m_album < other.m_album;
			}
			else if (src == "length")
			{
				result = origin.m_length < other.m_length;
			}
			else
			{
				result = false;
			}
			return result;
		};

		std::sort(m_song.begin(), m_song.end(), compare);

	}

	void SongCollection::cleanAlbum()
	{

		std::transform(m_song.begin(), m_song.end(), m_song.begin(), [](const Song& song)
			{
				Song emp = song;
				if (song.m_album == "[None]")
				{
					emp.m_album = "";
				}

				return emp;
			});

		//std::for_each(m_song.begin(), m_song.end(), [](Song& current) {current.m_album = current.m_album == "[None]" ? "" : current.m_album; });
	}

	bool SongCollection::inCollection(const std::string src) const
	{
		return std::any_of(m_song.begin(), m_song.end(), [src](const Song& origin) {return origin.m_artist == src; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string src) const
	{
		std::list<Song> list;

		std::copy_if(m_song.begin(), m_song.end(), std::back_inserter(list), [src](const Song& song)
			{
				return song.m_artist == src;
			});

		return list;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << setw(20) << theSong.m_title << "|" << setw(15) << theSong.m_title << "|" << setw(20) << theSong.m_album << "|"
			<< setw(6) << theSong.m_year << "|" << theSong.m_length << "|" << theSong.m_price;

		return out;
	}
}