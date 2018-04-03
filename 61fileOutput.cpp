// 61fileOutput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> // for cout, cin
#include <fstream>  // for file I/O
#include <string>
using namespace std;


int main()
{
	string s1;

	// build an output file
	ofstream outFile;

	// create a file in a directory that is writable.  "\" must be coded as "\\" 
	outFile.open("C:\\Users\\cmikk\\OneDrive\\School\\Fall 2017\\Computer Science 1\\fileOutput\\fileOutputtestOutFile.txt");  // to overwrite
														  // outFile.open("c:\\Users\\mmassey\\testOutFile.txt", ios::app);  // to append
	if (outFile.fail())
	{
		cout << "File open failed.\n";
		system("pause");
		exit(1);
	}

	// Get input
	cout << "Enter words(q to quit): ";
	while (cin >> s1)
	{
		// Write data to the file
		if (s1 == "q")
		{
			break;
		}
		else
		{
			//outFile << s1;
			outFile << s1 << endl;
		}
	}
	outFile.close();

	system("pause");
	return 0;
}