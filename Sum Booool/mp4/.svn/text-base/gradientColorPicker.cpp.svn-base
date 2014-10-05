#include "gradientColorPicker.h"

//ctor for gradientColorPicker class
gradientColorPicker::gradientColorPicker(RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int centerX, int centerY) {
   color1=fadeColor1;
   color2=fadeColor2;
   r=radius;
   c_x=centerX;
   c_y=centerY;
}

//functor to return pixel color
RGBApixel gradientColorPicker::operator()(int x, int y) {
   RGBApixel ret;
   int d=abs(c_x - x) + abs(c_y - y); //calcuate d
   if (d<r){
    //calculate gradient color
    ret.Red=color1.Red-floor(d*color1.Red/r)+floor(d*color2.Red/r);
    ret.Green=color1.Green-floor(d*color1.Green/r)+floor(d*color2.Green/r);
    ret.Blue=color1.Blue-floor(d*color1.Blue/r)+floor(d*color2.Blue/r);
   }
   else{
    ret.Red=color2.Red;
    ret.Green=color2.Green;
    ret.Blue=color2.Blue;
   }
   return ret;
}
