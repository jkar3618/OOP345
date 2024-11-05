#include <iostream>
#include <fstream>
#include "SongCollection.h"

using namespace std;

namespace seneca
{
	SongCollection::SongCollection(const std::string fname)
	{
	}

	void SongCollection::display(std::ostream& out) const
	{
	}
	
	void SongCollection::sort(std::string src)
	{
	}
	
	void SongCollection::cleanAlbum()
	{
	}
	
	bool SongCollection::inCollection(const std::string src) const
	{
		return false;
	}
	
	std::list<Song> SongCollection::getSongsForArtist(const std::string src) const
	{
		return std::list<Song>();
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		// TODO: insert return statement here
	}
}