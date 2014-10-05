#include "EasyBMP.h"
#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"


#ifndef IMAGE_H
#define IMAGE_H

/*
This header file declares the methods/functions of class Image, which is a
sub-class of BMP and inherits all of its functionality.
Image adds 3 additional declarations:
1) invertcolors
Inverts the color of a bmp image by taking pixels' current value and 
subtracting them from the maximum value--255.

2) flipleft
Flips the image along a vertical line down the center.

3) adjustbrightness

Adjusts brightness of a bmp image by specified values. Does error handling
to make sure range of pixel remains 0-255.
*/

class Image : public BMP  
{
   
	public:
	void invertcolors(void);
	void flipleft();
	void adjustbrightness(int r, int g, int b);

};
 
#endif
