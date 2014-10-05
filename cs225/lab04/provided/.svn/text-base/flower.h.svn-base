#ifndef FLOWER_H
#define FLOWER_H
#include "EasyBMP.h"

class Flower
{
public:
	Flower();
	virtual ~Flower();
	virtual void drawFlower(BMP* garden, int CoordX, int CoordY);
	void setNewColor(RGBApixel* newColor);
	RGBApixel * getNewColor();
protected:
	BMP * flowerImage;
private:
	RGBApixel* replaceColor;
};


#endif

