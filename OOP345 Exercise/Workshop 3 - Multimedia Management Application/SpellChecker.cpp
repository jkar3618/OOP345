#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;

namespace seneca
{
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream file(filename);

		if (!file)
		{
			throw "Bad file name!";
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

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		for (size_t i = 0; i < 6; i++)
		{
			out << right << setw(15) << m_badWord[i] << ": " << m_goodWord[i] << m_count[i] << " replacements" << endl;
		}
	}


}