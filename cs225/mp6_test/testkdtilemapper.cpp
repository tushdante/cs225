
#include "imagereader.h"
#include "kdtilemapper.h"

/**
 * adapter function that simplifies the code to read a source image
 */
bool readSourceImage(string const & fileName, SourceImage & source, int size = 20)
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

   // Test an empty vector of TileImages
   KDTileMapper emptyVectorMapper(realSource, emptyTiles);
   pass &= (emptyVectorMapper.getNumPoints() == 0);
   pass &= (emptyVectorMapper.getSourceWidth() == 462);
   pass &= (emptyVectorMapper.getSourceHeight() == 399);

   // Test a vector of default TileImages
   KDTileMapper defaultTileImagesMapper(realSource, defaultTiles);
   pass &= (defaultTileImagesMapper.getNumPoints() == 1);
   pass &= (defaultTileImagesMapper.getSourceWidth() == 462);
   pass &= (defaultTileImagesMapper.getSourceHeight() == 399);

   // Test constructor with real tiles
   KDTileMapper realTilesMapper(realSource, realTiles);
   pass &= (realTilesMapper.getNumPoints() == 2);
   pass &= (realTilesMapper.getSourceWidth() == 462);
   pass &= (realTilesMapper.getSourceHeight() == 399);

   return pass;
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

/**
 * prints out pass or fail message based on parameter value.
 */
void printResults(bool pass)
{
   if(pass)
      std::cout << "PASS" << std::endl;
   else
      std::cout << "FAIL" << std::endl;
}

void runAll(std::vector< pair<std::string, bool (*)()> > & testCases)
{
   unsigned int maxNameLength = 0;
   for (unsigned int i = 0; i < testCases.size(); ++i)
   {
      if (maxNameLength < testCases[i].first.size())
         maxNameLength = testCases[i].first.size();
   }

   for (unsigned int i = 0; i < testCases.size(); ++i)
   {
      std::cout << "Running " << testCases[i].first << "... ";
      unsigned int padding = maxNameLength - testCases[i].first.size();
      for (unsigned int j = 0; j < padding; ++j)
         std::cout << " ";
      printResults(testCases[i].second());
   }
}

int main(int argc, char* argv[])
{
   Magick::InitializeMagick(NULL); // added by j.e. because new im requires init 
   std::vector< pair<std::string, bool (*)()> > testCases;
   testCases.push_back(pair<std::string,bool (*)()>("testKDTileMapperConstructor",testKDTileMapperConstuctor));
   testCases.push_back(pair<std::string,bool (*)()>("testMapTilesWithInterestingInputs",testMapTilesWithInterestingInputs));
   if (argc == 2)
   {
      int testCaseNumber = atoi(argv[1])-1;
      if (testCaseNumber < 0 || testCaseNumber >= (int)testCases.size())
      {
         std::cerr << "invalid test case number" << std::endl;
      }
      else
      {
         printResults(testCases[testCaseNumber].second());
      }
   }
   else
   {
      runAll(testCases);
   }
}

