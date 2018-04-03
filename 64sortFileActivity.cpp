// 64sortFileActivity.cpp : Defines the entry point for the console application.
//
/*
Guided Inquiry Activities Paired with the Programming Example
Quad and Paired programming session with students trading driver/navigator and recorder/reporter roles at each step.

In Groups Of Four (driver, navigator, recorder, reporter):

1.	Discuss and describe how a bubble sort works and report out to the group.  (Nothing fancy required, just the general idea.)

2.	Discuss what you would need to do to sort a file of numbers and report out to the group.

3.	Write some pseudocode (programming tasks in English) that could sort a file of numbers.

In Pairs (driver, navigator):

1.	Write a program that reads numbers from a file and outputs them to the screen.

2.	Modify your program so it also outputs to a new file.

3.	Write pseudocode that could compare adjacent numbers from the input file and swap them if they are out of order and write them to the new file.

4.	Write actual code that swaps adjacent numbers in the input stream if they are out of order and writes resulting numbers to a new file.

In Groups Of Four (driver, navigator, recorder, reporter):

1.	Discuss how you could repeat passes through the numbers until they are sorted and report out.

2.	Write pseudocode that accomplishes multiple sorting passes through the numbers until sorted.

In Pairs (driver, navigator):

1.	Modify your program so it sorts any file of numbers.  (Trade roles every 10 minutes.)
*/


#include "stdafx.h"
#include <iostream> // for cout, cin
#include <fstream>  // for file I/O
#include <string>
#include <Windows.h>
#include <stdio.h>
using namespace std;

void swapInts(int& n1, int& n2);

int main()
{
	string s1;
	string fileName = "sortTemp", oldFileName;
	char fileNameSuffix = 'a';
	int n1, n2, passNumber = 1;
	ifstream inFile;
	ofstream outFile;
	bool notSorted = true;

	// Open an input file
	inFile.open("C:\\Users\\cmikk\\OneDrive\\School\\Fall 2017\\Computer Science 1\\fileInput\\unsorted.txt");
	// exit with error if open fails
	if (inFile.fail())
	{
		cout << "Original file open failed.\n";
		system("pause");
		exit(1);
	}

	while (notSorted) {
		notSorted = false;

		// Create output file
		outFile.open("C:\\Users\\cmikk\\OneDrive\\School\\Fall 2017\\Computer Science 1\\fileOutput\\" + fileName + fileNameSuffix + ".txt");
		// exit with error if open fails
		if (outFile.fail())
		{
			cout << "File out failed.\n";
			system("pause");
			exit(1);
		}

		cout << "Reading file pass " << passNumber++ << ":\n";
		Sleep(1000);
		// Get first number in file
		if (!(inFile >> n1))
		{
			cout << "No data in file.\n";
			system("pause");
			exit(1);
		}


		while (inFile >> n2)
		{
			if (n1 > n2)  // if the previous number is larger, swap
			{
				swapInts(n1, n2);
				notSorted = true;
			}
			outFile << n1 << endl;  // output previous number
			cout << n1 << " ";
			n1 = n2;  // set current number to previous
		}
		outFile << n1 << endl;  // write the last number
		cout << n1 << endl;

		outFile.close();
		inFile.close();

		if (notSorted)
		{
			// Open an input file
			inFile.open("C:\\Users\\cmikk\\OneDrive\\School\\Fall 2017\\Computer Science 1\\fileOutput\\" + fileName + fileNameSuffix + ".txt");
			// exit with error if open fails
			if (inFile.fail())
			{
				cout << "File open failed.\n";
				system("pause");
				exit(1);
			}


			// Increment output file suffix
			fileNameSuffix++;

		}

	}

	// display the sorted output
	cout << "The sorted output is: \n";
	// Open an input file
	inFile.open("C:\\Users\\cmikk\\OneDrive\\School\\Fall 2017\\Computer Science 1\\fileOutput\\" + fileName + fileNameSuffix + ".txt");
	// exit with error if open fails
	if (inFile.fail())
	{
		cout << "File open failed.\n";
		system("pause");
		exit(1);
	}
	while (inFile >> n1)
	{
		cout << n1 << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void swapInts(int& n1, int& n2)
{
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
	return;
}