#ifndef GRIDCOLORPICKER_H
#define GRIDCOLORPICKER_H

#include"colorPicker.h"

class gridColorPicker : public colorPicker{
  public:
    gridColorPicker(RGBApixel fillColor, int gridSpacing);
    virtual RGBApixel operator()(int x, int y);
  private:
    RGBApixel color;
    int spacing;
};

#endif
