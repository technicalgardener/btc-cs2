// 11helloWorld.cpp : Defines the entry point for the console application.
//

// Visual Studio needs this #include directive.  
//   Don't use it in MyProgrammingLab.
#include "stdafx.h"

// The #include directive tells the compiler where to find 
//   input(keyboard) and output(screen) information.
// Words with special meaning, like "#include" and "using" and "int" are
//   called keywords or reserved words.  They usually are given a color
//   in an IDE or Integrated Development Environment like VisualStudio. 
#include <iostream>

// "using namespace std" tells the compiler to use the standard names
// so you don't have to say std::cout
using namespace std;

// The start of the program is a function or group of code called 'main'
// It returns an integer so it starts with 'int'
int main()
// Braces identify the start and the end of the function.
{
	// To the character-based output (screen) send the text "Hello, World.\n"
	cout << "Hello, World.\n";

	// Ask the Windows operating system to execute the pause command.
	system("pause");

	// Exit the program, returning a 0 which means no errors.
	return 0;
}
