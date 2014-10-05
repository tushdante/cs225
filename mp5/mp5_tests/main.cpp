/*

Note to students:
  Because we cannot really test your functions without first creating a QuadTree,
  most of the test cases for this MP rely on the two-argument constructor.
  Hence, a mistake there could cause you to lose many points.  Similarly, some of
  the "large" test cases rely on decompress().  (Note that decompress() is not
  explicitly tested -- the points allocated to it have been distributed throughout
  the rest of the MP, to cover the test cases in which it's used to produce the
  testing output.)  This is undesirable, but necessary.

  IF YOU THINK THAT YOU SCREWED UP THE TWO-ARGUMENT CONSTRUCTOR OR DECOMPRESS,
  LET ME KNOW.  I MAY OWE YOU SOME POINTS.


Test cases:

default constructor - 2 points
#1 (2) - create, print empty tree

real constructor - 6 points
#2 (3) - create tree, fill with a 16x16 image, print it
#3 (3) - create tree, fill with 8x8 portion of 16x16 image, print

buildTree - 6 points
#4 (2) - same as #2
#5 (2) - same as #3
#6 (2) - same as #3, on an existing tree

copy constructor tests - 6 points
#7 (1) - create empty tree, copy it, compare
#8 (1) - create tree, fill it with a 1x1 image, copy, compare
#9 (2) - create tree, fill with 16x16 image, copy, compare
#10 (2) - create tree, fill with 16x16 image, copy, change first, compare

assignment operator tests - 6 points
#11 (1) - same as #3, using assignment operator to copy
#12 (1) - same as #4, using assignment operator to copy
#13 (2) - same as #5, using assignment operator to copy
#14 (2) - same as #6, using assignment operator to copy

getPixel - 6 points
#15 (2) - create tree, fill with a 1x1 image, getPixel
#16 (2) - create tree, fill with a 2x2 image, getPixel
#17 (2) - create tree, fill with a 512x512 image, getPixel

clockwiseRotate() tests - 8 points
#18 (2) - create empty tree, clockwiseRotate()
#19 (2) - create tree, fill with a 2x2 image, clockwiseRotate()
#20 (2) - create tree, fill with a 512x512 image, clockwiseRotate()
#21 (2) - create tree, fill with a 512x512 image, clockwiseRotate() twice

prune() tests - 19 points
#22 (2) - create empty tree, prune()
#23 (3) - create tree, fill with a 2x2 image, prune(200,000), print
#24 (2) - create tree, fill with monochromatic 32x32, prune(0)
#25 (5) - create tree, fill with 512x512 image, prune(10,000)
#26 (2) - create tree, fill with 512x512 image, prune, copy, compare
#27 (2) - create tree, fill with a 512x512 image, prune, clockwiseRotate()
#28 (3) - create tree, fill with a 512x512 image, prune, getPixel

pruneSize() tests - 10 points
#29 (2) - create empty tree, pruneSize()
#30 (2) - create tree, fill with 2x2 image, pruneSize(1)
#31 (2) - create tree, fill with 2x2 image, pruneSize(200,000)
#32 (2) - create tree, fill with monochromatic image, pruneSize(0)
#33 (2) - create tree, fill with 512x512 image, pruneSize(1000)

idealPrune() tests - 12 points
#34 (2) - create tree, fill with 2x2 image, idealPrune(1)
#35 (3) - create tree, fill with 2x2 image, idealPrune(3)
#36 (2) - create tree, fill with monochromatic image, idealPrune(1)
#37 (5) - create tree, fill with 512x512 image, idealPrune(10000)

const correctness - 6 points 
#38 (6) - attempt to compile main2.cpp.  Please see that file for details. 

valgrind tests - 13 points 
#39 (4) - big three 
#40 (2) - clockwiseRotate()
#41 (4) - prune() 
#42 (3) - pruneSize(), idealPrune(); build, idealPrune(), check answer with
                                  pruneSize(), delete

*/


#include <iostream>
#include <cstdlib>
#include "EasyBMP.h"
#include "quadtree.h"

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

extern ostream & operator<<(ostream & out, RGBApixel const & pixel);

