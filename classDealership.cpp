// classDealership.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle
{
public:
	void rdVehicle(istream& rdS);
	void wrtVehicle(ostream& wrtS);
	string rdVin();
	void wrtVin(string vin);
	double rdPrice();
	void wrtPrice(double price);
	int rdWeeksOnLot();
	void wrtWeeksOnLot(int weeksOnLot);
private:
	string vin;
	double price;
	int weeksOnLot;
};

// ageOfInventory function

int main()
{
	Vehicle veh1;
	ifstream rdStream;
	string diskFile = "C:\\Users\\cmikk\\OneDrive\\School\\Q3 - Spring 2018\\Computer Science 2\\assets\\vehicles.txt";
	rdStream.open(diskFile);

	if (rdStream.fail())
	{
		cout << "File open failed." << endl;
		system("pause");
		exit(1);
	}
	for (int ix = 0; ix < 5; ix++)
	{
		veh1.rdVehicle(rdStream);
		veh1.wrtVehicle(cout);
	}
	
    return 0;
}

void Vehicle::rdVehicle(istream & rdS)
{
	rdS >> vin >> price >> weeksOnLot;
}

void Vehicle::wrtVehicle(ostream & wrtS)
{
	wrtS << vin << '\t' << price << '\t' << weeksOnLot << endl;
}

string Vehicle::rdVin()
{
	return string(vin);
}

void Vehicle::wrtVin(string s)
{
	 vin = s;
}

double Vehicle::rdPrice()
{
	return double(price);
}

void Vehicle::wrtPrice(double p)
{
	price = p;
}

int Vehicle::rdWeeksOnLot()
{
	return int(weeksOnLot);
}

void Vehicle::wrtWeeksOnLot(int wol)
{
	weeksOnLot = wol;
}
