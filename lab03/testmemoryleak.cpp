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
#include "apartment.h"
#include "building.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    string names[] = {"Adam", "Bob", "Charlie", "Dennis", "Eric", "Fred"};
    int numbers[] = {123, 241, 395, 480, 567, 621};

    Building* myBuilding = new Building(4);
    for(int i = 0; i < 4; ++i)
    {
        myBuilding->addApartment(names[i],numbers[i]);
    }

    cout << "*****Printing full building with added apartments" << endl;
    cout << *myBuilding << endl;
    
    delete myBuilding;

    return 0;
}

