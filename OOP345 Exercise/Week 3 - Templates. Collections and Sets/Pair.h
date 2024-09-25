#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

namespace seneca
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.

		Pair() {};
		bool operator==(const Pair& pair) const;
	
	};

	std::ostream& operator<<(std::ostream& os, Pair& p);

}

#endif // !SENECA_PAIR_H

