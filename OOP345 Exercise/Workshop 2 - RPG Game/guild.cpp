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
#include <iostream>
#include "guild.h"
using namespace std;

namespace seneca
{
	// Defalut Constructor
	Guild::Guild() : m_member(nullptr), m_name(""), m_extraHP(300), m_count(0)
	{
	}

	// Constructor that initialize guild with name
	Guild::Guild(const char* name) : m_member(nullptr), m_name(name), m_extraHP(300), m_count(0)
	{
	}

	// Copy Constructor
	Guild::Guild(const Guild& g)
		: m_name(g.m_name), m_extraHP(g.m_extraHP), m_count(g.m_count)
	{
		// Allocate new memory and perform deep copy
		m_member = new Character * [m_count];
		for (int i = 0; i < m_count; i++) {
			m_member[i] = g.m_member[i]; 
		}
	}

	// Move Constructor
	Guild::Guild(Guild&& g) noexcept
		: m_member(g.m_member), m_name(std::move(g.m_name)), m_extraHP(g.m_extraHP), m_count(g.m_count)
	{
		// Initialize original object's pointer
		g.m_member = nullptr; 
		g.m_count = 0;        
	}

	// Destructor
	Guild::~Guild() {

		delete[] m_member;
	}

	// Copy assignment operator
	Guild& Guild::operator=(const Guild& g)
	{
		if (this != &g)
		{
			// Clean up existing members
			for (auto i = 0; i < m_count; i++)
			{
				delete m_member[i]; // Ensure we delete the Characters properly
			}
			delete[] m_member; // Delete the array itself
			m_member = nullptr;

			// Copy new values
			m_count = g.m_count;
			m_name = g.m_name;
			m_extraHP = g.m_extraHP;

			// Allocate new member array
			m_member = new Character * [m_count];

			// Deep copy the characters
			for (auto i = 0; i < m_count; i++)
			{
				m_member[i] = g.m_member[i]->clone(); // Assuming clone creates a new instance
			}
		}
		return *this;
	}

	// Move assignment operator
	Guild& Guild::operator=(Guild&& g) noexcept
	{
		if (this != &g)
		{
			// Clean up existing memory
			delete[] m_member; 

			m_member = g.m_member;
			m_name = std::move(g.m_name);
			m_extraHP = g.m_extraHP;
			m_count = g.m_count;


			g.m_member = nullptr;
			g.m_count = 0;
		}

		return *this;
	}

	// Add member to guild
	void Guild::addMember(Character* c)
	{
		// Check for duplicates
		bool flag = false;

		for (int i = 0; i < m_count; i++)
		{
			if (m_member[i] == c) {
				flag = true; // Set flag if duplicate is found
			}
		}

		if (!flag)
		{
			Character** temp = new Character * [m_count + 1];

			for (auto i = 0; i < m_count; i++)
			{
				temp[i] = m_member[i];
			}

			// Add new member
			temp[m_count] = c;
			m_count++;

			delete[] m_member;

			m_member = temp;

			// Increase new member's maximum health by 300 points
			int newHealthMax = c->getHealthMax() + m_extraHP;
			c->setHealthMax(newHealthMax);

			// Set health to max
			c->setHealth(newHealthMax);

			// Ensure current health doesn't exceed maximum
			if (c->getHealth() > c->getHealthMax())
			{
				c->setHealth(c->getHealthMax());
			}
		}
	}

	// Remove member by name
	void Guild::removeMember(const std::string& c)
	{
		int index = -1;

		for (auto i = 0; i < m_count; i++)
		{
			if (m_member[i]->getName() == c)
			{
				index = i;
			}
		}

		if (index != -1)
		{
			Character** temp = new Character * [m_count - 1];

			for (auto i = 0, j = 0; i < m_count; i++)
			{
				if (index != i)
				{
					temp[j++] = m_member[i];
				}
			}

			// Decrease health and max health for the removed member
			m_member[index]->setHealthMax(m_member[index]->getHealthMax() - m_extraHP);
			m_member[index]->setHealth(m_member[index]->getHealth() - m_extraHP);


			delete[] m_member; // Release old member array
			m_member = temp; // Point to the new array
			m_count--; // Decrease member count

		}
	}

	// Subscript operator
	Character* Guild::operator[](size_t idx) const
	{
		Character* result = nullptr;
		if (static_cast<int>(idx) < m_count)
		{
			result = m_member[idx];
		}
		return result;
	}

	// Display all guild members
	void Guild::showMembers() const
	{
		if (m_member == nullptr)
		{
			cout << "No guild." << endl;
		}
		else
		{
			cout << "[Guild] " << m_name << endl;
			for (auto i = 0; i < m_count; i++)
			{
				cout << setw(4) << "" << i + 1 << ": " << *m_member[i] << endl;
			}

		}
	}
}
