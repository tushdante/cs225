#ifndef GRADIENTCOLORPICKER_H
#define GRADIENTCOLORPICKER_H

#include"colorPicker.h"
#include<math.h>
#include<iostream>

class gradientColorPicker : public colorPicker{
  public:
    gradientColorPicker(RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int centerX, int centerY);
    virtual RGBApixel operator()(int x, int y);
    
  private:
	RGBApixel color1;
	RGBApixel color2;	
	int Tradius;
	int TcenterX;
	int TcenterY;   
};

#endif
