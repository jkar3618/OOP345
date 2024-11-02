#include <iostream>
using namespace std;
union group {
	struct {
		int val;
	} s1, s2;
	group(int arr[], int len) {
		for (auto i = 0; i < len; i++) {
			if (arr[i] % 2 == 0)
				s1.val = i;
			else
				s2.val = arr[i];
		}
	}
	void display() const {
		cout << s1.val << '|' << s2.val << endl;
	}
};
int main() {
	int arr1[]{ 1, 2 };
	int arr2[]{ 1,3, 3 };
	group g1(arr1, 2);
	group g2(arr2, 3);
	g1.display(); 
	g2.display();
	g1 = g2;
	g1.display();
}