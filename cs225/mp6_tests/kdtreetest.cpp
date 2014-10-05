
#include "kdtreetest.h"

bool enable_mines = false;

namespace testkdtree {

/**
 * returns true if the two parameter KDTrees produce the same
 * nearest neighbors for all target elements and false otherwise.
 */
template <int K>
bool diff(KDTree<K> & lhs, KDTree<K> & rhs, vector< Point<K> > & targets)
{
   for(unsigned int i = 0; i < targets.size(); ++i)
   {
      Point<K> lhsResult = lhs.findNearestNeighbor(targets[i]);
      Point<K> rhsResult = rhs.findNearestNeighbor(targets[i]);
      if(rhsResult != lhsResult)
         return false;
   }
   return true;
}

/**
 * returns true if nearest neighbor search of the kdtree returns an element 
 * that is equal to the expected element and false otherwise.
 */
template <int K>
bool matchingNNS(KDTree<K> & tree, Point<K> & target, Point<K> & expected)
{
   Point<K> actual = tree.findNearestNeighbor(target);
   return (actual == expected);
}

/**
 * returns true if nearest neighbor search of the kdree created by the 
 * parameter vector of elements returns an element that is equal to the 
 * expected element and false otherwise.
 */
template <int K>
bool matchingNNS(vector< Point<K> > & points, Point<K> & target, Point<K> & expected)
{
   KDTree<K> tree(points);
   return matchingNNS<K>(tree, target, expected);
}

/**
 * returns true if nearest neighbor search of the kdtree returns an element 
 * that is equal to the expected element for each target element and false 
 * otherwise.
 */
template <int K>
bool matchingNNS(KDTree<K> & tree, vector< Point<K> > & targets, vector< Point<K> > & expected)
{
   for(unsigned int i = 0; i < targets.size(); ++i)
      if(!matchingNNS<K>(tree, targets[i], expected[i]))
         return false;
   return true;
}

/**
 * returns true if nearest neighbor search of the kdree created by the 
 * parameter vector of elements returns an element that is equal to the 
 * expected element and false otherwise. The mine trigger is used to enable
 * all the mines. If the kdtree atempts to search subtrees of the kdtree
 * when it doesn't need to, the mine will "explode" resulting in a segmentation 
 * fault.
 */
template <int K>
bool matchingNNSMine(vector< Point<K> > & points, Point<K> & target, Point<K> & expected)
{
   KDTree<K> tree(points);
   //trigger->enableMineField();
   enable_mines = true;
   bool isMatching = matchingNNS<K>(tree, target, expected);
   enable_mines = false;
   //trigger->disableMineField();
   return isMatching;
}

/**
 * generates a vector of elements with dim dimensions. The vector will contain 
 * size number of elements. The valTypes array has dim integers, each of which 
 * signifies either a fixed positive value that all generated elements will use 
 * for that dimension or -1 to signify a variable value for that dimension.
 */
template <int K>
vector< Point<K> > generateElements(int valTypes[], int size)
{
   vector< Point<K> > result;
   double values[K];

   for(int i = 0; i < size; ++i)
   {
      for(int j = 0; j < K; ++j)
      {
         if(valTypes[j] < 0)
            values[j] = i;
         else
            values[j] = valTypes[j];
      }
      Point<K> currElement(values);
      result.push_back(currElement);
   }

   return result;
}

/**
 * generates a vector of elements with dim dimensions. The vector will contain 
 * size number of elements. Also the elements generated do not contain a fixed 
 * value for any dimension.
 */
template <int K>
vector< Point<K> > generateElements(int size)
{
   int valTypes[K];
   for(int i = 0; i < K; ++i)
      valTypes[i] = -1;
   return generateElements<K>(valTypes, size);
}

/**
 * creates a kdtree with the parameter elements and confirms that the elements 
 * are inserted into the tree using nearest neighbor search.
 */
template <int K>
bool testNNS(vector< Point<K> > & points, int size)
{
   KDTree<K> tree(points);
   return matchingNNS<K>(tree, points, points);
}

/**
 * generates elements and uses them to create a kdtree. Then confirms that the 
 * elements are inserted into the tree using nearest neighbor search.
 */
template <int K>
bool testNNS(int size)
{
   vector< Point<K> > points = generateElements<K>(size);
   return testNNS<K>(points, size);
}

/**
 * generates elements with the parameter value types and uses them to create a 
 * kdtree. Then confirms that the elements are inserted into the tree using 
 * nearest neighbor search.
 */
template <int K>
bool testNNSwithValTypes(int valTypes[], int size)
{
   vector< Point<K> > points = generateElements<K>(valTypes, size);
   return testNNS<K>(points, size);
}

/**
 * Test the KDTree constructor
 */
bool testConstruction(int size)
{
   vector< Point<3> > points = generateElements<3>(size);
   KDTree<3> tree(points);

   std::stringstream expectedSS;
   for (int i = 0; i < 63; ++i)
   {
      expectedSS << "Point #" << i << " coords = (" << i << ", " << i << ", " 
         << i << ") index = " << i << std::endl;
   }

   std::stringstream actualSS;
   actualSS << tree;
   return expectedSS.str() == actualSS.str();
}

bool testConstruction()
{
   double coords[10][2] = {{-8, 7}, {-6, 4}, {-5, 6}, {-3, 5}, {0, 7}, 
                          {2, -7}, {3, 0}, {5, -4}, {6, -3}, {7, -6}};
   vector< Point<2> > points;
   for (int i = 0; i < 10; ++i)
   {
      points.push_back(Point<2>(coords[i]));
   }

   std::stringstream expectedSS;
   expectedSS << "Point #0 coords = (-8, 7) index = 1\n";
   expectedSS << "Point #1 coords = (-6, 4) index = 3\n";
   expectedSS << "Point #2 coords = (-5, 6) index = 0\n";
   expectedSS << "Point #3 coords = (-3, 5) index = 2\n";
   expectedSS << "Point #4 coords = (0, 7) index = 4\n";
   expectedSS << "Point #5 coords = (2, -7) index = 5\n";
   expectedSS << "Point #6 coords = (3, 0) index = 9\n";
   expectedSS << "Point #7 coords = (5, -4) index = 7\n";
   expectedSS << "Point #8 coords = (6, -3) index = 6\n";
   expectedSS << "Point #9 coords = (7, -6) index = 8" << std::endl;

   std::stringstream actualSS;
   KDTree<2> tree(points);
   actualSS << tree;
   return expectedSS.str() == actualSS.str();
}

bool testConstruction63()
{
   return testConstruction(63);
}

/**
 * Test the KDTree copy constructor
 */
bool testKDTreeCopyConstructor(int size)
{
   vector< Point<3> > points = generateElements<3>(size);
   KDTree<3> sourceTree(points);
   KDTree<3> copyTree(sourceTree);
   return diff<3>(sourceTree,copyTree,points);
}

bool testKDTreeCopyConstructor63()
{
   return testKDTreeCopyConstructor(63);
}

/**
 * Test the KDTree assignment operator
 */
bool testKDTreeAssignmentOperator(int size)
{
   vector< Point<3> > emptyPoints;
   emptyPoints.push_back(Point<3>());
   vector< Point<3> > points = generateElements<3>(size);
   KDTree<3> rhs(points);
   KDTree<3> lhs(emptyPoints);
   lhs = rhs;
   return diff<3>(rhs,lhs,points);
}

bool testKDTreeAssignmentOperator63()
{
   return testKDTreeAssignmentOperator(63);
}

/**
 * Test nearest neighbor search on elements with zeroes for all red color 
 * components
 */
bool testNNSwithoutRed(int size)
{
   int valTypes[3] = {0,-1,-1};
   return testNNSwithValTypes<3>(valTypes,size); 
}

bool testNNSwithoutRed63()
{
   return testNNSwithoutRed(63);
}

/**
 * Test nearest neighbor search on elements with zeroes for all green color 
 * components
 */
bool testNNSwithoutGreen(int size)
{
   int valTypes[3] = {-1,0,-1};
   return testNNSwithValTypes<3>(valTypes,size); 
}

bool testNNSwithoutGreen63()
{
   return testNNSwithoutGreen(63);
}

/**
 * Test nearest neighbor search on elements with zeroes for all blue color 
 * components
 */
bool testNNSwithoutBlue(int size)
{
   int valTypes[3] = {-1,-1,0};
   return testNNSwithValTypes<3>(valTypes,size); 
}

bool testNNSwithoutBlue63()
{
   return testNNSwithoutBlue(63);
}

/**
 * Test nearest neighbor search on elements with zeroes for all red and green 
 * color components
 */
bool testNNSwithoutRedOrGreen(int size)
{
   int valTypes[3] = {0,0,-1};
   return testNNSwithValTypes<3>(valTypes,size); 
}

bool testNNSwithoutRedOrGreen63()
{
   return testNNSwithoutRedOrGreen(63);
}

/**
 * Test nearest neighbor search on elements with zeroes for all red and blue 
 * color components
 */
bool testNNSwithoutRedOrBlue(int size)
{
   int valTypes[3] = {0,-1,0};
   return testNNSwithValTypes<3>(valTypes,size); 
}

bool testNNSwithoutRedOrBlue63()
{
   return testNNSwithoutRedOrBlue(63);
}

/**
 * Test nearest neighbor search on elements with zeroes for all green and blue 
 * color components
 */
bool testNNSwithoutGreenOrBlue(int size)
{
   int valTypes[3] = {-1,0,0};
   return testNNSwithValTypes<3>(valTypes,size); 
}

bool testNNSwithoutGreenOrBlue63()
{
   return testNNSwithoutGreenOrBlue(63);
}

/*****************************************
*                    8                   * 
*     X              7     X             * 
*                    6                   * 
*                    5                   * 
*                    4                   * 
*                    3                   * 
*                    2             X     * 
*       O            1                   * 
* 9876543210987 X 32101234567890123456789* 
*       X            1                   * 
*                    2                   * 
*                    3             X     * 
*                    4                   * 
*                    5                   * 
*                    6                   * 
*                    7                   * 
*                    8                   * 
*****************************************/
// Looking for O, Xs are points 
bool testDeceptiveNNOneLevel()
{
   double coords[6][2] = {{-15, 7}, {6, 7}, {-13, -1}, {-5, 0}, {14, -3}, {14, 2}};
   double targetCoords[2] = {-13,1};
   double expectedCoords[2] = {-13,-1};

   vector< Point<2> > points;
   for (int i = 0; i < 6; ++i)
      points.push_back(Point<2>(coords[i]));
   Point<2> target(targetCoords);
   Point<2> expected(expectedCoords);
   return matchingNNS<2>(points, target, expected);
}

/*****************************************
*                    8                   * 
*                    7     X             * 
*                    6                   * 
*                                        * 
*                    X                   * 
*                                        * 
*                    2                   * 
*       X           O1                   * 
* 98765432109876 X 21012 X 67890123456789* 
*                    1X                  * 
*                    2                   * 
*                                        * 
*                    X                   * 
*                                        * 
*                    6                   * 
*                    7                   * 
*                    8                   * 
*****************************************/
// Looking for O, Xs are points 
bool testDeceptiveNNTwoLevel()
{
   double coords[7][2] = {{4, 0}, {1, -1}, {-4, 0}, {6, 7}, {0, 4}, {-13, 1}, {0, -4}};
   double targetCoords[2] = {-1,1};
   double expectedCoords[2] = {1,-1};

   vector< Point<2> > points;
   for (int i = 0; i < 7; ++i)
      points.push_back(Point<2>(coords[i]));
   Point<2> target(targetCoords);
   Point<2> expected(expectedCoords);
   return matchingNNS<2>(points, target, expected);
}

