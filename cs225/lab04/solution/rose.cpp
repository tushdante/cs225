#include "rose.h"

// Constructor for the Rose derived class.
// Sets up the Flower, reads in the image, and sets the original color of the Rose
// Returns: Nothing
// Parameters: None
Rose::Rose() {
	Flower();
	flowerImage->ReadFromFile("rose.bmp");
	originColor = getRoseOriginal();
}

// Destructor for Rose. Deletes the originalColor variable
// Returns: Nothing
// Parameters: None
Rose::~Rose() {
	delete originColor;
}

// Copy Constuctor for Rose.
// Sets up a new Flower, then copies the Image, originalColor and newColor to the new carnation object
// Returns: Nothing
// Parameters: Rose&
Rose::Rose(Rose & source) {
	Flower();
	*flowerImage = *(source.flowerImage);
	originColor = getRoseOriginal();
	setNewColor(source.getNewColor());	
}

// The Rose drawFlower method
// This method prints the image of the individual rose onto the garden image.
// If a new color is specified, it changes the original color to the new color here
// Returns: Nothing
// Parameters: BMP*, int, int
void Rose::drawFlower(BMP* garden, int CoordX, int CoordY) {
	int width = flowerImage->TellWidth();
	int height = flowerImage->TellHeight();
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (getNewColor() == NULL) {
				*((*garden)(CoordX+i, CoordY+j)) = *(*flowerImage)(i,j);
			} else {
				*((*garden)(CoordX+i, CoordY+j)) = changeColors(originColor, getNewColor(), (*flowerImage)(i,j));	
			}
		}
	}
}
