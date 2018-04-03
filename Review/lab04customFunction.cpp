// lab04customFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
string chunk(int score);

int main()
{
	int score;

	do {
		cout << "What is your score? ";
		cin >> score;
		cout << chunk(score) << endl;
	} while (score != 0);

	cout << endl << endl;
	system("pause");
	return 0;
}

string chunk(int score)
{
	string D;
	D = "'D' Not Good Enough!";
	string C;
	C = "'C' Mediocre Attempt";
	string B;
	B = "A 'B' is Nothing to Brag About";
	string A;
	A = "Well Done, 'A'";
	string S;
	S = "Get Out...";
	string P;
	P = "";

	if (score == 0) {
		return P;
	}
	else if (score <= 59) {
		return "You Fool! You got an 'F'";
	}
	else if (score <= 69) {
		return D;
	}
	else if (score <= 79) {
		return C;
	}
	else if (score <= 89) {
		return B;
	}
	else if (score <= 99) {
		return A;
	}
	else if (score == 100) {
		return S;
	}

}