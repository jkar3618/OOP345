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
#ifndef SENECA_WEAPONS_H
#define SENECA_WEAPONS_H

namespace seneca
{
	// for simplicity, the logic associated with the weapons is kept trivial.

	struct BareHands {
		double m_damage = 5;
		operator double() const { return m_damage; }
	};

	struct Sword {
		double m_damage = 20;
		operator double() const { return m_damage; }
	};

	struct Axe {
		double m_damage = 22.5;
		operator double() const { return m_damage; }
	};

	struct Bow {
		double m_damage = 19.2;
		operator double() const { return m_damage; }
	};

	struct Crossbow {
		double m_damage = 56;
		operator double() const { return m_damage; }
	};

	struct Dagger {
		double m_damage = 12.8;
		operator double() const { return m_damage; }
	};
}
#endif