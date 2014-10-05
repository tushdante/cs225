
#include "testcommon.h"

/**
 * prints out pass or fail message based on parameter value.
 */
void printResults(bool pass)
{
   if(pass)
      std::cout << "PASS" << std::endl;
   else
      std::cout << "FAIL" << std::endl;
}


void runAll(std::vector< TestCase > & testCases)
{
   unsigned int maxNameLength = 0;
   for (unsigned int i = 0; i < testCases.size(); ++i)
   {
      if (maxNameLength < testCases[i].first.size())
         maxNameLength = testCases[i].first.size();
   }

   for (unsigned int i = 0; i < testCases.size(); ++i)
   {
      std::cout << "Running " << testCases[i].first << "... ";
      unsigned int padding = maxNameLength - testCases[i].first.size();
      for (unsigned int j = 0; j < padding; ++j)
         std::cout << " ";
      printResults(testCases[i].second());
   }
}

