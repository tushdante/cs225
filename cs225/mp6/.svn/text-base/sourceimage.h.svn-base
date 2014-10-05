/**
 * sourceimage.h
 *
 * SourceImage extends the Image class and provides some additional data and
 * functions suitable for the source image for the photomosaic.  The default
 * constructor will take a number of rows and columns to divide the image
 * into.  The image will then be processes to find the average color of each
 * region.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#ifndef _SOURCEIMAGE_H
#define _SOURCEIMAGE_H

#include <Magick++.h>

#include "image.h"
#include "color.h"

using namespace std;

class SourceImage : public Image
{
	public:
		/**
		 * No-parameter constructor.  Note that this constructor
		 * shouldn't really be used in generally, but only creates
		 * a placeholder TileImage.  This is only so we can
		 * create TileImages in array initializations, etc.
		 */
		SourceImage();

		/**
		 * Default constructor
		 *
		 * @param magickImg The image data from GraphicsMagick
 		 * @param resolution The resolution of the sub-regions.  This will be the number
 		 * of tiles in the larger of the two dimensions of the SourceImage.  If the 
		 * given resolution is greater than the largest dimension of the image, it will
		 * be automatically set to the pixel dimensions
		 */
		SourceImage(const Magick::Image& magickImg, int resolution);
		/**
		 * Copy constructor
		 */
		SourceImage(const SourceImage& source);
		/**
		 * Assignment Operator
		 *
		 * @param source The SourceImage object to copy
		 * @return an identical, deep-copied SourceImage object
		 */
		const SourceImage& operator=(const SourceImage& source);
		/**
		 * Destructor
		 */
		virtual ~SourceImage();

		/**
		 * Get the average color of a particular region.  Note, the
		 * row and column should be specified with a 0-based index.
		 * i.e., The top-left corner is (row, column) (0,0).
		 *
		 * @param row The row of the particular region in the image
		 * @param col The column of the particular region in the image
		 *
		 * @return The average color of the image
		 */
		Color get_region_color(int row, int col) const;

		/**
		 * Retreive the number of row sub-regions the source image
		 * is broken into.
		 *
		 * @return The number of rows, or -1 if in an invalid state
		 */
		int get_rows() const;

		/**
		 * Retreive the number of column sub-regions the source
		 * image is broken into.
		 *
		 * @return The number of columns, or -1 if in an invalid state
		 */
		int get_columns() const;

	private:
		/**
		 * Cleans up dynamically allocated memory
		 */
		void destruct();

		/**
		 * Performs a deep copy of source into this
		 *
		 * @param source The source SourceImage object to copy.
		 */
		void copy(const SourceImage& source);

		/**
		 * Calculate the number of columns and rows based on a
		 * "resolution".  The numbers are chosen as to keep the
		 * tiles as close to square as possible.
		 *
		 * @param resolution The number of tiles in the larger dimension
		 */
		void calc_rows_and_cols(int resolution);

		/**
		 * Traverse over the set of sub-regions and calculate the
		 * average color for each tile.  Populate regionColors with
		 * their values.  If resolution is greater than the largest 
		 * dimension of the image, the rows and columns will be set to
		 * the pixel dimensions of the image.
		 *
		 * @param magickImg The GraphicsMagick image data
		 */
		void fill_region_colors(const Magick::Image& magickImg);

		/**
		 * The average color data for each region
		 */
		Color **regionColors;

		/**
		 * Number of row sub-regions
		 */
		int rows;

		/**
		 * Number of column subregions
		 */
		int columns;
};

#endif /* _SOURCEIMAGE_H */
