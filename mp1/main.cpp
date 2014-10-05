/*
This program reads a bmp from a file named "in.bmp" (exe has to be in same
folder as this file) and rotates the image by 180 degrees. The rotated
image is output into a new file "out.bmp" which contains the same dimensions
as the original.

*/
#include "EasyBMP.h"
#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"

/* 
This function takes an image and rotates it 180 degrees.
The original BMP image is passed as a parameter as well as its 
width and height (assuming it's greater than 0 for it to function, but 
not necessarily).
I subtracted 1 from width and height before passing them from main
to accomodate pixels and counters (i &j) starting at 0.
The function returns the rotated BMP image.
*/

BMP rotate180(BMP original, int width, int height)
{
   BMP Rotated;
   int width2=width;
   int height2=height;

   Rotated.SetSize(width2+1,height2+1);


/*
This loop implements the rotation. It takes the pixel at (0,0) of the original
(top left corner) & puts it at the bottom right corner of the new rotated image.
The bottom right corner (width, height) is defined by the maximum values of the 
image using .TellWidth/.TellHeight functions.
(0,0) is incremented with counters i,j while (width, height) is decremented.
*/
		for (int i = 0 ; i<=width ; i++, width2--)
    		{
       	 	for (int j = 0, height2=height; j<=height ; j++, height2--)
       	 	{
				(Rotated(width2, height2))->Red= (original(i,j)->Red);
				(Rotated(width2, height2))->Green= (original(i,j)->Green);
				(Rotated(width2, height2))->Blue= (original(i,j)->Blue);
				}
		}

	return Rotated;
}




int main ()
{
   BMP InputPic;
   BMP OutputPic;

   InputPic.ReadFromFile("in.bmp");

   OutputPic=rotate180(InputPic,InputPic.TellWidth()-1,InputPic.TellHeight()-1);
   OutputPic.WriteToFile("out.bmp");

   return 0;
}
