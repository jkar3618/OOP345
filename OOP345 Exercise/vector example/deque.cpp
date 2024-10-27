#include <deque>
#include <iostream>

int main() {
	std::deque<int> dq;

	dq.push_back(1);
	dq.push_front(0);

	for (size_t i = 0; i < dq.size(); i++)
	{
		std::cout << dq[i] << " ";
	}

	return 0;
}