
#include "kdtilemapper.h"
#include "kdtree.h"

/*
	KDTileMapper: 
	Constructor that takes a SourceImage and a reference to a STL 
	vector of TileImage objects in that order. Since this class derives from 
	TileMapper, call the constructor defined in the base class with the same
	parameters.
*/
KDTileMapper::KDTileMapper(const SourceImage & theSource , vector<TileImage> & theTiles ) 
															: TileMapper(theSource, theTiles)
{
}



/*
    map_tiles() :
    Maps the rectangular sections of the source image to tile 
    images. The locations of the tiles in the mosaic are defined by a 
    MosaicCanvas. This function creates a new MosaicCanvas which is 
    appropriately sized based on the rows and columns of tiles in the 
    SourceImage. Then, each tile in the MosaicCanvas is set to an 
    appropriate TileImage, using a KDTree to find the Nearest Neighbor for each 
    region. 
*/
MosaicCanvas* KDTileMapper::map_tiles() const
{
/*
 You should return NULL in the case of any errors. Possible error conditions 
 for map_tiles include:
          o the vector of TileImage objects is empty or does not contain at 
          	least one valid tile
          o the SourceImage has no pixels
          o setting a tile in the MosaicCanvas fails
*/
		
int width = source.get_width();
int height= source.get_height();
bool validTree=false;

	//vector of TileImage/points is empty
	if( points.empty() ) return NULL;
	
	//Source is empty
	if( (width<1 && height<1)) return NULL;
	
	//check if all tiles are invalid
	for( unsigned int i=0 ; i<points.size() ; i++)
		{
		TileImage checkTile = tile_avg_map.find(points[i])->second;
			
		//see if at least one valid tile image exists in map
		if	( checkTile.is_valid() ) validTree=true;
		}
		
	//if at least one valid tile was found, flag was changed to true
	if (validTree==false) return NULL;

//end error checking
//==============================================================================


//Map Tiles onto Canvas

	Point<3> tempPoint;
	Color sourceColor;	
	
	//Build KDtree
	KDTree<3> imgTree(points);
	TileImage tempImage;

	//get rows colums of source image
	int rows    = source.get_rows();
	int columns = source.get_columns();

	
	//create new Mosaic Canvas to be filled with tileImages. Returns pointer of this at the end.
	MosaicCanvas* canvas = new MosaicCanvas(rows, columns);

	//each tile in the MosaicCanvas is set to an appropriate TileImage, 
	//using Nearest Neighbor for each region
	
	for ( int i=0 ; i<rows ; i++ )
		for(int j=0; j<height ; j++)
			{
			//find avg of tile in source & convert it into point to be used
			//for kdtree findNN
			sourceColor = source.get_region_color(i, j);
			tempPoint[0]=sourceColor.rValue;
			tempPoint[1]=sourceColor.gValue;
			tempPoint[2]=sourceColor.bValue;	
			
			//find point (key) for tileimage that is closest to that from source
			tempPoint = imgTree.findNearestNeighbor(tempPoint);
			
			//find tileImage (data)
			tempImage = tile_avg_map.find(tempPoint)->second;

			//check validity
			if (!tempImage.is_valid()) 
				{
				delete canvas;
				return NULL;
				}
				
			//set valid tile into canvas
			canvas->set_tile(i, j, tempImage) ;
			}

	//return pointer
	return canvas;
}
