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
	Guild::Guild() : m_member(nullptr), m_name(""), m_extraHP(300), m_count(0)
	{
	}
	Guild::Guild(const char* name) : m_member(nullptr), m_name(name), m_extraHP(300), m_count(0)
	{
	}
	Guild::Guild(const Guild& g)
	{
		*this = g;
	}
	Guild::Guild(Guild&& g) noexcept
	{
		*this = std::move(g);
	}
	Guild::~Guild()
	{
		delete[] m_member;
	}
	Guild& Guild::operator=(const Guild& g)
	{
		if (this != &g)
		{
			delete[] m_member;

			m_count = g.m_count;
			m_name = g.m_name;
			m_extraHP = g.m_extraHP;

			m_member = new Character * [m_count];

			for (size_t i = 0; i < m_count; i++)
			{
				m_member[i] = g.m_member[i];
			}
		}

		return *this;
	}
	Guild& Guild::operator=(Guild&& g) noexcept
	{
		if (this != &g)
		{
			delete[] m_member;

			m_name = g.m_name;
			m_count = g.m_count;
			m_extraHP = g.m_extraHP;

			m_member = new Character * [m_count];

			for (size_t i = 0; i < m_count; i++)
			{
				m_member[i] = g.m_member[i];
			}

			g.m_name.clear();
			g.m_extraHP = 0;
			g.m_count = 0;
			g.m_member = nullptr;
		}

		return *this;
	}
	void Guild::addMember(Character* c)
	{
		int index = -1;

		for (size_t i = 0; i < m_count; i++)
		{
			if (m_member[i] == c) {
				index = i;
			}
		}

		if (index == -1)
		{
			Character** temp = new Character * [m_count + 1];

			for (size_t i = 0; i < m_count; i++)
			{
				temp[i] = m_member[i];
			}

			temp[m_count] = c;
			m_count++;

			m_member = temp;


			c->setHealthMax(c->getHealthMax() + m_extraHP);
			c->setHealth(c->getHealthMax());
		}
	}
	void Guild::removeMember(const std::string& c)
	{
		int index = -1;

		for (size_t i = 0; i < m_count; i++)
		{
			if (m_member[i]->getName() == c)
			{
				index = i;
			}
		}

		if (index != -1)
		{
			Character** temp = new Character * [m_count - 1];

			for (size_t i = 0, j = 0; i < m_count; i++)
			{
				if (index != i)
				{
					temp[j++] = m_member[i];
				}
			}
			m_member[index]->setHealthMax(m_member[index]->getHealthMax() - m_extraHP);

			delete[] m_member;
			m_member = temp;
			m_count--;

		}
	}
	Character* Guild::operator[](size_t idx) const
	{
		Character* result = nullptr;
		if (idx < m_count)
		{
			result = m_member[idx];
		}
		return result;
	}
	void Guild::showMembers() const
	{
		if (m_member == nullptr)
		{
			cout << "No guild." << endl;
		}
		else
		{
			cout << "[Guild] " << m_name << endl;
			for (size_t i = 0; i < m_count; i++)
			{
				cout << i + 1 << ": " << *m_member[i] << endl;
			}

		}
	}
}
