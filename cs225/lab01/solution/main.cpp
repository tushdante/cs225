// ***********************************************
// *                                             *
// *  main.cpp                                   *
// *                                             *
// *  File to test compilation and output        *
// *     formatting for Apartment                *
// *                                             *
// *  Written August 2005 by Jason Zych          *
// *                                             *
// ***********************************************

#include <iostream>
#include <string>

#include "apartment.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
   cout << "*** No-argument Constructor [Basic] ..." << endl;
   Apartment basicApartment;
   basicApartment.printInfo();
   cout << endl;

   cout << "*** Two-Argument Constructor [Complex] ..." << endl;
   Apartment complexApartment("Casper Malktose", 2124);
   complexApartment.printInfo();
   cout << endl;

   cout << "*** Print tenants for each Apartment ..." << endl;
   cout << "Basic: " << basicApartment.getTenant() << endl;
   cout << "Complex: " << complexApartment.getTenant() << endl;
   cout <<  endl;

   cout << "*** Print numbers for each Apartment ..." << endl;
   cout << "Basic: " << basicApartment.getNumber() << endl;
   cout << "Complex: " << complexApartment.getNumber() << endl;
   cout << endl;

   cout << "Done!" << endl;

   return 0;
}

