#ifndef ROSE_H
#define ROSE_H
#include "flower.h"
#include "gardenHelper.h"

class Rose : public Flower
{
public:
	Rose();
	Rose(Rose & source);
	~Rose();
	void drawFlower(BMP* garden, int CoordX, int CoordY);
private:
	RGBApixel* originColor;
	
};

#endif
