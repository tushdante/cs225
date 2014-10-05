/**
 * tilemapper.h
 *
 * Provides an abstract tile mapping class to fit an appropriate tile image
 * into each mosaic region.  TileMapper is subclassed to allow for
 * multiple ways of creating the mosaic. Implementations include KD-Trees,
 * etc. 
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 *
 * Updated Spring 2009
 * 	3/27/2009 - Changes to support Points and the new KDTree interface
 */

#ifndef _TILEMAPPER_H
#define _TILEMAPPER_H

#include <vector>
#include <map>

#include "point.h"
#include "sourceimage.h"
#include "tileimage.h"
#include "mosaiccanvas.h"

using namespace std;

class TileMapper
{
	public:
		/**
		 * Destructor
		 */
		virtual ~TileMapper();

		/**
		 * Map the image tiles into a mosaic canvas which closely
		 * matches the input image.  The algorithm for iterating over
		 * the tiles and source image regions is up to the particular
		 * TileMapper subclass.
		 *
		 * This method will fail if the tiles list is empty, or if
		 * the SourceImage or any Tile hasn't been properly initialized.
		 *
		 * @param mosaic The completed MosaicCanvas
		 * @return 0 on success, or non-zero otherwise
		 */
		virtual MosaicCanvas* map_tiles() const = 0;

   int getSourceWidth() const;
   int getSourceHeight() const;
   unsigned int getNumPoints() const;

	protected:
		/**
		 * Main TileMapper Constructor.
		 *
		 * This constructor should be used for all general purposes.
		 * The default constructor is only defined for convenience.
		 *
		 * @param theSource The input image to construct a photomosaic of
		 * @param theTiles The tiles image to use in the mosaic
		 */
		TileMapper(const SourceImage& theSource, const vector<TileImage>& theTiles);

		/**
		 * The input image to construct a photomosic of
		 */
		SourceImage source;

		/**
		 * Map the points in the tree back to TileImages
		 */
		map<Point<3>, TileImage> tile_avg_map;	

		/**
		 * The points associated with the tiles
		 */
		vector<Point<3> > points;
};

#endif /* _TILEMAPPER_H */
