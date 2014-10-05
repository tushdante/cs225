/**********************************************************
* image.h --part of mp2
* This defines functions that allow pictures to be inverted, 
* flipped left, and brightened.
* Date: Sept 6, 2010
**********************************************************/

/**********************************************************
* Class: Image
* Derived from: BMP
* Objects of this class is a subset of the BMP class. All
* of the public BMP class in inherited, and a definition of
* invertedcolors(), flipleft(), and adjustbrightness() are 
* added.
***********************************************************/
#ifndef IMAGE_H
#define IMAGE_H
#include "EasyBMP.h"
class Image:public BMP{
	public:
	
	// invertedcolors goes through a picture pixel by pixel
	// and inverts the RGB colors.
	void invertcolors();
	
	// flipleft flipps an image over a vertical axis through
	// its axis.
	void flipleft();

	// adjustbrightness goes through the image pixel by pixel 
	// and adds brightness to the image by adding r to the red
	// components, g to the green components and b to the 
	// blue components.
	void adjustbrightness(int r, int g, int b);
};
#endif

