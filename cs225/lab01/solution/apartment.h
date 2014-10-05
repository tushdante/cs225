// ***********************************************
// *                                             *
// *  apartment.h                                *
// *                                             *
// *  Interface for a class holding information  *
// *    about an apartment in a building         * 
// *                                             *
// *  Based on code by Jason Zych                *
// *                                             *
// ***********************************************

#ifndef APARTMENT_H
#define APARTMENT_H

#include <string>
using std::string;

class Apartment
{
public:

   // Apartment
   //    - constructor
   //    - initializes object to be a default apartment (i.e.
   //        an empty name and a number of 0)
   Apartment();

   // Apartment
   //    - constructor
   //    - parameters : paramTenant - reference to a string holding the
   //                     name of the person who resides in this apartment; 
   //                     the string cannot be changed through the reference
   //                 : paramNumber - the number of this; this 
   //                     value is assumed to be non-negative
   //    - initializes apartment to have the parameter tenant and
   //          number
   Apartment(string const & paramTenant, int paramNumber);
   
   // getTenant
   //    - return value : a reference to a string holding tenant's 
   //                        name; the string cannot be changed through
   //                        this reference 
   //    - returns name of person who resides in this apartment
   string const & getTenant() const;
   
   // setTenant
   //    - sets the tenants name of this apartment
   void setTenant(string const & newTenant);	

   // evictTenant
   //    - return value : a string holding the previous tenant's name
   //    - sets the tenant's name to the default value
   string evictTenant();

   // getNumber
   //    - return value : an integer storing a number
   //    - returns the number of this apartment
   int getNumber() const;

   // setNumber
   //    - sets the number of this apartment
   void setNumber(int newNumber);
	
   // printInfo
   //   - Prints the apartment number and tenant name
   void printInfo() const;
 
private:

    string tenant;   // tenant of apartment
    int number;      // number of apartment
};

#endif

