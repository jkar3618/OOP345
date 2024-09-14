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
		ProteinDatabase();
		~ProteinDatabase();
		ProteinDatabase(ProteinDatabase& src);
		ProteinDatabase(ProteinDatabase&& src) noexcept;

		ProteinDatabase& operator=(ProteinDatabase& src);
		ProteinDatabase& operator=(ProteinDatabase&& src) noexcept;

		size_t size() const;
		std::string operator[](size_t) const;
		std::string getUID(size_t);

	};
}


#endif // !SENECA_PROTEINDATABASE_H
