/**********************************************************
* image.cpp --part of mp2
* These functions allow pictures to be inverted, 
* flipped left, and brightened.
* Date: Sept 6, 2010
**********************************************************/


#include "image.h"
#include "EasyBMP.h"

// invertedcolors goes through a picture pixel by pixel
// and inverts the RGB colors.
void Image::invertcolors(){
	int i,j,Width,Height;
	Width=TellWidth();
	Height=TellHeight();
	
	// initialize pointer that will point to color information 
	RGBApixel* ipic;
		

	// runs horizontally across the image
  	for (i=0;i<=(Width-1);i++){

	// runs vertically across image
		for (j=0;j<=(Height-1);j++){
			// allows the image that was called to be used
			ipic=(*this)(i,j);
		// code for changing output image  
			ipic->Red = 255-(ipic->Red); 
          		ipic->Green =255-(ipic->Green); 
          		ipic->Blue = 255-(ipic->Blue); 
		}
	}
}

// flipleft flipps an image over a vertical axis through
// its axis.
void Image::flipleft(){
	int i,j,Width,Height,w;
	Width=TellWidth();
	Height=TellHeight();

	//initialize pointer to point to color information
	RGBApixel *fl,*fl2;

	// initialie temp variables to hold color information
	unsigned char temp_red,temp_green,temp_blue;
	for (j=0;j<Height;j++){
		for(i=0,w=Width-1;i!=Width/2;i++,w-=2){
			// fl= current (i,j) [left side of vertical flip line]
			// fl2= swap (i,j) [right side of vertical flip line]
			fl=(*this)(i,j);
			fl2=(*this)(i+w,j);
	
			//get temp information of current pixel
			temp_red = fl->Red;
			temp_green=fl->Green;
			temp_blue=fl->Blue;

			// replace current pixel with swap pixel
			fl->Red=fl2->Red;
			fl->Green=fl2->Green;
			fl->Blue=fl2->Blue;

			// replce swap pixel with old current pixel information
			fl2->Red=temp_red;
			fl2->Green=temp_green;
			fl2->Blue=temp_blue;
		}
	}
}

// adjustbrightness goes through the image pixel by pixel 
// and adds brightness to the image by adding r to the red
// components, g to the green components and b to the 
// blue components.
void Image::adjustbrightness(int r, int g, int b){
	int i,j,Width,Height;
	Width=TellWidth();
	Height=TellHeight();

	// initializes pointer for pointing to color information
	RGBApixel* ab;
		

	// runs horizontally across the image
  	for (i=0;i<=(Width-1);i++){

	// runs vertically across image
		for (j=0;j<=(Height-1);j++){
			ab=(*this)(i,j);
			// code for changing output image 
			// checks if new values are <0 or >255 for all colors 
			if (((ab->Red)+r)<0)
				ab->Red = 0;
			else if (((ab->Red)+r)>255)
				ab->Red = 255;
			else
				ab->Red = (ab->Red)+r;
			
			if (((ab->Green)+g)<0)
				ab->Green = 0;
			else if (((ab->Green)+g)>255)
				ab->Green = 255;
			else 
          			ab->Green =(ab->Green)+g;

			if (((ab->Blue)+b)<0)
				ab->Blue = 0;
			else if (((ab->Blue)+b)>255)
				ab->Blue = 255;
			else 
          			ab->Blue = (ab->Blue)+b;
		}
	}
}



			
	
