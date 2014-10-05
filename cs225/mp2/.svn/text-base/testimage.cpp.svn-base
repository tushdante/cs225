/**********************************************************
 * testimage.cpp -- part of CS225 MP2
 *
 * This file performs some basic tests of the Image class.
 * It is not intended to catch every possible error.You may 
 * modifty this or write your own testimage.cpp to perform 
 * additional tests.
 *
 *   Author: Jonathan Ray
 *     Date: 02 Feb 2007
 */

#include "image.h"

int main()
{
   Image* myImage = new Image();
   bool b = myImage->ReadFromFile("in_01.bmp");
   myImage->invertcolors();
   b = myImage->WriteToFile("inverted.bmp");

   myImage->flipleft();
   b = myImage->WriteToFile("flipped.bmp");
	
   myImage->adjustbrightness(20, 20, -40);
   b = myImage->WriteToFile("brightened.bmp");

   delete myImage;
	
   return 0;
}

