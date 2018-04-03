// 91pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	/* A couple of variables. */
	int num1 = 111, num2 = 222;
	/* A couple of pointers to ints. */
	int *p1, *p2;

	cout << "num1 is " << num1 << endl;
	cout << "num2 is " << num2 << endl;

	/* &variable give the address of a variable. */
	cout << "&num1 is " << &num1 << endl;
	cout << "&num2 is " << &num2 << endl;

	/* Pointers contain addresses. sets the adress in p1 to the address for num1 */
	p1 = &num1;
	cout << "p1 is " << p1 << endl;

	/* *pointer returns the value (some say the variable), *  is the dereferencing operator */
	cout << "*p1 is " << *p1 << endl;

	/* *pointer works just like the variable it points to, access the value of the memory location */
	*p1 = 333;
	cout << "After *p1=333,, num1 is " << num1 << endl;

	/* Dynamic variables can be created with pointers. */
	/* (usually a bad idea, just use local scopes) */
	p1 = new int;
	cout << "After p1= new int, p1 is " << p1 << endl;
	cout << "After p1= new int, *p1 is " << *p1 << endl;
	*p1 = 444;
	cout << "After *p1=444,, *p1 is " << *p1 << endl;
	cout << "num1 is " << num1 << " because p1 no longer points to it." << endl;
	system("pause");

	/* You need to manually destroy the variable when done with delete. */
	/* p1 still exists, the dynamic variable it pointed to is destroyed, memory freed. */
	delete p1;
	/*
	cout << "After delete p1, *p1 is " << *p1 << endl;
	*/
	p1 = &num2;
	cout << "After delete p1, *p1=&num2, *p1 is " << *p1 << endl;
	system("pause");
	*p1 += 5;
	cout << *p1 << endl;

	system("pause");
	return 0;
}