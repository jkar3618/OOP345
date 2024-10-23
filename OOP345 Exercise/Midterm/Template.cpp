#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;
// assume all necessary headers have been included
template <class T>
T* insertAtEnd(T* arr, size_t sz, const T& elem)
{
	// add elem to end of arr => resize of arr
	T* temp = new T[sz + 1];

	// copy old stuff to new temp
	for (auto i = 0; i < sz; i++)
	{
		temp[i] = arr[i];
	}

	// add elem to temp
	temp[sz] = elem;

	delete[] arr;

	return temp;
}

template<>
char* insertAtEnd(char* arr, size_t sz, const char& elem)
{
	// add elem to end of arr => resize of arr, consider the nullbyte
	char* temp = new char[sz + 2]; // space for elem, and nullbyte

	// copy old stuff to new temp
	/*for (auto i = 0; i < sz; i++)
	{
		temp[i] = arr[i];
	}*/
	if (arr)
	{
		strcpy(temp, arr);

	}

	// add elem to temp
	temp[sz] = elem;
	temp[sz + 1] = '\0';

	delete[] arr;

	return temp;
}


int main()
{
	{
		int* arrI = nullptr;
		arrI = insertAtEnd(arrI, 0, 1); // 1
		arrI = insertAtEnd(arrI, 1, 5); // 1, 5
		arrI = insertAtEnd(arrI, 2, -3);// 1, 5, -3
		delete[] arrI;
	}
	{
		double* arrD = nullptr;
		arrD = insertAtEnd(arrD, 0, 1.2);// 1.2
		arrD = insertAtEnd(arrD, 1, 2.3);// 1.2, 2.3
		arrD = insertAtEnd(arrD, 2, 3.4);// 1.2, 2.3, 3.4
		delete[] arrD;
	}
	{
		char* arrC = nullptr;
		arrC = insertAtEnd(arrC, 0, 'a');// a\0
		arrC = insertAtEnd(arrC, 1, 'b');// ab\0
		arrC = insertAtEnd(arrC, 2, 'c');// abc\0
		cout << arrC;
		delete[] arrC;
	}
}
