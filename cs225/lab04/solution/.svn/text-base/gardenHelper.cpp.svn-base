// A collection of functions to help out with the Garden. 
// Allows users to reuse functions that are common to each flower
#include "gardenHelper.h"

// A method to change the color of a pixel
// The method looks at the current pixel. 
// If it is the same color as the "Original" color, it changes it to the "NewColor"
// Returns: RGBApixel (The pixel that will be written to the Garden image)
// Parameters: RGBApixel*, RGBApixel*, RGBApixel*
RGBApixel changeColors(RGBApixel * original, RGBApixel * newcolor, RGBApixel * source) {
        RGBApixel* retval = new RGBApixel();
        if (source->Red == original->Red && source->Blue == original->Blue && source->Green == original->Green) {
                *retval = *newcolor;
        } else {
                *retval = *source;
        }
        return *retval;
}


// The following three functions are just to get the original color of each default image
// This was done so that the you won't have to remember the original color values, you can just use these functions to get them
RGBApixel* getRoseOriginal() {
        RGBApixel* temp = new RGBApixel();
        temp->Red = 255;
        temp->Blue = 1;
        temp->Green = 1;
        return temp;
}
RGBApixel* getCarnationOriginal() {
        RGBApixel* temp = new RGBApixel();
        temp->Red = 0;
        temp->Blue = 255;
        temp->Green = 64;
        return temp;
}
RGBApixel* getLilacOriginal() {
        RGBApixel* temp = new RGBApixel();
        temp->Red = 189;
        temp->Blue = 198;
        temp->Green = 181;
        return temp;
}

