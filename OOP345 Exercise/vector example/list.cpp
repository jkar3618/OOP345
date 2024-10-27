#include <list>
#include <iostream>

int main() {
	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	
	//std::list<int>::iterator it;
	auto it = lst.begin();
	++it;
	lst.insert(it, 5);

	for (int num : lst)
	{
		std::cout << num << " ";
	}

	return 0;
}