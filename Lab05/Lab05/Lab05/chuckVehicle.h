#ifndef GOT_CHUCKVEHICLE
#define GOT_CHUCKVEHICLE
using namespace std;


/*
With the Vehicle object, you can store a vehicle's whole vin (which is broken up stored as three independent variables: v1, vin, v3), a vehicle's price, and the number of weeks the vehicle has been on the lot. 
Custom options can also be stored into each vehicle object. To do this, it reads the numerical value of listSize and grabs that number of (option) lines listed below that vehicle and can store them within a 
sperate dynamic array using the string pointer listPtr. It includes several tools listed below to help modify the data within.
*/
class Vehicle
{
public:
	/* Constructor declarations */
	Vehicle(); // Default constructor
	Vehicle(string vin); // This constructor creates an object with only a given whole vin, and is used in search4Vehicle() to create temporary Vehicle objects.

	/* Destructor declarations */
	~Vehicle(); // Deletes the dynamic array that is pointed to by the pointer 'listPtr', and then resets listPtr for use. The dynamic array holds the options for a Vehicle as strings.

	/* Mutator and Accessor declarations */
	void wrtVin(string wVin); // Mutator that takes in a whole vin, makes it uppercase, and calls vinBreaker() to split it into the 3 variables: 'v1', 'vin', and 'v3'.
	void wrtPrice(double wPrice); // Mutator that makes a change to the variable 'price'.

	/* Helper functions */
	friend void operator ++(Vehicle& v); // Overloads the operator '++' and allows to update weeksOnLot (The number of weeks a vehicle has been on the lot) variable by one.
	friend bool operator ==(const Vehicle& v1, const Vehicle& v2); // Overloads '==' to set the variable vin of one object equal to the vin of another object.
	friend ostream& operator << (ostream& outS, const Vehicle& v); // Overloads '<<' to gather all entries of an objects variables and sends them to an a chosen output stream.
	friend istream& operator >> (istream& inS, Vehicle& v); // Overloads '>>' to write all the variables of an object from an input stream, into a file or array.
	
	/* Copy functions */
	Vehicle(const Vehicle& original); // Creates an independent copy of the dynamic array (list of vehicle options) of a given Vehicle.
	void operator =(const Vehicle& rightSide); //Overloads '=' assignment operator to copy entire Vehicle object to another Vehicle object. The left side is the target Vehicle, and the rightside is the original.

private:
	void makeUC(string& s);	// Private function to convert a given string into all uppercase letters.
	void vinBreaker(string& wVin); // Private Mutator that takes in one string vin and splits it among the three variables: v1, v2, and v3.
	string v1 = ""; // Holds the first character (a number) of a whole vin.
	string vin;		// Holds the middle letters of a whole vin.
	string v3 = ""; // Holds the last set of 5 numbers of a whole vin.
	double price;   // Price of a Vehicle.
	int weeksOnLot; // Number of weeks a Vehicle has been the lot.
	int listSize = 0; // Number of options a Vehicle has
	string * listPtr = NULL;  // Pointer, used to point to a dynamic string array that holds a variable number of Vehicle options
};

#endif