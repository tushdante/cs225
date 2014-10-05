/**
 * tilemapper.cpp
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
 */

#include "tilemapper.h"

#include <iostream>

using namespace std;

/**
 * Destructor
 */
TileMapper::~TileMapper() {
    // Nothing to do here
}

/**
 * Main TileMapper Constructor.
 *
 * This constructor should be used for all general purposes.
 * The default constructor is only defined for convenience.
 *
 * @param theSource The input image to construct a photomosaic of
 * @param theTiles The tiles image to use in the mosaic
 */
TileMapper::TileMapper(const SourceImage& theSource, const vector<TileImage>& theTiles)  
    : source(theSource) {

    // Create the map from Point to TileImage.
    for(unsigned int i = 0; i < theTiles.size(); ++i){
        Point<3> avg = theTiles[i].get_average_point();
        tile_avg_map[avg] = theTiles[i];
        points.push_back(avg);
    }
}

int TileMapper::getSourceWidth() const
{
   return source.get_width();
}
int TileMapper::getSourceHeight() const
{
   return source.get_height();
}

unsigned int TileMapper::getNumPoints() const
{
   return points.size();
}

