/**
 * sourceimage.cpp
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

#include <iostream>
#include <cmath>

#include "sourceimage.h"

using namespace std;

/**
 * No-parameter constructor.  Note that this constructor
 * shouldn't really be used in generally, but only creates
 * a placeholder TileImage.  This is only so we can
 * create TileImages in array initializations, etc.
 */
SourceImage::SourceImage() {
	regionColors = NULL;
	rows = columns = -1;
}

/**
 * Default constructor
 *
 * @param magickImg The image data from GraphicsMagick
 * @param resolution The resolution of the sub-regions.  This will be the number
 * of tiles in the larger of the two dimensions of the SourceImage.  If the 
 * given resolution is greater than the largest dimension of the image, it will
 * be automatically set to the pixel dimensions
 */
SourceImage::SourceImage(const Magick::Image& magickImg, int resolution) : Image(magickImg) {
	if (resolution< 1) {
		regionColors = NULL;
		rows = columns = -1;
		return;
	}
	
	calc_rows_and_cols(resolution);
	regionColors = new Color*[rows];
	for (int row = 0; row < rows; row++)
		regionColors[row] = new Color[columns];
	fill_region_colors(magickImg);
}

/**
 * Copy constructor
 */
SourceImage::SourceImage(const SourceImage& source) : Image(source) {
	copy(source);
}

/**
 * Assignment Operator
 *
 * @param source The SourceImage object to copy
 *
 * @return an identical, deep-copied SourceImage object
 */
const SourceImage& SourceImage::operator=(const SourceImage& source) {
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
SourceImage::~SourceImage() {
	destruct();
}

/**
 * Get the average color of a particular region
 *
 * @param row The row of the particular region in the image
 * @param col The column of the particular region in the image
 *
 * @return The average color of the image
 */
Color SourceImage::get_region_color(int row, int col) const {
	if ((rows < 1) || (columns < 1)
			|| (row < 0) || (col < 0)
			|| (row > rows - 1) || (col > columns -1)) {	
		Color c;
		c.bValue = c.gValue = c.rValue = -1;
		return c;
	}

	return regionColors[row][col];
}

/**
 * Retreive the number of row sub-regions the source image
 * is broken into.
 *
 * @return The number of rows, or -1 if in an invalid state
 */
int SourceImage::get_rows() const {
	return rows;
}

/**
 * Retreive the number of column sub-regions the source
 * image is broken into.
 *
 * @return The number of columns, or -1 if in an invalid state
 */
int SourceImage::get_columns() const {
	return columns;
}

/**
 * Cleans up dynamically allocated memory
 */
void SourceImage::destruct() {
	if ((rows < 1) || (columns < 1))
		return;

	for (int row = 0; row < rows; row++)
		delete[] regionColors[row];
	delete[] regionColors;
	regionColors = NULL;
}

/**
 * Performs a deep copy of source into this
 *
 * @param source The source SourceImage object to copy.
 */
void SourceImage::copy(const SourceImage& source) {
	rows = source.rows;
	columns = source.columns;
	if ((rows < 1) || (columns < 1)) {
		regionColors = NULL;
		return;
	}

	regionColors = new Color*[rows];
	for (int row = 0; row < rows; row++) {
		regionColors[row] = new Color[columns];
		for (int col = 0; col < columns; col++)
			regionColors[row][col] = source.regionColors[row][col];
	}
}

/**
 * Calculate the number of columns and rows based on a
 * "resolution".  The numbers are chosen as to keep the
 * tiles as close to square as possible.
 *
 * @param resolution The number of tiles in the larger dimension
 */
void SourceImage::calc_rows_and_cols(int resolution) {
	int height = get_height(), width = get_width();

	if (resolution > max(height, width)) {
		columns = width;
		rows = height;
		return;
	}

	if (height < width) {
		columns = resolution;
		float ratio = (float)height / (float)width;
		rows = (int)ceil((float)columns * ratio);

	} else /* width < height */ {
		rows = resolution;
		float ratio = (float)width / (float)height;
		columns = (int)ceil((float)rows * ratio);
	}
}

/**
 * Traverse over the set of sub-regions and calculate the
 * average color for each tile.  Populate regionColors with
 * their values.  If resolution is greater than the largest 
 * dimension of the image, the rows and columns will be set to
 * the pixel dimensions of the image.
 *
 * @param magickImg The GraphicsMagick image data
 */
void SourceImage::fill_region_colors(const Magick::Image& magickImg) {
	int width = get_width(), height = get_height();

	if ((width < 1) || (height < 1))
		return;

	int startX, endX, startY, endY;
	int regionWidth, regionHeight;

	const Magick::PixelPacket *pixelData;

	int totalRed, totalGreen, totalBlue;

	for (int row = 0; row < rows; row++)
		for (int col = 0; col < columns; col++) {

			// Calculate our offsets
			startX = (width * col) / columns;
			endX = (width* (col + 1)) / columns;
			startY = (height * row) / rows;
			endY = (height * (row + 1)) / rows;

			regionWidth = endX - startX;
			regionHeight = endY - startY;
			
			pixelData = magickImg.getConstPixels(
					startX, startY, 
					regionWidth, regionHeight);
			totalRed = totalGreen = totalBlue = 0;

			// Traverse pixels
			for (int curY = 0; curY < regionHeight; curY++)
				for (int curX = 0; curX < regionWidth; curX++) {
					totalRed += pixelData[curY*regionWidth + curX].red;
					totalGreen += pixelData[curY*regionWidth + curX].green;
					totalBlue += pixelData[curY*regionWidth + curX].blue;
				}
			Color c;
			c.rValue = totalRed / (regionWidth * regionHeight);
			c.gValue = totalGreen / (regionWidth * regionHeight);
			c.bValue = totalBlue / (regionWidth * regionHeight);

			regionColors[row][col] = c;
		}
}



