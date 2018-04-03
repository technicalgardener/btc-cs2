// lab03doWhilenumberGuesser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	int numberToGuess, numberGuessed = 11, numberOfGuesses = 2;
	srand(time(NULL));
	numberToGuess = rand() % 10 + 1;
	//numberToGuess = 3;

	cout << "T H E    S I M P L Y    A M A Z I N G    N U M B E R    G U E S S E R" << endl;

	do 
	{
		cout << "\n\nGuess a number 1-10: ";
		cin >> numberGuessed;

		if (numberOfGuesses == 0) {
			cout << "\n\nToo bad you have failed" << endl << endl << endl;
			break;
		}
		if (numberGuessed == numberToGuess) {
			cout << "\n\nC O N G R A T S !! You did it!" << endl << endl;
			break;
		}


		if (numberGuessed > 10) {
			cout << "\nHEY! Stop trying to break the rules!! Try again...";
			numberOfGuesses--;
		}

		else if (numberGuessed > numberToGuess) {
			cout << "\nNope! Try lower...";
			numberOfGuesses--;
		}
		else if (numberGuessed < numberToGuess) {
			cout << "\nNope! Try higher...";
			numberOfGuesses--;
		}

	} while (numberGuessed != numberToGuess);


	// cout << numberToGuess << endl << numberGuessed << endl << numberOfGuesses << endl;

	system("pause");
	return 0;
}