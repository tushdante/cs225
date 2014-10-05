/* Test case ideas:

Note to the student:
Most test cases are split up into three parts -- print the list forward,
print the list backwards, and print the size of the list.  Typically,
these cases will be worth 2, 2, and 1 points, respectively.  Before you
complain that you shouldn't lose 3/5 points for producing a list that
looks correct only when traversed forward, note that you're still producing
a broken list, and one could argue that doing so doesn't warrant _any_
points at all.  ;)  (In fact, when similar MPs were used in earlier terms,
that's how the grading was done; seemed a bit too harsh to me, though.)
That's also why there are about a billion test cases for this MP.

Testing is not totally exhaustive.  This is unfortunate, but is due to the
complexity of some functions, and the sheer number of test cases.  (I didn't
want to involve fractional points, and the MP is worth 100 points, so...)

The "printForward", "printBackward", and "printSize" functions were added
to the List class for the purposes of testing this MP.  Additionally, so
was the instantiation List<int>; constructing test cases is much easier
with ints than with RGBApixels.  Also note that we have added warnings to
each of the List functions, to make sure that you didn't call them; correct
test case output will include _some_ warnings, but all of those warnings
should originate from the calls in this file, and hence should be consistent
across all correct solutions.

Per-problem point weightings are not equal; the harder problems are worth more.


removeNth (24 points total):
#1 (2) - empty list, printAll
#2 (2) - size = 1, N = 1, printAll
#3 (2) - size = 1, N = 3, list size 9, printForward
#4 (2) - size = 1, N = 3, list size 9, printBackward
#5 (1) - size = 1, N = 3, list size 9, printSize
#6 (2) - size = 1, N = 3, list size 8, printForward
#7 (2) - size = 1, N = 3, list size 8, printBackward
#8 (1) - size = 1, N = 3, list size 8, printSize
#9 (2) - size = 4, N = 3, list size 36, printForward
#10 (2) - size = 4, N = 3, list size 36, printBackward
#11 (1) - size = 4, N = 3, list size 36, printSize
#12 (2) - size = 4, N = 3, list size 35, printForward
#13 (2) - size = 4, N = 3, list size 35, printBackward
#14 (1) - size = 4, N = 3, list size 35, printSize


tripleRotate (26 points total):
Note: no printSize used here; tripleRotate shouldn't change size at all
#15 (2) - empty list, printAll
#16 (2) - size = 1, list size 3, printForward
#17 (2) - size = 1, list size 3, printBackward
#18 (2) - size = 1, list size 9, printForward
#19 (2) - size = 1, list size 9, printBackward
#20 (2) - size = 1, list size 11, printForward
#21 (2) - size = 1, list size 11, printBackward
#22 (2) - size = 3, list size 9, printForward
#23 (2) - size = 3, list size 9, printBackward
#24 (2) - size = 3, list size 27, printForward
#25 (2) - size = 3, list size 27, printBackward
#26 (2) - size = 3, list size 26, printForward
#27 (2) - size = 3, list size 26, printBackward


appendList (15 points total):
#28 (2) - empty list appended to list of size 8, printAll
#29 (3) - list of size 8 appended to empty list, printAll
#30 (2) - list of size 1 appended to list of size 8, printForward
#31 (2) - list of size 1 appended to list of size 8, printBackward
#32 (1) - list of size 1 appended to list of size 8, printSize
#33 (2) - list of size 8 appended to list of size 8, printForward
#34 (2) - list of size 8 appended to list of size 8, printBackward
#35 (1) - list of size 8 appended to list of size 8, printSize


mixList (20 points total):
#36 (2) - mix empty list with empty list, printAll
#37 (3) - mix list of size 8 with empty list, printAll
#38 (2) - mix empty list with list of size 8, printForward
#39 (2) - mix empty list with list of size 8, printBackward
#40 (1) - mix empty list with list of size 8, printSize
#41 (2) - mix list of size 8 with list of size 8, printForward
#42 (2) - mix list of size 8 with list of size 8, printBackward
#43 (1) - mix list of size 8 with list of size 8, printSize
#44 (2) - mix list of size 8 with list of size 12, printForward
#45 (2) - mix list of size 8 with list of size 12, printBackward
#46 (1) - mix list of size 8 with list of size 12, printSize


splitList (15 points total):
#47 (2) - list of size 8, rank of 9, printAll
#48 (3) - list of size 8, rank of 1, printAll
#49 (2) - list of size 9, rank of 9, printForward
#50 (2) - list of size 9, rank of 9, printBackward
#51 (1) - list of size 9, rank of 9, printSize
#52 (2) - list of size 16, rank of 9, printForward
#53 (2) - list of size 16, rank of 9, printBackward
#54 (1) - list of size 16, rank of 9, printSize


valgrind:
No valgrind tests this time.  Since no nodes can be created, only one
function actually presents an opportunity to leak memory; busting out
valgrind doesn't seem worth it.  Also, it gives me more points to spend
on the other test cases, which is honestly quite necessary here.


To be checked manually:
- commenting (max -10)
*/

