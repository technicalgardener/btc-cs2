// lab02bwhileadder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int exitvalue = 0;
	int numberValue = 0;
	int numberEntered = 0;
	int totalValue = 0;


	cout << "                                   W E L C O M E    T O    B E E R    C O U N T E R" << endl;
	cout << "Give us the number of beers yeh 'ave guzzled or press \"0\" to yield. \n";

	do {
		cout << "\nCurrent number of beers quaffed: " << totalValue << endl;
		cout << "\n\nHow many you drank? ";
		cin >> numberEntered;
		totalValue += numberEntered;
		//numberValue++; not used but could be to limit number of entries made
		cout << endl;

	} while (numberEntered != 0); //,totalValue <= 999999999) - experimenting on eliminating numbers that would break program such as any number >= 10^10

	cout << "\n\n\n\n\n\n                    T O T A L    N U M B E R    O F    B E E R S    C O N S U M E D :    " << totalValue;
	if (totalValue < 15) {
		cout << "\n\n\n...The gods have deemed you weak." << endl << endl;

	}
	else if (totalValue <= 24) {
		cout << "\n\n\n...Your tenaciousness and intrepid spirit has won the favor of the gods." << endl << endl;
	}
	else if (totalValue > 24) {
		cout << "\n\n\n         ~~Congradulations, little one, you have the admiration of the gods and have won a seat at their table~~" << endl << endl;
	}


	system("pause");
	return 0;
}