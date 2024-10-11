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
	// Default constructor
	Team::Team() : m_name(""), m_count(0), m_capacity(0), m_member(nullptr)
	{
	}

	// Constructor with name
	Team::Team(const char* name) : m_name(name), m_count(0), m_capacity(0), m_member(nullptr)
	{
	}

	// Copy constructor
	Team::Team(const Team& t) : m_count(0), m_capacity(0), m_member(nullptr)
	{
		*this = t;
	}

	// Move constructor
	Team::Team(Team&& t) noexcept
		: m_name(std::move(t.m_name)), m_count(t.m_count), m_capacity(t.m_capacity), m_member(t.m_member)
	{
		t.m_count = 0;
		t.m_capacity = 0;
		t.m_member = nullptr; 
	}

	// Destructor
	Team::~Team()
	{
		for (size_t i = 0; i < m_count; i++)
		{
			delete m_member[i];
		}
		delete[] m_member;
	}

	// Copy assignment operator
	Team& Team::operator=(const Team& t)
	{
		if (this != &t)
		{
			for (size_t i = 0; i < m_count; i++)
			{
				delete m_member[i]; // Delete existing characters
			}
			delete[] m_member; // Release the member array

			// Copy new values
			m_name = t.m_name;
			m_count = t.m_count;
			m_capacity = t.m_capacity;
			m_member = new Character * [m_count];

			if (m_count > 0)
			{
				// Clone characters from the source team
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

	// Move assignment operator
	Team& Team::operator=(Team&& t) noexcept
	{
		if (this != &t)
		{
			// Clean up existing members if necessary
			if (m_member != nullptr) {
				for (size_t i = 0; i < m_count; i++)
				{
					delete m_member[i];
				}
				delete[] m_member;
			}

			// Move operation
			m_name = t.m_name;
			m_count = t.m_count;
			m_capacity = t.m_capacity;
			m_member = t.m_member;

			// Initialize the original object
			t.m_name = "";
			t.m_count = 0;
			t.m_capacity = 0;
			t.m_member = nullptr;
		}

		return *this;
	}

	// Method to add a member to the team
	void Team::addMember(const Character* c)
	{
		// Check for duplicate members
		int index = -1;

		for (size_t i = 0; i < m_count; i++)
		{
			if (m_member[i]->getName() == c->getName())
			{
				index = i; // Duplicate found
			}
		}

		// If no duplicate, add new member
		if (index == -1)
		{
			Character** temp = nullptr;

			temp = new Character * [m_count + 1];

			for (size_t i = 0; i < m_count; i++)
			{
				temp[i] = m_member[i]; // Copy existing members
			}
			temp[m_count] = c->clone(); // Clone new member
			delete[] m_member; // Release old member array

			m_member = temp; // Update member pointer
			m_count++;
		}
	}

	// Method to remove a member from the team by name
	void Team::removeMember(const std::string& c)
	{
		size_t index = m_count; // Start with an invalid index

		// Search for the member to remove
		for (size_t i = 0; i < m_count; i++)
		{
			if (m_member[i]->getName() == c)
			{
				index = i; // Store index if found
			}
		}

		// If the member was found, remove them
		if (index != m_count)
		{
			Character** temp = new Character * [m_count - 1];

			for (size_t i = 0, j = 0; i < m_count; i++)
			{
				if (i != index)
				{
					temp[j++] = m_member[i]; // Copy members except the one to remove
				}
			}

			delete[] m_member; // Release old member array
			m_member = temp; // Update member pointer
			m_count--; // Decrement member count
		}
	}

	// Operator overload to access team members by index
	Character* Team::operator[](size_t idx) const
	{
		return (idx < m_count) ? m_member[idx] : nullptr;
	}

	// Method to display all team members
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