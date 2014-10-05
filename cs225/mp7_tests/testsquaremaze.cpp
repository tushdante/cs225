
#include "squaremazetest.h"
#include <iostream>

int main()
{
   const unsigned int numSquareMazeTests = 13;
   
   unsigned int testCase;
   std::cin >> testCase;

   if (testCase <= 0 || testCase > numSquareMazeTests)
   {
      std::cout << "Invalid test case number: " << testCase << std::endl;
   }
   else
   {
      SquareMazeTest::runTest(testCase);
   }

   return 0;
}

