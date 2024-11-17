//*****************************************************************************
//<assessment name : Workshop - #3>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <string>
#include "mediaItem.h"

namespace seneca
{
	class Movie : public MediaItem
	{
		Movie(const std::string& title, unsigned short year, const std::string& summary);

	public:
		void display(std::ostream& out) const override;
		static Movie* createItem(const std::string& strMovie);
	};

}

#endif

