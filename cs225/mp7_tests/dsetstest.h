
/* Test cases

Disjoint sets (30 points):
--------------

addElements() - 5 points
#1 (2) -- add 5 elements, find() on #3
#2 (3) -- add 5, find(0), add 5 more, find(9)

find(), setunion() - 15 points
#3 (5) -- add 2, setunion(1, 2), find(1) == find(2)? 
#4 (5) -- union everything together, check for same root
#5 (5) -- too subtle to explain in few words

To be checked manually:
 - union-by-size (5 points)
 - path compression (5 points)
Credit for this stuff will be awarded by test case #6,
and removed via deduction if necessary.
*/

#include "dsets.h"

namespace DSetsTest {

typedef std::pair<std::string, bool (*)()> TestCase;

bool testAddElements1();
bool testAddElements2();
bool testFindAndSetUnion1();
bool testFindAndSetUnion2();
bool testFindAndSetUnion3();
bool testFreePoints();

void runTest(unsigned int testCaseNumber);

}

