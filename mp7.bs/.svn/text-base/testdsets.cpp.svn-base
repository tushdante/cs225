/*
*  testdsets.cpp
*  cs225 Maze MP
*  Performs basic tests of DisjointSets.
*  Written April 2007 by Jonathan Ray
*/

#include <iostream>
#include "dsets.h"

int main()
{
   DisjointSets s;
   s.addelements(50);
   s.setunion(2,3);
   s.setunion(3,5);
   s.setunion(5,7);
   s.setunion(7,2);
   s.setunion(4,6);
   std::cout << s.find(7) << std::endl;
   std::cout << s.find(5) << std::endl;
   std::cout << s.find(6) << std::endl;
   s.addelements(1);
   std::cout << s.find(50) << std::endl;
   s.setunion(50,3);
   std::cout << s.find(50) << std::endl;
   std::cout << "Disjoint Sets test complete"<< std::endl;
   return 0;
}

