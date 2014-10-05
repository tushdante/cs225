#include "image.h"
#include <algorithm>
#if !defined(max)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

/*
This method inverts the color of a bmp image by taking pixels' current value & 
subtracting it from the maximum value: 255. Does so by looping through all
pixels in an image, regardless of dimensions.
*/
void Image :: invertcolors(void)
{
	if(this==NULL)
	{
	return;
	}
	
	
	int red;
	int green;
	int blue;
	
	int width = this->TellWidth();
	int height= this->TellHeight();
	
		for (int i = 0 ; i<(width) ; i++)
    		{
       	 	for (int j = 0; j<(height) ; j++)
       	 	{
				red  =((*this)(i,j)->Red);
				green=((*this)(i,j)->Green);
				blue =((*this)(i,j)->Blue);
				
				
				((*this)(i,j)->Red)=255-red;
				((*this)(i,j)->Green)=255-green;
				((*this)(i,j)->Blue)=255-blue;
				}
			}
};

/*
This method flips/reflects an image down the center, vertically.
It does so by taking the pixel in the upper left hand, storing it into a 
temporary struct, swapping the top left pixel with the one from the top right, 
and then assigning the temporary pixel to the top right.
The loop forces this procedure to continue down the column until it reaches
the bottom of the image. Once it does so, the outside loop moves this same
procedure over a column, closer towards the middle until the center is 
reached.
*/
void Image ::  flipleft()
{
	if(this==NULL)
	{
	return;
	}
	
   RGBApixel TempPixel;
   int width = (this->TellWidth())-1;
	int height= (this->TellHeight())-1;
   
   int width2=width;
   
   
   	
		for (int i = 0 ; i<=(width/2) ; i++, width2--)
    		{
    		
       	 	for (int j = 0; j<=height ; j++)
       	 	{
				TempPixel.Red   = ((*this)(i, j))->Red;
				TempPixel.Green = ((*this)(i, j))->Green;
				TempPixel.Blue  = ((*this)(i, j))->Blue;
				
				((*this)(i, j))->Red   = ((*this)(width2, j)->Red);
				((*this)(i, j))->Green = ((*this)(width2, j)->Green);
				((*this)(i, j))->Blue  = ((*this)(width2, j)->Blue);
				
				((*this)(width2, j)->Red)   = TempPixel.Red;
				((*this)(width2, j)->Green) = TempPixel.Green;
				((*this)(width2, j)->Blue)  = TempPixel.Blue;
				}
		}
    
};

/*
Adjusts brightness of a bmp image by specified parameters. Does error handling
to make sure range of pixel remains 0-255 utilizing the min/max functions.
*/
void Image :: adjustbrightness(int r, int g, int b)
{
	if(this==NULL)
	{
	return;
	}
	
	
   int width = (this->TellWidth())-1;
	int height= (this->TellHeight())-1;
   

   for (int i =0; i <=width; i++)
	{
   	for (int j =0; j <=height; j++)
      {
		((*this)(i, j))->Red   = max(0, min( 255, (((*this)(i, j)->Red)+r)));
		((*this)(i, j))->Green = max(0, min( 255, (((*this)(i, j)->Green)+g)));
		((*this)(i, j))->Blue  = max(0, min( 255, (((*this)(i, j)->Blue)+b)));
         
      }
	}

};
