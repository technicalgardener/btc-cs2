// 72sortArrayActivity.cpp : Defines the entry point for the console application.
//
/*
Sort Array Inquiry Activity
1.	Create a new program and declare an array of 5 integers.
2.	Assign a value to element 0 of your array.
3.	Display element 0 of your array.
4.	Initialize your array with test data.
5.	Write a for loop that displays your array.
6.	Write or copy in a call-by-reference function that swaps two integers.
7.	Use the function to swap elements 0 and 1;
8.	Write a for loop that walks through the array, swapping adjacent elements if they are out of order.
9.	Put the swapping for loop inside a while loop so the for loop repeats until the array is in order.
10.	Output the sorted array.
11.	Write a for loop that fills the array from user input.
12.	Allow the user to enter as many numbers as they want up to 25.
*/

#include "stdafx.h"
#include <iostream> // for cout, cin
#include <string>
#include <Windows.h>
using namespace std;

void showArray(int a[], int size);
void swapInts(int& n1, int& n2);

int main()
{
	const int MAX_SIZE = 25;
	int nums[MAX_SIZE], i = 0, size, n1, n2, passNumber = 1;
	bool sorted = false;

	cout << "Enter up to " << MAX_SIZE << " numbers separated by spaces or lines, -99 to quit: ";
	while (cin >> nums[i])
	{
		if (nums[i] == -99)
		{
			size = i;
			break;
		}
		else
			i++;
	}


	while (!sorted) {
		sorted = true;

		cout << "Reading array pass " << passNumber++ << ":\n";
		Sleep(1000);

		for (int i = 1; i < size; i++)  // walk through the array to sort
		{
			if (nums[i - 1] > nums[i])  // if the previous number is larger, swap
			{
				swapInts(nums[i - 1], nums[i]);
				sorted = false;
			}
		}
		// show progress
		showArray(nums, size);
	}

	cout << "The sorted numbers are:\n";
	showArray(nums, size);

	system("pause");
	return 0;
}

void showArray(int a[], int size)
{
	// display the array
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;


}

void swapInts(int& n1, int& n2)
{
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
	return;
}