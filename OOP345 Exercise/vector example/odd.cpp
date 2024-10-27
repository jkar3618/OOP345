#include <iostream>
#include <vector>

int main()
{
	std::vector<int> number = { 10, 15, 20, 25, 30 };

	for (auto it = number.begin(); it != number.end(); it++)
	{
		if (*it % 2 != 0)
		{
			std::cout << *it << " ";
		}
	}
}