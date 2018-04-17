// Lab02.cpp : Defines the entry point for the console application.
// classes on p. 483

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle
{
public:
	void addVehicle(ostream& wrtS);
	void rdVehicle(istream& rdS);
	void wrtVehicle(ostream& wrtS);
	string rdVin();
	void wrtVin(string wVin);
	double rdPrice();
	void wrtPrice(double wPrice);
	int rdWeeksOnLot();
	void wrtWeeksOnLot(int wWol);
private:
	string vin;
	double price;
	int weeksOnLot;
};

Vehicle veh1;
void ageInventory(int weeks);
void viewDB(istream& rdS);

int main()
{
	char menuChoice;
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

	do
	{
		cout << "\n\nMenu: (V)iew DB, (N)ew entry, (U)pdate week, (F)ind vin, e(X)it program: ";
		cin >> menuChoice;
		switch (menuChoice)
		{
		case 'X': case 'x':
			cout << "Goodbye!\n";
			system("pause");
			return (0);
		case 'V': case 'v':
			viewDB(rdStream);
			break;
		case 'N': case 'n':
			veh1.addVehicle(wrtStream);
			break;
		case 'U': case 'u':
			for (int ix = 0; ix < 5; ix++)
			{
				veh1.rdVehicle(rdStream);
				ageInventory(veh1.rdWeeksOnLot());
				veh1.wrtVehicle(cout);
			}
			break;
		default:
			cout << "Illegal choice.  Try again. \n";
		}
	} while (true);
	/*
	for (int ix = 0; ix < 5; ix++)
	{
	veh1.rdVehicle(rdStream);
	ageInventory(veh1.rdWeeksOnLot());
	veh1.wrtVehicle(cout);
	veh1.wrtVehicle(wrtStream);
	}
	*/
	rdStream.close();
	wrtStream.close();
	system("pause");
	return 0;
}

void ageInventory(int weeks)
{
	weeks++;
	veh1.wrtWeeksOnLot(weeks);

}


void viewDB(istream& rdS)
{
	for (int ix = 0; ix < 5; ix++)
	{
		veh1.rdVehicle(rdS);
		veh1.wrtVehicle(cout);
	}
}

void Vehicle::addVehicle(ostream & wrtS)
{
	cout << "Enter Vehicle VIN number: " << endl;
	cin >> vin;
	cout << "Enter Vehicle price: " << endl;
	cin >> price;
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
