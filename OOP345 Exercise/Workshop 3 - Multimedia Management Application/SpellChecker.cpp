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
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "spellChecker.h"

using namespace std;

namespace seneca
{
	// Constructor
	SpellChecker::SpellChecker(const char* filename) 
	{
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}

		std::string line;
		int index = 0;
		while (std::getline(file, line) && index < SIZE) {
			std::istringstream iss(line);
			std::string badWord, goodWord;
			iss >> badWord >> goodWord; // Read the bad and good words
			m_badWord[index] = badWord;
			m_goodWord[index] = goodWord;
			index++;
		}
	}


	// Replace bad word with the good word
	void SpellChecker::operator()(std::string& text)
	{
		for (auto i = 0; i < 6; i++)
		{
			size_t idx = 0;

			while ((idx = text.find(m_badWord[i], idx)) != std::string::npos)
			{
				text.replace(idx, m_badWord[i].length(), m_goodWord[i]);

				idx += m_goodWord[i].length();
				m_count[i]++;
			}
		}
	}

	// Display the statistics
	void SpellChecker::showStatistics(std::ostream& out) const 
	{

		out << "Spellchecker Statistics" << std::endl;

		for (int i = 0; i < SIZE; ++i) {
			out << std::left << std::setw(15) << m_badWord[i] << ": " << m_count[i] << " replacements" << std::endl;
		}
	}




}