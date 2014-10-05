/**
 * kdtilemapper.h
 *
 * KDTree implementation of the abstract TileMapper class. Uses a
 * K-dimensional Tree, defined in kdtree.h,  to do nearest-neighbor
 * search on images in the mosaic canvas.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#ifndef _KDTILEMAPPER_H
#define _KDTILEMAPPER_H

#include "tilemapper.h"

class KDTileMapper : public TileMapper
{
   // declare member functions and/or variables here
	public:
	KDTileMapper(const SourceImage & source, const vector<TileImage> & Tiles);
	MosaicCanvas* map_tiles() const;
	private:
	vector< Point<3> > validPoints;
};

#endif /* _KDTILEMAPPER_H */

