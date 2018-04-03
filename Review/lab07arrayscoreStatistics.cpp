// lab07arrayscoreStatistics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void showArray(int a[], int size);

int main()
{
	const int MAX_SIZE = 25;
	int scores[MAX_SIZE], i = 0, totalEntered = 0, size, temp, min = 100, max = 0, average;

	cout << "Enter up to " << MAX_SIZE << " scores separated by spaces or lines, -1 to quit:" << endl;
	while (cin >> temp)
	{
		if (temp == -1 || i >= MAX_SIZE)
		{
			size = i;
			break;
		}
		else if (min > temp) {
			min = temp;
		}
		else if (max < temp) {
			max = temp;
		}
		scores[i] = temp;
		totalEntered += scores[i];
		i++;
	}

	average = totalEntered / i;
	system("pause");

	cout << endl;
	cout << "the contents of your array are:" << endl;
	showArray(scores, i);
	cout << endl;
	cout << "i is: " << i << endl;
	cout << "MAX_SIZE is: " << MAX_SIZE << endl;
	cout << "totalEntered is: " << totalEntered << endl;

	system("pause");

	cout << endl << "  STATISTICS  " << endl;
	cout << "The total value of all scores is: " << totalEntered << endl;
	cout << "The average score is: " << average << endl;
	cout << "The maximum score is: " << max << endl;
	cout << "The minimum score is: " << min << endl;


	system("pause");
	return 0;
}

void showArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}