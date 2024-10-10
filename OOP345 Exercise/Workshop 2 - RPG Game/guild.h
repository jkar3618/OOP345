//*****************************************************************************
//<assessment name example : Workshop - #2>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************
#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include "character.h"

namespace seneca
{
	class Guild
	{
		Character** m_member;
		std::string m_name;
		int m_extraHP;
		int m_count;

	public:
		Guild();
		Guild(const char* name);

		//rule of 5
		Guild(const Guild& g);
		Guild(Guild&& g) noexcept;
		~Guild();

		Guild& operator=(const Guild& g);
		Guild& operator=(Guild&& g) noexcept;

		void addMember(Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;
	};

}

#endif // !SENECA_ROGUE_H

