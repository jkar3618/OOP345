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
		std::string word{};
		std::string definition{};
		PartOfSpeech pos = PartOfSpeech::Unknown;
	};

	class Dictionary
	{
		Word* m_words;
		size_t m_size{};

	public:
		Dictionary();
		Dictionary(const char* filename);

		Dictionary(const Dictionary& src);
		Dictionary& operator=(const Dictionary& src);

		Dictionary(Dictionary&& src) noexcept;
		Dictionary& operator=(Dictionary&& src) noexcept;

		~Dictionary();

		void searchWord(const char* word);
		PartOfSpeech parsePos(const string& strPos);
		// void parsePos2(const string& strPos, PartOfSpeech& pos);
	};
}

#endif