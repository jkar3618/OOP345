#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <string>
#include "mediaItem.h"

namespace seneca
{
	class Movie : public MediaItem
	{
		Movie(const std::string& title, const std::string& summary, unsigned short year);

	public:
		void display(std::ostream& out) const override;
		static Movie* createItem(const std::string& strMovie);
	};

}

#endif