#include <iostream>
#include "doubly-linked-list.h"

using std::cout;
using std::cin;

int main()
{
   int testCase;
   cin >> testCase;
   List<int> testList, returnList;

/* BEGIN REMOVENTH TESTS */

   if (testCase == 1) {
      testList.removeNth(4,8);
      testList.printAll();

   } else if (testCase == 2) {
      for (int i = 1; i <= 15; i++)
         testList.insertAfter(i);
      testList.removeNth(1,1);
      testList.printAll();

   } else if (testCase == 3) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      testList.removeNth(3,1);
      testList.printForward();

   } else if (testCase == 4) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      testList.removeNth(3,1);
      testList.printBackward();

   } else if (testCase == 5) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      testList.removeNth(3,1);
      testList.printSize();

   } else if (testCase == 6) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      testList.removeNth(3,1);
      testList.printForward();

   } else if (testCase == 7) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      testList.removeNth(3,1);
      testList.printBackward();

   } else if (testCase == 8) {
       for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      testList.removeNth(3,1);
      testList.printSize();

   } else if (testCase == 9) {
      for (int i = 1; i <= 36; i++)
         testList.insertAfter(i);
      testList.removeNth(3,4);
      testList.printForward();

   } else if (testCase == 10) {
      for (int i = 1; i <= 36; i++)
         testList.insertAfter(i);
      testList.removeNth(3,4);
      testList.printBackward();

   } else if (testCase == 11) {
      for (int i = 1; i <= 36; i++)
         testList.insertAfter(i);
      testList.removeNth(3,4);
      testList.printSize();

   } else if (testCase == 12) {
      for (int i = 1; i <= 35; i++)
         testList.insertAfter(i);
      testList.removeNth(3,4);
      testList.printForward();

   } else if (testCase == 13) {
      for (int i = 1; i <= 35; i++)
         testList.insertAfter(i);
      testList.removeNth(3,4);
      testList.printBackward();

   } else if (testCase == 14) {
      for (int i = 1; i <= 35; i++)
         testList.insertAfter(i);
      testList.removeNth(3,4);
      testList.printSize();

/* END REMOVENTH TESTS */
/* BEGIN TRIPLEROTATE TESTS */

   } else if (testCase == 15) {
      testList.tripleRotate(1);
      testList.printAll();

   } else if (testCase == 16) {
      for (int i = 1; i <= 3; i++)
         testList.insertAfter(i);
      testList.tripleRotate(1);
      testList.printForward();

   } else if (testCase == 17) {
      for (int i = 1; i <= 3; i++)
         testList.insertAfter(i);
      testList.tripleRotate(1);
      testList.printBackward();

   } else if (testCase == 18) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      testList.tripleRotate(1);
      testList.printForward();

   } else if (testCase == 19) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      testList.tripleRotate(1);
      testList.printBackward();

   } else if (testCase == 20) {
      for (int i = 1; i <= 11; i++)
         testList.insertAfter(i);
      testList.tripleRotate(1);
      testList.printForward();

   } else if (testCase == 21) {
      for (int i = 1; i <= 11; i++)
         testList.insertAfter(i);
      testList.tripleRotate(1);
      testList.printBackward();

   } else if (testCase == 22) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      testList.tripleRotate(3);
      testList.printForward();

   } else if (testCase == 23) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      testList.tripleRotate(3);
      testList.printBackward();

   } else if (testCase == 24) {
      for (int i = 1; i <= 27; i++)
         testList.insertAfter(i);
      testList.tripleRotate(3);
      testList.printForward();

   } else if (testCase == 25) {
      for (int i = 1; i <= 27; i++)
         testList.insertAfter(i);
      testList.tripleRotate(3);
      testList.printBackward();

   } else if (testCase == 26) {
      for (int i = 1; i <= 26; i++)
         testList.insertAfter(i);
      testList.tripleRotate(3);
      testList.printForward();

   } else if (testCase == 27) {
      for (int i = 1; i <= 26; i++)
         testList.insertAfter(i);
      testList.tripleRotate(3);
      testList.printBackward();

/* END TRIPLEROTATE TESTS */
/* BEGIN APPENDLIST TESTS */

   } else if (testCase == 28) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 100; i <= 0; i++)
         returnList.insertAfter(i+20);
      testList.appendList(returnList);
      testList.printAll();
      returnList.printAll();

   } else if (testCase == 29) {
      for (int i = 1; i <= 0; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.appendList(returnList);
      testList.printAll();
      returnList.printAll();

   } else if (testCase == 30) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 1; i++)
         returnList.insertAfter(i+20);
      testList.appendList(returnList);
      testList.printForward();
      returnList.printForward();

   } else if (testCase == 31) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 1; i++)
         returnList.insertAfter(i+20);
      testList.appendList(returnList);
      testList.printBackward();
      returnList.printBackward();

   } else if (testCase == 32) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 1; i++)
         returnList.insertAfter(i+20);
      testList.appendList(returnList);
      testList.printSize();
      returnList.printSize();

   } else if (testCase == 33) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.appendList(returnList);
      testList.printForward();
      returnList.printForward();

   } else if (testCase == 34) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.appendList(returnList);
      testList.printBackward();
      returnList.printBackward();

   } else if (testCase == 35) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.appendList(returnList);
      testList.printSize();
      returnList.printSize();

