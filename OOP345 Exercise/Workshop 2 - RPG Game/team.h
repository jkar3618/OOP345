#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
#include <string>
#include "character.h"

namespace seneca
{
	class Team
	{
		std::string m_name;
		const Character** m_character{ nullptr };
	
	public:
		Team();
		Team(const char* name);
		
		// rule of 5
		Team(const Team& t);
		Team(Team&& t) noexcept;
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
