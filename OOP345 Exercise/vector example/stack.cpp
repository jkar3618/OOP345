#include <stack>
#include <iostream>

int main() {
	std::stack<int> stk;

	stk.push(1);
	stk.push(2);
	stk.push(3);

	while (!stk.empty())
	{
		std::cout << stk.top() << " ";
		stk.pop();
	}

	return 0;
}