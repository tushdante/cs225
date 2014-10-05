#include "garden.h"
#include "rose.h"
#include "lilac.h"
#include "carnation.h"
#include <iostream>

int main() {
Garden * myGarden = new Garden(3, 3);

Rose *myRose = new Rose();

Rose *myRoseTwo = new Rose();
RGBApixel* newColor = new RGBApixel();
newColor->Red = 0;
newColor->Blue = 255;
newColor->Green = 0;
myRoseTwo->setNewColor(newColor);

Rose *myRoseThree = new Rose(*myRose);
newColor->Red = 0;
newColor->Blue = 0;
newColor->Green = 0;
myRoseThree->setNewColor(newColor);

Rose *myRoseFour = new Rose();
newColor->Red = 255;
newColor->Blue = 201;
newColor->Green = 174;
myRoseFour->setNewColor(newColor);


Carnation *myCarn = new Carnation();

Carnation *myCarnTwo = new Carnation();
newColor->Red = 0;
newColor->Blue = 0;
newColor->Green = 0;
myCarnTwo->setNewColor(newColor);

Carnation *myCarnThree = new Carnation();
newColor->Red = 255;
newColor->Blue = 201;
newColor->Green = 174;
myCarnThree->setNewColor(newColor);

Lilac *myLilac = new Lilac();

Lilac *myLilacTwo = new Lilac();
newColor->Red = 218;
newColor->Blue = 2;
newColor->Green = 223;
myLilacTwo->setNewColor(newColor);


myGarden->addFlower(myRose);
myGarden->addFlower(myCarn);
myGarden->addFlower(myRoseTwo);
myGarden->addFlower(myLilac);
myGarden->addFlower(myRoseFour);
myGarden->addFlower(myCarnTwo);
myGarden->addFlower(myLilacTwo);
myGarden->addFlower(myRoseThree);
myGarden->addFlower(myCarnThree);



myGarden->drawGarden("out_garden.bmp");
return 0;
}
