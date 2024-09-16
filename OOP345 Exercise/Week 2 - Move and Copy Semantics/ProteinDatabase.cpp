#include <iostream>
#include <fstream>
#include <string>
#include "ProteinDatabase.h"

using namespace std;

namespace seneca
{

	// default constructor
	ProteinDatabase::ProteinDatabase() : p_id{ nullptr }, p_sequence{ nullptr }, p_numProtein(0) {}

	// 1 argument constructor
	ProteinDatabase::ProteinDatabase(const std::string& fname) : p_id{ nullptr }, p_sequence { nullptr }, p_numProtein(0u)
	{
		std::ifstream file(fname);

		if (file.is_open())
		{
			string temp;

			// read the file and count number of protein
			while (getline(file, temp))
			{
				if (temp[0] == '>')
				{
					p_numProtein++;
				}
			}
			
			// allocate memory
			p_id = new std::string[p_numProtein];
			p_sequence = new std::string[p_numProtein];


			// read the file and load the protein sequences
			file.clear();
			file.seekg(0);
			size_t index = 0;
			std::string sequence;

			while (getline(file, temp)) {
				if (temp[0] == '>') {
					if (index > 0)
					{
						p_sequence[index - 1] = sequence;
						sequence.clear();
					}
					// get id
					size_t start = temp.find('|') + 1;
					size_t end = temp.find('|', start);
					p_id[index] = temp.substr(start, end - start);
					index++;
				}
				else
				{
					sequence += temp;
				}
			}
			if (!sequence.empty())
			{
				p_sequence[index - 1] = sequence;
			}

		}
	}

	/*ProteinDatabase::ProteinDatabase(const char* fname) : p_numProtein(0)
	{
		std::ifstream file(fname);

		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				if (line[0] == '>')
				{
					p_numProtein++;
				}
			}

			p_id = new std::string[p_numProtein];
			p_sequence = new std::string[p_numProtein];

			file.clear();
			file.seekg(0, std::ios::beg);

			size_t index = 0;
			std::string sequence;

			while (getline(file, line))
			{
				if (line[0] == '>')
				{
					size_t start = line.find('|') + 1;
					size_t end = line.find('|', start);
					p_id[index] = line.substr(start, end - start);

					if (!sequence.empty() && index > 0)
					{
						p_sequence[index - 1] = sequence;
					}

					sequence.clear();

					index++;
				}
				else
				{
					sequence += line;
				}

			}
			file.close();
		}
	}*/



	// copy constructor
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) : p_numProtein(src.p_numProtein)
	{
		//// allocate memory
		//p_id = new std::string[p_numProtein];
		//p_sequence = new std::string[p_numProtein];

		//// loop for copy
		//for (int i = 0; i < p_numProtein; i++)
		//{
		//	p_id[i] = src.p_id[i];
		//	p_sequence[i] = src.p_sequence[i];
		//}

		*this = src;
	}

	// copy operator
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
	{
		if (this != &src)
		{
			delete[] p_id; // deallocate memory
			p_id = nullptr; // safe empty state

			delete[] p_sequence; // deallocate memory
			p_sequence = nullptr; // safe empty state

			p_numProtein = src.p_numProtein;

			if (p_numProtein > 0)
			{
				// deep copy
				p_id = new string[p_numProtein];
				p_sequence = new string[p_numProtein];
				
				for (int i = 0; i < p_numProtein; i++)
				{
					p_id[i] = src.p_id[i];
					p_sequence[i] = src.p_sequence[i];
				}
			}
		}

		return *this;
	}

	// move constructor
	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) noexcept
	{
		*this = std::move(src);
	}

	// move operator
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src) noexcept
	{
		if (this != &src)
		{
			delete[] p_id; 
			delete[] p_sequence; 
			
			p_id = nullptr; 
			p_sequence = nullptr; 

			p_id = src.p_id;
			p_sequence = src.p_sequence;
			p_numProtein = src.p_numProtein;

			src.p_id = nullptr;
			src.p_sequence = nullptr;
			src.p_numProtein = 0;
		}

		return *this;

	}

	// destructor
	ProteinDatabase::~ProteinDatabase()
	{
		delete[] p_id;
		delete[] p_sequence;

	}

	size_t ProteinDatabase::size() const
	{
		return p_numProtein;
	}

	std::string ProteinDatabase::operator[](size_t index) const
	{

		return index < p_numProtein ? p_sequence[index] : ""; // return sequence
	}

	std::string ProteinDatabase::getUID(size_t index) const
	{

		return index < p_numProtein ? p_id[index] : "None"; // return "None" if the index is invalid
	}
}

