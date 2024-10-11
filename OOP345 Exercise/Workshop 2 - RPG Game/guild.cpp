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
		: m_name(g.m_name), m_extraHP(g.m_extraHP), m_count(g.m_count)
	{
		// 새로운 메모리 할당 및 깊은 복사
		m_member = new Character * [m_count];
		for (int i = 0; i < m_count; i++) {
			m_member[i] = g.m_member[i]; // 깊은 복사
		}
	}
	Guild::Guild(Guild&& g) noexcept
		: m_member(g.m_member), m_name(std::move(g.m_name)), m_extraHP(g.m_extraHP), m_count(g.m_count)
	{
		g.m_member = nullptr; // 원본 객체의 포인터 초기화
		g.m_count = 0;        // 원본 객체의 멤버 수 초기화
	}
	Guild::~Guild() {

		delete[] m_member; // 멤버 배열 해제
	}

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


	Guild& Guild::operator=(Guild&& g) noexcept
	{
		if (this != &g)
		{
			// 기존 메모리 해제
			delete[] m_member; // 기존 멤버 해제

			// 이동 연산
			m_member = g.m_member; // 포인터 이동
			m_name = std::move(g.m_name);
			m_extraHP = g.m_extraHP;
			m_count = g.m_count;

			// 원본 객체 초기화
			g.m_member = nullptr;
			g.m_count = 0;
		}

		return *this;
	}
	void Guild::addMember(Character* c)
	{
		// 중복 체크
		bool flag = false;
		for (int i = 0; i < m_count; i++)
		{
			if (m_member[i] == c) {
				flag = true; // 중복이 발견되면 플래그 설정
			}
		}

		if (!flag)
		{
			Character** temp = new Character * [m_count + 1];

			for (auto i = 0; i < m_count; i++)
			{
				temp[i] = m_member[i];
			}

			temp[m_count] = c;
			m_count++;

			delete[] m_member;

			m_member = temp;

			// 새로운 멤버의 최대 체력을 300 포인트 증가
			int newHealthMax = c->getHealthMax() + m_extraHP;
			c->setHealthMax(newHealthMax);

			// 체력을 최대 체력으로 설정
			c->setHealth(newHealthMax); // 최대 체력으로 설정
			c->setHealthMax(newHealthMax);

			// 캐릭터의 현재 체력이 최대 체력보다 크면 최대 체력으로 설정
			if (c->getHealth() > c->getHealthMax())
			{
				c->setHealth(c->getHealthMax());
			}

			/*c->setHealthMax(c->getHealthMax() + m_extraHP);
			c->setHealth(c->getHealthMax());

			if (c->getHealth() > c->getHealthMax()) 
			{
				c->setHealth(c->getHealthMax());
			}*/
		}
	}
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

			m_member[index]->setHealthMax(m_member[index]->getHealthMax() - m_extraHP);
			m_member[index]->setHealth(m_member[index]->getHealth() - m_extraHP);


			delete[] m_member;
			m_member = temp;
			m_count--;

		}
	}
	Character* Guild::operator[](size_t idx) const
	{
		Character* result = nullptr;
		if (static_cast<int>(idx) < m_count)
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
			for (auto i = 0; i < m_count; i++)
			{
				cout << setw(4) << "" << i + 1 << ": " << *m_member[i] << endl;
			}

		}
	}
}
