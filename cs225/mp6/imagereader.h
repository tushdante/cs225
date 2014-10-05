/**
 * imageReader.h
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

#ifndef _IMAGEREADER_H
#define _IMAGEREADER_H

#include <Magick++.h>

#include "sourceimage.h"
#include "tileimage.h"

using namespace std;

class ImageReader 
{
	public:
		/**
		 * Default constructor
		 */
		ImageReader();
		/**
		 * Copy constructor
		 *
		 * @param source The ImageReader object to copy
		 */
		ImageReader(const ImageReader& source);
		/**
		 * Assignment Operator
		 *
		 * @param source The ImageReader object to copy
		 * @returns an identical, deep-copied ImageReader object
		 */
		const ImageReader& operator=(const ImageReader& source);
		/**
		 * Destructor
		 */
		virtual ~ImageReader();

		/**
		 * Read in the source image.  This should be used for the
		 * main source image in the photomosaic algorithm.  Once
		 * the image is actually retreived, we also split it up
		 * into regions and calculate the average color information
		 * for each.
		 *
		 * @param source the path or URL of the image file
		 * @param img Reference to an Image to read
		 * @param resolution The "resolution" of the tiles the source image will be divided into
		 * @return 0 on success, non-zero otherwise
		 */
		int read_source_image(const string source, SourceImage& img, int resolution) const;

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
		int read_tile_image(const string source, TileImage& img) const;

		/**
		 * The square size that all thumbnail images should be
		 * rescaled to.
		 *
		 * NOTE: If this value is changed, then the test images
		 * in test/testfiles should be resized as well.  Please
		 * see test/testImageReader.cpp for a listing of files
		 * used.
		 */
		static const int THUMBNAIL_SIZE = 75;

	private:
		/**
		 * Cleans up dynamically allocated memory
		 */
		void destruct();

		/**
		 * Performs a deep copy of source into this
		 *
		 * @param source The source ImageReader object to copy.
		 */
		void copy(const ImageReader& source);

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
		void normalize_image(Magick::Image& img, int size) const;
};

#endif /* _IMAGEREADER_H */