 /***********************
 *    X      8          * 
 *           7          * 
 *       X   6          * 
 *     S  X             * 
 *      N    X          * 
 *                      * 
 *           2          * 
 *           1          * 
 * 098765432101 X 567890* 
 *           1          * 
 *           2          * 
 *           3     M    * 
 *           4          * 
 *           5   X      * 
 *           6      M   * 
 *           7 M        * 
 ***********************/
// M: mine
// S: search target
// N: nearest neighbor
// X: non-mine elements
bool testMines()
{
   //                              NN
   double coords[10][2] = {{-8, 7}, {-6, 4}, {-5, 6}, {-3, 5}, {0, 7}, 
                          {2, -7}, {3, 0}, {5, -4}, {6, -3}, {7, -6}};
   //                     M        M       M        M        M
   bool isMine[10] = { false, false, false, false, false, true, true, true, true, true };
   double targetCoords[2] = {-7,5};
   double expectedCoords[2] = {-6,4};

   vector< Point<2> > points;
   for (int i = 0; i < 10; ++i)
      points.push_back(Point<2>(coords[i], isMine[i]));
   Point<2> target(targetCoords);
   Point<2> expected(expectedCoords);
   return matchingNNSMine<2>(points, target, expected);
}

bool testMines2()
{
   //                                                                     M
   double coords[7][2] = {{2, 3}, {4, 7}, {5, 4}, {7, 2}, {8, 1}, {9, 6}, {10, 8}};
   bool isMine[7] = { false, false, false, false, false, false, true };
   double targetCoords[2] = {6, 2};
   double expectedCoords[2] = {7, 2};

   vector< Point<2> > points;
   for (int i = 0; i < 7; ++i)
      points.push_back(Point<2>(coords[i], isMine[i]));
   Point<2> target(targetCoords);
   Point<2> expected(expectedCoords);
   return matchingNNSMine<2>(points, target, expected);
}

bool testMines3()
{
   //                     M       M       M               M
   double coords[7][2] = {{2, 3}, {4, 7}, {5, 4}, {7, 2}, {8, 1}, {9, 6}, {10, 8}};
   bool isMine[7] = { true, true, true, false, true, false, false };
   double targetCoords[2] = {9, 8};
   double expectedCoords[2] = {10, 8};

   vector< Point<2> > points;
   for (int i = 0; i < 7; ++i)
      points.push_back(Point<2>(coords[i], isMine[i]));
   Point<2> target(targetCoords);
   Point<2> expected(expectedCoords);
   return matchingNNSMine<2>(points, target, expected);
}

bool testMines4()
{
   //                     M       M       M               M
   double coords[6][2] = {{2, 3}, {4, 7}, {5, 4}, {7, 2}, {8, 1}, {9, 6}};
   bool isMine[6] = { true, true, false, false, true, false };
   double targetCoords[2] = {9, 8};
   double expectedCoords[2] = {9, 6};

   vector< Point<2> > points;
   for (int i = 0; i < 6; ++i)
      points.push_back(Point<2>(coords[i], isMine[i]));
   Point<2> target(targetCoords);
   Point<2> expected(expectedCoords);
   return matchingNNSMine<2>(points, target, expected);
}

bool testMines5()
{
   //                                                     M       M       M
   double coords[7][2] = {{2, 3}, {4, 7}, {5, 4}, {7, 2}, {8, 1}, {9, 6}, {10,8}};
   bool isMine[7] = { false, false, false, false, true, true, true };
   double targetCoords[2] = {0, 4};
   double expectedCoords[2] = {2, 3};

   vector< Point<2> > points;
   for (int i = 0; i < 7; ++i)
      points.push_back(Point<2>(coords[i], isMine[i]));
   Point<2> target(targetCoords);
   Point<2> expected(expectedCoords);
   return matchingNNSMine<2>(points, target, expected);
}

bool testMines6()
{
   //                                                            M       M       M
   double coords[8][2] = {{2, 3}, {4, 7}, {0,5}, {5, 4}, {7, 2}, {8, 1}, {9, 6}, {8,8}};
   bool isMine[8] = { false, false, false, false, false, true, true, true };
   double targetCoords[2] = {0, 4};
   double expectedCoords[2] = {0, 5};
   vector< Point<2> > points;
   for (int i = 0; i < 8; ++i)
      points.push_back(Point<2>(coords[i], isMine[i]));
   Point<2> target(targetCoords);
   Point<2> expected(expectedCoords);
   return matchingNNSMine<2>(points, target, expected);
}

bool testNNS_1_10()
{
   return testNNS<1>(10);
}

bool testNNS_2_1000()
{
   return testNNS<2>(1000);
}

bool testNNS_3_63()
{
   return testNNS<3>(63);
}

bool testNNS_4_1000()
{
   return testNNS<4>(1000);
}

bool testNNS_3_1000()
{
   return testNNS<3>(1000);
}

bool testConstCorrectness()
{
   system("g++ -c -w testcckdtree.cpp >& __temp.file ; cat __temp.file");
   return true;
}

void runTestKDTree(unsigned int testCaseNumber)
{
   std::vector< TestCase > testCases;
   testCases.push_back(TestCase("testConstruction63",testConstruction63));
   testCases.push_back(TestCase("testConstruction",testConstruction));
   testCases.push_back(TestCase("testKDTreeCopyConstructor63",testKDTreeCopyConstructor63));
   testCases.push_back(TestCase("testKDTreeAssignmentOperator63",testKDTreeAssignmentOperator63));
   testCases.push_back(TestCase("testNNS_1_10",testNNS_1_10));
   testCases.push_back(TestCase("testNNS_2_1000",testNNS_2_1000));
   testCases.push_back(TestCase("testNNS_3_63",testNNS_3_63));
   testCases.push_back(TestCase("testNNS_4_1000",testNNS_4_1000));
   testCases.push_back(TestCase("testNNS_3_1000",testNNS_3_1000));
   testCases.push_back(TestCase("testNNSwithoutRed63",testNNSwithoutRed63));
   testCases.push_back(TestCase("testNNSwithoutGreen63",testNNSwithoutGreen63));
   testCases.push_back(TestCase("testNNSwithoutBlue63",testNNSwithoutBlue63));
   testCases.push_back(TestCase("testNNSwithoutRedOrGreen63",testNNSwithoutRedOrGreen63));
   testCases.push_back(TestCase("testNNSwithoutRedOrBlue63",testNNSwithoutRedOrBlue63));
   testCases.push_back(TestCase("testNNSwithoutGreenOrBlue63",testNNSwithoutGreenOrBlue63));
   testCases.push_back(TestCase("testDeceptiveNNOneLevel",testDeceptiveNNOneLevel));
   testCases.push_back(TestCase("testDeceptiveNNTwoLevel",testDeceptiveNNTwoLevel));
   testCases.push_back(TestCase("testMines",testMines));
   testCases.push_back(TestCase("testMines2",testMines2));
   testCases.push_back(TestCase("testMines3",testMines3));
   testCases.push_back(TestCase("testMines4",testMines4));
   testCases.push_back(TestCase("testMines5",testMines5));
   testCases.push_back(TestCase("testMines6",testMines6));
   testCases.push_back(TestCase("testConstCorrectness",testConstCorrectness));
   testCases.push_back(TestCase("testNNS_3_1000",testNNS_3_1000));
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

