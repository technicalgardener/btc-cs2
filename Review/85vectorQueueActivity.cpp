// 85vectorQueueActivity.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void displayNames(vector<string>& names);

int main()
{
	vector <string> namesList = { "Luke", "Leia", "Han" };
	char choice;
	int i = 0;
	int remove = 0;
	string name;

	displayNames(namesList);

	cin >> choice;

	while (choice != 'Q' && choice != 'q')
	{
		switch (choice)
		{
		case 'S': case 's':
			if (namesList.size() >= 1)
			{
				cout << "Now serving: " << namesList[0] << endl;
				system("pause");
				namesList.erase(namesList.begin());
				displayNames(namesList);
				break;
			}
			else
			{
				cout << "\a";
				cout << "You must construct additional pylons" << endl;
				system("pause");
				displayNames(namesList);
				break;
			}

		case 'A': case 'a':
			cout << "Who would you like to add? :";
			cin >> name;
			namesList.push_back(name);
			displayNames(namesList);
			break;

		case 'R': case 'r':
			if (namesList.size() >= 1)
			{
				cout << "What is the number of the person you would like to remove? :";
				cin >> remove;
				if (remove > namesList.size())
				{
					cout << "\a";
					cout << "Just what do you think you're doing, Dave?\n" << "Please enter an acceptable number..." << endl << endl;
					system("pause");
					displayNames(namesList);
					break;
				}
				else
				{
					namesList.erase(namesList.begin() + remove - 1);
					displayNames(namesList);
				}
			}
			else
			{
				cout << "\a";
				cout << "I'm sorry, Dave. I'm afraid I can't do that." << endl;
				system("pause");
				displayNames(namesList);
				break;
			}

		case 'Q': case 'q':
			break;
		}
		cin >> choice;
	}

	displayNames(namesList);
	system("pause");
	return 0;
}

void displayNames(vector<string>& names)
{
	system("cls");
	cout << "     Customer Queue" << endl << "-------------------------" << endl;
	for (int i = 0; i < names.size(); i++)
		cout << i + 1 << "\t" << names[i] << endl;
	cout << endl << endl;
	cout << "(S)erve   (A)dd   (R)emove   (Q)uit: ";
	cout << endl;
}