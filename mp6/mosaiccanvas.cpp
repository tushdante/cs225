/**
 * mosaiccanvas.cpp
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

#include <iostream>
#include <sys/stat.h>
#include <errno.h>

#include "mosaiccanvas.h"

using namespace std;

/**
 * Convenience constructor.  Should only be used to
 * declare a default MosaicCanvas
 */
MosaicCanvas::MosaicCanvas() {
	rows = -1;
	columns = -1;
	images = NULL;
}

/**
 * Default constructor
 *
 * @param theRows Number of rows to divide the canvas into
 * @param theColumns Number of columns to divide the canvas into
 */
MosaicCanvas::MosaicCanvas(int theRows, int theColumns) {
	if ((theRows < 1) || (theColumns < 1)) {
		this->rows = -1;
		this->columns = -1;
		images = NULL;
		return;
	}

	this->rows = theRows;
	this->columns = theColumns;

	images = new TileImage*[this->rows];
	for (int rowNum = 0; rowNum < this->rows; rowNum++)
		images[rowNum] = new TileImage[this->columns];
}

/**
 * Copy constructor
 *
 * @param source The MosaicCanvas object to copy
 */
MosaicCanvas::MosaicCanvas(const MosaicCanvas& source) {
	copy(source);
}

/**
 * Assignment Operator
 *
 * @param source The MosaicCanvas object to copy
 * @returns an identical, deep-copied MosaicCanvas object
 */
const MosaicCanvas& MosaicCanvas::operator=(const MosaicCanvas& source) {

	if(this != &source){
		destruct();
		copy(source);
	}
	
	return *this;
}

/**
 * Destructor
 */
MosaicCanvas::~MosaicCanvas() {
	destruct();
}

/**
 * Retrieve the number of rows of images
 *
 * @return The number or rows in the mosaic, or -1 on error
 */
int MosaicCanvas::get_rows() const {
	return rows;
}

/**
 * Retrieve the number of columns of images
 *
 * @return The number of columns in the mosaic, or -1 or error
 */
int MosaicCanvas::get_columns() const {
	return columns;
}

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
int MosaicCanvas::set_tile(int row, int column, const TileImage& i) {
	if ((row    < 0) || (row    > rows -1)
	 || (column < 0) || (column > columns -1))
		return -1;

	images[row][column] = i;
	return 0;
}

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
const TileImage& MosaicCanvas::get_tile(int row, int column) const {
	if ((row    < 0) || (row    > rows -1)
	 || (column < 0) || (column > columns -1)) {
		return TileImage::invalidTile;
	}

	return images[row][column];
}

/**
 * Save the current MosaicCanvas as a file with
 * the following dimensions.  To obtain a reasonable
 * mosaic, the dimensions should preserve the aspect
 * ratio set by the rows and columns of the MosaicCanvas.
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
int MosaicCanvas::save_mosaic(int width, int height, string fileName, bool overwrite) const {
	
	// Validate parameters
	if ((width < 1) || (height < 1))
		return -1;
	if ((rows < 1) || (columns < 1))
		return -1;
	
	// Check file before calculating complete mosaic
	struct stat statbuf;
	if (stat(fileName.c_str(), &statbuf) < 0) {
		if (errno != ENOENT)
			return -1;
	} else if (overwrite == false)
		return -1;

	// Create the image
	cout << "Creating canvas, size (" << width << "x" << height << ")" << endl;
	Magick::Image mosaic(Magick::Geometry(width, height, 0, 0), Magick::Color("white"));

	// Create list of drawable tiles
	list<Magick::Drawable> drawableTileList;
	int startX, endX, startY, endY, tileWidth, tileHeight;
	for (int row = 0; row < rows; row++)
		for (int col = 0; col < columns; col++) {
			if (images[row][col].is_valid() == false)
				continue;

			startX = width  * col     / columns;
			endX   = width  * (col+1) / columns;
			startY = height * row     / rows;
			endY   = height * (row+1) / rows;

			tileWidth  = endX - startX;
			tileHeight = endY - startY;

			if ((tileWidth == 0) || (tileHeight == 0))
				continue;

			Magick::DrawableCompositeImage scaledTile(
					startX, startY, tileWidth, tileHeight,
					images[row][col].get_magick());
			drawableTileList.push_back(scaledTile);
		}

	cout << "Drawing." << endl;

	// Draw tiles into mosaic
	if (drawableTileList.size() > 0)
		mosaic.draw(drawableTileList);

	cout << "Saving to " << fileName << "!" << endl;
	// Save!
	try { mosaic.write(fileName); }
	catch (Magick::Exception e) { 
#ifdef MOSAICCANVAS_DEBUG
		cout << "Save exception: " << e.what() << endl;
#endif
		return -1;
	}

	cout << "Done saving." << endl;

	return 0;
}

Magick::Image* MosaicCanvas::getMosaicImage(int pixelsPerTile) const
{
   int width = columns * pixelsPerTile;
   int height = rows * pixelsPerTile;
   
   // Validate parameters
   if ((width < 1) || (height < 1) || (rows < 1) || (columns < 1))
      return NULL;

   // Create the image
   Magick::Image* mosaic = new Magick::Image(
         Magick::Geometry(width, height, 0, 0), 
         Magick::Color("white"));

   // Create list of drawable tiles
   list<Magick::Drawable> drawableTileList;
   int startX, endX, startY, endY, tileWidth, tileHeight;
   for (int row = 0; row < rows; row++)
   {
      for (int col = 0; col < columns; col++)
      {
         if (images[row][col].is_valid() == false)
            continue;

         startX = width  * col     / columns;
         endX   = width  * (col+1) / columns;
         startY = height * row     / rows;
         endY   = height * (row+1) / rows;
         tileWidth  = endX - startX;
         tileHeight = endY - startY;

         if ((tileWidth == 0) || (tileHeight == 0))
            continue;

         Magick::DrawableCompositeImage scaledTile(
         startX, startY, tileWidth, tileHeight,
         images[row][col].get_magick());
         drawableTileList.push_back(scaledTile);
      }
   }

   // Draw tiles into mosaic
   if (drawableTileList.size() > 0)
      mosaic->draw(drawableTileList);
   return mosaic;
}

/**
 * Cleans up dynamically allocated memory
 */
void MosaicCanvas::destruct() {
	for (int rowNum = 0; rowNum < rows; rowNum++)
		delete[] images[rowNum];
	delete[] images;
}

/**
 * Performs a deep copy of source into this
 *
 * @param source The source MosaicCanvas object to copy.
 */
void MosaicCanvas::copy(const MosaicCanvas& source) {

	rows = source.rows;
	columns = source.columns;
	if ((rows < 1) || (columns < 1)) {
		images = NULL;
		return;
	}

	images = new TileImage*[rows];

	for (int rowNum = 0; rowNum < rows; rowNum++) {
		images[rowNum] = new TileImage[columns];
		for (int colNum = 0; colNum < columns; colNum++)
			images[rowNum][colNum] = source.images[rowNum][colNum];
	}
}
