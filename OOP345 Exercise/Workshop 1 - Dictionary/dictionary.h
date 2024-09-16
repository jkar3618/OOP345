#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

namespace seneca
{

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
	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};

	class Dictionary
	{
		Word* m_words;
		size_t size{};

	public:
		Dictionary();
		Dictionary(const char* filename);
		void searchWord(const char* word);
	};
}

#endif