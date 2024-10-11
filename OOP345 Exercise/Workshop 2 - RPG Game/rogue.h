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
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include "characterTpl.h"
#include "weapons.h"
#include "abilities.h"

using namespace std;

namespace seneca
{
	// Define template class Archer, inheritance from CharacterTpl<T>
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpl<T>
	{
		int m_baseAttack;
		int m_baseDefense;
		FirstAbility_t m_firstAbility;
		FirstAbility_t m_secondAbility;
		Dagger m_weapon;

	public:
		// Constructor
		Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);

		// Calculate attack amount
		int getAttackAmnt() const;

		// Return defense amount
		int getDefenseAmnt() const;

		// Creat a clone of the Rogue obj
		Character* clone() const;

		// Attack
		void attack(Character* enemy);

		// Take damage from attack
		void takeDamage(int dmg);
	};

	// Constructor
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(const char* name, int healthMax, int baseAttack, int baseDefense) :CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense)
	{
	}

	// Caculate attack amount
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const
	{
		int damage = m_baseAttack + 2 * static_cast<double>(m_weapon);
		return static_cast<int>(damage);
	}

	// Return defense amount
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const
	{
		return m_baseDefense;
	}

	// Create clone of Rogue obj
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const
	{
		return new Rogue(*this);
	}

	// Attack
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

	// Take damage 
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
