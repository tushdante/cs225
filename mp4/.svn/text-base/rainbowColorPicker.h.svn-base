#ifndef RAINBOWCOLORPICKER_H
#define RAINBOWCOLORPICKER_H

#include <map>
#include <utility>
#include "colorPicker.h"

class rainbowColorPicker : public colorPicker{
  public:
    rainbowColorPicker(long double freq_);
    virtual RGBApixel operator()(int x, int y);

  private:
    RGBApixel nextColor();

    typedef std::map<std::pair<int, int>, RGBApixel> BMPmap;
    size_t iter;
    BMPmap prev;
	long double freq;
};

#endif
