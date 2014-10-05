#include "garden.h"
#include "lilac.h"
#include <iostream>

int main() {
Garden * myGarden = new Garden(2, 2);

Lilac *myLilac = new Lilac();
myGarden->addFlower(myLilac);

Lilac *myLilacTwo = new Lilac();
RGBApixel* newColor = new RGBApixel();
newColor->Red = 0;
newColor->Blue = 255;
newColor->Green = 0;
myLilacTwo->setNewColor(newColor);
myGarden->addFlower(myLilacTwo);

Lilac *myLilacThree = new Lilac(*myLilacTwo);
myGarden->addFlower(myLilacThree);

Lilac *myLilacFour = new Lilac(*myLilac);
newColor->Red = 255;
newColor->Blue = 0;
newColor->Green = 0;
myLilacFour->setNewColor(newColor);
myGarden->addFlower(myLilacFour);

myGarden->drawGarden("out_lilacs.bmp");
return 0;
}
