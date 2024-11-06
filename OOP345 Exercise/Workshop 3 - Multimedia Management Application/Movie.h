#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

namespace seneca
{
	class Movie : public MediaItem
	{
		Movie();

	public:
		void display(std::ostream& out) const override;
		static Movie* createItem(const std::string& strMovie);
	};

}

#endif

