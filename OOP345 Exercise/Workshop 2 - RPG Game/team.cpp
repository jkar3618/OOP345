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
#include <iomanip>
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

	Team::Team(const Team& t) : m_count(0), m_capacity(0), m_member(nullptr)
	{

		*this = t;
	}

	Team::Team(Team&& t) noexcept
		: m_name(std::move(t.m_name)), m_count(t.m_count), m_capacity(t.m_capacity), m_member(t.m_member)
	{
		// 원본 객체 초기화
		t.m_count = 0;
		t.m_capacity = 0;
		t.m_member = nullptr; // 원본 객체의 포인터 초기화
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
		}
		return *this;
	}

	Team& Team::operator=(Team&& t) noexcept
	{
		if (this != &t)
		{
			// m_member가 nullptr인지 확인
			if (m_member != nullptr) {
				for (size_t i = 0; i < m_count; i++)
				{
					delete m_member[i];
				}
				delete[] m_member;
			}

			// 이동 연산
			m_name = t.m_name;
			m_count = t.m_count;
			m_capacity = t.m_capacity;
			m_member = t.m_member;

			// 원본 객체 초기화
			t.m_name = "";
			t.m_count = 0;
			t.m_capacity = 0;
			t.m_member = nullptr;
		}

		return *this;
	}

	void Team::addMember(const Character* c)
	{
		int index = -1;

		for (size_t i = 0; i < m_count; i++)
		{
			if (m_member[i]->getName() == c->getName())
			{
				index = i;
			}
		}

		if (index == -1)
		{
			Character** temp = nullptr;

			temp = new Character * [m_count + 1];

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
		size_t index = m_count;

		for (size_t i = 0; i < m_count; i++)
		{
			if (m_member[i]->getName() == c)
			{
				index = i;
			}
		}


		if (index != m_count)
		{
			Character** temp = new Character * [m_count - 1];

			for (size_t i = 0, j = 0; i < m_count; i++)
			{
				if (i != index)
				{
					temp[j++] = m_member[i];
				}
			}

			delete[] m_member;
			m_member = temp;
			m_count--;

		}
	}

	Character* Team::operator[](size_t idx) const
	{
		return (idx < m_count) ? m_member[idx] : nullptr;
	}

	void Team::showMembers() const
	{
		if (m_member == nullptr)
		{
			cout << "No team." << endl;
		}
		else
		{
			cout << "[Team] " << m_name << endl;
			for (size_t i = 0; i < m_count; i++)
			{
				cout << setw(4) << "" << i + 1 << ": " << *m_member[i] << endl;
			}

		}
	}
}