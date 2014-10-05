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

#include <iostream>
#include <string>

class Apartment
{
public:
   Apartment();
   Apartment(std::string const & paramTenant, int paramNumber);
   std::string const & getTenant() const;
   void setTenant(std::string const & newTenant);	
   std::string evictTenant();
   int getNumber() const;
   void setNumber(int newNumber);
   friend std::ostream & operator<<(std::ostream & stream, Apartment const & apartment);
 
private:
    std::string tenant;   
    int number;      
};

std::ostream & operator<<(std::ostream & stream, Apartment const & apartment);

#endif

