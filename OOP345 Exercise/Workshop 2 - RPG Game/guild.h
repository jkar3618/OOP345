#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include "character.h"

namespace seneca
{
	class Guild
	{
		const Character** m_character{ nullptr };
		int m_extraHP{ 300 };

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

