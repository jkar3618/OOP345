// main.cpp
#include <iostream>
#include "A.h"
using namespace std;

int main()
{
    // #1 - compile
    //array size is 5 but elements are 6
    int arrI[5]{ 0, 1, 2, 3, 4, 5 };
    
    // #4, process expects the use of a parameter
    // in the temp params that cannot be inferred
    // Fix process<int, 5>
    cout << process<int, 5>(arrI) << endl;
    A arrA[5]{ {1.2}, {2.3}, {3.4}, {4.5} };

    // #5 compile
    // the expression of cout << A ... is not defined
    // because of the lack of a operator<<(...)
    // Fix: Make the overload of op<< for A to work with
    // ostream, ostream& operator<<(ostream& os, const A&)
    cout << process<>(arrA) << endl;
}