/* kdtree.h
 * KDTree implementation using Points in k-dimensional space.
 *
 * Written by Cinda Heeren for CS225 MP6
 * Spring 2009
 * 
 * Revision history:
 * 3/31/2009        Created
*/

#ifndef __KDTREE_H__
#define __KDTREE_H__

#include <vector>
#include "point.h"

template<int Dim>
class KDTree;

template<int Dim>
std::ostream & operator<<(std::ostream & out, KDTree<Dim> const & tree);

template<int Dim>
class KDTree
{
private:
   std::vector< Point<Dim> > points;
   std::vector<int> point_index;
	void GetMedian(int upper, int lower, int level);
	void sort_vector(int upper, int lower, const int level);
	double min_D;
	int index_min_D;
	Point<Dim>helper(int min,int max, const Point<Dim> &pt, int level);	
public:
	Point<Dim> findNearestNeighbor(const Point<Dim> &pt);
	KDTree(const std::vector< Point<Dim> > & points);
   friend std::ostream & operator<< <Dim>(std::ostream & out, KDTree<Dim> const & tree);
};

#include "kdtree.cpp"

#endif

