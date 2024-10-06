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
		const Character** m_member;
	
	public:
		Team();
		Team(const char* name);
		
		// rule of 5
		Team(const Team& t); // copy constructor
		Team(Team&& t) noexcept; // move constructor
		~Team();

		Team& operator=(const Team& t);
		Team& operator=(Team&& t) noexcept;

		void addMember(const Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;

	};
}

#endif
