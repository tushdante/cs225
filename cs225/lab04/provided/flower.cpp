#include <iostream>
#include "flower.h"

// Constructor for the superclass, Flower
// Allocated memory for the BMP image of the flower and sets the color to replace to NULL
// Returns: Nothing
// Parameters: None
Flower::Flower() {
	flowerImage = new BMP();
	replaceColor = NULL;
}

// Destructor for Flower objects
// the Image is deleted as well as the replaceColor variable
// Returns: Nothing
// Parameters: None
Flower::~Flower() {
	delete flowerImage;
	delete replaceColor;
}

// The default drawFlower method for all flowers. 
// Simply copies each pixel of the flower onto the garden image. No colors are changed
// Returns: Nothing
// Parameters: BMP* garden (The garden image), int x (The Starting x locatin of the image), int y (The starting y location of the image)
void Flower::drawFlower(BMP* garden, int CoordX, int CoordY) {
	int width = flowerImage->TellWidth();
	int height = flowerImage->TellHeight();
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			*((*garden)(CoordX+i, CoordY+j)) = *(*flowerImage)(i,j);
		}
	}
}

// The settor for replaceColor
// Takes the new color and sets the private variable, replaceColor
// Returns: Nothing
// Parameters: RGBApixel* newColor (A pointer to a pixel that holds the new color)
void Flower::setNewColor(RGBApixel* newColor) {
	if (newColor != NULL) {
		if (replaceColor != NULL) {
			delete replaceColor;
		}
		replaceColor = new RGBApixel();
		*replaceColor = *newColor;
	} else {
		replaceColor = NULL;
	}
}

// The Accessor for replaceColor.
// Returns a pointer to the repalceColor variable
// Returns: RGBApixel*
// Parameters: None
RGBApixel * Flower::getNewColor() {
	return replaceColor;
}
