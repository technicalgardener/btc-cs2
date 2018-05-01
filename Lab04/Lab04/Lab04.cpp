// Lab04.cpp
// Author: Charles Mikkelborg, Brett Turner
// Description: Reads an input file to poplulate a class object in an array that can be output to the console and a file.
//		Includes functionality to view the database, enter a new vehicle, update how many weeks a car has been the lot,
//		and search by VIN number.
// Last modified: 04/25/2018
/*
Part 1.  Modify your existing code to deal with the option-package lines, making use of a private dynamic string[ ] array variable.  
Make necessary changes to all constructors.  Eliminate your existing rdDBEntry() and wrtDBEntry() functions, 
and instead provide functions that overload the << and  >> operators.  
The overloaded operator should be capable of dealing with an entire Vehicle object at once -- i.e., ">>"  reads in all normal fields, 
notices whether optional lines are there, builds dynamic storage as needed, populates the storage.  
The operators should work with either the console stream or a file stream.  
The operators should then be used elsewhere in your code (like the viewDB() menu-handler, the file I/O operations, etc.)   
You do NOT need to change your (N)ew vehicle handler to support the action of specifying additional options for a new vehicle.  
Finally, write a "destructor" function that releases an object's dynamic storage back to the freestore.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

/******* Our only globals are CONST variables  **************/
const string diskFileRd = "xvehicles_db.txt";
const int VA_SIZE = 10;


/****************  Member functions  *****************/
class Vehicle
{
public:
	/* Mutator and Accessor declarations */
	//string rdVin();
	void wrtVin(string wVin);
	//double rdPrice();
	void wrtPrice(double wPrice);
	//int rdWeeksOnLot();
	//void wrtWeeksOnLot(int wWol);
	void vinBreaker(string& wVin);
	string wholeVin();

	/* Constructor declarations */
	Vehicle();
	Vehicle(string vin);

	/* Destructor declarations */
	~Vehicle();

	friend ostream& operator << (ostream& outS, const Vehicle& v);
	friend istream& operator >> (istream& inS, Vehicle& v);

	//bool rdDBEntry(istream& stream);  // Disk DB record rd-wrt pair
	//void wrtDBEntry(ostream& stream);

	/* Helper functions */
	friend void operator ++(Vehicle& v);
	friend bool operator ==(const Vehicle& v1, const Vehicle& v2);

private:
	void makeUC(string& s);	// A private make uppercase function
	string v1 = "";
	string vin;
	string v3 = "";
	double price;
	int weeksOnLot;
	int listSize = 0;
	string * listPtr = NULL;
};

/****************  Regular functions  ***************/
void viewDB(Vehicle V[], int size);
int add2DB(Vehicle V[], int size);
void updateWeeksOnLot(Vehicle V[], int size);
void search4Vehicle(Vehicle V[], int size);

int main()
{
	ifstream rdDB;
	ofstream wrtDB;
	Vehicle VA[VA_SIZE];
	int vaSize = 0;

	// Opens vehicle.txt and populates vehicle class objects.
	// class objects are then put into an array.
	rdDB.open(diskFileRd);
	if (rdDB.fail())
	{
		cout << "Open File Error";
		exit(1);
	}

	while (rdDB >> VA[vaSize])
	{
		if (++vaSize >= VA_SIZE)
		{
			cout << "Array full! Skipping remaining DB entries.";
			break;
		}
	}
	rdDB.close();

	/* Menu */
	char menuChoice;
	do
	{
		cout << "\n\nMenu: (V)iew DB, (N)ew entry, (U)pdate, (S)earch, e(X)it program: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 'X': case 'x':
			// writes changes made to the array to file on exit.
			cout << "Goodbye!\n";
			//wrtDB.open(diskFileRd);
			//for (int ix = 0; ix < vaSize; ix++)
			//	wrtDB << VA[ix];
			//wrtDB.close();
			return(0);
		case 'V': case 'v':
			viewDB(VA, vaSize);
			break;
		case 'N': case 'n':
			// add new vehicle
			if (vaSize < VA_SIZE)
				vaSize = add2DB(VA, vaSize);
			else
				cout << "Can't add a vehicle! Array already full.";

			break;
		case 'U': case 'u':
			updateWeeksOnLot(VA, vaSize);
			break;
		case 'S': case 's':
			search4Vehicle(VA, vaSize);
			break;
		default:
			cout << "Illegal choice.  Try again. \n";
		}
	} while (true);

	return 0;
}

