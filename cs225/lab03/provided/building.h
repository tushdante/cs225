/******************************************************************************
 *                                                                            *
 * building.h                                                                 *
 *                                                                            *
 * Represents an apartment building that contains numerous Apartments, each   *
 * of which have a tenant name and apartment number.                          *
 *                                                                            *
 * Based on code written by Jason Zych                                        *
 * Modified by Daniel Hoodin                                                  *
 *                                                                            *
 *****************************************************************************/

#ifndef BUILDING_H
#define BUILDING_H

#include "apartment.h"
#include <string>
#include <iostream>

class Building
{
public:
   Building(int size);
   int addApartment(std::string const & tenantName, int apartmentNumber);
   bool removeApartment(int index);
   bool getTenantAt(int index, std::string & tenantName) const;
   int getSize() const;
   Building(const Building & orig);
		


   friend std::ostream & operator<<(std::ostream & stream, Building const & building);
    
private:
   int getIndexOfVacantApartment() const;

   Apartment* * myApartments;
   int mySize;
};

std::ostream & operator<<(std::ostream & stream, Building const & building);

#endif
