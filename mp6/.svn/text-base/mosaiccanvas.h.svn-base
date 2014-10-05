/**
 * mosaiccanvas.h
 *
 * This is the actual mosaic data-structure which will hold the matrix
 * of sub-images to be written.  This is effectively just a 2-D array
 * of Image objects which can be accessed via convenience methods.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#ifndef _MOSAICCANVAS_H
#define _MOSAICCANVAS_H

#include "tileimage.h"

class MosaicCanvas
{
	public:
		/**
		 * Convenience constructor.  Should only be used to
		 * declare a default MosaicCanvas
		 */
		MosaicCanvas();

		/**
		 * Default constructor
		 *
		 * @param theRows Number of rows to divide the canvas into
		 * @param theColumns Number of columns to divide the canvas into
		 */
		MosaicCanvas(int theRows, int theColumns);

		/**
		 * Copy constructor
		 *
		 * @param source The MosaicCanvas object to copy
		 */
		MosaicCanvas(const MosaicCanvas& source);
		/**
		 * Assignment Operator
		 *
		 * @param source The MosaicCanvas object to copy
		 * @returns an identical, deep-copied MosaicCanvas object
		 */
		const MosaicCanvas& operator=(const MosaicCanvas& source);
		/**
		 * Destructor
		 */
		virtual ~MosaicCanvas();

		/**
		 * Retrieve the number of rows of images
		 *
		 * @return The number of rows in the mosaic, or -1 on error
		 */
		int get_rows() const;

		/**
		 * Retrieve the number of columns of images
		 *
		 * @return The number of columns in the mosaic, or -1 on error
		 */
		int get_columns() const;

		/**
		 * Set the TiledImage for a particular region.  Note
 		 * that row and tile indices should be zero-based.
		 *
		 * @param row The row
		 * @param column The column
		 * @param i The TileImage to set
		 *
		 * @return 0 on success, or non-zero otherwise
		 */
		int set_tile(int row, int column, const TileImage& i);

		/**
		 * Retrieve the current TileImage for a particular
		 * row and column.  If the row or column is out of
		 * bounds, the default TileImage is returned.  Note
 		 * that row and tile indices should be zero-based.
		 *
		 * @param row The row
		 * @param column The column
		 *
		 * @return The current TileImage for a particular,
		 * or the default TileImage if none is set.
		 */
		const TileImage& get_tile(int row, int column) const;

		/**
		 * Save the current MosaicCanvas as a file with
		 * the following dimensions.  To obtain a reasonable
		 * mosaic, the dimensions should preserve the aspect
		 * ratio set by the Rows and Columns of the MosaicCanvas.
		 *
		 * If the specified file exists on the file system, then
		 * the overwrite parameter specifies how to handle it.  If
		 * overwrite is set to false, then the file will be preserved,
		 * and the method will return an error code.  Otherwise, the
		 * file will be overwritten.
		 *
		 * @param width The width, in pixels
		 * @param height The height, in pixels
		 * @param fileName Name of file on the filesystem to
		 * write to.
		 * @param overwrite If the file exists on the filesystem,
		 * whether to overwrite it.
		 *
		 * @return 0 on success, or non-zero otherwise.
		 */
		int save_mosaic(int width, int height, string fileName, bool overwrite) const;
      
   Magick::Image* getMosaicImage(int pixelsPerTile) const;

	private:
		/**
		 * Cleans up dynamically allocated memory
		 */
		void destruct();

		/**
		 * Performs a deep copy of source into this
		 *
		 * @param source The source MosaicCanvas object to copy.
		 */
		void copy(const MosaicCanvas& source);

		/**
		 * Number of image columns in the Mosaic
		 */
		int columns;

		/**
		 * Number of image rows in the Mosaic
		 */
		int rows;
		
		/**
		 * The actual matrix of Image data
		 */
		TileImage** images;
};

#endif /* _MOSAICCANVAS_H */
