// 12favNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	// Declare variables at the top of the program.
	// int for integers, char for a character, string for words and sentences
	int fav_number;

	// ask a question
	cout << "What is your favorate number? ";

	// get an answer, put it in a variable
	cin >> fav_number;

	// output text and the variable
	cout << "Your favorate number is ";
	cout << fav_number;
	cout << ".\n";


	system("pause");
	return 0;
}

