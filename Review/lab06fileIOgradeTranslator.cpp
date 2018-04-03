// lab06fileIOgradeTranslator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int intSwitch(string& whole);

int main()
{
	int score = 0;
	string whole;
	bool isname = true;

	ifstream gradeScores;
	gradeScores.open("C:\\Users\\cmikk\\OneDrive\\School\\Fall 2017\\Computer Science 1\\fileInput\\gradeScores.txt");
	ofstream gradeComplete;
	gradeComplete.open("C:\\Users\\cmikk\\OneDrive\\School\\Fall 2017\\Computer Science 1\\fileOutput\\gradeComplete.txt");

	if (gradeScores.fail())
	{
		cout << "Input file open failed. \n";
		system("pause");
		exit(1);
	}
	if (gradeComplete.fail())
	{
		cout << "Output file open failed. \n";
		system("pause");
		exit(1);
	}

	while (gradeScores >> whole)
	{
		if (isname)
		{
			cout << whole << " ";
			gradeComplete << whole << "	";
			//system("pause");
		}
		else
		{
			int score = std::stoi(whole);
			cout << score;
			gradeComplete << score << " ";
			//system("pause");
			if (score <= 59) {
				gradeComplete << " F" << endl;
				cout << " F" << endl;
			}
			else if (score <= 69) {
				gradeComplete << " D" << endl;
				cout << " D" << endl;
			}
			else if (score <= 79) {
				gradeComplete << " C" << endl;
				cout << " C" << endl;
			}
			else if (score <= 89) {
				gradeComplete << " B" << endl;
				cout << " B" << endl;
			}
			else if (score <= 99) {
				gradeComplete << " A" << endl;
				cout << " A" << endl;
			}
			else if (score == 100) {
				gradeComplete << "A+" << endl;
				cout << " A+" << endl;
			}
		}
		isname = !isname;
	}

	gradeScores.close();
	gradeComplete.close();
	cout << endl << endl << endl;
	system("pause");
	return 0;
}

int intSwitch(string & whole)
{
	int score = std::stoi(whole);

	return 0;
}