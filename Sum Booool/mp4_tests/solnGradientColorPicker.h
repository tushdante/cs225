#ifndef solnGradientCOLORPICKER_H
#define solnGradientCOLORPICKER_H

#include"colorPicker.h"
#include<math.h>
#include<iostream>

class solnGradientColorPicker : public colorPicker{
  public:
    solnGradientColorPicker(RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int centerX, int centerY);
    virtual RGBApixel operator()(int x, int y);
  private:
    int distance(int x1, int y1, int x2, int y2);

    RGBApixel color1, color2;
    int rad, cX, cY;
};

#endif
