#include "garden.h"
#include <iostream>
#define IMAGEWIDTH 36
#define IMAGEHEIGHT 36
using namespace std;

// Constructor for Garden
// Sets the number of flowers in each row and column
// Initializes the array of flower pointers and sets them all to NULL
// Returns: Nothing
// Parameters: None
Garden::Garden(int x, int y) {
	(*this).x = x;
	(*this).y = y;
	flowers = new Flower*[x*y];
	for (int i = 0; i < (x*y); i++) {
		flowers[i] = NULL;
	}
}

// Destructor for Garden
// Deletes the individual flowers and then deletes the flowers array
// Returns: Nothing
// Parameters: None
Garden::~Garden() {
	for (int i = 0; i < (x*y); i++) {
		delete flowers[i];
	}
	delete [] flowers;
}

// Copy Constructor for Garden
// Makes a deep copy of the x and y variables, as well as the array of Flowers
// Returns: Nothing
// Parameters: Garden&
Garden::Garden(Garden & source) {
	(*this).x = source.x;
	(*this).y = source.y;
	flowers = new Flower*[x*y];
	for (int i = 0; i < (x*y); i++) {
		if (source.flowers[i] == NULL) {
			flowers[i] = NULL;
		} else {
			*flowers[i] = *(source.flowers[i]);
		}
	}
}

// Method that draws each flower to the garden image
// Loops through each flower, and calls that flowers drawFlower method to paint the pixels to the garden
// Then saves the resulting garden to a file
// Returns: Nothing
// Parameters: char* filename
void Garden::drawGarden(char* filename) {
	BMP* outputGarden = new BMP();
	(*outputGarden).SetSize(IMAGEWIDTH * x, IMAGEHEIGHT * y);
	int offsetX = 0;
	int offsetY = 0;
	for (int i = 0; i < (x*y); i++) {
		if (flowers[i] != NULL) {
			flowers[i]->drawFlower(outputGarden, offsetX * IMAGEWIDTH, offsetY * IMAGEHEIGHT);
		}
		offsetX++;
		if (offsetX == x) {
			offsetX = 0;
			offsetY++;
		}
	}
	(*outputGarden).WriteToFile(filename);
}

// Private method for Garden's use only
// Returns the index of the next available spot to put a flower (i.e. the lowest index that is NULL)
// Returns: int
// Parameters: None
int Garden::getVacantFlowerBed() {
	for (int i = 0; i < (x*y); i++) {
		if (flowers[i] == NULL) {
			return i;
		}
	}
	return -1;
}

// Method to add a flower to the flowers array
// Adds teh default flower class to the array
// Returns: Nothing
// Parameters: Flower*
void Garden::addFlower(Flower* newFlower) {
	int index = getVacantFlowerBed();
	if (index == -1) {
		cout << "Not enough space in the Garden" << endl;
		return;
	}
	flowers[index] = newFlower; 		
}
