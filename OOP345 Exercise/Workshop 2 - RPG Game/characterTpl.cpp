#include <iostream>
#include "characterTpl.h"

using namespace std;

namespace seneca
{
	template<typename T>
	CharacterTpl<T>::CharacterTpl(const std::string& name, int max) :Character(name), m_healthMax(max), m_health(max) {}

	template<typename T>
	void CharacterTpl<T>::takeDamage(int dmg)
	{
		std::string name = this->getName();

		m_health -= dmg;

		if (m_health < 0)
		{
			cout << name << " has been defeated!" << endl;
		}
		else
		{
			cout << name << " took " << dmg << " damage, " << m_health << " health remaing." << endl;
		}
	}

	template<typename T>
	int CharacterTpl<T>::getHealth() const
	{
		return static_cast<int>m_health;
	}

	template<typename T>
	int CharacterTpl<T>::getHealthMax() const
	{
		return m_healthMax;
	}

	template<typename T>
	void CharacterTpl<T>::setHealth(int health)
	{
		m_health = health;
	}

	template<typename T>
	void CharacterTpl<T>::setHealthMax(int max)
	{
		m_healthMax = max;
	}

}