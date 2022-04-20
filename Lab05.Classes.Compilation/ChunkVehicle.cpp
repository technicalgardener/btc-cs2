#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "ChunkVehicle.h"
using namespace std;


/**********************************************************************/
// CONSTRUCTOR definitions
Vehicle::Vehicle() : v1(""), vin("?"), v3(""), price(0.00), weeksOnLot(0), listSize(0) // Default constructor, all variables set to their default values.
{
	listPtr = NULL;
}

Vehicle::Vehicle(string s) // Constructor that takes in a vin to be used in the function search4Vehicle()
{
	makeUC(s);	// Changes the string into uppercase letters.
	v1 = "";
	vin = s;	// sets the value of vin equal to the passed string.
	v3 = "";
	price = 0.00;
	weeksOnLot = 0;
	listSize = 0;
}


/**********************************************************************/
// Here are DESTRUCTOR definitions
Vehicle::~Vehicle()
{
	if (listPtr != NULL) // if listPtr is pointing to an object, then delete the object. 
		delete[] listPtr;
	listPtr = NULL; // set pointer and size (number of vehicle options) to default state
	listSize = 0;
}


/**********************************************************************/
// MUTATOR and ACCESSOR definitions
void Vehicle::wrtVin(string wVin)		// Mutator that takes in a whole vin, makes it uppercase, and calls vinBreaker() to split it into the 3 variables: 'v1', 'vin', and 'v3'.
{
	makeUC(wVin);	// Makes string upper case.
	vinBreaker(wVin);	// splits up the whole vin string.
}

void Vehicle::wrtPrice(double wPrice)		// // Mutator that makes a change to the variable 'price'.
{
	price = wPrice;
}


/**********************************************************************/
// OVERLOADED HELPER definitions
void operator ++(Vehicle& v) // Overloads the operator '++' and allows to update weeksOnLot variable by one.
{
	v.weeksOnLot = v.weeksOnLot++;
}

bool operator==(const Vehicle & v1, const Vehicle & v2) // Overloads '==' to set the variable vin of one object equal to the vin of another object.
{
	return (v1.vin == v2.vin);
}

ostream& operator << (ostream& outS, const Vehicle& v) // Overloads '<<' to read an objects variables and sends them to an a chosen output stream.
{
	outS << v.v1 + v.vin + v.v3 << '\t' << v.price << '\t' << v.weeksOnLot << '\t' << v.listSize << endl; // Sends a Vehicles whole vin, price, and number of weeks on lot, and number of options to an output stream
	if (v.listSize > 0) // If there are Vehicle options, then make sure the additional lines for each option are retrieved and sent to the out stream as well.
	{
		string * sPtr = v.listPtr; // find the object that the Vehicle object's list pointer is pointing.
		for (int ix = 0; ix < v.listSize; ix++) // Grab a number of lines equal to the value of listSize.
		{
			outS << *sPtr << endl; // send each line to the out stream.
			sPtr++;
		}

	}
	return(outS); // return the stream for output use
}

istream& operator >> (istream& inS, Vehicle& v)	// Overloads '>>' to write variables to an object from an input stream.
{
	v.vin[0] = '?'; // Sets the first character of the vin variable to '?'
	inS >> v.vin; // Writes in an new value of vin (if there is one retrieved).
	if (v.vin[0] != '?') // checks to see if there is something inputed into vin from above, if there is, then continue to fill object, if not stop.
	{
		v.vinBreaker(v.vin);
		inS >> v.price >> v.weeksOnLot >> v.listSize;
		inS.get();
		if (v.listSize > 0) // Checks to see if there is any additional lines belonging to the Vehicle defined by listSize, if there are, then continue.
		{
			v.listPtr = new string[v.listSize]; // creates a new dynamic array for the additional lines equal in size of listSize.
			string * sPtr = v.listPtr; // creates a pointer to the first spot in the new array.
			for (int ix = 0; ix < v.listSize; ix++) // runs for the number of times as listSize value.
			{
				getline(inS, *sPtr); // Grabs one line for the stream and and stores it.
				sPtr++; // Updates the pointer to point to the next spot in the array.
			}
		}
	}
	return(inS); // return the stream for input use
}


/**********************************************************************/
// COPY definitions
Vehicle::Vehicle(const Vehicle &original) // Creates an independent copy of the dynamic array within the object
{
	listSize = original.listSize; // Sets the listSize of a Vehicle equal to the original.

	listPtr = new string[listSize];  // Creates a pointer to a new dynamic array based on the new value of listSize.
	for (int ix = 0; ix < listSize; ix++) // Run for the value of listSize.
		listPtr[ix] = original.listPtr[ix]; // Set each each value of the new dynamic array equal to the one of the original.
}

void Vehicle::operator =(const Vehicle& rightSide) // Overloads '=' assignment operator to copy entire object to another independent object.
{
	if (listPtr != NULL)  // If dynamic storage in use on left side, then delete it.
		delete[] listPtr;

	listSize = rightSide.listSize;  // Sets the listSize of the left Vehicle equal to the original on the right.
	listPtr = new string[listSize]; // Creates a pointer to a new dynamic array based on the new value of listSize.
	v1 = rightSide.v1;              // all other variables are copied to create a exact copy.
	vin = rightSide.vin;
	v3 = rightSide.v3;
	price = rightSide.price;
	weeksOnLot = rightSide.weeksOnLot;
	listSize = rightSide.listSize;
	for (int ix = 0; ix < listSize; ix++) // Set each each value of the new dynamic array on the left equal to the one of the original on the right.
		listPtr[ix] = rightSide.listPtr[ix];

}

/**********************************************************************/
// PRIVATE HELPER definitions
void Vehicle::makeUC(string& s) // Private function to convert a given string into uppercase letters.
{
	char * cL = &s[0]; // Pointer to first char
	char * cR = &s[s.length()]; // Pointer to just beyond the string.

	for (; cL < cR; cL++) // Examine each char, in turn.
		if (isalpha(*cL)) // Continue if the char is a letter.
			*cL = toupper(*cL); // take the char and change it into a capital letter.
}

void Vehicle::vinBreaker(string& wVin) // Private Mutator that takes in one string vin and splits it among the three variables: v1, v2, and v3.
{
	v1 = wVin.substr(0, 1);
	v3 = wVin.substr(4, 5);
	vin = wVin.substr(1, 3);

}
