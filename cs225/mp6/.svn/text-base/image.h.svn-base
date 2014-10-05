/**
 * image.h
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

#ifndef _IMAGE_H
#define _IMAGE_H

#include <Magick++.h>

using namespace std;

class Image 
{
	public:
		/**
		 * Copy constructor
		 *
		 * @param source The Image to copy
		 */
		Image(const Image& source);
		/**
		 * Assignment Operator
		 *
		 * @param source The Image object to copy
		 * @returns an identical, deep-copied Image object
		 */
		const Image& operator=(const Image& source);
		/**
		 * Destructor
		 */
		virtual ~Image();
		/**
		 * Test whether two Images are equal
		 *
		 * @param other The other Image to compare to
		 * @return true if they are the same, and false otherwise
		 */
		bool operator==(const Image &other) const;

		/**
		 * Test whether two Images are unequal
		 *
		 * @param other The other Image to compare to
		 * @return false if they are the same, and false otherwise
		 */
		bool operator!=(const Image &other) const;

		/**
		 * Test whether we have a valid image or not.
		 * This is in case the default constructor was used,
		 * or we don't have a valid GraphicMagick image
		 *
		 * @return true if the Image is valid, or false otherwise
		 */
		bool is_valid() const;

		/**
		 * Retrieve the height of the image
		 *
		 * @return The image width, or -1 on error
		 */
		int get_height() const;

		/**
		 * Retrieve the width of the image
		 *
		 * @return The image width, or -1 on error
		 */
		int get_width() const;

		/**
		 * The GraphicsMagick image which represents
		 * this image
		 */
		const Magick::Image& get_magick() const;

	protected:
		/**
		 * No-parameter constructor.  Note that this constructor
		 * shouldn't really be used in generally, but only creates
		 * a placeholder TileImage.  This is only so we can
		 * create TileImages in array initializations, etc.
		 */
		Image();
		/**
		 * Default constructor
		 *
		 * @param magickImg The image data from GraphicsMagick
		 */
		Image(const Magick::Image& magickImg);

		/**
		 * The actual GraphicsMagick image data
		 */
		Magick::Image magickData;

	private:
		/**
		 * Cleans up dynamically allocated memory
		 */
		void destruct();

		/**
		 * Performs a deep copy of source into this
		 *
		 * @param source The source Image object to copy.
		 */
		void copy(const Image& source);
};

#endif /* _IMAGE_H */
