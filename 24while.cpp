// 24while.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int counter, temp;
	string wordToSay;

	cout << "Enter the word you would like to say: ";
	cin >> wordToSay;
	cout << "Enter how many times you would like to say " << wordToSay << ": ";
	cin >> counter;

	// while the condition is true, do everything in the code block.
	// Test at the top.
	temp = counter;
	while (counter > 0)
	{
		cout << wordToSay << " ";
		// cout << "counter = " << counter << " ";
		counter -= 1;
	}
	cout << "\n";

	// "do-while" loop.  do everthing in the block, while the condition is true.
	// Test at the bottom.
	// first, reset the counter
	counter = temp;
	do
	{
		cout << wordToSay << " ";
		// cout << "counter = " << counter << " ";
		counter -= 1;
	} while (counter > 0);
	cout << "\n";


	system("pause");
	return 0;
}