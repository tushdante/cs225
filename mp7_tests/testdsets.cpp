
#include "dsetstest.h"
#include <iostream>

int main()
{
   const unsigned int numDSetsTests = 6;
   
   unsigned int testCase;
   std::cin >> testCase;

   if (testCase <= 0 || testCase > numDSetsTests)
   {
      std::cout << "Invalid test case number: " << testCase << std::endl;
   }
   else
   {
      DSetsTest::runTest(testCase);
   }

   return 0;
}

