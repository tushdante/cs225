/******************************************************************************
 * Test Cases (28 points total):
 *
 * KDTileMapper - constructor - 9 points
 * #26 (3) - constructor
 * #27 (3) - copy constructor
 * #28 (3) - assignment operator
 *
 * KDTileMapper - map_tiles - 15 points
 * #29 (3) - map_tiles default source
 * #30 (4) - map_tiles empty tile list
 * #31 (4) - map_tiles list of only invalid tiles
 * #32 (4) - map_tiles interesting inputs
 * 
 * KDTileMapper - const correctness - 4 points 
 * #33 (4) - attempt to compile testcckdtilemapper.cpp.  Please see that file for details. 
 * 
 ******************************************************************************/

#ifndef KD_TILE_MAPPER_TEST_H
#define KD_TILE_MAPPER_TEST_H

#include "imagereader.h"
#include "kdtilemapper.h"
#include "testcommon.h"

using std::vector;

namespace testkdtilemapper
{
bool readSourceImage(string const & fileName, SourceImage & source, int size = 20);
bool readTileImage(string const & fileName, TileImage & tile);
bool matchingMapTiles(KDTileMapper const & mapper, string const & fileName, bool pass);
bool assertPassMapTiles(KDTileMapper const & mapper, string const & fileName);
bool assertFailMapTiles(KDTileMapper const & mapper, string const & fileName);
bool testKDTileMapperConstuctor();
bool testKDTileMapperCopyConstructor();
bool testKDTileMapperAssignmentOperator();
bool testMapTilesOnDefaultSource();
bool testMapTilesOnEmptyTileList();
bool testMapTilesWithListOfOnlyInvalidTiles();
bool testMapTilesWithOnlyOneTile();
bool testMapTilesWithInterestingInputs();
bool testConstCorrectness();
void runTestKDTileMapper(unsigned int testCaseNumber);
}

#endif
