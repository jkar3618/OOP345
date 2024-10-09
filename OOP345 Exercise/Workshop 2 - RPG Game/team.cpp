#include <iostream>
#include "team.h"
using namespace std;

namespace seneca
{
	Team::Team() : m_name(""), m_count(0), m_capacity(0), m_member(nullptr)
	{
	}

	Team::Team(const char* name) : m_name(name), m_count(0), m_capacity(0), m_member(nullptr)
	{
	}

	Team::Team(const Team& t)
	{
		/*m_name = t.m_name;
		m_count = t.m_count;
		m_capacity = t.m_capacity;

		if (m_count > 0)
		{
			m_member = new Character * [m_capacity];

			for (size_t i = 0; i < m_count; i++)
			{
				m_member[i] = t.m_member[i]->clone();
			}
		}
		else
		{
			m_member = nullptr;
		}*/

		*this = t;
	}

	Team::Team(Team&& t) noexcept
	{
		*this = std::move(t);
	}

	Team::~Team()
	{
		for (size_t i = 0; i < m_count; i++)
		{
			delete m_member[i];
		}
		delete[] m_member;
	}

	Team& Team::operator=(const Team& t)
	{
		if (this != &t)
		{
			for (size_t i = 0; i < m_count; i++)
			{
				delete m_member[i];
			}
			delete[] m_member;
		}

		m_name = t.m_name;
		m_count = t.m_count;
		m_capacity = t.m_capacity;
		m_member = new Character * [m_count];

		if (m_count > 0)
		{

			for (size_t i = 0; i < m_count; i++)
			{
				m_member[i] = t.m_member[i]->clone();
			}
		}
		else
		{
			m_member = nullptr;
		}
		return *this;
	}

	Team& Team::operator=(Team&& t) noexcept
	{
		if (this != &t)
		{
			for (size_t i = 0; i < m_count; i++)
			{
				delete m_member[i];
			}
			delete[] m_member;
		}

		m_name = std::move(t.m_name);
		m_count = t.m_count;
		m_capacity = t.m_capacity;
		m_member = t.m_member;

		t.m_name = "";
		t.m_count = 0;
		t.m_capacity = 0;
		t.m_member = nullptr;

		return *this;
	}

	void Team::addMember(const Character* c)
	{
		int index = -1;

		for (size_t i = 0; i < m_count; i++)
		{
			if (m_member == &c)
			{
				index = i;
			}
		}

		if (index == -1)
		{
			const Character** temp = nullptr;

			temp = new const Character * [m_count + 1];

			for (size_t i = 0; i < m_count; i++)
			{
				temp[i] = m_member[i];
			}
			temp[m_count] = c->clone();
			delete[] m_member;

			m_member = temp;
			m_count++;
		}
	}

	void Team::removeMember(const std::string& c)
	{

	}

	Character* Team::operator[](size_t idx) const
	{
		return nullptr;
	}

	void Team::showMembers() const
	{
	}
}