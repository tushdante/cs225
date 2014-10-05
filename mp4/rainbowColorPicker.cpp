#include "rainbowColorPicker.h"
#include <math.h>

using std::pair;
using std::map;

rainbowColorPicker::rainbowColorPicker(long double freq_)
	: iter(0), freq(freq_) {
	
}

RGBApixel rainbowColorPicker::operator()(int x, int y) {
	BMPmap::iterator stored = prev.find(pair<int,int>(x, y));
	if (stored == prev.end())
	{
		RGBApixel next = nextColor();
		prev[pair<int,int>(x, y)] = next;
		return next;
	}
	else
		return stored->second;
}

// http://www.krazydad.com/makecolors.php
RGBApixel rainbowColorPicker::nextColor() {
	RGBApixel ret;
	ret.Red   = (uint8_t)(sin(freq*iter + 0) * 127 + 128);
	ret.Green = (uint8_t)(sin(freq*iter + 2) * 127 + 128);
	ret.Blue  = (uint8_t)(sin(freq*iter + 4) * 127 + 128);
	iter++;
	return ret;
}
