
#include <iostream>
#include <string>
#include "building.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
   string names[] = {"Adam", "Bob", "Charlie", "Dennis", "Eric", "Fred"};
   int numbers[] = {123, 241, 395, 480, 567, 621};

   Building myBuilding(4);
    
   cout << "*****Printing building created from int constructor with"
        << " no assigned apartments apartments." << endl;
   cout << myBuilding << endl;

   cout << "*****Adding apartments..." << endl;
   for(int x = 0; x<4; x++)
      myBuilding.addApartment(names[x], numbers[x]);

   cout << "*****Printing full building with added apartments" << endl;
   cout << myBuilding << endl;

   cout << "*****Adding extra apartment (building already full)" << endl;
	if (myBuilding.addApartment(names[4], numbers[4]) == -1)
      cout << "Could not add additional apartment.  Building Full" << endl;

   cout << endl;
   cout << "*****Removing apartment at index 1" << endl;
   myBuilding.removeApartment(1);
   cout << myBuilding << endl;

   cout << "*****Creating a copy of the building" << endl;
   Building copyBuilding(myBuilding);
   cout << "*Copy's contents" << endl << myBuilding << endl;

   cout << "*****Adding apartment to copy" << endl;
   copyBuilding.addApartment(names[4], numbers[4]);

   cout << "***Copy's Contents" << endl << copyBuilding << endl;
   cout << "***Original's Contents" << endl << myBuilding << endl;

   cout << "*****Removing apartment at index 2 from copy" << endl;
   copyBuilding.removeApartment(2);

   cout << "***Copy's Contents" << endl << copyBuilding << endl;
   cout << "***Original's Contents" << endl << myBuilding << endl;

   cout << "*****Adding one last apartment to the original" << endl;
   myBuilding.addApartment(names[5], numbers[5]);
   cout << "***Copy's Contents" << endl << copyBuilding << endl;
   cout << "***Original's Contents" << endl << myBuilding << endl;
    
   cout << "Done!!" << endl;

   return 0;
}

