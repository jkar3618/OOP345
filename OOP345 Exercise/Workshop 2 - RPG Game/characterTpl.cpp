#include <iostream>
#include "characterTpl.h"

using namespace std;

namespace seneca
{
	template<typename T>
	CharacterTpl<T>::CharacterTpl(const std::string& name, int max):Character(name), m_healthMax(max)
	{
	}

	template<typename T>
	void CharacterTpl<T>::takeDamage(int dmg)
	{
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
		m_health = heath;
	}

	template<typename T>
	void CharacterTpl<T>::setHealthMax(int max)
	{
		m_healthMax = max;
	}

}