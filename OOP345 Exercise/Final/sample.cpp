// sample.cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<future>
#include"sample.h"

TreasureBox::TreasureBox(const std::string* names, unsigned* weights, unsigned size) {
	for (unsigned x = 0; x < size; ++x) {
		gems.push_back(Gem{ names[x], weights[x] });
		weight += weights[x];

	}
	// no return 
	// return *this; 

}

TreasureBox& TreasureBox::operator+=(const Gem& g) {
	gems.push_back(g);
	weight += g.weight;
	return *this;

}

void TreasureBox::update(const std::string& name) {
	std::vector<Gem>::iterator itr;
	for (itr = gems.begin(); itr != gems.end(); ++itr) {
		if (itr->name == name) {
			unsigned sum = 0;
			sum = std::accumulate(name.begin(), name.end(), 0);
			itr->weight += sum;
		}
	}
}

std::ostream& TreasureBox::display() const {
	std::cout << "TreasureBox Contents" << std::endl;
	for (auto& g : gems) {
		std::cout << g.name << " : " << g.weight << std::endl;
	}
	return std::cout;
}

void task(std::promise<unsigned>& p) {
	Gem gems[]{ {"Red",10},{"Green",20},{"Blue",30} };

	auto idx = std::find_if(gems, gems + 2, [](const Gem& g) {
		return g.name == "Green";
		});

}