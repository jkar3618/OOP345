#include <iostream>
#include <fstream>
#include "Filesystem.h"


using namespace std;

namespace seneca
{
	Filesystem::Filesystem(const std::string& name, const std::string& rootName)
	{
		ifstream file(name);

		if (!file)
		{
			throw "Error";
		}

		m_root = new Directory(rootName);
		m_current = m_root;

		auto trim = [&](std::string& str)
		{
			size_t start = str.find_first_not_of(" ");
			size_t end = str.find_last_not_of(" ");

			if (start != std::string::npos && end != std::string::npos)
			{
				str = str.substr(start, end - start + 1);
			}

			return str;
		};

		string line;

		while (std::getline(file, line))
		{
			size_t pos = line.find('|');
			string fPath;
			string cont;

			if (pos != std::string::npos)
			{
				fPath = line.substr(0, pos);
				cont = line.substr(pos + 1);
			}
			else
			{
				fPath = line;
			}

			fPath = trim(fPath);

			if (!cont.empty())
			{
				cont = trim(cont);
			}

			vector<string> comp;
			while (!fPath.empty())
			{
				size_t num = fPath.find('/');
				string token;

				if (num != std::string::npos)
				{
					token = fPath.substr(0, num + 1);
					fPath = fPath.substr(num);
				}
				else
				{
					token = fPath;

					fPath.clear();
				}

				token = trim(token);

				if (!token.empty())
				{
					comp.push_back(token);
				}
			}

			Directory* currentDir = m_root;

			for (auto itr = comp.begin(); itr != comp.end(); itr++)
			{
				if ((*itr).back() == '/')
				{
					Resource* res = currentDir->find(*itr);
					if (res == nullptr)
					{
						Directory* newDir = new Directory(*itr);
						*currentDir += newDir;
						currentDir = newDir;
					}
					else
					{
						currentDir = dynamic_cast<Directory*>(res);
					}
				}
				else
				{
					File* newFile = new File(*itr, cont);
					*currentDir += newFile;
				}

			}
		}

	}
}