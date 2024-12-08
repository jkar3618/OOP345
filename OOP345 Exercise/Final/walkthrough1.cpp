#include <iostream>
using namespace std;

#define SQR(VAL) VAL * VAL
#define CUB(VAL) VAL * VAL * VAL
#define ADD(VAL1, VAL2) VAL1 + VAL2

int main() {
	cout << SQR(2) + ADD(3, 4) << endl;
	cout << CUB(5) * ADD(7, 8) << endl;
	cout << CUB(3) - SQR(2) << endl;
}