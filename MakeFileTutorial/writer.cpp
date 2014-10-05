/*
writer.cpp

Defines class Writer's methods

**Part of the Makefile Tutorial**
Authors: Will Dietz, Matt Sachtler, Derrick Wright 
Date: 9/2/07
*/
#include "writer.h"

#include <iostream>
using std::cout;
using std::endl;

/*PrintToScreen(const char * message)
-parameters:
	message- string containing message to be printed out
-purpose:
	prints message to stdout
-assumptions:
	assumes message is a valid string
-returns:
	nothing
*/
void Writer::PrintToScreen(const char * message)
{
	if (message != NULL)//basic checking
	{
		//Prints the message to stdout
		cout << message << endl;
	}
}
