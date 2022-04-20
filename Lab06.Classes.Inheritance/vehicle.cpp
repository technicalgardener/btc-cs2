/* Vehicle class implementation file.  vehicle.h is the interface file */

#include "stdafx.h"
#include <iostream>
#include <string>
#include "vehicle.h"
using namespace std;

/****** VEHICLE MUTATORS, ACCESSORS, CONSTRUCTORS, etc. ***************/

void Vehicle::putVIN(string newVIN)   // Pair for the "VIN" variable
{
	baseVIN = newVIN.substr(0, 5);  // 2-part split-VIN
	extVIN = newVIN.substr(5, 5);
}

string Vehicle::getVIN()
{
	return(baseVIN + extVIN);  // Put halves together to export to caller
}

void Vehicle::putPrice(double p)  // Function pair for "price" 
{
	price = p;
}

double Vehicle::getPrice()
{
	return(price);
}

void Vehicle::putWeeks(int w)  // Pair for weeksOnLot
{
	weeksOnLot = w;
}

int Vehicle::getWeeks()
{
	return(weeksOnLot);
}

Vehicle::Vehicle()  // Default constructor
{
	baseVIN = "?";
	extVIN = "";
	price = 0.0;
	weeksOnLot = 0;
}

Vehicle::Vehicle(string v, double p, int w)  // 3-arg constructor
{
	baseVIN = v.substr(0, 5);  // Splits the VIN
	extVIN = v.substr(5, 5);
	price = p;
	weeksOnLot = w;
}

bool operator == (const Vehicle& c1, const Vehicle& c2) // Overload ==
{
	return (c1.baseVIN == c2.baseVIN);
}

void operator ++(Vehicle& c)  // Overload ++
{
	c.weeksOnLot += 1;
}

/******  A function we'll use as example of "redefining" ************/

void Vehicle::display1(char vType)
{
	cout << endl << vType << ": " << baseVIN + extVIN << '\t' << price
		<< '\t' << weeksOnLot;
}

void Vehicle::discountPrice()
{
}

