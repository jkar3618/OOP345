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
		Guild(); // Defalut Constructor
		Guild(const char* name); // Constructor that initialize guild with name

		//rule of 5
		Guild(const Guild& g); // Copy Constructor
		Guild(Guild&& g) noexcept; // Move Constructor
		~Guild(); // Destructor

		Guild& operator=(const Guild& g); // Copy assignment operator
		Guild& operator=(Guild&& g) noexcept; // Move assignment operator

		void addMember(Character* c); // Add member to guild
		void removeMember(const std::string& c); // Remove member by name
		Character* operator[](size_t idx) const; // Subscript operator
		void showMembers() const; // Display all guild members
	};

}

#endif // !SENECA_ROGUE_H

