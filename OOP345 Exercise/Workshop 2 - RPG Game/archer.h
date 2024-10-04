
#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include "characterTpl.h"
#include "weapons.h"

namespace seneca
{
	template<typename Weapon_t>
	class Archer : public CharacterTpl<seneca::SuperHealth>
	{
		int m_baseDefense;
		int m_baseAttack;
		Weapon_t m_weapon;

	public:
		Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);
		int getAttackAmnt() const;
		int getDefenseAmnt() const;
		Character* clone() const;
		void attack(Character* enemy);
		void takeDamage(int dmg);
	};



}

#endif // !SENECA_ARCHER_H

