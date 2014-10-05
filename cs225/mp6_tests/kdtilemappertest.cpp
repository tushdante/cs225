
#include "kdtilemappertest.h"

namespace testkdtilemapper
{

/**
 * adapter function that simplifies the code to read a source image
 */
bool readSourceImage(string const & fileName, SourceImage & source, int size)
{
   ImageReader ir;
   return ir.read_source_image(fileName, source, size) == 0;
}

/**
 * adapter function that simplifies the code to read a tile image
 */
bool readTileImage(string const & fileName, TileImage & tile)
{
   ImageReader ir;
   return ir.read_tile_image(fileName, tile) == 0;
}

/**
 * KDTileMapper Testing Helper Functions
 */

/**
 * attempts to create the photomosaic using map tiles and compares it to the 
 * expected image. Returns true if the success or failures of the mapping is 
 * the same as expected. The expected outcome is passed as a boolean variable 
 * named pass. The filename is the name of the expected mosaic image.
 */
bool matchingMapTiles(KDTileMapper const & mapper, string const & fileName, bool pass)
{
   MosaicCanvas* canvas = mapper.map_tiles();
   if (canvas == NULL)
      return !pass;
   else if(!pass)
      return false;

   int pixelsPerTile = 10;
   Magick::Image* actualImage = canvas->getMosaicImage(pixelsPerTile);
   Magick::Image expectedImage("./sampleimages/" + fileName);
   delete canvas;
   if (actualImage == NULL)
      return false;
   bool matches = expectedImage.compare(*actualImage);
   delete actualImage;
   return matches;
}

/**
 * adapter for matchingMapTiles to clean up the interface. This function is
 * used when the mapping is expected to be successfull.
 */
bool assertPassMapTiles(KDTileMapper const & mapper, string const & fileName)
{
   return matchingMapTiles(mapper, fileName, true);
}

/**
 * adapter for matchingMapTiles to clean up the interface. This function is
 * used when the mapping is expected to fail.
 */
bool assertFailMapTiles(KDTileMapper const & mapper, string const & fileName)
{
   return matchingMapTiles(mapper, fileName, false);
}

/**
 * KDTileMapper tests
 */

bool testKDTileMapperConstuctor()
{
   bool pass = true;
   vector<TileImage> realTiles;
   realTiles.push_back(TileImage());
   realTiles.push_back(TileImage());

   vector<TileImage> defaultTiles;
   defaultTiles.push_back(TileImage());

   vector<TileImage> emptyTiles;

   ImageReader ir;
   SourceImage realSource;
   ir.read_source_image(string("./sampleimages/tree.png"), realSource, 10);

   SourceImage defaultSource;

   // Test the default SourceImage
   KDTileMapper defaultSourceMapper(defaultSource, realTiles);
   pass &= (defaultSourceMapper.getNumPoints() == 2);
   pass &= (defaultSourceMapper.getSourceWidth() == 0);
   pass &= (defaultSourceMapper.getSourceHeight() == 0);
   //std::cout << "defaultSourceMapper (" << defaultSourceMapper.getNumPoints() << ", " 
   //   << defaultSourceMapper.getSourceWidth() << ", " 
   //   << defaultSourceMapper.getSourceHeight() << ")" << std::endl;

   // Test an empty vector of TileImages
   KDTileMapper emptyVectorMapper(realSource, emptyTiles);
   pass &= (emptyVectorMapper.getNumPoints() == 0);
   pass &= (emptyVectorMapper.getSourceWidth() == 462);
   pass &= (emptyVectorMapper.getSourceHeight() == 399);
   //std::cout << "emptyVectorMapper (" << emptyVectorMapper.getNumPoints() << ", " 
   //   << emptyVectorMapper.getSourceWidth() << ", " 
   //   << emptyVectorMapper.getSourceHeight() << ")" << std::endl;

   // Test a vector of default TileImages
   KDTileMapper defaultTileImagesMapper(realSource, defaultTiles);
   pass &= (defaultTileImagesMapper.getNumPoints() == 1);
   pass &= (defaultTileImagesMapper.getSourceWidth() == 462);
   pass &= (defaultTileImagesMapper.getSourceHeight() == 399);
   //std::cout << "defaultTileImagesMapper (" << defaultTileImagesMapper.getNumPoints() << ", " 
   //   << defaultTileImagesMapper.getSourceWidth() << ", " 
   //   << defaultTileImagesMapper.getSourceHeight() << ")" << std::endl;

   // Test constructor with real tiles
   KDTileMapper realTilesMapper(realSource, realTiles);
   pass &= (realTilesMapper.getNumPoints() == 2);
   pass &= (realTilesMapper.getSourceWidth() == 462);
   pass &= (realTilesMapper.getSourceHeight() == 399);
   //std::cout << "realTilesMapper (" << realTilesMapper.getNumPoints() << ", " 
   //   << realTilesMapper.getSourceWidth() << ", " 
   //   << realTilesMapper.getSourceHeight() << ")" << std::endl;

   return pass;
}

bool testKDTileMapperCopyConstructor()
{
   bool pass = true;
   vector<TileImage> realTiles;
   realTiles.push_back(TileImage());
   realTiles.push_back(TileImage());
   
   ImageReader ir;
   SourceImage source;
   ir.read_source_image(string("./sampleimages/tree.png"), source, 10);

   KDTileMapper mapper(source, realTiles);
   pass &= (mapper.getNumPoints() == 2);
   pass &= (mapper.getSourceWidth() == 462);
   pass &= (mapper.getSourceHeight() == 399);
   
   KDTileMapper mapperCopy(mapper);
   pass &= (mapperCopy.getNumPoints() == 2);
   pass &= (mapperCopy.getSourceWidth() == 462);
   pass &= (mapperCopy.getSourceHeight() == 399);
   
   return pass;
}

bool testKDTileMapperAssignmentOperator()
{
   bool pass = true;
   SourceImage defaultSource;
   vector<TileImage> emptyTiles;
   KDTileMapper mapperLHS(defaultSource,emptyTiles);
   
   vector<TileImage> realTiles;
   realTiles.push_back(TileImage());
   realTiles.push_back(TileImage());
   
   ImageReader ir;
   SourceImage source;
   ir.read_source_image(string("./sampleimages/tree.png"), source, 10);

   KDTileMapper mapperRHS(source, realTiles);
   pass &= (mapperRHS.getNumPoints() == 2);
   pass &= (mapperRHS.getSourceWidth() == 462);
   pass &= (mapperRHS.getSourceHeight() == 399);
   
   mapperLHS = mapperRHS;
   pass &= (mapperLHS.getNumPoints() == 2);
   pass &= (mapperLHS.getSourceWidth() == 462);
   pass &= (mapperLHS.getSourceHeight() == 399);
   
   return pass;
}

bool testMapTilesOnDefaultSource()
{
   SourceImage source;
   vector<TileImage> tileList;
   tileList.push_back(TileImage());
   KDTileMapper mapper = KDTileMapper(source, tileList);
   return assertFailMapTiles(mapper, "default-mosaic.png");
}

/**
 * Test KDTileMapper's map_tiles function on an empty tile list
 */
bool testMapTilesOnEmptyTileList()
{
   SourceImage source;
   if(!readSourceImage("./sampleimages/empty-mosaic-400x500.png", source))
      return false;
   
   vector<TileImage> tileList;
   
   KDTileMapper mapper(source, tileList);
   return assertFailMapTiles(mapper, "empty-mosaic.png");
}

/**
 * Test KDTileMapper's map_tiles function on a list of only invalid tiles
 */
bool testMapTilesWithListOfOnlyInvalidTiles()
{
   SourceImage source;
   if(!readSourceImage("./sampleimages/empty-mosaic-400x500.png", source))
      return false;
   
   vector<TileImage> defaultTileList;
   defaultTileList.push_back(TileImage());
   
   KDTileMapper mapper = KDTileMapper(source, defaultTileList);
   return assertFailMapTiles(mapper, "invalid-tiles-mosaic.png");
}

/**
 * Test KDTileMapper's map_tiles function on a list of only one valid tile
 */
bool testMapTilesWithOnlyOneTile()
{
   SourceImage source;
   if(!readSourceImage("./sampleimages/empty-mosaic-400x500.png", source))
      return false;
   
   TileImage theTile;
   if(!readTileImage("./sampleimages/redbox-50x50.png", theTile))
      return false;
   
   vector<TileImage> tileList;
   tileList.push_back(theTile);
   
   KDTileMapper mapper(source, tileList);
   return assertPassMapTiles(mapper, "single-tile-mosaic.png");
}

/**
 * Test KDTileMapper's map_tiles function on a list of several valid tiles
 */
bool testMapTilesWithInterestingInputs()
{
   ImageReader ir;
   SourceImage source;
   if(!readSourceImage("./sampleimages/checkered-source.png", source, 8))
      return false;
   
   vector<TileImage> tileList;
   tileList.push_back(TileImage((Color) {0, 0, 255}));
   tileList.push_back(TileImage((Color) {0, 255, 0}));
   tileList.push_back(TileImage((Color) {255, 0, 0}));
   
   KDTileMapper mapper(source, tileList);
   return assertPassMapTiles(mapper, "checkered-mosaic.png");
}

bool testConstCorrectness()
{
   system("g++ -c -w testcckdtree.cpp  >& __temp2.file ; cat __temp2.file");
   return true;
}

void runTestKDTileMapper(unsigned int testCaseNumber)
{
   std::vector< TestCase > testCases;
   testCases.push_back(TestCase("testKDTileMapperConstructor",testKDTileMapperConstuctor));
   testCases.push_back(TestCase("testKDTileMapperCopyConstructor",testKDTileMapperCopyConstructor));
   testCases.push_back(TestCase("testKDTileMapperAssignmentOperator",testKDTileMapperAssignmentOperator));
   testCases.push_back(TestCase("testMapTilesOnDefaultSource",testMapTilesOnDefaultSource));
   testCases.push_back(TestCase("testMapTilesOnEmptyTileList",testMapTilesOnEmptyTileList));
   testCases.push_back(TestCase("testMapTilesWithOnlyOneTile",testMapTilesWithOnlyOneTile));
   testCases.push_back(TestCase("testMapTilesWithInterestingInputs",testMapTilesWithInterestingInputs));
   testCases.push_back(TestCase("testConstCorrectness",testConstCorrectness));
   if (testCaseNumber > 0 && testCaseNumber <= testCases.size())
   {
      printResults(testCases[testCaseNumber-1].second());
   }
   else
   {
      runAll(testCases);
   }
}

}

