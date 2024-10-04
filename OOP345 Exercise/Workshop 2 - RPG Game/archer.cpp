#include <iostream>
#include <string>
#include "archer.h"

using namespace std;

namespace seneca
{
	template<typename Weapon_t>
	Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon) : CharacterTpl(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense), m_weapon(weapon)
	{
	}

	template<typename Weapon_t>
	int Archer<Weapon_t>::getAttackAmnt() const
	{
		int damage = static_cast<double>(1.3 * m_baseAttack);
		return damage;
	}

	template<typename Weapon_t>
	int Archer<Weapon_t>::getDefenseAmnt() const
	{
		int defense = static_cast<double>(1.2 * m_baseDefense);
		return defense;
	}

	template<typename Weapon_t>
	Character* Archer<Weapon_t>::clone() const
	{
		return new Archer(*this);
	}

	template<typename Weapon_t>
	void Archer<Weapon_t>::attack(Character* enemy)
	{
		std::string name = this.getName();
		std::string enemyName = enemy->getName();

		cout << name << " is attacking " << enemyName << "." << endl;

		int damage = getAttackAmnt();

		cout << "Archer deals " << damage << " ranged damage!" << endl;

		enemy->takeDamage(damage);

	}

	template<typename Weapon_t>
	void Archer<Weapon_t>::takeDamage(int dmg)
	{
		std::string name = this->getName();
		int offense = getAttackAmnt();
		int defense = getDefenseAmnt();

		cout << name << " is attacked for " << offense << " damage." << endl;
		cout << '\t' << "Archer has a defense of <<" << defense << ". " << "Reducing damage received." << endl;

		dmg -= getDefenseAmnt();
		dmg = std::max(dmg, 0);

		CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);

	}
}
