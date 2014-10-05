#ifndef GARDEN_H
#define GARDEN_H
#include "EasyBMP.h"
#include "flower.h"

class Garden
{
public:
	Garden(int x, int y);
	~Garden();
	Garden(Garden & source);
	void drawGarden(char* filename);
	void addFlower(Flower* newFlower);
private:
	int x, y;
	Flower* * flowers;
	int getVacantFlowerBed();
};

#endif
