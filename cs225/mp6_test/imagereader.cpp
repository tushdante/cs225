/**
 * imageReader.cpp
 *
 * ImageReader is a simple interface to open images from a
 * variety of sources using GraphicsMagick++ methods.  Although
 * this class isn't so useful on its own (as it just wraps a few
 * constructors for the Image class), the idea is that it should
 * be easy to extend to create new functionality.  For example,
 * it would be useful to have a CachedImageReader, etc.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#include <iostream>

#include "imagereader.h"

using namespace std;

/**
 * Default constructor
 */
ImageReader::ImageReader() {
	// Nothing to do here.
}

/**
 * Copy constructor
 * 
 * @param source The ImageReader to copy
 */
ImageReader::ImageReader(const ImageReader& source) {
	copy(source);
}

/**
 * Assignment Operator
 *
 * @param source The ImageReader object to copy
 * @returns an identical, deep-copied ImageReader object
 */
const ImageReader& ImageReader::operator=(const ImageReader& source) {
	if (this != &source) {
		destruct();
		copy(source);
	}

	return *this;
}

/**
 * Destructor
 */
ImageReader::~ImageReader() {
	destruct();
}

/**
 * Read in the source image.  This should be used for the
 * main source image in the photomosaic algorithm.  Once
 * the image is actually retreived, we also split it up
 * into regions and calculate the average color information
 * for each.
 *
 * @param source the path or URL of the image file
 * @param img Reference to an Image to read
 * @param resolution The "resolution" of the tiles which the image will be divided into.
 * @return 0 on success, non-zero otherwise
 */
int ImageReader::read_source_image(const string source, SourceImage& img, int resolution) const {
#ifdef IMAGEREADER_DEBUG
	cout << "Image source: " << source << endl;
#endif
	Magick::Image magickImg;
	try {
		magickImg = Magick::Image(source);
	} catch (exception &ex) {
		img = SourceImage();
		return -1;
	}

	img = SourceImage(magickImg, resolution);
	return 0;
}

/**
 * Read in a tile image.  This method can be used on all of
 * the images returned from the image plugins.  Once the
 * image is actually retreived, we also calculate the average
 * pixel value of the entire region.
 *
 * @param source the path or URL of the image file
 * @param img Reference to an Image to read
 * @return 0 on success, non-zero otherwise
 */
int ImageReader::read_tile_image(const string source, TileImage& img) const {
#ifdef IMAGEREADER_DEBUG
	cout << "Image source: " << source << endl;
#endif
	Magick::Image magickImg;
	try {
		magickImg = Magick::Image(source);
	} catch (exception ex) {
		img = TileImage();
		return -1;
	}

	normalize_image(magickImg, THUMBNAIL_SIZE);
	img = TileImage(magickImg);

	return 0;
}

/**
 * Cleans up dynamically allocated memory
 */
void ImageReader::destruct() {
	// Nothing to do here.
}

/**
 * Performs a deep copy of source into this
 *
 * @param source The source ImageReader object to copy.
 */
void ImageReader::copy(const ImageReader& source) {
	// Nothing to do here.
}

/**
 * "Normalize" the image for subsequent processing by
 * putting it in an explicit format the program can
 * understand.  At this point, that means cropping
 * the image to a square and scaling it to a
 * square of the specified size.
 *
 * @param img The image to be normalized
 * @param size The new width and height of the thumbnail,
 * in pixels
 */
void ImageReader::normalize_image(Magick::Image& img, const int scaledSize) const {
	int height = img.rows(), width = img.columns();

#ifdef IMAGEREADER_DEBUG
	cout << "Original image size: (" << width << ", " << height << ")" << endl;
#endif

	// First, make the image square.
	if (width < height) {
		img.crop( Magick::Geometry(width, width, 0,
					(height - width) / 2) );
	} else if (height < width) {
		img.crop( Magick::Geometry(height, height, 
					(width - height) / 2, 0) );
	}
	height = img.rows();
	width = img.columns();
	// setting page necessary to fix crop offset
	img.page( Magick::Geometry(width, height, 0, 0));

#ifdef IMAGEREADER_DEBUG
	cout << "Cropped image size: (" << width << ", " << height << ")" << endl;
#endif

	// Then scale it down to the specified size
	if (((int)width != scaledSize) || ((int)height != scaledSize)) {
		img.scale( Magick::Geometry(scaledSize, scaledSize) );
	}
#ifdef IMAGEREADER_DEBUG
		height = img.rows();
		width = img.columns();
		cout << "Scaled image size: (" << width << ", " << height << ")" << endl;
#endif

	return;
}
