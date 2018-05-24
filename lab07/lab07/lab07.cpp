// lab07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const string diskFileRd = "C:\\Users\\cmikk\\OneDrive\\School\\Q3 - Spring 2018\\Computer Science 2\\laughing-garbanzo\\Lab07.LinkedLists\\Lab07.LinkedLists\\Resource\\unsorted127.txt";

struct Numb {
	int value;
	struct Numb * nextNumb;
};

int main()
{
	ifstream rdDB;

	struct Numb * numbListHead = NULL;
	struct Numb * movingPtr;
	struct Numb * createdNode;

	rdDB.open(diskFileRd);
	if (rdDB.fail())
	{
		cout << "-Failed to Open File-" << endl;

		system("pause");
		exit(1);
	}

	createdNode = new Numb;

	if (!(rdDB >> createdNode->value)) {
		cout << "No data in file.\n";

		system("pause");
		exit(1);
	} else {
		numbListHead = createdNode;  
		numbListHead->nextNumb = NULL;  
		createdNode = new Numb; 
		cout << "+";
	}

	while (rdDB >> createdNode->value) {
		if (createdNode->value <= numbListHead->value) { // Check to see if new number is the smallest number so far
			createdNode->nextNumb = numbListHead;
			numbListHead = createdNode;
			cout << "+";
		} 
		else {
			bool inserted = false;
			movingPtr = numbListHead;
			while (!inserted) {
				if (movingPtr->nextNumb == NULL) {
					movingPtr->nextNumb = createdNode;
					createdNode->nextNumb == NULL;
					inserted = true;
					
				}
				else if (createdNode->value <= movingPtr->value) {
					createdNode->nextNumb = movingPtr->nextNumb;
					movingPtr->nextNumb = createdNode;
					createdNode->nextNumb = NULL;
					inserted = true;
					
				}
				else
					movingPtr = movingPtr->nextNumb;
				cout << "+";
			}
		}
		createdNode = new Numb;
	}
	delete createdNode;

	cout << numbListHead->value << endl;
	/*
	movingPtr = numbListHead;
	while (movingPtr->nextNumb != NULL) {
		cout << movingPtr->value << endl;
		movingPtr = movingPtr->nextNumb;
	}
	*/

	system("pause");
    return 0;
}

