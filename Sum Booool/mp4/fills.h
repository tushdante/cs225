#ifndef FILLS_H
#define FILLS_H

//includes 
#include<EasyBMP.h>
#include"stack.h"
#include"queue.h"
#include"solidColorPicker.h"
#include"gridColorPicker.h"
#include"gradientColorPicker.h"
#include"animation.h"


// High level wrappers for the _aux functions
animation DFSfillSolid(BMP& img, int x, int y, RGBApixel fillColor, int tolerance, int frameFreq);
animation DFSfillGrid(BMP& img, int x, int y, RGBApixel gridColor, int gridSpacing, int tolerance, int frameFreq);
animation DFSfillGradient(BMP& img, int x, int y, RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int tolerance, int frameFreq);

animation BFSfillSolid(BMP& img, int x, int y, RGBApixel fillColor, int tolerance, int frameFreq);
animation BFSfillGrid(BMP& img, int x, int y, RGBApixel gridColor, int gridSpacing, int tolerance, int frameFreq);
animation BFSfillGradient(BMP& img, int x, int y, RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int tolerance, int frameFreq);


// Driver functions
template<typename pickerType>
animation DFSfill_aux(BMP& img, int x, int y, pickerType pickColor, int tolerance, int frameFreq);
template<typename pickerType>
animation BFSfill_aux(BMP& img, int x, int y, pickerType pickColor, int tolerance, int frameFreq);

#include "fills.cpp"
#endif
