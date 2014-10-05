#ifndef CARNATION_H
#define CARNATION_H
#include "flower.h"
#include "gardenHelper.h"

class Carnation : public Flower
{
public:
	Carnation();
	~Carnation();
	Carnation(Carnation & source);
	void drawFlower(BMP* garden, int CoordX, int CoordY);
private:
	RGBApixel* originColor;
};

#endif
