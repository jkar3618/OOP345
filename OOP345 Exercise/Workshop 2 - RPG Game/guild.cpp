#include "guild.h"
using namespace std;

namespace seneca
{
	Guild::Guild()
	{
	}
	Guild::Guild(const char* name)
	{
	}
	Guild::Guild(const Guild& g)
	{
	}
	Guild::Guild(Guild&& g) noexcept
	{
	}
	Guild::~Guild()
	{
	}
	Guild& Guild::operator=(const Guild& g)
	{
		return *this;
	}
	Guild& Guild::operator=(Guild&& g) noexcept
	{
		return *this;
	}
	void Guild::addMember(Character* c)
	{
	}
	void Guild::removeMember(const std::string& c)
	{
	}
	Character* Guild::operator[](size_t idx) const
	{
		return nullptr;
	}
	void Guild::showMembers() const
	{
	}
}
