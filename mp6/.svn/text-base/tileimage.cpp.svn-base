/**
 * tileimage.cpp
 *
 * TileImage extends the Image class and provides some additional data and
 * functions suitable for images pulled from the plugins and used for tiling
 * inside the final mosaic.  For example, there will be data members representing
 * the average red, green, and blue channel values.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#include <iostream>

#include "tileimage.h"

using namespace std;

/**
 * No-parameter constructor.  Note that this constructor
 * shouldn't really be used in generally, but only creates
 * a placeholder TileImage.  This is only so we can
 * create TileImages in array initializations, etc.
 */
TileImage::TileImage() {
    avgColor.rValue = avgColor.gValue = avgColor.bValue = -1;
}

/**
 * Default constructor
 *
 * @param magickImg The image data from GraphicsMagick
 */
TileImage::TileImage(const Magick::Image& magickImg) : Image(magickImg) {
    fill_avg_color();
}

/**
 * Color constructor.  Create a 1-pixel tile image
 * which represents the specified color
 *
 * @param color The color of the new TileImage
 */
TileImage::TileImage(Color color)
    : Image(Magick::Image(
        Magick::Geometry(1,1,0,0),
        Magick::Color(color.rValue, color.gValue, color.bValue))) {
    
    // Set the colorspace so that we can later save the image
    // (Required by GraphicsMagick)
    magickData.magick("PNG");
    fill_avg_color();
}

/**
 * Copy constructor
 *
 * @param source The TileImage object to copy
 */
TileImage::TileImage(const TileImage& source) : Image(source) {
    copy(source);
}

/**
 * Assignment Operator
 *
 * @param source The TileImage object to copy
 * @returns an identical, deep-copied TileImage object
 */
const TileImage& TileImage::operator=(const TileImage& source) {
    if (this != &source) {
        destruct();
        Image::operator=(source);
        copy(source);
    }

    return *this;
}

/**
 * Destructor
 */
TileImage::~TileImage() {
    destruct();
}


/**
 * Test whether two TileImages are equal
 *
 * @param other The other TileImage to compare to
 * @return true if they are the same, and false otherwise
 */
bool TileImage::operator==(const TileImage &other) const {
    if (Image::operator==(other) == false)
        return false;

    return (
               (avgColor.rValue == other.avgColor.rValue)
            && (avgColor.gValue == other.avgColor.gValue)
            && (avgColor.bValue == other.avgColor.bValue)
           );
}

/**
 * Test whether two TileImages are unequal
 *
 * @param other The other TileImage to compare to
 * @return false if they are the same, and false otherwise
 */
bool TileImage::operator!=(const TileImage &other) const {
    return !(*this == other);
}

/**
 * Retrieve a Point with the average color data for all three channels:
 *
 * @return The Point representing the average color
 */
Point<3> TileImage::get_average_point() const {
    Point<3> p;
    p.set(0, avgColor.rValue);
    p.set(1, avgColor.gValue);
    p.set(2, avgColor.bValue);
    return p;
}

/**
 * Retrieve the average color data for all three channels:
 *
 * @return The average color data for all three channels,
 * or a Colors object filled with (-1, -1, -1) on error
 */
Color TileImage::get_average_color() const {
    return avgColor;
}

/**
 * From the KDElement interface: get the value at a particular
 * "level".  For a TileImage, this will return the average color
 * value corresponding to a particular channel, in the order:
 *  0 - RED
 *  1 - GREEN
 *  2 - BLUE
 *
 * @param level The level (or channel number) to query
 *
 * @return the value (or average color) of the particular level,
 * or -1 on an illegal level.
 */
int TileImage::get_value(int level) const {
    switch (level) {
        case 0:
            return avgColor.rValue;
            break;

        case 1:
            return avgColor.gValue;
            break;

        case 2:
            return avgColor.bValue;
            break;

        default:
            // Illegal level
            return -1;
            break;
    }
}

/**
 * From the KDElement interface: get the number of "levels"
 * to query upon.  For the TileImage, this will always be
 * 3-- the number of color channels.
 *
 * @return The number of KDTree levels, 3.
 */
int TileImage::get_num_levels(void) const {
    return 3;
}

/**
 * Represents an invalid tile.  Useful to return in cases
 * when a valid TileImage isn't available.
 */
const TileImage TileImage::invalidTile = TileImage();

/**
 * Cleans up dynamically allocated memory
 */
void TileImage::destruct() {
    // Nothing to do here
}

/**
 * Performs a deep copy of source into this
 *
 * @param source The source TileImage object to copy.
 */
void TileImage::copy(const TileImage& source) {
    avgColor = source.avgColor;
}

/**
 * Traverse over the image pixel-by-pixel to find
 * the average image color.
 */
void TileImage::fill_avg_color() {
    
    int width = get_width(), height = get_height();
    if ((height< 1) || (width < 1)) {
        avgColor.rValue = avgColor.gValue = avgColor.bValue = -1;
        return;
    }

    Magick::Pixels pixelsView(magickData);
    const Magick::PixelPacket *pixelData = pixelsView.getConst(
            0, 0, width, height);

    int totalRed = 0, totalGreen = 0, totalBlue = 0;
    for (int row = 0; row < height; row++)
           for (int col = 0; col < width; col++) {
            totalRed += pixelData[row*width + col].red;           
            totalGreen += pixelData[row*width + col].green;           
            totalBlue += pixelData[row*width + col].blue;
           }

    avgColor.rValue = totalRed / (width*height);
    avgColor.gValue = totalGreen / (width*height);
    avgColor.bValue = totalBlue / (width*height);
}
