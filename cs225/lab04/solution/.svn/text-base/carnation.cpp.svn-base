#include "carnation.h"

// Constructor for the Carnation derived class.
// Sets up the Flower, reads in the image, and sets the original color of the carnation
// Returns: Nothing 
// Parameters: None
Carnation::Carnation() {
	Flower();
	flowerImage->ReadFromFile("carnation.bmp");
	originColor = getCarnationOriginal();
}

// Destructor for Carnation. Deletes the originalColor variable
// Returns: Nothing
// Parameters: None
Carnation::~Carnation() {
	delete originColor;
}

// Copy Constuctor for Carnation.
// Sets up a new Flower, then copies the Image, originalColor and newColor to the new carnation object
// Returns: Nothing
// Parameters: Carnation&
Carnation::Carnation(Carnation & source) {
        Flower();
        *flowerImage = *(source.flowerImage);
        originColor = getCarnationOriginal();
        setNewColor(source.getNewColor());
}

// The Carnation drawFlower method
// This method prints the image of the individual carnation onto the garden image.
// If a new color is specified, it changes the original color to the new color here
// Returns: Nothing
// Parameters: BMP*, int, int
void Carnation::drawFlower(BMP* garden, int CoordX, int CoordY) {
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
