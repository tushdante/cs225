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
#include<math.h>


// High level wrappers for the driver functions
animation DFSfillSolid(BMP & img, int x, int y, RGBApixel fillColor, int tolerance, int frameFreq);
animation DFSfillGrid(BMP & img, int x, int y, RGBApixel gridColor, int gridSpacing, int tolerance, int frameFreq);
animation DFSfillGradient(BMP & img, int x, int y, RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int tolerance, int frameFreq);

animation BFSfillSolid(BMP & img, int x, int y, RGBApixel fillColor, int tolerance, int frameFreq);
animation BFSfillGrid(BMP & img, int x, int y, RGBApixel gridColor, int gridSpacing, int tolerance, int frameFreq);
animation BFSfillGradient(BMP & img, int x, int y, RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int tolerance, int frameFreq);


// Driver functions
animation DFSfill(BMP & img, int x, int y, colorPicker & fillColor, int tolerance, int frameFreq);
animation BFSfill(BMP & img, int x, int y, colorPicker & fillColor, int tolerance, int frameFreq);

#include "fills.cpp"
#endif
