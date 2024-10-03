<<<<<<< HEAD
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include "character.h"

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



}

#endif // !SENECA_CHARACTERTPL_H


=======
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include "character.h"

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



}

#endif // !SENECA_CHARACTERTPL_H


>>>>>>> 69c242c304a8380511264f99b4a1266495f8b178
