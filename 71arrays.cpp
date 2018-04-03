// 71arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Passing an array parameter (and its size), like call by reference
void showArray(int a[], int size);

int main()
{
	// Initializing an array of size 5.  Indexes 0-4 to access elements.
	int numbers[5] = { 1,2,3,4,5 };
	int count;

	// Ways to access elements in the array using the index.
	cout << "numbers[0] is " << numbers[0] << endl;
	count = 3;
	cout << "numbers[count] is " << numbers[count] << endl;
	numbers[0] = 7;
	cout << "numbers[0] is " << numbers[0] << endl;
	cout << "numbers contains ";

	// Calling a function to show the contents of an array.
	showArray(numbers, 5);
	//showArray(numbers, 6); 

	system("pause");
	return 0;
}

void showArray(int a[], int size)
{
	// Traditional for loop to see array.
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

}