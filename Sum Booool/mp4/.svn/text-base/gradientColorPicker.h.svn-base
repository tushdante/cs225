/******************************************************************************
* Class gradientColorPicker
* Derived from: colorPicker
* Contains a virtual functor that was derived from a purely virtual declaration
* from the derived class
******************************************************************************/

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
    RGBApixel color1, color2;
    int r, c_x, c_y;
};

#endif
