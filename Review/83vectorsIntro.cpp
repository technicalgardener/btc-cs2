// 83vectorsIntro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void displayIntVector(vector<int>& v);

int main()
{
	/* Vectors are like arrays you can make bigger and smaller while the program is running. */
	vector <int> v1 = { 2,4,6 };
	int num1 = 0;

	displayIntVector(v1);

	/* Use the push_back member function to add to the vector. */
	v1.push_back(8);
	displayIntVector(v1);

	/* Don't go out of bounds, just like arrays. */
	/*
	cout << v1[4] << endl;
	*/
	v1.push_back(10);
	displayIntVector(v1);

	/* Assign num1 to the last element. */
	num1 = v1[(v1.size() - 1)];
	cout << "num1=" << num1 << endl;
	/* Remove the last element. (Typical push/pop on/off the stack.) */
	v1.pop_back();
	displayIntVector(v1);

	/* insert at begining */
	v1.insert(v1.begin(), 12);
	displayIntVector(v1);

	/* insert at 4th position */
	v1.insert(v1.begin() + 3, 14);
	displayIntVector(v1);

	/* erase second-to-last element */
	v1.erase(v1.end() - 2);
	displayIntVector(v1);


	system("pause");
	return 0;
}

void displayIntVector(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	cout << "v size is " << v.size() << endl;
	cout << "v capacity in memory is " << v.capacity() << endl << endl;
}