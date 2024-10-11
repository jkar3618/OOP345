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

#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include "character.h"
#include "health.h"
using namespace std;

namespace seneca
{
	// Template class CharacterTpl inheriting from Character
	template<typename T>
	class CharacterTpl: public Character
	{
		int m_healthMax;
		T m_health;

	public:
		// Constructor
		CharacterTpl(const std::string& name, int max);

		// Override taking damag
		void takeDamage(int dmg) override;

		// Override get health
		int getHealth() const override;

		// Override get health max
		int getHealthMax() const override;

		// Override set health
		void setHealth(int health) override;

		// Override set health max
		void setHealthMax(int max) override;


	};

	// Constructor
	template<typename T>
	CharacterTpl<T>::CharacterTpl(const std::string& name, int max) :Character(name.c_str()), m_healthMax(max) 
	{
		m_health = max;
	}

	// Override taking damag
	template<typename T>
	void CharacterTpl<T>::takeDamage(int dmg)
	{
		std::string name = this->getName();

		m_health -= dmg;

		if (m_health < 0)
		{
			cout << setw(4) << "" << name << " has been defeated!" << endl;
		}
		else
		{
			cout << setw(4) << "" << name << " took " << dmg << " damage, " << m_health << " health remaining." << endl;
		}
	}

	// Override get health
	template<typename T>
	int CharacterTpl<T>::getHealth() const
	{
		return (static_cast<int>(m_health) > 0) ? static_cast<int>(m_health) : 0;
	}

	// Override get health max
	template<typename T>
	int CharacterTpl<T>::getHealthMax() const
	{
		return m_healthMax;
	}

	// Override set health
	template<typename T>
	void CharacterTpl<T>::setHealth(int health)
	{
		m_health = health;
	}

	// Override set health max
	template<typename T>
	void CharacterTpl<T>::setHealthMax(int max)
	{
		m_healthMax = max;
	}

}

#endif // !SENECA_CHARACTERTPL_H


