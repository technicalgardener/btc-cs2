// 63charIO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char c1;
	cout << "Enter anything on a line and I will echo it: \n";
	do
	{
		cin.get(c1);
		cout.put(c1);
	} while (c1 != '\n');

	cout << "Enter numbers on a line and I will echo them: \n";
	do
	{
		cin.get(c1);

		if (c1 >= '0' && c1 <= '9')
			// if (isdigit(c1))
		{
			cout.put(c1);
		}

	} while (c1 != '\n');

	cout.put('\n');


	system("pause");
	return 0;
}