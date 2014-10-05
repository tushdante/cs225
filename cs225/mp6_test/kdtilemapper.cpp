
#include "kdtilemapper.h"
#include "kdtree.h"

using std::cout;
using std::endl;

// define KDTileMapper member functions here

KDTileMapper::KDTileMapper(const SourceImage & source, const vector<TileImage> & Tiles):TileMapper(source, Tiles) {
	//copy points to validPoints
	validPoints = points;

	//remove any invalid points in validPoints vector
	vector< Point<3> >::iterator it;
	for(it = validPoints.begin(); it < validPoints.end(); it++){
		if( (tile_avg_map.find( (*it)) -> second).is_valid() == false) {
			validPoints.erase(it);
		}
	}
}

MosaicCanvas* KDTileMapper::map_tiles() const{
	//check for any invalid cases
	if(validPoints.empty() == true || source.get_rows() < 1 || source.get_columns() < 1)
		return NULL;
	//make the mosaic canvas according to the rows and columns of the image
	MosaicCanvas* mosaic = new MosaicCanvas(source.get_rows(), source.get_columns());
	//make kdtree
	KDTree<3> tree(points);
	//go through each pixel in the image, get color, find nearest point, set appropriate tile image to the canvas
	for(int i = 0; i < source.get_rows(); i++) {
		for (int j = 0; j < source.get_columns(); j++) {
			//get color
			Color c = source.get_region_color(i,j);
			//convert the color to point
			double red = c.rValue;
			double green = c.gValue;
			double blue = c.bValue;
			Point<3> p;
			p.set(0,red);
			p.set(1,green);
			p.set(2,blue);
			//find nearest neightbor
			Point<3> NearestNeighbor = tree.findNearestNeighbor(p);
			//get the iterator correspond to the founded point.
			map<Point<3>,TileImage>::const_iterator iter = tile_avg_map.find(NearestNeighbor); 
			//assign the tile to the canvas
			(*mosaic).set_tile(i,j,(*iter).second);
		}
	}
	return mosaic;
}
