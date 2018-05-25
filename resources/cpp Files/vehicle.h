#ifndef V_CLASS
#define V_CLASS

/* An interface definition file for our Vehicle class,
   from which a couple of other classes will be "derived"
   I've made the VIN format a bit different in this demo file,
   simply to eliminate clutter.  A VIN now has 5 letters at the
   front and 5 numbers at the rear, with "equality" of VINS
   being equality of just the 5 alpha characters.
*/

using std::string; 

/******* Our "Vehicle" class definition of old, with minor tweaks *************/

class Vehicle
{
public:
	void putVIN(string newVIN); // Accessor-mutator function pairs
	string getVIN();
	void putPrice(double p);
	double getPrice();
	void putWeeks(int w);
	int getWeeks();

	Vehicle();  // Couple of constructors
	Vehicle(string VIN, double p, int w);

	friend bool operator ==(const Vehicle& c1, const Vehicle& c2);
	friend void operator ++(Vehicle& c);

	void display1(char);

private:
//protected:	// This allows child class to access parent's private vars. p.850
	string baseVIN;  // Incorporating a simpler split-VIN implementation
	string extVIN;
	double price;
	int weeksOnLot;
};

#endif