/************* "Friend" functions and operator overload ***************/
void operator ++(Vehicle& v) // Operator overload function to update "weeksOnLot" by one.
{
	v.weeksOnLot = v.weeksOnLot++;
}

bool operator==(const Vehicle & v1, const Vehicle & v2) // Operator overload function to compare two vins.
{
	return (v1.vin == v2.vin);
}

/**********************************************************************/
// Here are paired MUTATOR and ACCESSOR functions for private Vehicle variables

/*
string Vehicle::rdVin()		// Accessor to read private variable "vin"
{
	return string(wholeVin());
}
*/

void Vehicle::wrtVin(string wVin)		// Mutator to change private variable "vin"
{
	makeUC(wVin);		// Assure UC vin through "helper" function
	vinBreaker(wVin);
}

/*
double Vehicle::rdPrice()		// Accessor to read private variable "price"
{
	return double(price);
}
*/

void Vehicle::wrtPrice(double wPrice)		// Mutator to change private variable "price"
{
	price = wPrice;
}

/*
int Vehicle::rdWeeksOnLot()		// Accessor to read private variable "weeksOnLot"
{
	return(weeksOnLot);
}
*/

/*
void Vehicle::wrtWeeksOnLot(int wWol)		// Mutator to change private variable "weeksOnLot"
{
	weeksOnLot = wWol;
}
*/

void Vehicle::vinBreaker(string& wVin) // Mutator to break down a given vin number into 3 parts
{
	cout << endl << "--------> " << wVin << endl;
	v1 = wVin.substr(0, 1);
	v3 = wVin.substr(4, 5);
	vin = wVin.substr(1, 3);
	
}

string Vehicle::wholeVin() // Accessor function that retreives all parts of a vin and returns them as a single string
{
	return (v1 + vin + v3);
}

/**********************************************************************/
// Here are CONSTRUCTOR definitions
Vehicle::Vehicle() : vin("?"), price(0.00), weeksOnLot(0) // Default constructor
{
	cout << "+";
	listSize = 0;
	listPtr = NULL;
}

Vehicle::Vehicle(string s) // Constructor with vin field
{
	makeUC(s);	// UC vin through "helper" function
	vin = s;
	price = 0.00;
	weeksOnLot = 0;
}

/**********************************************************************/
// Here are DESTRUCTOR definitions
Vehicle::~Vehicle()
{
	cout << "-";
	if (listPtr != NULL)
		delete[] listPtr;
	listPtr = NULL;
	listSize = 0;
}

/****** Our member functions that read and write DB entries ******************/
// A member function that populates a Vehicle object with values
// fetched from a Database file.  If object is fetched from file,
// returns TRUE, otherwise, when none left to fetch, returns FALSE

/*
bool Vehicle::rdDBEntry(istream& stream)
{
	string bVin;
	// Set a fixed double decimal amount to 2 places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	if (stream >> bVin) // Evaluates TRUE if successful read of 1st field
	{
		makeUC(bVin);
		vinBreaker(bVin);
		stream >> price >> weeksOnLot; // Get other 2 fields
		return (true);
	}
	return (false);
}
*/

// A member function that writes the fields of a Vehicle object
// out to the console or a Database file, tab separated, one vehicle per line.
/*
void Vehicle::wrtDBEntry(ostream& stream)
{
	/* Set a fixed double decimal amount to 2 places *//*
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	stream << wholeVin() << '\t' << price << '\t' << weeksOnLot << endl;
}
*/

