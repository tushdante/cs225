
#include "dsetstest.h"
#include <iostream>

namespace DSetsTest {

bool testAddElements1()
{
   DisjointSets disjSets;
   disjSets.addelements(5);
   std::cout << disjSets.find(3) << "\n";
   return true;
}

bool testAddElements2()
{
   DisjointSets disjSets;
   disjSets.addelements(5);
   std::cout << disjSets.find(0) << "\n";
   disjSets.addelements(5);
   std::cout << disjSets.find(9) << "\n";
   return true;
}

bool testFindAndSetUnion1()
{
   DisjointSets disjSets;
   disjSets.addelements(4);
   disjSets.setunion(1, 2);
   if (disjSets.find(1) == disjSets.find(2))
      std::cout << "Roots match.\n";
   else
      std::cout << "Roots don't match.\n";
   return true;
}

bool testFindAndSetUnion2()
{
   DisjointSets disjSets;
   disjSets.addelements(10);
   disjSets.setunion(4, 8);
   disjSets.setunion(1, 3);
   disjSets.setunion(1, 5);
   disjSets.setunion(8, 3);
   disjSets.setunion(6, 7);
   disjSets.setunion(2, 8);
   disjSets.setunion(7, 1);
   int root = disjSets.find(1);
   for (int i = 2; i <= 8; i++) {
      if (disjSets.find(i) == root) 
         std::cout << "Root for " << i << " matches.\n";
      else
         std::cout << "Root for " << i << " does not match.\n";
   }
   return true;
}

bool testFindAndSetUnion3()
{
   DisjointSets disjSets;
   disjSets.addelements(8);
   disjSets.setunion(1, 2);
   disjSets.setunion(1, 3);
   disjSets.setunion(4, 5);
   disjSets.setunion(4, 6);
   disjSets.setunion(3, 6);
   if (disjSets.find(1) == disjSets.find(4))
      std::cout << "Roots match.\n";
   else
      std::cout << "Roots don't match.\n";
   return true;
}

bool testFreePoints()
{
   DisjointSets disjSets;
   std::cout << "Hooray!  Free points for everybody!\n";
   return true;
}

void runTest(unsigned int testCaseNumber)
{
   std::vector< TestCase > testCases;
   testCases.push_back(TestCase("testAddElements1",testAddElements1));
   testCases.push_back(TestCase("testAddElements2",testAddElements2));
   testCases.push_back(TestCase("testFindAndSetUnion1",testFindAndSetUnion1));
   testCases.push_back(TestCase("testFindAndSetUnion2",testFindAndSetUnion2));
   testCases.push_back(TestCase("testFindAndSetUnion3",testFindAndSetUnion3));
   testCases.push_back(TestCase("testFreePoints",testFreePoints));

   if (testCaseNumber > 0 && testCaseNumber <= testCases.size())
   {
      testCases[testCaseNumber-1].second();
   }
}

}

