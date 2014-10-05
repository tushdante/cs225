#include "garden.h"
#include "rose.h"
#include <iostream>

int main() {
Garden * myGarden = new Garden(2, 2);

Rose * myRose = new Rose();
myGarden->addFlower(myRose);

Rose *myRoseTwo = new Rose();
RGBApixel* newColor = new RGBApixel();
newColor->Red = 0;
newColor->Blue = 255;
newColor->Green = 0;
myRoseTwo->setNewColor(newColor);
myGarden->addFlower(myRoseTwo);

Rose *myRoseThree = new Rose(*myRoseTwo);
myGarden->addFlower(myRoseThree);

Rose *myRoseFour = new Rose(*myRose);
myGarden->addFlower(myRoseFour);



myGarden->drawGarden("out_roses.bmp");

delete myGarden;
delete newColor;

return 0;
}
