/*************************************************\
|                                                 |
|  testpartone.cpp -- CS225 MP3, Spring '09       |
|                                                 |
|  This file tests the five List functions        |
|    added in MP3.                                |
|                                                 |
|  Written by John Fischer, Fall '06; slight      |
|    changes by Bill Kinnersley, Spring '07;      |
|    slight changes by Daniel Hoodin, Spring      |
|    '09                                          |
|                                                 |
\*************************************************/

#include <iostream>
#include <string>
#include "EasyBMP.h"
#include "doubly-linked-list.h"

using std::string;
using std::cout;
using std::endl;
using std::ostream;


// The List class assumes the existence of operator==, operator!=, and
//   operator<< for its elements.  The EasyBMP library does not provide
//   these out of the box for RGBApixels, so we implement them here.

bool operator==(RGBApixel const & left, RGBApixel const & right)
{
   return (left.Red == right.Red && left.Green == right.Green &&
           left.Blue == right.Blue && left.Alpha == right.Alpha);
}

bool operator!=(RGBApixel const & left, RGBApixel const &right)
{
   return !(left == right);
}

ostream & operator<<(ostream & out, RGBApixel pixel)
{
   out << "Pixel with color value (";
   out << pixel.Red << "," << pixel.Green << "," << pixel.Blue << ")\n";
   return out;
}

// Utility function which rebuilds an image from a list of pixels
void buildImage(BMP & image, List<RGBApixel> theList, int width, int height) 
{
   if (width * height != theList.length()) {
      cout << "Error: invalid parameters to buildImage.\n";
      return;
   }

   image.SetSize(width, height);
   int x = 0, y = 0;
   theList.front();
   for (int pos = 0; pos < theList.length(); pos++) {
      *image(x,y) = theList.retrieve();

      // move to next pixel position
      x++;
      if (x >= width) {
         x = 0;
         y++;
      }

      // avoid spurious warning message
      if (pos != theList.length() - 1)
         theList.forwardOne();
   }
}

void setup(string const & filename, List<RGBApixel> & pixelList, int & width, int & height)
{
   BMP imgIn;
   imgIn.ReadFromFile(filename.c_str());

   width = imgIn.TellWidth();
   height = imgIn.TellHeight();

   // fill list with pixels
   pixelList.clear();
   for (int y = 0; y < height; y++)
      for(int x = 0; x < width; x++)
         pixelList.insertAfter(*imgIn(x,y));
}

// test -- removeNth()
void testRemoveNth()
{
   int width, height;
   List<RGBApixel> pixelList;
   setup("in_01.bmp", pixelList, width, height);

   pixelList.removeNth(4, 2);

   // reconstruct the image
   // note: original width was divisible by four, so this works
   BMP imgOut;
   buildImage(imgOut, pixelList, 3 * (width / 4) , height);
   imgOut.WriteToFile("removed.bmp");
}

// test -- tripleRotate()
void testTripleRotate()
{
   int width, height;
   List<RGBApixel> pixelList;
   setup("in_02.bmp", pixelList, width, height);
   pixelList.tripleRotate(4);

   BMP imgOut;
   buildImage(imgOut, pixelList, width, height);
   imgOut.WriteToFile("rotated.bmp");
}

int main()
{
   testRemoveNth();
   testTripleRotate();

   return 0;
}

