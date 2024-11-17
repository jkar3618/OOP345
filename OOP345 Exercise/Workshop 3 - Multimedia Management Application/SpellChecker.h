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

#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#define SIZE 6
#include <iostream>
#include <string>

namespace seneca {
	class SpellChecker {
		std::string m_badWord[SIZE];
		std::string m_goodWord[SIZE];
		int m_count[SIZE]{ 0 };

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif

