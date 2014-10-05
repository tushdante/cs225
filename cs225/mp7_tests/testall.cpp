
#include "squaremazetest.h"
#include "dsetstest.h"
#include <iostream>

int main()
{
   const unsigned int numDSetsTests = 6;
   const unsigned int numSquareMazeTests = 13;
   const unsigned int totalTestCount = numDSetsTests + numSquareMazeTests;
   
   unsigned int testCase;
   std::cin >> testCase;

   if (testCase <= 0 || testCase > totalTestCount)
   {
      std::cout << "Invalid test case number: " << testCase << std::endl;
   }
   else if (testCase <= numDSetsTests)
   {
      DSetsTest::runTest(testCase);
   }
   else
   {
      SquareMazeTest::runTest(testCase-numDSetsTests);
   }

   return 0;
}

