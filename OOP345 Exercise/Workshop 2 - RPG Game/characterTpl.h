#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include "character.h"

namespace seneca
{
	template<typename T>
	class CharacterTpl
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


