// 62fileInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> // for cout, cin
#include <fstream>  // for file I/O
#include <string>
using namespace std;


int main()
{
	int s1;
	int even = 0, odd = 0;
	// build an input file
	ifstream inFile;

	// Open an input file
	inFile.open("C:\\Users\\cmikk\\OneDrive\\School\\Fall 2017\\Computer Science 1\\fileInput\\testInFile.txt");
	// exit with error if open fails
	if (inFile.fail())
	{
		cout << "File open failed.\n";
		system("pause");
		exit(1);
	}

	cout << "Using a while loop to read the whole file:\n";
	while (inFile >> s1)
	{
		if (s1 = even)
			even++;
		else
			odd++;

		//cout << s1;
		//cout << s1 << " ";
		cout << s1 << endl;
		cout << "even: " << even << "\tOdd: " << odd << endl;
	}
	system("pause");
	return 0;
}