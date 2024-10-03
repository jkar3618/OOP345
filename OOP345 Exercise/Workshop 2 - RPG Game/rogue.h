<<<<<<< HEAD
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"

namespace seneca
{
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpl<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		FirstAbility_t m_firstAbility;
		FirstAbility_t m_secondAbility;
		Dagger m_weapon[2];

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

=======
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"

namespace seneca
{
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpl<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		FirstAbility_t m_firstAbility;
		FirstAbility_t m_secondAbility;
		Dagger m_weapon[2];

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

>>>>>>> 69c242c304a8380511264f99b4a1266495f8b178
