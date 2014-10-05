#include "gridColorPicker.h"


gridColorPicker::gridColorPicker(RGBApixel gridColor, int gridSpacing) {
  color = gridColor;
  spacing = gridSpacing;
}

RGBApixel gridColorPicker::operator()(int x, int y) {
  if(x % spacing == 0 || y % spacing == 0){
    return color;
  }else {
    RGBApixel ret;
    ret.Red = ret.Blue = ret.Green = ret.Alpha  = 255;
    return ret;
  }
}
