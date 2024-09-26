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

#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>

namespace seneca
{
	// Enum class to represent the part of speech
	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};

	// struct represent a word with its definition and part of speech
	struct Word
	{
		std::string word{};
		std::string definition{};
		PartOfSpeech pos = PartOfSpeech::Unknown;
	};

	class Dictionary
	{
		Word* m_words;
		size_t m_size{};

	public:
		Dictionary(); // default constructor
		Dictionary(const char* filename); // constructor that loads dictionary from a file

		Dictionary(const Dictionary& src); // copy constructor
		Dictionary& operator=(const Dictionary& src); // copy operator

		Dictionary(Dictionary&& src) noexcept; // move constructor
		Dictionary& operator=(Dictionary&& src) noexcept; // move operator

		~Dictionary(); // destructor

		void searchWord(const char* word); // searching a word and display with definition and part of speech
		PartOfSpeech parsePos(const std::string& strPos); // parsing the part of speech from a string and return the corresponding enum value
	};
}

#endif