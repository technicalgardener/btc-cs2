// lab02aifgradeTranslator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int score;

	cout << "If you give me the percentage of your last quiz, I will tell you your letter grade" << endl;
	cout << "What was your score? ";
	cin >> score;

	if (score <= 59) {
		cout << "Wow, your score really bumbs me out. You got an \"F\"" << endl;
	}
	else if (score <= 69) {
		cout << "Well, you avoided failure! You got a \"D\"" << endl;
	}
	else if (score <= 79) {
		cout << "Agressively mediocre, you got a \"C\"" << endl;
	}
	else if (score <= 89) {
		cout << "Okay, you got a \"B\"" << endl;
	}
	else if (score <= 99) {
		cout << "Nice work, you got a \"A\"" << endl;
	}
	else if (score == 100) {
		cout << "Get out..." << endl;
	}

	system("pause");
	return 0;
}