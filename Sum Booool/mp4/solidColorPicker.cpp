#include "solidColorPicker.h"

//ctor for solidColorPicker class
solidColorPicker::solidColorPicker(RGBApixel fillColor) {
	color=fillColor;
}

//functor to return pixel color
RGBApixel solidColorPicker::operator()(int x, int y) {
	return color;
}
