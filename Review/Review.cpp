// Review.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// define string to assign variables to whole text
	string greeting;
	greeting = "Hark";
	// int - whole numbers, double - decimal
	int reset;
	int count = 10;
	double sum;

	cin >> sum;

	count = count + 1;
	count = 2 * count;
	count = count / sum;

	cout << greeting << " " << count << endl;

	count = -1;
	reset = count;
	// do while - will run the loop before checking while - so that it is run at least once
	do {
		cout << count-- << endl;
	} while (count > 0);

	count = reset;


	// while - will run only if condition is true
	while (count > 0) {
		cout << count-- << endl;
	}


	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}

	system("pause");
    return 0;
}

