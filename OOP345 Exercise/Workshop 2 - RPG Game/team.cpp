#include "team.h"
using namespace std;

namespace seneca
{
	Team::Team()
	{
	}

	Team::Team(const char* name)
	{
	}

	Team::Team(const Team& t)
	{
	}

	Team::Team(Team&& t) noexcept
	{
	}

	Team::~Team()
	{
	}

	Team& Team::operator=(const Team& t)
	{
		return *this;
	}

	Team& Team::operator=(Team&& t) noexcept
	{
		return *this;
	}

	void Team::addMember(const Character* c)
	{
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