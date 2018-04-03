// cReview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void rdPerson(int& age, string& first, string& last);
void makeUC(string& name);

int main()
{
	int age;
	string fName, lName, upper;

	// loops the functions rdPerson() and makeUC() while age is greater than 0.
	while (true)
	{
		rdPerson(age, fName, lName);
		if (age <= 0)
			break;
		makeUC(fName);
		makeUC(lName);

		cout << age << " " << fName << " " << lName << " " << endl;
	}

	system("pause");
    return 0;
}

void rdPerson(int& age, string& first, string& last)
{
	// primary function: takes input and seperates into 3 variables.
	cout << "Enter age, first name, last name, seperated by a tab: " << endl;
	cin >> age;
	cin >> first;
	getline(cin, last);
	last.erase(0, 1);
}

void makeUC(string& name)
{
	// takes a string and converts all characters into upper case letters.
	string upper(name);
	for (int i = 0; i < name.length(); i++)
		upper[i] = toupper(name[i]);
	name = upper;
}