
#include "kdtilemapper.h"
#include "kdtree.h"

//ctor
KDTileMapper::KDTileMapper(const SourceImage & source, const vector<TileImage> & tiles):TileMapper(source,tiles){

}

//MosaicCanvas
MosaicCanvas* KDTileMapper::map_tiles() const {

	int columns=source.get_columns(),
		 rows=source.get_rows(),
		 testMosaic=0;
	
	Color	color_temp;
	
	MosaicCanvas	*Mosaic = new MosaicCanvas(rows, columns);
	
	Point <3>	pt,ClosestPt;
	
	KDTree<3> KD_tree(points);

	//vector of TileImage is empty or doesn't contain atleast 1 valid tile
	//SourceImage has no Pixels

	if ( (rows <= 0)||(columns <= 0) || (points.size()==0) ){
		return NULL;
	}


	for (int i=0; i<columns;i++){
		for (int j=0;j<rows;j++){
			color_temp = source.get_region_color(i,j);

			//set color
			pt.set(0, color_temp.rValue);
			pt.set(1, color_temp.gValue);
			pt.set(2, color_temp.bValue);

			//find nearest color
			ClosestPt = KD_tree.findNearestNeighbor(pt);

			testMosaic = Mosaic->set_tile(i,j,tile_avg_map.find(ClosestPt)->second);

			//check case a tile in the MosaicCanvas fails
			if (testMosaic)
				return NULL;
		}
	}
	return Mosaic;
}
