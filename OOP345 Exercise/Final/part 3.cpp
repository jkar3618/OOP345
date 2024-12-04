#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

struct ComputerParts
{
	string partType;
	string model;
	double price;
	double powerConsumption;
	bool used;
};

int main()
{
	vector<ComputerParts> wishList;
	//1. Add to the `wishList` some number of desired `ComputerParts`.
	//Eg.GPU, RTX 3080, 1000, 300, false
	wishList.push_back({ "GPU", "RTX 3080", 1000.0, 320.0, false });
	wishList.push_back({ "CPU", "Intel Core i9", 500.0, 95.0, false });
	wishList.push_back({ "SDD", "Samsung 970 EVO Plus 1TB", 200.0, 5.0, true });
	wishList.push_back({ "GPU", "RTX 3070", 700.0, 220.0, true });
	wishList.push_back({ "CPU", "AMD Ryzen 9", 550.0, 105.0, false });

	std::sort(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
		return c1.price < c2.price;
		});

	const ComputerParts* min;
	const ComputerParts* max;
	double powerMin = wishList[0].powerConsumption;
	double powerMax = wishList[0].powerConsumption;

	std::for_each(wishList.begin(), wishList.end(), [&](const ComputerParts& c) {
		if (c.powerConsumption < powerMin)
		{
			powerMin = c.powerConsumption;
			min = &c;
		}

		if (c.powerConsumption > powerMax)
		{
			powerMax = c.powerConsumption;
			max = &c;
		}
		});

	vector<ComputerParts> temp;

	std::copy_if(wishList.begin(), wishList.end(), std::back_inserter(temp), [](const ComputerParts& c) {
		return c.used == false;
		});

	wishList = std::move(temp);

	double totalCost;

	totalCost = std::accumulate(wishList.begin(), wishList.end(), 0.0, [](double total, const ComputerParts& current) {
		return total + current.price;
		});

	double average = totalCost / wishList.size();

	vector<ComputerParts> newList;
	std::transform(wishList.begin(), wishList.end(), std::back_inserter(newList), [](ComputerParts& c) {

		c.used = true;
		c.price *= 0.8;

		return c;
		});

	std::string part = "CPU";
	int cnt = std::count_if(wishList.begin(), wishList.end(), [part](const ComputerParts& c) {
		return part == c.partType;
		});

	vector<ComputerParts> newWishList(wishList.size());

	std::copy(wishList.begin(), wishList.end(), newWishList.begin());
	newWishList.push_back({ "Case", "NZXT H510", 100.0, 0.0, false });
	newWishList.push_back({ "Cooling", "Corsair Hydro Series H100i", 120.0, 5.0, false });

	std::vector<ComputerParts> mergedList;
	std::merge(wishList.begin(), wishList.end(), newWishList.begin(), newWishList.end(), std::back_inserter(mergedList));


	//    std::cout <<

}