#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include "characterTpl.h"

namespace seneca
{
	template<typename T, typename Ability_t, typename Weapon_t>
	class Barbarian : public CharacterTpl<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		Ability_t m_ability;
		Weapon_t m_weapon[2];

	public:
		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);
		int getAttackAmnt() const;
		int getAttackAmnt() const;
		int getDefenseAmnt() const;
		Character* clone() const;
		void attack(Character* enemy);
		void takeDamage(int dmg);


	};

}

#endif // !SENECA_BARBARIAN_H



