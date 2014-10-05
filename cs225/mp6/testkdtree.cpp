
#include "mine_point.h"
#include "kdtree.h"

#include <sstream>

bool enable_mines = false;

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
   enable_mines = true;
   bool isMatching = matchingNNS<K>(tree, target, expected);
   enable_mines = false;
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

/******************************************************************************
 * Test Cases
 *****************************************************************************/

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

bool testConstruction63()
{
   return testConstruction(63);
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

bool testNNS_1_10()
{
   return testNNS<1>(10);
}

bool testNNS_3_63()
{
   return testNNS<3>(63);
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

void runAll(std::vector< std::pair<std::string, bool (*)()> > & testCases)
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
   std::vector< std::pair<std::string, bool (*)()> > testCases;
   testCases.push_back(std::pair<std::string,bool (*)()>("testConstruction63",testConstruction63));
   testCases.push_back(std::pair<std::string,bool (*)()>("testNNS_1_10",testNNS_1_10));
   testCases.push_back(std::pair<std::string,bool (*)()>("testNNS_3_63",testNNS_3_63));
   testCases.push_back(std::pair<std::string,bool (*)()>("testDeceptiveNNOneLevel",testDeceptiveNNOneLevel));
   testCases.push_back(std::pair<std::string,bool (*)()>("testMines",testMines));
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

