// ****************************************************
// *                                                  *
// *  apartment.cpp                                   *
// *                                                  *
// *  Implementation for a class holding information  *
// *    about an apartment in a building              * 
// *                                                  *
// *  Based on code by Jason Zych                     *
// *                                                  *
// ****************************************************

#include "apartment.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

// Apartment
//    - constructor
//    - initializes object to be a default apartment (i.e.
//        an empty name and a number of 0)
Apartment::Apartment()
{
   tenant = "";
   number = -1;
}

// Apartment
//    - constructor
//    - parameters : paramTenant - reference to a string holding the
//                     name of the person who resides in this apartment; 
//                     the string cannot be changed through the reference
//                 : paramNumber - the number of this; this 
//                     value is assumed to be non-negative
//    - initializes apartment to have the parameter tenant and
//          number
Apartment::Apartment(string const & paramTenant, int paramNumber)
{
   tenant = paramTenant;
   number = paramNumber;
}

// getTenant
//    - return value : a reference to a string holding tenant's
//                        name; the string cannot be changed through
//                        this reference
//    - returns name of person who resides in this apartment
string const & Apartment::getTenant() const
{
   return tenant;
}

// setTenant
//    - sets the tenants name of this apartment
void Apartment::setTenant(string const & newTenant)
{
   tenant = newTenant;
}

// evictTenant
//    - return value : a string holding the previous tenant's name
//    - sets the tenant's name to the default value
string Apartment::evictTenant()
{
   string previousTenant = tenant;
   tenant = "";
   return previousTenant;
}

// getNumber
//    - return value : an integer storing a number
//    - returns the number of this apartment
int Apartment::getNumber() const
{
   return number;
}

// setNumber
//    - sets the number of this apartment
void Apartment::setNumber(int newNumber)
{
   number = newNumber;
}

ostream & operator<<(ostream & stream, Apartment const & apartment)
{
   stream << "Apartment #" << apartment.getNumber() << endl;
   string tenant = apartment.getTenant();

   if (tenant == "")
      stream << "Vacant" << endl;
   else
      stream << tenant << endl;
   return stream;
}

