#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "settings.h"
#include "dictionary.h"

using namespace std;

namespace seneca
{
	Dictionary::Dictionary() : m_words(nullptr), m_size(0)
	{
	}


	Dictionary::Dictionary(const char* filename) : m_words(nullptr), m_size(0)
	{
		ifstream file(filename);

		if (file.is_open())
		{
			string temp;
			size_t count{ 0 };

			while (getline(file, temp))
			{
				count++;
			}

			file.clear();
			file.seekg(0);

			m_words = new Word[count];
			m_size = 0;

			while (getline(file, temp))
			{
				stringstream ss(temp);

				string strWord, strDef, strPos;

				getline(ss, strWord, ',');
				getline(ss, strPos, ',');
				getline(ss, strDef);

				m_words[m_size].word = strWord;
				m_words[m_size].definition = strDef;

				m_words[m_size].pos = parsePos(strPos);

				m_size++;


			}
		}
	}

	Dictionary::Dictionary(const Dictionary& src)
	{
		m_size = src.m_size;

		if (m_size > 0) {
			m_words = new Word[m_size];
			for (size_t i = 0; i < m_size; ++i) {
				m_words[i] = src.m_words[i];
			}
		}
		else {
			m_words = nullptr;
		}
	}
	Dictionary& Dictionary::operator=(const Dictionary& src)
	{
		if (this != &src)
		{
			if (m_words != nullptr)
			{
				delete[] m_words;
			}

			m_size = src.m_size;

			if (m_size > 0)
			{
				m_words = new Word[m_size];
				for (size_t i = 0; i < m_size; i++)
				{
					m_words[i] = src.m_words[i];
				}
			}
			else
			{
				m_words = nullptr;
			}
		}

		return *this;
	}

	Dictionary::Dictionary(Dictionary&& src) noexcept : m_words{ src.m_words }, m_size{ src.m_size }
	{
		src.m_words = nullptr;
		src.m_size = 0;
	}

	Dictionary& Dictionary::operator=(Dictionary&& src) noexcept
	{
		if (this != &src)
		{
			delete[] m_words;

			m_size = src.m_size;
			m_words = src.m_words;

			src.m_words = nullptr;
			src.m_size = 0;
		}

		return *this;
	}

	Dictionary::~Dictionary()
	{
		delete[] m_words;
		m_words = nullptr;
	}

	void Dictionary::searchWord(const char* word)
	{
		bool searched = false;
		size_t len = strlen(word);
		bool done = true;

		for (size_t i = 0; i < m_size && done; i++)
		{
			if (m_words[i].word == word) {
				if (!searched)
				{
					cout << m_words[i].word;
				}
				else
				{
					cout << setw(len + 3);

				}

				cout << " - ";

				if (g_settings.m_verbose && m_words[i].pos != PartOfSpeech::Unknown)
				{
					cout << "(";
					if (m_words[i].pos == PartOfSpeech::Noun)
					{
						cout << "noun";
					}
					else if (m_words[i].pos == PartOfSpeech::Verb)
					{
						cout << "verb";
					}
					else if (m_words[i].pos == PartOfSpeech::Adjective)
					{
						cout << "adjective";
					}

					cout << ") ";
				}

				cout << m_words[i].definition << endl;
				searched = true;
				if (!g_settings.m_show_all)
				{
					done = false;
				}


			}

		}
				if(!searched)
				{
					cout << "Word '" << word << "' was not found in the dictionary." << endl;
				}
	}
	PartOfSpeech Dictionary::parsePos(const string& strPos)
	{
		PartOfSpeech pos = PartOfSpeech::Unknown;

		if (strPos == "n." || strPos == "n.pl.")
		{
			pos = PartOfSpeech::Noun;
		}
		else if (strPos == "adv.")
		{
			pos = PartOfSpeech::Adverb;
		}
		else if (strPos == "a.")
		{
			pos = PartOfSpeech::Adjective;
		}
		else if (strPos == "v." || strPos == "v. i." || strPos == "v. t." || strPos == "v. t. & i.")
		{
			pos = PartOfSpeech::Verb;
		}
		else if (strPos == "prep.")
		{
			pos = PartOfSpeech::Preposition;
		}
		else if (strPos == "pron.")
		{
			pos = PartOfSpeech::Pronoun;
		}
		else if (strPos == "conj.")
		{
			pos = PartOfSpeech::Conjunction;
		}
		else if (strPos == "interj.")
		{
			pos = PartOfSpeech::Interjection;
		}

		return pos;
	}


}