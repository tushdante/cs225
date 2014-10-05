// ***********************************************
// *                                             *
// *  main.cpp (Lab3)                            *
// *                                             *
// *  Driver for the Building class              *
// *                                             *
// *                                             *
// *  Based on code by Jason Zych                *
// *                                             *
// ***********************************************

#include <iostream>
#include <string>
using namespace std;

#include "apartment.h"
#include "building.h"

int main()
{
   string names[] = {"Adam", "Bob", "Charlie", "Dennis", "Eric", "Fred"};
   int numbers[] = {123, 241, 395, 480, 567, 621};
   int apartmentIndex = 5;
   string tenantName = "";

   Building myBuilding(4);
    
   cout << "*****Adding apartments..." << endl;
   for(int x = 0; x<4; x++)
   {
      myBuilding.addApartment(names[x], numbers[x]);
   }

   cout << "*****Printing full building with added apartments" << endl;
   cout << myBuilding << endl;

   cout << "*****Getting apartment at index " << apartmentIndex << endl;
   
   if(myBuilding.getTenantAt(apartmentIndex,tenantName))
      cout << tenantName << endl;
   else
      cout << "Out of bounds" << endl;

   cout << "Done!!" << endl;
   return 0;
}

