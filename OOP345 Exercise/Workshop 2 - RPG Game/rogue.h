#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"
#include "weapons.h"

namespace seneca
{
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpl<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		FirstAbility_t m_firstAbility;
		FirstAbility_t m_secondAbility;
		seneca::Dagger m_weapon;

	public:
		Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);
		int getAttackAmnt() const;
		int getDefenseAmnt() const;
		Character* clone() const;
		void attack(Character* enemy);
		void takeDamage(int dmg);
	};



}

#endif