bool operator==(RGBApixel const & left, RGBApixel const & right) {
   return (left.Red == right.Red && left.Green == right.Green
                                   && left.Blue == right.Blue);
}

bool operator!=(RGBApixel const & left, RGBApixel const & right) {
   return !(left == right);
}

bool operator==(BMP const & left, BMP const & right) {
   int width = left.TellWidth();
   int height = left.TellHeight();
   if (right.TellWidth() != width || right.TellHeight() != height)
      return false;

   for (int i = 0; i < width; i++)
      for (int j = 0; j < height; j++)
         if (*(left(i,j)) != *(right(i,j)))
            return false;

   return true;
}

int main() {
   int testCase;
   cin >> testCase;

   Quadtree *first, *second;
   BMP pixel, tiny, small, monochrome, large, rVal, soln;
   pixel.ReadFromFile("pixel.bmp");
   tiny.ReadFromFile("tiny.bmp");
   monochrome.ReadFromFile("monochrome.bmp");
   small.ReadFromFile("small.bmp");
   large.ReadFromFile("large.bmp");

   if (testCase == 1) {
      first = new Quadtree();
      first->printTree();

   } else if (testCase == 2) {
      first = new Quadtree(small, 16);
      first->printTree();

   } else if (testCase == 3) {
      first = new Quadtree(small, 8);
      first->printTree();

   } else if (testCase == 4) {
      first = new Quadtree();
      first->buildTree(small, 16);
      first->printTree();

   } else if (testCase == 5) {
      first = new Quadtree();
      first->buildTree(small, 8);
      first->printTree();

   } else if (testCase == 6) {
      first = new Quadtree(monochrome, 16);
      first->buildTree(small, 8);
      first->printTree();

   } else if (testCase == 7) {
      first = new Quadtree();
      second = new Quadtree(*first);
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

   } else if (testCase == 8) {
      first = new Quadtree(pixel, 1);
      second = new Quadtree(*first);
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

   } else if (testCase == 9) {
      first = new Quadtree(large, 16);
      second = new Quadtree(*first);
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

   } else if (testCase == 10) {
      first = new Quadtree(large, 16);
      second = new Quadtree(*first);
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

      first = new Quadtree(monochrome, 16);
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

   } else if (testCase == 11) {
      first = new Quadtree();
      second = new Quadtree();
      *second = *first;
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

   } else if (testCase == 12) {
      first = new Quadtree(pixel, 1);
      second = new Quadtree();
      *second = *first;
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

   } else if (testCase == 13) {
      first = new Quadtree(large, 16);
      second = new Quadtree();
      *second = *first;
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

   } else if (testCase == 14) {
      first = new Quadtree(large, 16);
      second = new Quadtree();
      *second = *first;
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

      first = new Quadtree(monochrome, 16);
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";

   } else if (testCase == 15) {
      first = new Quadtree(pixel, 1);
      cout << first->getPixel(0, 0) << "\n";

   } else if (testCase == 16) {
      first = new Quadtree(tiny, 2);
      cout << first->getPixel(0, 1) << "\n";

   } else if (testCase == 17) {
      first = new Quadtree(large, 512);
      cout << first->getPixel(302, 178) << "\n";

   } else if (testCase == 18) {
      first = new Quadtree();
      first->clockwiseRotate();
      first->printTree();

   } else if (testCase == 19) {
      first = new Quadtree(tiny, 2);
      first->clockwiseRotate();
      rVal = first->decompress();
      soln.ReadFromFile("tinyRotated.bmp");
      if (rVal == soln)
         cout << "Rotate was successful.\n";
      else
         cout << "Rotate was unsuccessful.\n";

   } else if (testCase == 20) {
      first = new Quadtree(large, 512);
      first->clockwiseRotate();
      rVal = first->decompress();
      soln.ReadFromFile("largeRotated.bmp");
      if (rVal == soln)
         cout << "Rotate was successful.\n";
      else
         cout << "Rotate was unsuccessful.\n";

   } else if (testCase == 21) {
      first = new Quadtree(large, 512);
      first->clockwiseRotate();
      first->clockwiseRotate();
      rVal = first->decompress();
      soln.ReadFromFile("largeRotatedTwice.bmp");
      if (rVal == soln)
         cout << "Rotate was successful.\n";
      else
         cout << "Rotate was unsuccessful.\n";

   } else if (testCase == 22) {
      first = new Quadtree();
      first->prune(13);
      first->printTree();

   } else if (testCase == 23) {
      first = new Quadtree(tiny, 2);
      first->prune(200000);
      first->printTree();

   } else if (testCase == 24) {
      first = new Quadtree(monochrome, 8);
      first->prune(0);
      first->printTree();

   } else if (testCase == 25) {
      first = new Quadtree(large, 512);
      first->prune(10000);
      rVal = first->decompress();
      soln.ReadFromFile("largePruned10k.bmp");
      if (rVal == soln)
         cout << "Prune was successful.\n";
      else
         cout << "Prune was unsuccessful.\n";

   } else if (testCase == 26) {
      first = new Quadtree(large, 512);
      first->prune(10000);
      second = new Quadtree(*first);
      if (*first == *second)
         cout << "Copy was successful.\n";
      else
         cout << "Copy was unsuccessful.\n";

   } else if (testCase == 27) {
      first = new Quadtree(large, 512);
      first->prune(10000);
      first->clockwiseRotate();
      rVal = first->decompress();
      soln.ReadFromFile("largePruned10kRotated.bmp");
      if (rVal == soln)
         cout << "Rotate was successful.\n";
      else
         cout << "Rotate was unsuccessful.\n";

   } else if (testCase == 28) {
      first = new Quadtree(large, 512);
      first->prune(10000);
      cout << first->getPixel(76, 204) << "\n";

   } else if (testCase == 29) {
      first = new Quadtree();
      int ans = first->pruneSize(13);
      cout << ans << "\n";

   } else if (testCase == 30) {
      first = new Quadtree(tiny, 2);
      int ans = first->pruneSize(1);
      cout << ans << "\n";

   } else if (testCase == 31) {
      first = new Quadtree(tiny, 2);
      int ans = first->pruneSize(200000);
      cout << ans << "\n";

   } else if (testCase == 32) {
      first = new Quadtree(monochrome, 8);
      int ans = first->pruneSize(0);
      cout << ans << "\n";

   } else if (testCase == 33) {
      first = new Quadtree(large, 512);
      int ans = first->pruneSize(1000);
      cout << ans << "\n";

   } else if (testCase == 34) {
      first = new Quadtree(tiny, 2);
      int ans = first->idealPrune(1);
      cout << ans << "\n";

   } else if (testCase == 35) {
      first = new Quadtree(tiny, 2);
      int ans = first->idealPrune(3);
      cout << ans << "\n";

   } else if (testCase == 36) {
      first = new Quadtree(monochrome, 8);
      int ans = first->idealPrune(1);
      cout << ans << "\n";

   } else if (testCase == 37) {
      first = new Quadtree(large, 256);
      int ans = first->idealPrune(10000);
      cout << ans << "\n";

   } else if (testCase == 39) {
      first = new Quadtree(large, 512);
      second = new Quadtree(*first);
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
         cout << "Copy doesn't match original.\n";
      *second = *first;
      if (*first == *second)
         cout << "Copy matches original.\n";
      else
        cout << "Copy doesn't match original.\n";
      delete first;
      delete second;

   } else if (testCase == 40) {
      first = new Quadtree(tiny, 2);
      first->clockwiseRotate();
      rVal = first->decompress();
      soln.ReadFromFile("tinyRotated.bmp");
      if (rVal == soln)
         cout << "Rotate was successful.\n";
      else
         cout << "Rotate was unsuccessful.\n";
      delete first;

   } else if (testCase == 41) {
      first = new Quadtree(large, 512);
      first->prune(1000);
      rVal = first->decompress();
      soln.ReadFromFile("largePruned1k.bmp");
      if (rVal == soln)
         cout << "Prune was successful.\n";
      else
         cout << "Prune was unsuccessful.\n";
      delete first;

   } else if (testCase == 42) {
      first = new Quadtree(large, 128);
      int ans = first->idealPrune(1000);
      cout << ans << "\n";
      cout << first->pruneSize(ans) << "\n";
      delete first;

   } else {
      system("g++ -c -w main2.cpp");

   }

   return 0;
}
