// Lab02.cpp : Defines the entry point for the console application.
//

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

int main()
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
}

void ageInventory(int weeks)
{
	weeks++;
	veh1.wrtWeeksOnLot(weeks);

}

void Vehicle::addVehicle(ostream & wrtS)
{
	//Ask for input VIN and Price
	//put those values into Vehicle
	//write values to file
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
