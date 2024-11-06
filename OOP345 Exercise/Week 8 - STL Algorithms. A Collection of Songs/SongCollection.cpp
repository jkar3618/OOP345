#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <iterator>
#include "SongCollection.h"

using namespace std;

namespace seneca
{
	SongCollection::SongCollection(const std::string& fname)
	{
		ifstream file(fname);

		Song song;


		if (!file)
		{
			throw "Error";
		}


	}

	void SongCollection::display(std::ostream& out) const
	{
	}
	
	void SongCollection::sort(std::string src)
	{
		if (src == "title")
		{
			std::sort(m_song.begin(), m_song.end(), [](Song& origin, Song& other) {return origin.m_title < other.m_title; });
		}
		else if (src == "album")
		{
			std::sort(m_song.begin(), m_song.end(), [](Song& origin, Song& other) {return origin.m_album < other.m_album; });
		}
		else if (src == "length")
		{
			std::sort(m_song.begin(), m_song.end(), [](Song& origin, Song& other) {return origin.m_length < other.m_length; });
		}
		else
		{
			cout << "Error" << endl;
		}
	}
	
	void SongCollection::cleanAlbum()
	{
		std::for_each(m_song.begin(), m_song.end(), [](Song& current) {current.m_album = current.m_album == "[None]" ? "" : current.m_album; });
	}
	
	bool SongCollection::inCollection(const std::string src) const
	{
		return false;
	}
	
	std::list<Song> SongCollection::getSongsForArtist(const std::string& src) const
	{
		return std::list<Song>();
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		// TODO: insert return statement here
	}
}