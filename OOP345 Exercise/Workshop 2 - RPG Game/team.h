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
#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
#include <string>
#include "character.h"

namespace seneca
{
	class Team
	{
		std::string m_name;
		size_t m_count;
		size_t m_capacity; 
		Character** m_member;
	
	public:
		Team(); // Default constructor
		Team(const char* name); // Constructor with name 
		
		// rule of 5
		Team(const Team& t); // Copy constructor
		Team(Team&& t) noexcept; // Move constructor
		~Team(); // Destructor

		Team& operator=(const Team& t); // Copy assignment operator
		Team& operator=(Team&& t) noexcept; // Move assignment operator

		// Method to add a member to the team
		void addMember(const Character* c);

		// Method to remove a member from the team by name
		void removeMember(const std::string& c);

		// Operator overload to access team members by index
		Character* operator[](size_t idx) const;

		// Method to display all team members
		void showMembers() const;

	};
}

#endif
