#include "lilac.h"

// Constructor for the Lilac derived class.
// Sets up the Flower, reads in the image, and sets the original color of the lilac
// Returns: Nothing
// Parameters: None
Lilac::Lilac() {
	Flower();
	flowerImage->ReadFromFile("lilac.bmp");
	originColor = getLilacOriginal();
}

// Destructor for Lilac. Deletes the originalColor variable
// Returns: Nothing
// Parameters: None
Lilac::~Lilac() {
	delete originColor;
}

// Copy Constuctor for Lilac.
// Sets up a new Flower, then copies the Image, originalColor and newColor to the new carnation object
// Returns: Nothing
// Parameters: Lilac&
Lilac::Lilac(Lilac & source) {
	Flower();
	*flowerImage = *(source.flowerImage);
        originColor = getLilacOriginal();
        setNewColor(source.getNewColor());
}

// The Lilac drawFlower method
// This method prints the image of the individual lilac onto the garden image.
// If a new color is specified, it changes the original color to the new color here
// Returns: Nothing
// Parameters: BMP*, int, int
void Lilac::drawFlower(BMP* garden, int CoordX, int CoordY) {
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
