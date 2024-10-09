#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"
#include "weapons.h"
#include "abilities.h"

using namespace std;

namespace seneca
{
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpl<T>
	{
		int m_baseDefense;
		int m_baseAttack;
		FirstAbility_t m_firstAbility;
		FirstAbility_t m_secondAbility;
		Dagger m_weapon;

	public:
		Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);
		int getAttackAmnt() const;
		int getDefenseAmnt() const;
		Character* clone() const;
		void attack(Character* enemy);
		void takeDamage(int dmg);
	};

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense) :CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense)
	{
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const
	{
		int damage = m_baseAttack + 2 * static_cast<double>(m_weapon);
		return damage;
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const
	{
		return m_baseDefense;
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const
	{
		return new Rogue(*this);
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy)
	{
		std::string name = this->getName();
		std::string enemyName = enemy->getName();

		std::cout << this->getName() << " is attacking " << enemy->getName() << "." << endl;

		m_firstAbility.useAbility(this);
		m_secondAbility.useAbility(this);

		int damage = getAttackAmnt();

		m_firstAbility.transformDamageDealt(damage);
		m_secondAbility.transformDamageDealt(damage);

		cout << "Rogue deals " << damage << " melee damage!" << endl;

		enemy->takeDamage(damage);
	}

	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg)
	{
		std::string name = this->getName();
		int offense = getAttackAmnt();
		int defense = getDefenseAmnt();

		cout << name << " is attacked for " << offense << " damage." << endl;
		cout << '\t' << "Rogue has a defense of <<" << defense << ". " << "Reducing damage received." << endl;

		dmg -= getDefenseAmnt();
		dmg = std::max(dmg, 0);

		m_firstAbility.transformDamageReceived(dmg);
		m_secondAbility.transformDamageReceived(dmg);

		CharacterTpl<T>::takeDamage(dmg);

	}



}

#endif
