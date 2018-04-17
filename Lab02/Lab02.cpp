// Lab02.cpp : Defines the entry point for the console application.
/*
Make a full suite of accessor and mutator functions that apply to your 3 member variables.  That's six functions in all.
Continue to have your rdVehicle() and wrtVehicle() member functions.  Change the rdVehicle so that it returns a boolean indicating whether it got a record.  
This will allow it to be used in a loop that can work on files of varying sizes.
Make 3 "constructor" functions.  One is the default, which sets VIN to "NULL", price to 0.0, and weeksOnLot to 0.  
Second accepts a single argument of VIN and uses above defaults for other two variables.  Third accepts VIN and price, using above default for weeksOnLot.
Make a program that implements a simple menu, as in the Comet example.  
You can cut/paste my main() routine and use it almost unchanged, simply providing your own regular functions to do the A, V, U, and X actions.
Make the (V) function.  Declare an object, loop and read disk records into object, writing each object to cout, until no more records.
Make the (A) function.  It accepts user input of VIN or VIN + price, calls appropriate constructor, opens the diskfile for appending, tacks the new vehicle onto the file.
Make the (U) function.  It opens two files.  Declares an object, reads records (until all are consumed), updates the weeksOnLot, writes updated object to second file.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/****************  Regular function prototypes ****************/
void viewDB();
void add2DB();
void updateWeeksOnLot();

const string diskFileRd = "vehicles.txt";
const string diskFileWrt = "aged_vehicles.txt";

class Vehicle
{
public:
	string rdVin();
	void wrtVin(string wVin);
	double rdPrice();
	void wrtPrice(double wPrice);
	int rdWeeksOnLot();
	void wrtWeeksOnLot(int wWol);

	Vehicle();
	Vehicle(string vin);
	Vehicle(string vin, double price);

	bool rdDBEntry(istream& stream);  // Disk DB record rd-wrt pair
	void wrtDBEntry(ostream& stream);
private:
	string vin;
	double price;
	int weeksOnLot;
};

int main()
{
	char menuChoice;  // Simple menu, easy to copy/paste for your lab
	do
	{
		cout << "\n\nMenu: (V)iew DB, (N)ew entry, (U)pdate, e(X)it program: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 'X': case 'x':
			cout << "Goodbye!\n";
			return (0);
		case 'V': case 'v':
			viewDB();
			break;
		case 'N': case 'n':
			add2DB();
			break;
		case 'U': case 'u':
			updateWeeksOnLot();
			break;
		default:
			cout << "Illegal choice.  Try again. \n";
		}
	} while (true);

	return 0;
}

/**********************************************************************/
// Here are paired MUTATOR and ACCESSOR for "name" private variable
string Vehicle::rdVin()
{
	return string(vin);
}

void Vehicle::wrtVin(string wVin)
{
	vin = wVin;
}

double Vehicle::rdPrice()
{
	return double(price);
}

void Vehicle::wrtPrice(double wPrice)
{
	price = wPrice;
}

int Vehicle::rdWeeksOnLot()
{
	return(weeksOnLot);
}

void Vehicle::wrtWeeksOnLot(int wWol)
{
	weeksOnLot = wWol;
}

/********** Constructors ********************************************/

Vehicle::Vehicle() : vin("?"), price(0.00), weeksOnLot(0) // Default constructor
{

}

Vehicle::Vehicle(string s)
{
	vin = s;
	price = 0.00;
	weeksOnLot = 0;
}

Vehicle::Vehicle(string s, double p)
{
	vin = s;
	price = p;
	weeksOnLot = 0;
}


/****** Our member functions that read and write DB entries ******************/

// A member function that populates a Vehicle object with values
// fetched from a Database file.  If object is fetched from file,
// returns TRUE, otherwise, when none left to fetch, returns FALSE
bool Vehicle::rdDBEntry(istream& stream)
{
	if (stream >> vin) // Evaluates TRUE if successful read of 1st field
	{
		stream >> price >> weeksOnLot; // Get other 2 fields
		return (true); // We GOT one!  Return TRUE
	}
	return (false); // Failed to get one from file.  Return FALSE
}

