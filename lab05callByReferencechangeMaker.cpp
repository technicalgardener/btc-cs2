// lab05callByReferencechangeMaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int coinReturn(int& quarters, int& dimes, int& nickles, int& pennies);
double totalReturn(double& total);
string dialogue(string& question, string& answer, string& errorNonInt);
string multiplicity(string& q, string& d, string& n, string& p);

int main()
{
	double total;
	int quarters, dimes, nickles, pennies;

	string question, answer, errorNonInt;
	string q, d, n, p;

	coinReturn(quarters, dimes, nickles, pennies);
	dialogue(question, answer, errorNonInt);
	multiplicity(q, d, n, p);

	cout << question;
	cin >> total;
	while (cin.fail())
	{
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		cout << errorNonInt;
		cout << question << endl;
		cin >> total;
	}

	totalReturn(total);

	while (total >= 25) {
		total -= 25;
		quarters++;
	}
	while (total >= 10) {
		total -= 10;
		dimes++;
	}
	while (total >= 5) {
		total -= 5;
		nickles++;
	}
	while (total > 0) {
		total -= 1;
		pennies++;
	}

	if (quarters > 1) {

	}
	cout << endl << answer << endl;

	cout << endl << endl << endl;
	cout << "Total: " << total << endl << "Quarters: " << quarters << endl << "Dimes: " << dimes;
	cout << endl << "Nickles: " << nickles << endl << "Pennies: " << pennies << endl;
	cout << endl << endl << endl;
	system("pause");
	return 0;
}

int coinReturn(int & quarters, int & dimes, int & nickles, int & pennies)
{
	quarters = 0;
	dimes = 0;
	nickles = 0;
	pennies = 0;
	return 0;
}

string dialogue(string & question, string & answer, string & errorNonInt)
{
	question = "What is your change? ";
	answer = "This is the lowest amount of coin you could have: ";
	errorNonInt = "You can only enter numbers. Please re-enter your change: ";
	return string();
}

string multiplicity(string & q, string & d, string & n, string & p)
{
	q = "quarter";
	d = "dime";
	n = "nickle";
	p = "penny";
	return string();
}

double totalReturn(double & total)
{
	total *= 100;
	return 0.0;
}