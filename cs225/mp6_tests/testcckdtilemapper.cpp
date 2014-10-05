
/**
 * const correctness tests for KDTileMapper
 */

#include "kdtilemapper.h"
#include "sourceimage.h"
#include "tileimage.h"
#include "mosaiccanvas.h"
#include <vector>

using std::vector;

void testCopyConstructor(KDTileMapper const & tileMapper)
{
   KDTileMapper copy(tileMapper);
}

void testAssignmentOperator(KDTileMapper const & tileMapper)
{
   SourceImage sourceImage;
   vector<TileImage> tileImages;
   KDTileMapper copy(sourceImage, tileImages);
   KDTileMapper const & cr = (copy = tileMapper);
}

void testMapTiles(KDTileMapper const & tileMapper)
{
   MosaicCanvas mosaic;
   tileMapper.map_tiles(mosaic);
}

int main()
{
   SourceImage sourceImage;
   vector<TileImage> tileImages;
   KDTileMapper tileMapper(sourceImage, tileImages);
   testCopyConstructor(tileMapper); 
   testAssignmentOperator(tileMapper);
   testMapTiles(tileMapper); 
   return 0;
}
