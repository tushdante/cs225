/******************************************************************************
 * Test Cases (72 points total):
 *
 * KDTree - constructor - 4 points
 * #1 (2) - construct
 * #2 (2) - construct
 *
 * KDTree - copy constructor - 4 points
 * #3 (4) - construct, copy, compare 
 *
 * KDTree - assignment operator - 4 points
 * #4 (4) - construct, assign, compare
 * 
 * KDTree - create_tree()/find_nearest_neighbor() - 50 points
 * #5 (3) - create 1D tree and verify NNS
 * #6 (3) - create 2D tree and verify NNS
 * #7 (2) - create 3D tree and verify NNS
 * #8 (3) - create 4D tree and verify NNS
 * #9 (3) - create 3D with many points and verify NNS
 * #10 (2) - create 3D tree with no red and verify NNS
 * #11 (2) - create 3D tree with no green and verify NNS
 * #12 (2) - create 3D tree with no blue and verify NNS
 * #13 (2) - create 3D tree with no red or green and verify NNS
 * #14 (2) - create 3D tree with no red or blue and verify NNS
 * #15 (2) - create 3D tree with no green or blue and verify NNS
 * #16 (3) - nearest neighbor is one level above bottom on backtrace
 * #17 (3) - nearest neighbor is two levels above bottom on backtrace
 * #18 (3) - mines to ensure the code uses O(log n) average search time
 * #19 (3) - mines to ensure the code uses O(log n) average search time
 * #20 (3) - mines to ensure the code uses O(log n) average search time
 * #21 (3) - mines to ensure the code uses O(log n) average search time
 * #22 (3) - mines to ensure the code uses O(log n) average search time
 * #23 (3) - mines to ensure the code uses O(log n) average search time
 * 
 * KDTree - const correctness - 6 points 
 * #24 (6) - attempt to compile testcckdtree.cpp.  Please see that file for details. 
 * 
 * KDTree - valgrind tests - 4 points
 * #25 (4) - check KDTree class for memory leaks or errors
 ******************************************************************************/

#ifndef KD_TREE_TEST_H
#define KD_TREE_TEST_H

#include "mine_point.h"
#include "kdtree.h"
#include "testcommon.h"

#include <vector>
#include <sstream>

using std::vector;

extern bool enable_mines;

namespace testkdtree
{

template <int K>
bool diff(KDTree<K> & lhs, KDTree<K> & rhs, vector< Point<K> > & targets);
template <int K>
bool matchingNNS(KDTree<K> & tree, Point<K> & target, Point<K> & expected);
template <int K>
bool matchingNNS(vector< Point<K> > & points, Point<K> & target, Point<K> & expected);
template <int K>
bool matchingNNS(KDTree<K> & tree, vector< Point<K> > & targets, vector< Point<K> > & expected);
template <int K>
bool matchingNNSMine(vector< Point<K> > & points, Point<K> & target, Point<K> & expected);
template <int K>
vector< Point<K> > generateElements(int valTypes[], int size);
template <int K>
vector< Point<K> > generateElements(int size);
template <int K>
bool testNNS(vector< Point<K> > & points, int size);
template <int K>
bool testNNS(int size);
template <int K>
bool testNNSwithValTypes(int valTypes[], int size);
bool testConstruction(int size);
bool testConstruction();
bool testConstruction63();
bool testKDTreeCopyConstructor(int size);
bool testKDTreeCopyConstructor63();
bool testKDTreeAssignmentOperator(int size);
bool testKDTreeAssignmentOperator63();
bool testNNSwithoutRed(int size);
bool testNNSwithoutRed63();
bool testNNSwithoutGreen(int size);
bool testNNSwithoutGreen63();
bool testNNSwithoutBlue(int size);
bool testNNSwithoutBlue63();
bool testNNSwithoutRedOrGreen(int size);
bool testNNSwithoutRedOrGreen63();
bool testNNSwithoutRedOrBlue(int size);
bool testNNSwithoutRedOrBlue63();
bool testNNSwithoutGreenOrBlue(int size);
bool testNNSwithoutGreenOrBlue63();
bool testDeceptiveNNOneLevel();
bool testDeceptiveNNTwoLevel();
bool testMines();
bool testMines2();
bool testMines3();
bool testMines4();
bool testMines5();
bool testMines6();
bool testNNS_1_10();
bool testNNS_2_1000();
bool testNNS_3_63();
bool testNNS_4_1000();
bool testNNS_3_1000();
bool testConstCorrectness();
void runTestKDTree(unsigned int testCaseNumber);

}

#endif

