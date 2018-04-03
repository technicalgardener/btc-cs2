// lab01multiplier.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int number1, number2, number3, answer;

	cout << "Give me a number:" << endl;
	cin >> number1;
	cout << "Give me another number:" << endl;
	cin >> number2;
	cout << "Now give me a final number:" << endl;
	cin >> number3;

	cout << "If I multiply your first two numbers " << number1 << " and " << number2 << " and then add the third number " << number3 << " , that would equal: ";
	answer = (number1 * number2) + number3;
	cout << answer << endl;
	cout << endl;
	system("pause");
	return 0;
}

