// Lab09.ExeptionHandling.cpp
// Authors: David Davidson, Charles Mikkelborg
// Discription: creates an intream from a file of chars that store a hidden message in a binary tree. The purpose here is to to make sure
//     that the file is loaded, make sure all chars are stored and there are no empty tree nodes. When these "exceptions" do happen, the
//     try() functions that contain the code of these errors will throw variables and objects that are caught with their coresponding catch() functions
//     that alert the user to the error and it's reason.
// Last modified: 06/04/2018


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct tNode // Node for storing values from the file and pointers to other nodes
{
	char content;
	tNode * leftN;
	tNode * rightN;
};

class ComplexE { // This is defines our class value that we will use for storing exception reporting information
public:
	ComplexE() {};
	ComplexE(string s, int i) { msg = s; value = i; }
	string getE_m() { return msg; }
	int getE_v() { return value; }
private:
	string msg = "Default";
	int value = -1;
};

tNode * buildTree(int depth, tNode * subRoot, ifstream& inF)
{
	bool cont = false;
	tNode * localP; // Simple local variable
	if (depth) // Skips functionality once "depth" decrements to 0
	{
		localP = new tNode; // Create a new node...
		subRoot = localP;   //  ... which will be the root of a sub-tree
		localP->leftN = NULL; // Make sure the node has no sub-trees yet.
		localP->rightN = NULL;
		
		if (inF >> localP->content)
			cont = true;
		cout << localP->content << " ";
		
		if (!cont) // Here is our exeption throw for when there is not enough chars to populate the tree.
			throw ComplexE("not enough chars at depth: ", abs(depth - 6)); // since this thow happens within main() which is within a try() 
																		   // there is no need to put this function within it's own try()
																		   // It returns an object which stores a string and a value equal
																		   // to the depth of tree where error occured to be printed to consol.
		depth--; // Decrement toward "stopping" case
		localP->leftN = buildTree(depth, localP->leftN, inF);
		localP->rightN = buildTree(depth, localP->rightN, inF);
	}
	
	return(subRoot);
}

int main()
{
	try { // I've put the whole main within the try, and having that try throw a different object which will print to the consol the reason for the throw.
		ifstream inF; // define an input stream
	
		inF.open("treedecode.txt"); // open a file as the input stream

		if (inF.fail()) // here is a check for our first exeption, the file not loading.
		{
			throw static_cast <string>("File open failed. "); // if our the file fails to load, it will throw this string to be displayed to the consol.
		};


		int depth; // Target depth of tree
		tNode * root = nullptr; // Pointer that will point to ENTIRE tree

		inF >> depth; // First thing in file is int identifying the depth of the tree
		cout << "Depth = " << depth << endl;

		root = buildTree(depth, root, inF); // build the tree with values from the input stream
		cout << endl;

		char charCatch; // create a char variable for checking for more chars
		if (inF >> charCatch) // if there are more chars within the file they will get sent to our new variable
			throw ComplexE("Not enough nodes to store nodes", 1); // if this happens then the exception thrown is this objects that displays its string to the console

		inF.close(); // close input stream
	}
	catch (string e) // Here is our catch for errors that only display a single string.
	{
		cout << e << endl;
		system("pause");
		exit(1);
	}
	catch (ComplexE e) // Here is our catch for erros, it takes in an object which stores information on the error, and prints it to the consol.
	{
		cout << e.getE_m() << e.getE_v() << endl;
		system("pause");
		exit(1);
	}
	system("pause");
	return 0;
}