/********************* Private "helper" functions ***********************/
// Function to convert all letters in string to Upper Case.
void Vehicle::makeUC(string& s) // class function to make characters upper case
{
	char * cL = &s[0]; // Pointer to first char
	char * cR = &s[s.length()]; // Pointer BEYOND end of string

	for (; cL < cR; cL++) // Examine each char, in turn
		if (isalpha(*cL))
			*cL = toupper(*cL);
}

/**************  Regular functions, one to handle each menu choice ************/
// Displays a list of vehicles that are in the database
void viewDB(Vehicle V[], int size) // The (V)iew menu choice
{
	for (int i = 0; i < size; i++)
		cout << V[i];
}

// Lets the user input a vehicle to be added to the database
int add2DB(Vehicle dbVehicle[], int aSize) // The (N)ew menu choice.  Fetch data, build Vehicle, APPEND to DB file
{
	string bVin;
	double price;
	char y_n;

	cout << "\nEnter Vehicle VIN number: " << endl;
	cin >> bVin;
	cout << "Known vehicle price (Y/N)? ";
	cin >> y_n;

	if ((y_n != 'y') && (y_n != 'Y')) { // if 'y' or 'Y' are entered then ask for price
		dbVehicle[aSize].wrtVin(bVin);
		return(aSize + 1);
	}
	else {
		cout << "\nEnter Vehicle price: " << endl;
		cin >> price;
		dbVehicle[aSize].wrtVin(bVin);
		dbVehicle[aSize].wrtPrice(price);
		return(aSize + 1);
	}
}

// Increments the number of weeks a vehicle has been on the lot by 1, writes the updated database to a new file
void updateWeeksOnLot(Vehicle dbVehicle[], int aSize) // Mutator that updates weeksOnLot for all objects in an array
{
	for (int ix = 0; ix < aSize; ix++)
		++dbVehicle[ix];
}

// User can search the vehicle database by entering three uppercase letters that are in the vehicles vin
// If a vin with those letters is found information about that vehicle is displayed
void search4Vehicle(Vehicle V[], int size)	// Choice to (S)earch for vehicle in DB.
{
	string bVin;
	bool notFound = true;  // Assume it's NOT there...

	cout << "Enter the first 3 capital letters of the vehicle's vin: ";
	cin >> bVin;

	Vehicle search4(bVin);		// Local object to hold disk DB entries			


	for (int i = 0; i < size; i++)
	{
		if (V[i] == search4) // Loop until all entries read
		{
			cout << "Found! >> ";
			cout << V[i];
			notFound = false;  // Now will skip failure msg. below
		}
	}
	if (notFound)  // Failure message
		cout << "Vehicle \"" << bVin << "\" not in DB.";
}

ostream& operator << (ostream& outS, const Vehicle& v)
{
	outS << v.v1 + "-" + v.vin + "-" + v.v3 << '\t' << v.price << '\t' << v.weeksOnLot << '\t' << v.listSize << endl;
	if (v.listSize > 0)
	{
		string * sPtr = v.listPtr;
		for (int ix = 0; ix < v.listSize; ix++)
		{
			outS << *sPtr << endl;
			sPtr++;
		}		
	} return(outS);
}

istream& operator >> (istream& inS, Vehicle& v)
{
	string bVin;
	v.vin[0] = '?';
	inS >> v.vin;
	if (v.vin[0] != '?')
	{
		v.vinBreaker(v.vin);
		inS >> v.price >> v.weeksOnLot >> v.listSize;
		inS.get();
		if (v.listSize > 0)
		{
			v.listPtr = new string[v.listSize];
			string * sPtr = v.listPtr;
			for (int ix = 0; ix < v.listSize; ix++)
			{
				getline(inS, *sPtr);
				sPtr++;
			}
		}
	}
	return(inS);
}