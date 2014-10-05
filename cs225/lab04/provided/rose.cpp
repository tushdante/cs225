#include "rose.h"
using std::cout;
using std::endl;

// Constructor for the Rose derived class.
// Sets up the Flower, reads in the image, and sets the original color of the Rose
// Returns: Nothing
// Parameters: None
Rose::Rose() {
	Flower();
	flowerImage->ReadFromFile("rose.bmp");
	// Initialize originColor. Use getRoseOriginal()
	originColor=getRoseOriginal();
}

// Destructor for Rose. Deletes the originalColor variable
// Returns: Nothing
// Parameters: None
Rose::~Rose() {
	delete originColor;
	cout<<"rose Dtor"<<endl;
}

// Copy Constuctor for Rose.
// Sets up a new Flower, then copies the Image, originalColor and newColor to the new carnation object
// Returns: Nothing
// Parameters: Rose&
Rose::Rose(Rose & source) {
	RGBApixel* r_color;
	Flower();
	// Copy flowerImage from source
	*flowerImage= (*(source.flowerImage));
	// get the originColor
	originColor= new RGBApixel(*(source.originColor));
	// set the replacemane color (hint: see getters and setters of flower)
	//get replacement color
	r_color=source.getNewColor();
	setNewColor(r_color);

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
			// Print the pixels of each flower. 
			// If the new color is available, run changeColors()
			if (getNewColor() == NULL) {
				// TODO
				(*garden)(CoordX+i,CoordY+j)->Red=(*flowerImage)(i,j)->Red;
				(*garden)(CoordX+i,CoordY+j)->Green=(*flowerImage)(i,j)->Green;
				(*garden)(CoordX+i,CoordY+j)->Blue=(*flowerImage)(i,j)->Blue;
			} else {
				// TODO
				*((*garden)(CoordX+i, CoordY+j)) = changeColors(originColor, getNewColor(), (*flowerImage)(i,j));				}
			

		}
	}
}