// A member function that writes the fields of a Vehicle object
// out to a Database file, tab separated, one vehicle per line.  Order
// of variables MUST match order in above rdDBEntry() function,
// as well as order in original Database.
void Vehicle::wrtDBEntry(ostream& stream)
{
	stream << vin << '\t' << price << '\t' << weeksOnLot << endl;
}


/**************  Regular functions, one to handle each menu choice ************/

void viewDB() // The (V)iew menu choice
{
	ifstream rdDB;
	Vehicle aVehcile;  // Default constructor -- NO PARENTHESES!! p.586
	rdDB.open(diskFileRd);
	while (aVehcile.rdDBEntry(rdDB) == true) // Loop until all entries read
		aVehcile.wrtDBEntry(cout);

	rdDB.close();
}

void add2DB() // The (N)ew menu choice.  Fetch data, build Vehicle, APPEND to DB file
{
	string vin;
	double price;
	int wol;
	char y_n;

	ofstream wrtDB;
	wrtDB.open(diskFileRd, ios::app); // Open DB file for WRITE/APPEND p. 321

	cout << "\nEnter Vehicle VIN number: " << endl;
	cin >> vin;
	cout << "Known vehicle price (Y/N)? ";
	cin >> y_n;

	if ((y_n != 'y') && (y_n != 'Y')) { // See top p. 345 re: this logic
		Vehicle newVehicle(vin);  // Constructor with 1 arg
		newVehicle.wrtDBEntry(wrtDB);
	}
	else {
		cout << "\nEnter Vehicle price: " << endl;
		cin >> price;
		Vehicle newVehicle(vin, price);  // Constructor with 2 args
		newVehicle.wrtDBEntry(wrtDB);
	}

	wrtDB.close();
}

void updateWeeksOnLot()
{
	int weeks;
	Vehicle aVehicle;  // A single local "vehicle" object we'll shuffle them through

	ifstream rdDB;  // Got to open TWO files, one to read, other to write
	ofstream wrtDB;
	rdDB.open(diskFileRd); // Again, YOU should check for file-open errors
	wrtDB.open(diskFileWrt);


	while (aVehicle.rdDBEntry(rdDB) == true) // Loop until all entries read
	{
		{
		
			weeks = aVehicle.rdWeeksOnLot();
			weeks++;
			aVehicle.wrtWeeksOnLot(weeks);
		}

		aVehicle.wrtDBEntry(wrtDB);
	}
	rdDB.close();
	wrtDB.close();
}

/* int main()
{
ifstream rdStream;
ofstream wrtStream;
string diskFile = "vehicles.txt";
string outFile = "agedvehicles.txt";

rdStream.open(diskFile);
if (rdStream.fail())
{
cout << "File open failed." << endl;
system("pause");
exit(1);
}

wrtStream.open(outFile);
if (wrtStream.fail())
{
cout << "Failed open for output: " << outFile << endl;
system("pause");
exit(1);
}

for (int ix = 0; ix < 5; ix++)
{
veh1.rdVehicle(rdStream);
ageInventory(veh1.rdWeeksOnLot());
veh1.wrtVehicle(cout);
veh1.wrtVehicle(wrtStream);
}

veh1.addVehicle(wrtStream);

rdStream.close();
wrtStream.close();
system("pause");
return 0;
} */

/*
void Vehicle::addVehicle(ostream & wrtS)
{
//Ask for input VIN and Price
//put those values into Vehicle
//write values to file




weeksOnLot = 0;
wrtS << vin << '\t' << price << '\t' << weeksOnLot << endl;
cout << vin << '\t' << price << '\t' << weeksOnLot << endl;

}

void Vehicle::rdVehicle(istream& rdS)
{
rdS >> vin >> price >> weeksOnLot;
}

void Vehicle::wrtVehicle(ostream& wrtS)
{
wrtS << vin << '\t' << price << '\t' << weeksOnLot << endl;
}

void ageInventory(int weeks)
{
weeks++;
veh1.wrtWeeksOnLot(weeks);

}
*/

