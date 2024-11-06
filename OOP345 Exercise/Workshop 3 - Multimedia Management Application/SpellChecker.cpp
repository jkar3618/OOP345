#include <iostream>
#include <fstream>
#include "SpellChecker.h"

using namespace std;

namespace seneca
{
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream file(filename);

		if (!file)
		{
			throw "Error";
		}

		string line{};
		size_t idx{ 0 };

		while (std::getline(file, line))
		{
			m_badWord[idx] = line.substr(0, line.find_last_not_of(' '));

			m_goodWord[idx] = line.substr(line.find_first_of(' ') + 1);
			idx++;
		}
	}


}