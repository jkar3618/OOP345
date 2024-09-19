#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "dictionary.h"

using namespace std;

namespace seneca
{
    Dictionary::Dictionary()
    {
    }

    Dictionary::Dictionary(const char* filename)
    {
        ifstream file(filename);

        if (file.is_open())
        {
            string temp;
            size_t count;
            
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
                parsePos2(strPos, m_words[m_size].pos);

                m_size++;


            }
        }
    }

    Dictionary::Dictionary(const Dictionary& src)
    {
        operator = (src);
    }
    Dictionary& Dictionary::operator=(const Dictionary& src)
    {
        if (this != &src)
        {
            delete[] m_words;
            
            m_size = src.m_size;

            m_words = new Word[m_size];
            for (size_t i = 0; i < m_size; i++)
            {
                m_words[i] = src.m_words[i];
            }
        }

        return *this;
    }

    Dictionary::Dictionary(Dictionary&& src) noexcept : m_words{src.m_words}, m_size {src.m_size}
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
    }

    void Dictionary::searchWord(const char* word)
    {
    }
    PartOfSpeech Dictionary::parsePos(const string& strPos)
    {
        PartOfSpeech pos;
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









    /*void Dictionary::parsePos2(const string& strPos, PartOfSpeech& pos)
    {
        if (strPos == "n." || strPos == "n.pl.")
        {
            pos = PartOfSpeech::Noun;
        }
        else if (strPos == "adv.")
        {
            m_words[m_size].pos = PartOfSpeech::Adverb;
        }
        else if (strPos == "a.")
        {
            m_words[m_size].pos = PartOfSpeech::Adjective;
        }
        else if (strPos == "v." || strPos == "v. i." || strPos == "v. t." || strPos == "v. t. & i.")
        {
            m_words[m_size].pos = PartOfSpeech::Verb;
        }
        else if (strPos == "prep.")
        {
            m_words[m_size].pos = PartOfSpeech::Preposition;
        }
        else if (strPos == "pron.")
        {
            m_words[m_size].pos = PartOfSpeech::Pronoun;
        }
        else if (strPos == "conj.")
        {
            m_words[m_size].pos = PartOfSpeech::Conjunction;
        }
        else if (strPos == "interj.")
        {
            m_words[m_size].pos = PartOfSpeech::Interjection;
        }
    }*/
}