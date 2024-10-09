#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include "character.h"
#include "health.h"
using namespace std;

namespace seneca
{
	template<typename T>
	class CharacterTpl: public Character
	{
		int m_healthMax;
		T m_health;

	public:
		CharacterTpl(const std::string& name, int max);

		void takeDamage(int dmg) override;
		int getHealth() const override;
		int getHealthMax() const override;
		void setHealth(int health) override;
		void setHealthMax(int max) override;


	};


	template<typename T>
	CharacterTpl<T>::CharacterTpl(const std::string& name, int max) :Character(name.c_str()), m_healthMax(max) 
	{
		m_health = max;
	}

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
		return static_cast<int>(m_health);
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

#endif // !SENECA_CHARACTERTPL_H


