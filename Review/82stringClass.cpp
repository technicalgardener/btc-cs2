// 82stringClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
/* The class string allows us to treat strings as a type instead of a char array. */
#include <string>
using namespace std;

int main()
{
	string s1 = "initial value", s2, s3;


	cout << "s1 is " << s1 << endl << endl;

	/* You can add to strings like other types. */
	s1 += " plus more stuff";
	cout << "s1 is " << s1 << endl << endl;

	/* You can get words from the standard input with cin. */
	cout << "Enter two words separated by a space: ";
	cin >> s1 >> s2;
	cout << "s1 is " << s1 << ", s2 is " << s2 << endl << endl;
	/* Mixing "cin >>"and getline is dangerours since cin leaves \n in the stream.*/
	/* cin.ignore(1000,'\n'); gobbles up the remaining characters up to and including the first \n.*/
	cin.ignore(1000, '\n');

	/* You can get lines from the standard input with getline. */
	cout << "Enter a line of text and press Enter:\n";
	getline(cin, s1);
	cout << "s1 is " << s1 << endl << endl;

	/* Other useful member functions or methods (since string is a class).*/
	cout << "The last 5 characters of s1 are: " << s1.substr(s1.length() - 5, 5) << endl;

	/*Array access to characters is still available.*/
	cout << "First ten characters of s1: ";
	for (int i = 0; i < 10; i++)
		cout << s1[i] << " ";
	cout << endl;


	system("pause");
	return 0;
}