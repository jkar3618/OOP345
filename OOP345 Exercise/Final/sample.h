// sample.h

#include<iostream>
#include<string>
#include<vector>
#include<future>

struct Gem {
	std::string name{};
	unsigned  weight{}; // no data type
};

class TreasureBox {
	std::vector<Gem> gems;
	unsigned weight{}; // no data type
public:
	TreasureBox(const std::string* names, unsigned* weights, unsigned size); // no data type and no ref
	TreasureBox& operator+=(const Gem& g);
	void update(const std::string& name);
	std::ostream& display()const;
};

void task(std::promise<unsigned>& p); // no data type
