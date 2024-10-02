#pragma once
#include "characterTpl.h"

namespace seneca
{
	template<typename T, typename Ability_t, typename Weapon_t>
	class barbarian : public CharacterTpl<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		Ability_t m_ability;
		Weapon_t m_weapon[2];

	public:
		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);


	};

}


