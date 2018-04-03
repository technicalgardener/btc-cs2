// 52callByReferenceSortExercise.cpp : Defines the entry point for the console application.
//
/*
Guided Inquiry Activities Paired with the Programming Example
Paired programming session with students trading driver and navigator roles at each step.
1.	Write a program that gets a word from a user and puts it into a variable.

2.	Add output to confirm the word.

3.	Get a second word from the user into a second variable.

4.	Swap the contents of the two variables.  (This step may give them trouble since they need a third temporary variable to complete the swap of values.Have them experiment and ask focusing questions if needed.Use the example of two people standing on rocks in a stream wanting to trade places.How do they do it ? With a third rock.)

5.	Replace the swapping code in main with a call by reference function and function call that does the same thing.  (This step uses the elemental concept of call by reference functions previously learned in class.)

6.	Test the variables and only swap them if the contents of the first variable is larger than the contents of the second variable.

7.	Add a third variable.Swap the first two if the first variable is larger and then swap the second and third if the second variable is larger.

8.	Add a fourth variable, continuing to swap pairs of adjacent variables if the first one is larger than the second in any given pair, working your way through the variables in order.

9.	Put your testing and swapping code in a while loop, repeating the loop until the contents of all four variables are in ascending order.

10.	Output your variables after each series of swaps.Can you see how the largest value bubbles to the top ? Congratulations, you have created a bubble sort!
*/


#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void getFiveWords(string& w1, string& w2, string& w3, string& w4, string& w5);

void sortFiveWords(string& w1, string& w2, string& w3, string& w4, string& w5);

void swapWords(string& w1, string& w2);

int main()
{
	string word1, word2, word3, word4, word5;

	getFiveWords(word1, word2, word3, word4, word5);

	sortFiveWords(word1, word2, word3, word4, word5);

	cout << "The five words in sorted order are:\n";
	cout << word1 << " " << word2 << " " << word3;
	cout << " " << word4 << " " << word5 << endl;
	system("pause");
	return 0;
}

void getFiveWords(string& w1, string& w2, string& w3, string& w4, string& w5)
{
	cout << "Enter 5 words separated by spaces: ";
	cin >> w1 >> w2 >> w3 >> w4 >> w5;
	return;
}

void sortFiveWords(string& w1, string& w2, string& w3, string& w4, string& w5)
{
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		if (w1 > w2)
		{
			sorted = false;
			swapWords(w1, w2);

		}

		if (w2 > w3)
		{
			sorted = false;
			swapWords(w2, w3);

		}
		if (w3 > w4)
		{
			sorted = false;
			swapWords(w3, w4);

		}
		if (w4 > w5)
		{
			sorted = false;
			swapWords(w4, w5);

		}
	}
	return;
}

void swapWords(string& w1, string& w2)
{
	string temp;
	temp = w1;
	w1 = w2;
	w2 = temp;
	return;
}