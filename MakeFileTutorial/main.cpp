/*
main.cpp

Creates an object of type 'Writer'
and uses it to print a message to the screen

**Part of the Makefile Tutorial**
Authors: Will Dietz, Matt Sachtler, Derrick Wright 
Date: 9/2/07
*/
#include "writer.h"

int main()
{
	//Declare object 'myWriter' of type 'Writer'
	Writer myWriter;

	//Use myWriter's 'PrintToScreen' method to print a message to stdout
	myWriter.PrintToScreen("Congratulations, this works!");	

	//success!
	return 0;
}
