
/******************************************************************************
 *
 * PhotoMosaic Tests
 *
 * 33 tests
 *
 * See kdtreetest.h and kdtilemappertest.h for details.
 *
 *****************************************************************************/

#include "kdtreetest.h"
#include "kdtilemappertest.h"
#include <iostream>

int main()
{
   Magick::InitializeMagick((char *)NULL);
   const unsigned int numKDTreeTestCases = 25;
   const unsigned int numKDTileMapperTestCases = 8;
   const unsigned int numTestCases = numKDTreeTestCases + numKDTileMapperTestCases;
   unsigned int testCaseNumber;
   std::cin >> testCaseNumber;
   if (testCaseNumber > 0 && testCaseNumber <= numKDTreeTestCases)
   {
      testkdtree::runTestKDTree(testCaseNumber);
   }
   else if (testCaseNumber > numKDTreeTestCases && testCaseNumber <= numTestCases)
   {
      testkdtilemapper::runTestKDTileMapper(testCaseNumber-numKDTreeTestCases);
   }else
   {
      std::cout << "invalid test case number" << std::endl;
   }
   return 0;
}

