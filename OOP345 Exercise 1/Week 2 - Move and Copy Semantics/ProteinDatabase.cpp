#include <iostream>
#include <string>
#include "ProteinDatabase.h"

using namespace std;

namespace seneca
{
	ProteinDatabase::ProteinDatabase()
	{
	}

	ProteinDatabase::~ProteinDatabase()
	{
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase& src)
	{
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) noexcept
	{
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase& src)
	{
		// TODO: insert return statement here
		return *this;
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src) noexcept
	{
		// TODO: insert return statement here
		return *this;

	}

	size_t ProteinDatabase::size() const
	{
		return size_t();
	}

	std::string ProteinDatabase::operator[](size_t) const
	{
		return std::string();
	}

	std::string ProteinDatabase::getUID(size_t)
	{
		return std::string();
	}
}