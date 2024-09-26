//*****************************************************************************
//<assessment name example : Workshop - #1>
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
#include <iomanip>
#include <sstream>
#include <cstring>
#include "settings.h"
#include "dictionary.h"

using namespace std;

namespace seneca
{
	// default constructor
	Dictionary::Dictionary() : m_words(nullptr), m_size(0)
	{
	}

	// constructor that loads dictionary from a file
	Dictionary::Dictionary(const char* filename) : m_words(nullptr), m_size(0)
	{
		ifstream file(filename); // open the input file

		if (file.is_open())
		{
			string temp;
			size_t count{ 0 };

			// count the number of lines in the file
			while (getline(file, temp))
			{
				count++;
			}

			// reset file state and rewind the file to the beginning
			file.clear();
			file.seekg(0);

			m_words = new Word[count];
			m_size = 0;

			// read each line from the file and store the word data
			while (getline(file, temp))
			{
				stringstream ss(temp);

				string strWord, strDef, strPos;

				getline(ss, strWord, ','); // extract word
				getline(ss, strPos, ','); // extract part of speech
				getline(ss, strDef); // extract definition

				// store the word, definition and part of speech
				m_words[m_size].word = strWord;
				m_words[m_size].definition = strDef;
				m_words[m_size].pos = parsePos(strPos);

				m_size++;
			}
		}
	}

	// copy constructor
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

	// copy operator
	Dictionary& Dictionary::operator=(const Dictionary& src)
	{
		if (this != &src) // self assignmet check
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

	// move constructor
	Dictionary::Dictionary(Dictionary&& src) noexcept : m_words{ src.m_words }, m_size{ src.m_size }
	{
		src.m_words = nullptr;
		src.m_size = 0;
	}

	// move operator
	Dictionary& Dictionary::operator=(Dictionary&& src) noexcept
	{
		if (this != &src)
		{
			delete[] m_words;

			// shallow copy
			m_size = src.m_size;
			m_words = src.m_words;

			// nullity the source
			src.m_words = nullptr;
			src.m_size = 0;
		}

		return *this;
	}

	// destructor
	Dictionary::~Dictionary()
	{
		delete[] m_words;
	}

	// searching a word and display with definition and part of speech
	void Dictionary::searchWord(const char* word)
	{
		bool searched = false;
		size_t len = strlen(word);
		bool flag = true;

		// Iteration through the list of words to find a match
		for (size_t i = 0; i < m_size && flag; i++)
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
					else if (m_words[i].pos == PartOfSpeech::Adverb)
					{
						cout << "adverb";
					}
					else if (m_words[i].pos == PartOfSpeech::Preposition)
					{
						cout << "preposition";
					}
					else if (m_words[i].pos == PartOfSpeech::Pronoun)
					{
						cout << "pronoun";
					}
					else if (m_words[i].pos == PartOfSpeech::Interjection)
					{
						cout << "interjection";
					}
					else if (m_words[i].pos == PartOfSpeech::Conjunction)
					{
						cout << "conjunction";
					}

					cout << ") ";
				}

				cout << m_words[i].definition << endl;
				searched = true;
				if (!g_settings.m_show_all)
				{
					flag = false;
				}

			}

		}
		if (!searched)
		{
			cout << "Word '" << word << "' was not found in the dictionary." << endl;
		}
	}

	// parsing the part of speech from a string and return the corresponding enum value
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