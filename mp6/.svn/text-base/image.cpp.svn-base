/**
 * image.cpp
 *
 * Image is the general base class for the image objects we use for the
 * photomosaic program.  It represents only the general data we care about,
 * in an effort to maintain simplicity.  More intricate functions and data
 * are available through the Magick::Image data object.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#include <iostream>

#include "image.h"

using namespace std;


/**
 * Copy constructor
 * 
 * @ param source the Image to copy
 */
Image::Image(const Image& source) {
    copy(source);
}

/**
 * Assignment Operator
 *
 * @param source The Image object to copy
 * @returns an identical, deep-copied Image object
 */
const Image& Image::operator=(const Image& source) {
    if (this != &source) {
        destruct();
        copy(source);
    }

    return *this;
}

/**
 * Destructor
 */
Image::~Image() {
    destruct();
}

/**
 * Test whether two Images are equal
 *
 * @param other The other Image to compare to
 * @return true if they are the same, and false otherwise
 */
bool Image::operator==(const Image &other) const {
    return (magickData == other.magickData);
}

/**
 * Test whether two Images are unequal
 *
 * @param other The other Image to compare to
 * @return true if they are the same, and false otherwise
 */
bool Image::operator!=(const Image &other) const {
    return !(*this == other);
}

/**
 * Test whether we have a valid image or not.
 * This is in case the default constructor was used,
 * or we don't have a valid GraphicMagick image
 *
 * @return true if the Image is valid, or false otherwise
 */
bool Image::is_valid() const {
    return ((magickData.rows() > 0)
            && (magickData.columns() > 0));
}

/**
 * Retrieve the height of the image
 */
int Image::get_height() const {
    return magickData.rows();
}

/**
 * Retrieve the width of the image
 */
int Image::get_width() const {
    return magickData.columns();
}

/**
 * The GraphicsMagick image which represents
 * this image
 */
const Magick::Image& Image::get_magick() const {
    return magickData;
}

/**
 * No-parameter constructor.  Note that this constructor
 * shouldn't really be used in generally, but only creates
 * a placeholder TileImage.  This is only so we can
 * create TileImages in array initializations, etc.
 */
Image::Image() {
    // Nothing to do here
}

/**
 * Default constructor
 *
 * @param magickImg The image data from GraphicsMagick
 */
Image::Image(const Magick::Image& magickImg) {
    magickData = magickImg;
}

/**
 * Cleans up dynamically allocated memory
 */
void Image::destruct() {
    // Nothing to do here
}

/**
 * Performs a deep copy of source into this
 *
 * @param source The source Image object to copy.
 */
void Image::copy(const Image& source) {
    magickData = source.magickData;
}
