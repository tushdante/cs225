/*

Note to students:  Most of the Scene-related tests use getpicture() to verify that
  your methods have done the right thing.  This means that if your getpicture()
  method had any errors, then you failed most of the test cases.  If this happened
  to you, contact me and I'll give you back some points (although hopefully
  getpicture() is simple enough that nobody screwed it up).  Likwise, if your
  default constructor had errors, and caused you to fail every test case, let me
  know and I'll look into it.
  Some tests are classified under one method, but also use another.  I will probably
  NOT give back points if you miss one of those because one of the two methods didn't
  work correctly.  I will, however, try to make the dependence as weak as possible.

Regarding memory leaks in the testing code: they're intentional.  I wanted to make
  sure that buggy destructors didn't cause people to fail every test.

Regarding valgrind tests: To get ANY credit on the valgrind test cases, your code
  must run correctly (i.e. produce the correct output) and must not perform any
  illegal memory operations (illegal write, read of uninitialized value, segfault,
  etc.)  The first condition is necessary because otherwise, code that literally
  does nothing at all would receive full credit on these tests, and that's dumb.
  The second condition is necessary because illegal memory operations almost always
  indicate code that "shouldn't" work (although such code will sometimes run
  successfully in practice, usually through luck or coincidence).  If both of those
  conditions are met, the number of points awarded is determined by how many bytes
  were leaked; the cutoffs are individually chosen for each test case, and are based
  on my analysis of the possible causes for memory leaks in each test.


Test cases:

Image tests -- 30 points total
  invertcolors() -- 8 points
    #1 (8) - straightforward, no tricks
  flipleft() -- 10 points
    #2 (5) - even width image
    #3 (5) - odd width image
  adjustbrightness() -- 12 points
    #4 (6) - no overflow
    #5 (3) - "upward" overflow
    #6 (3) - "downward" overflow

Scene tests -- 55 points total
  addpicture() -- 5 points
    #7 (3) - no tricks
    #8 (2) - invalid indices
  getpicture() -- 4 points
    #9 (2) - make sure picture can be changed through returned pointer
    #10 (2) - invalid parameter
  changemaxlayers() -- 6 points
    #11 (3) - increase # layers, attempt to add in new slot
    #12 (1) - decrease # layers, attempt to add in slot that shouldn't be there anymore
    #13 (2) - invalid parameter
  copy constructor -- 5 points
    #14 (3) - attempt to get picture from copy
    #15 (2) - change copy, see if original is changed
  assignment operator -- 5 points
    #16 (3) - same as #14
    #17 (2) - same as #15
  changelayer() -- 5 points
    #18 (3) - move picture to new layer, check to make sure it's there
    #19 (2) - invalid parameters
  drawscene() -- 16 points
    #20 (3) - small composition, no NULLs, size determined by bottom layer
    #21 (3) - small composition, some NULLs, size determined by bottom layer
    #22 (3) - small composition, no NULLs, size not determined by bottom layer
    #23 (3) - small composition, some NULLs, size not determined by bottom layer
    #24 (2) - make sure changelayer() deletes source image
    #25 (2) - make sure deletepicture() deletes the picture
  translate() -- 6 points
    #26 (2) - no tricks
    #27 (2) - translate to stretch dimensions, and back
    #28 (2) - invalid indices (NULL, out of range)
  deletepicture() -- 3 points (but see also test #26)
    #29 (1) - make sure index gets set to NULL (via translate())
    #30 (2) - invalid parameters

valgrind tests -- 15 points total
  #31 (5) - Image functions
  #32 (5) - Scene copy constructor, assignment operator; #14, #16
  #33 (5) - Scene miscellany

To be checked manually for deductions:
  Insufficient commenting, up to -10 points
  Extra buffer in Image::flipleft(), -10 points

*/


#include <iostream>
#include "EasyBMP.h"
#include "image.h"
#include "scene.h"