/* END APPENDLIST TESTS */
/* BEGIN MIXLIST TESTS */

   } else if (testCase == 36) {
      for (int i = 1; i <= 0; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 0; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printAll();
      returnList.printAll();

   } else if (testCase == 37) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 0; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printAll();
      returnList.printAll();

   } else if (testCase == 38) {
      for (int i = 1; i <= 0; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printForward();
      returnList.printForward();

   } else if (testCase == 39) {
      for (int i = 1; i <= 0; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printBackward();
      returnList.printBackward();

   } else if (testCase == 40) {
      for (int i = 1; i <= 0; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printSize();
      returnList.printSize();

   } else if (testCase == 41) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printForward();
      returnList.printForward();

   } else if (testCase == 42) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printBackward();
      returnList.printBackward();

   } else if (testCase == 43) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 8; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printSize();
      returnList.printSize();

   } else if (testCase == 44) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 12; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printForward();
      returnList.printForward();

   } else if (testCase == 45) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 12; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printBackward();
      returnList.printBackward();

   } else if (testCase == 46) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      for (int i = 1; i <= 12; i++)
         returnList.insertAfter(i+20);
      testList.mixList(returnList);
      testList.printSize();
      returnList.printSize();

/* END MIXLIST TESTS */
/* BEGIN SPLITLIST TESTS */

   } else if (testCase == 47) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      returnList = testList.splitList(9);
      testList.printAll();
      returnList.printAll();

   } else if (testCase == 48) {
      for (int i = 1; i <= 8; i++)
         testList.insertAfter(i);
      returnList = testList.splitList(1);
      testList.printAll();
      returnList.printAll();

   } else if (testCase == 49) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      returnList = testList.splitList(9);
      testList.printForward();
      returnList.printForward();

   } else if (testCase == 50) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      returnList = testList.splitList(9);
      testList.printBackward();
      returnList.printBackward();

   } else if (testCase == 51) {
      for (int i = 1; i <= 9; i++)
         testList.insertAfter(i);
      returnList = testList.splitList(9);
      testList.printSize();
      returnList.printSize();

   } else if (testCase == 52) {
      for (int i = 1; i <= 16; i++)
         testList.insertAfter(i);
      returnList = testList.splitList(9);
      testList.printForward();
      returnList.printForward();

   } else if (testCase == 53) {
      for (int i = 1; i <= 16; i++)
         testList.insertAfter(i);
      returnList = testList.splitList(9);
      testList.printBackward();
      returnList.printBackward();

   } else if (testCase == 54) {
      for (int i = 1; i <= 16; i++)
         testList.insertAfter(i);
      returnList = testList.splitList(9);
      testList.printSize();
      returnList.printSize();

   }

   cout << "Testing complete.\n";

   return 0;
}
