/**
 * tileimage.h
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

#ifndef _TILEIMAGE_H
#define _TILEIMAGE_H

#include <Magick++.h>

#include "image.h"
#include "color.h"
#include "point.h"

using namespace std;

class TileImage : public Image
{
	public:
		/**
		 * No-parameter constructor.  Note that this constructor
		 * shouldn't really be used in generally, but only creates
		 * a placeholder TileImage.  This is only so we can
		 * create TileImages in array initializations, etc.
		 *
		 */
		TileImage();
		/**
		 * Default constructor
		 *
		 * @param magickImg The image data from GraphicsMagick
		 */
		TileImage(const Magick::Image& magickImg);
		/**
		 * Color constructor.  Create a 1-pixel tile image
		 * which represents the specified color
		 *
		 * @param color The color of the new TileImage
		 */
		TileImage(Color color);
		/**
		 * Copy constructor
		 *
		 * @param source The TileImage object to copy
		 */
		TileImage(const TileImage& source);
		/**
		 * Assignment Operator
		 *
		 * @param source The TileImage object to copy
		 * @returns an identical, deep-copied TileImage object
		 */
		const TileImage& operator=(const TileImage& source);
		/**
		 * Destructor
		 */
		virtual ~TileImage();

		/**
		 * Test whether two TileImages are equal
		 *
		 * @param other The other TileImage to compare to
		 * @return true if they are the same, and false otherwise
		 */
		bool operator==(const TileImage &other) const;

		/**
		 * Test whether two TileImages are unequal
		 *
		 * @param other The other TileImage to compare to
		 * @return false if they are the same, and false otherwise
		 */
		bool operator!=(const TileImage &other) const;

		/**
		 * Retrieve a Point with the average color data for all three channels:
		 *
		 * @return The Point representing the average color
		 */
		Point<3> get_average_point() const;

		/**
		 * Retrieve the average color data for all three channels:
		 *
		 * @return The average color data for all three channels
 		 * or a Colors object filled with (-1, -1, -1) on error
		 */
		Color get_average_color() const;

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
		int get_value(int level) const;

		/**
		 * From the KDElement interface: get the number of "levels"
		 * to query upon.  For the TileImage, this will always be
		 * 3-- the number of color channels.
		 *
		 * @return The number of KDTree levels, 3.
		 */
		 int get_num_levels() const;

		 /**
		  * Represents an invalid tile.  Useful to return in cases
		  * when a valid TileImage isn't available.
		  */
		 static const TileImage invalidTile;

	private:
		/**
		 * Cleans up dynamically allocated memory
		 */
		void destruct();

		/**
		 * Performs a deep copy of source into this
		 *
		 * @param source The source TileImage object to copy.
		 */
		void copy(const TileImage& source);

		/**
		 * Traverse over the image pixel-by-pixel to find
		 * the average image color.
		 */
		void fill_avg_color();
		
		/**
		 * The actual data member for the average color
		 */
		Color avgColor;
};

#endif /* _TILEIMAGE_H */