using std::cout;
using std::endl;
using std::cin;

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

   Image theImage, soln;
   Scene *firstScene, *secondScene;
   Image red, green, blue, yellow, black, input;

   // lazy; just gonna read in all of these every time
   red.ReadFromFile("red10.bmp");
   green.ReadFromFile("green10.bmp");
   blue.ReadFromFile("blue10.bmp");
   yellow.ReadFromFile("yellow10.bmp");
   black.ReadFromFile("black100.bmp");


   if (testCase == 1) {
      theImage.ReadFromFile("gradientEven.bmp");
      theImage.invertcolors();
      soln.ReadFromFile("gradientEvenInverted.bmp");
      if (theImage == soln)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 2) {
      theImage.ReadFromFile("gradientEven.bmp");
      theImage.flipleft();
      soln.ReadFromFile("gradientEvenFlipped.bmp");
      if (theImage == soln)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 3) {
      theImage.ReadFromFile("gradientOdd.bmp");
      theImage.flipleft();
      soln.ReadFromFile("gradientOddFlipped.bmp");
      if (theImage == soln)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 4) {
      theImage.ReadFromFile("gradientEven.bmp");
      theImage.adjustbrightness(-25, 0, 25);
      soln.ReadFromFile("gradientEvenBright1.bmp");
      if (theImage == soln)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 5) {
      theImage.ReadFromFile("gradientEven.bmp");
      theImage.adjustbrightness(-120, -180, 2);
      soln.ReadFromFile("gradientEvenBright2.bmp");
      if (theImage == soln)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 6) {
      theImage.ReadFromFile("gradientEven.bmp");
      theImage.adjustbrightness(130, 7, 313);
      soln.ReadFromFile("gradientEvenBright3.bmp");
      if (theImage == soln)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 7) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      if (*(firstScene->getpicture(1)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 8) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", -1, 13, 72);
      firstScene->addpicture("red10.bmp", 0, 13, 72);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      firstScene->addpicture("red10.bmp", 2, 13, 72);

   } else if (testCase == 9) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      *(firstScene->getpicture(1)) = blue;
      if (*(firstScene->getpicture(1)) == blue)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 10) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      firstScene->getpicture(-1);
      firstScene->getpicture(2);

   } else if (testCase == 11) {
      firstScene = new Scene(2);
      firstScene->changemaxlayers(5);
      firstScene->addpicture("red10.bmp", 4, 13, 72);
      if (*(firstScene->getpicture(4)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 12) {
      firstScene = new Scene(2);
      firstScene->changemaxlayers(1);
      firstScene->addpicture("red10.bmp", 1, 13, 72);

   } else if (testCase == 13) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      firstScene->changemaxlayers(1);
      if (*(firstScene->getpicture(1)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 14) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      secondScene = new Scene(*firstScene);
      if (*(secondScene->getpicture(1)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 15) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      secondScene = new Scene(*firstScene);
      *(firstScene->getpicture(1)) = blue;
      if (*(secondScene->getpicture(1)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 16) {
      firstScene = new Scene(2);
      secondScene = new Scene(1);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      *secondScene = *firstScene;
      if (*(secondScene->getpicture(1)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 17) {
      firstScene = new Scene(2);
      secondScene = new Scene(1);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      *secondScene = *firstScene;
      *(firstScene->getpicture(1)) = blue;
      if (*(secondScene->getpicture(1)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 18) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      firstScene->addpicture("blue10.bmp", 0, 13, 72);
      firstScene->changelayer(1, 0);
      if (*(firstScene->getpicture(0)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 19) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      firstScene->changelayer(-1, 1);
      firstScene->changelayer(1, 2);
      if (*(firstScene->getpicture(1)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 20) {
      firstScene = new Scene(5);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 1, 5, 7);
      firstScene->addpicture("blue10.bmp", 2, 71, 84);
      firstScene->addpicture("green10.bmp", 3, 86, 2);
      firstScene->addpicture("yellow10.bmp", 4, 13, 12);
      soln.ReadFromFile("drawscene1.bmp");
      if (soln == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 21) {
      firstScene = new Scene(11);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 4, 5, 7);
      firstScene->addpicture("blue10.bmp", 7, 71, 84);
      firstScene->addpicture("green10.bmp", 8, 86, 2);
      firstScene->addpicture("yellow10.bmp", 10, 13, 12);
      soln.ReadFromFile("drawscene1.bmp");
      if (soln == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 22) {
      firstScene = new Scene(5);
      firstScene->addpicture("black100.bmp", 1, 10, 0);
      firstScene->addpicture("red10.bmp", 0, 0, 7);
      firstScene->addpicture("blue10.bmp", 2, 71, 94);
      firstScene->addpicture("green10.bmp", 3, 106, 2);
      firstScene->addpicture("yellow10.bmp", 4, 13, 12);
      soln.ReadFromFile("drawscene2.bmp");
      if (soln == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 23) {
      firstScene = new Scene(10);
      firstScene->addpicture("black100.bmp", 4, 10, 0);
      firstScene->addpicture("red10.bmp", 0, 0, 7);
      firstScene->addpicture("blue10.bmp", 7, 71, 94);
      firstScene->addpicture("green10.bmp", 9, 106, 2);
      firstScene->addpicture("yellow10.bmp", 10, 13, 12);
      soln.ReadFromFile("drawscene2.bmp");
      if (soln == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 24) {
      firstScene = new Scene(3);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 1, 10, 7);
      firstScene->addpicture("blue10.bmp", 2, 71, 84);
      firstScene->changelayer(1, 2);
      soln.ReadFromFile("drawscene3.bmp");
      if (soln == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 25) {
      firstScene = new Scene(3);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 1, 10, 7);
      firstScene->addpicture("blue10.bmp", 2, 71, 84);
      firstScene->deletepicture(2);
      soln.ReadFromFile("drawscene3.bmp");
      if (soln == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 26) {
      firstScene = new Scene(2);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 1, 10, 7);
      firstScene->translate(1, 45, 45);
      soln.ReadFromFile("drawscene4.bmp");
      if (soln == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 27) {
      firstScene = new Scene(2);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 1, 10, 7);
      firstScene->translate(1, 145, 45);
      firstScene->translate(1, 45, 145);
      soln.ReadFromFile("drawscene5.bmp");
      if (soln == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 28) {
      firstScene = new Scene(3);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 1, 10, 7);
      firstScene->translate(2, 145, 45);
      firstScene->translate(-1, 45, 145);
      firstScene->translate(3, 45, 145);

   } else if (testCase == 29) {
      firstScene = new Scene(3);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 2, 10, 7);
      firstScene->deletepicture(2);
      firstScene->translate(2, 145, 45);

   } else if (testCase == 30) {
      firstScene = new Scene(3);
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 2, 10, 7);
      firstScene->deletepicture(-1);
      firstScene->deletepicture(3);
      firstScene->deletepicture(1);

   } else if (testCase == 31) {
      theImage.ReadFromFile("gradientEven.bmp");
      theImage.adjustbrightness(10, -15, 23);
      theImage.invertcolors();
      theImage.flipleft();
      soln.ReadFromFile("gradientEvenEverything.bmp");
      if (theImage == soln)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";

   } else if (testCase == 32) {
      firstScene = new Scene(2);
      firstScene->addpicture("red10.bmp", 1, 13, 72);
      secondScene = new Scene(*firstScene);
      if (*(secondScene->getpicture(1)) == red)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";
      firstScene->addpicture("blue10.bmp", 0, 5, 5);
      *(firstScene->getpicture(1)) = green;
      *secondScene = *firstScene;
      if (*(secondScene->getpicture(1)) == green)
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";
      delete secondScene;
      delete firstScene;

   } else {  // testCase == 33
      firstScene = new Scene(2); //was 2
      firstScene->addpicture("black100.bmp", 0, 0, 0);
      firstScene->addpicture("red10.bmp", 1, 10, 7);
      firstScene->translate(1, 45, 45);
      *(firstScene->getpicture(1)) = blue;
      firstScene->changemaxlayers(5);
      firstScene->addpicture("blue10.bmp", 3, 4, 5);    
      firstScene->changelayer(1, 3); //was (1,3)
      firstScene->deletepicture(3);
      if (black == firstScene->drawscene())
         cout << "Output image matches solution.\n";
      else
         cout << "Output image does not match solution.\n";
      delete firstScene;

   }

   return 0;
}
