
#include "building.h"

using std::ostream;
using std::string;
using std::cout;
using std::endl;

// Building
//  - Constructor
//  - Parameters - size: the number of apartments that the Building can hold
//  - Creates a building that can hold size apartments with each apartment
//    initialized to NULL
Building::Building(int size)
{
    myApartments = new Apartment*[size];
    for(int x=0; x<size; x++)
        myApartments[x] = NULL;
    mySize = size;
}


// Building Copy
//  -Copy Constructor
//  -Itself as a parameter, no return

Building::Building (const Building & copyBuilding)
{
	copy(copyBuilding);
}



Building& Building::operator=(const Building & rhs)
{
	if (&rhs == this)
	{
	return *this;
	}
	clear();
	
	copy(rhs);

	return *this;
}


void Building::copy(const Building & copyBuilding)
{
	mySize = copyBuilding.getSize();
	myApartments = new Apartment*[mySize];
		for(int x=0; x<mySize; x++)
		{
		if(copyBuilding.myApartments[x] == NULL) 
			{
			myApartments[x] = NULL;
			}
      else 
      	{ 
      	myApartments[x] = new Apartment(*copyBuilding.myApartments[x] );
      	}
      }
}



// ~Building
//  -Destructor
//  -No parameters, no return statement
Building::~Building(){
	clear();

}



void Building::clear( )
{
int size = this->getSize();

		for(int x=0; x<size; x++)
		{
		if(this->myApartments[x] != NULL) 
			{
			delete this->myApartments[x];
			}
      }
     	delete [] myApartments;
     	myApartments = NULL;
}






// getIndexOfVacantApartment
//  - returns index of the first vacant apartment
//  - returns -1 if no apartments are vacant
int Building::getIndexOfVacantApartment() const
{
   int index = -1;
   for (int i = 0; i < mySize && index < 0; ++i)
   {
      if (myApartments[i] == NULL)
         index = i;
   }
   return index;
}

// addApartment
//  - Parameters - tenantName: the name of the tenant in the new apartment
//                 apartmentNumber: the apartment number of the new apartment
//  - Creates a new apartment with the given parameters and adds it to the array 
//    at the first available slot.  If the building is full the apartment is 
//    not added
//  - Return - the index of where the apartment is added or -1 if not added
int Building::addApartment(string const & tenantName, int apartmentNumber)
{
   int index = getIndexOfVacantApartment();
   if (index >= 0)
      myApartments[index] = new Apartment(tenantName, apartmentNumber);
   return index;
}

// removeApartment
//  - Parameters - index: the index of the apartment to be removed
//  - Removes the given apartment from the collection 
//  - Return - true if removal is successful, and false otherwise. 
bool Building::removeApartment(int index)
{
   if(index < 0 || index >= mySize)
      return false;
   
   delete myApartments[index];
   myApartments[index] = NULL;
   return true;
}

// getTenantAt
//  - Parameters - index: the index of the apartment to get the tenant
//                 tenantName: assigned to the name of the tenant
//  - Gets the name of the tenant residing in the apartment at index
//    and assigns the parameter tenantName to it.
//  - Return - true if access is successful, and false otherwise. 
bool Building::getTenantAt(int index, string & tenantName) const
{
   if(index < 0 || myApartments[index] == NULL)
      return false;

   tenantName = myApartments[index]->getTenant();
   return true;
}

// getSize
//  - Gets the size of the building
//  - Return - size of building as determined by value passed
//             into the constructor
int Building::getSize() const
{
    return mySize;
}

// printAll
//  - Prints the tenant's names and apartment numbers to the screen
ostream & operator<<(ostream & stream, Building const & building)
{
   stream << "Building Info:" << endl;
   stream << "Number of possible apartments: " << building.mySize << endl << endl;

   for(int i = 0; i < building.mySize; i++)
   {
      if(building.myApartments[i] != NULL)
         stream << *building.myApartments[i] << endl;
   }

   stream << "End Info" << endl;
   return stream;
}

