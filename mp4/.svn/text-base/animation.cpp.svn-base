#include <stdint.h>
#include <iostream>
#include "animation.h"

using std::cout;
using std::endl;

void animation::addFrame(BMP const & img) {
    frames.push_back(convertToMagickImage(img));
}

void animation::write(std::string filename) {
    if(frames.empty())
    {
        cout << "Animation Warning: No frames added!" << endl;
        return;
    }
    writeImages(frames.begin(), frames.end(), filename);
}

Magick::Image animation::convertToMagickImage(BMP const & img) const {
    int height = img.TellHeight(), width = img.TellHeight();

    // Allocate some new memory to set ip the char array to hold all the pixel info
    uint8_t * pixels = new uint8_t[width * height * NUM_CHANNELS];
    int i = 0;
    // Copying over the pixel data
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++) {
            RGBApixel const * p = img(x, y);
            pixels[i++] = p->Red;
            pixels[i++] = p->Green;
            pixels[i++] = p->Blue;
        }

    // Build the image out of the array that was build
    Magick::Image magickImg( width, height, "RGB", Magick::StorageType(Magick::CharPixel), pixels );
    //Clean up the array
    delete[] pixels;

    return magickImg;
}
