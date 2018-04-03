// 81cstrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
/* C strings are arrays of characters with a null ('\0') at the end. */
/* The C string manipulation functions strcpy, strcmp and strlen are in the cstring library. */
#include <cstring>
using namespace std;


int main()
{
	/* Initializing a C string with a string is ok. [] just fits. */
	/*
	char s1[] = "initial value";
	*/
	char s1[24] = "initial value";
	char s2[24];
	int strSize;
	cout << s1 << endl;
	/* Assigning a C string directly with '=' is not ok. */
	/*
	s1 = "subsequent value";
	*/
	/* strcpy dangerous so strncpy safer but can still overflow */
	strncpy(s1, "subsequent value", 18);
	cout << s1 << endl;
	strSize = strlen(s1);
	cout << "s1 is " << strSize << " bytes long.\n";

	/* Comparing C strings is not obvious. */
	strncpy(s1, "apples", 24);
	strncpy(s2, "apples", 24);
	if (strcmp(s1, s2))
		cout << "strcmp " << s1 << " " << s2 << " returns true" << endl;
	else
		cout << "strcmp " << s1 << " " << s2 << " returns false" << endl;

	strncpy(s1, "apples", 24);
	strncpy(s2, "oranges", 24);
	if (strcmp(s1, s2))
		cout << "strcmp " << s1 << " " << s2 << " returns true" << endl;
	else
		cout << "strcmp " << s1 << " " << s2 << " returns false" << endl;

	system("pause");
	return 0;
}