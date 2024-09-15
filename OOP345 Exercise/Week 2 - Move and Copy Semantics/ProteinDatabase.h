#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>

namespace seneca
{
	class ProteinDatabase
	{
		std::string *p_id{};
		std::string *p_sequence{};
		size_t p_numProtein{ 0u };

	public:
		ProteinDatabase(); // default constructor
		ProteinDatabase(const std::string& fname); // 1 argument constructor
		
		// rule of 5
		~ProteinDatabase(); // destructor
		ProteinDatabase(const ProteinDatabase& src); // copy constructor
		ProteinDatabase& operator=(const ProteinDatabase& src); // copy assignment
		ProteinDatabase(ProteinDatabase&& src) noexcept; // move constructor
		ProteinDatabase& operator=(ProteinDatabase&& src) noexcept; // move assignment

		size_t size() const;
		std::string operator[](size_t index) const;
		std::string getUID(size_t index) const;

	};
}


#endif // !SENECA_PROTEINDATABASE_H


