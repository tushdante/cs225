
/**
 * const correctness tests for KDTree
 */

#include "kdtree.h"
#include "mine_point.h"
#include <vector>

using std::vector;

void testCreateTree(vector< Point<3> > const & v)
{
   KDTree<3> k(v);
}

void testFindNearestNeighbor(KDTree<3> const & k, Point<3> const & target)
{
   k.findNearestNeighbor(target);
}

void testCopyConstructor(KDTree<3> const & k)
{
   KDTree<3> l(k);
}

void testAssignmentOperator(KDTree<3>  const & k, vector< Point<3> > v)
{
   KDTree<3> l(v);
   KDTree<3> const & cr = (l = k);
}

int main()
{
   Point<3> target;
   vector< Point<3> > v;
   v.push_back(target);
   KDTree<3> k(v);

   testCreateTree(v);
   testFindNearestNeighbor(k,target);
   testCopyConstructor(k);
   testAssignmentOperator(k,v);
   return 0;
}

