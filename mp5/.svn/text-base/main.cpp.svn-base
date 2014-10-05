#include <iostream>
#include "EasyBMP.h"
#include "quadtree.h"

using std::cout;
using std::endl;

int main() {

   BMP imgIn, imgOut;
   imgIn.ReadFromFile("in.bmp");

   // test constructor, decompress
   Quadtree halfTree(imgIn, 128);
   imgOut = halfTree.decompress();
   imgOut.WriteToFile("outHalf.bmp");

   // now for the real tests
   Quadtree fullTree;
   fullTree.buildTree(imgIn, 256);

   // you may want to experiment with different commands in this section

/*
   // test pruneSize and idealPrune (slow in valgrind, so you may want to
   // comment these out when doing most of your testing for memory leaks)
   cout << "fullTree.pruneSize(0) = " << fullTree.pruneSize(0) << endl;
   cout << "fullTree.pruneSize(100) = " << fullTree.pruneSize(100) << endl;
   cout << "fullTree.pruneSize(1000) = " << fullTree.pruneSize(1000) << endl;
   cout << "fullTree.pruneSize(100000) = " << fullTree.pruneSize(100000) << endl;

   cout << "fullTree.idealPrune(1000) = "  << fullTree.idealPrune(1000) << endl;
   cout << "fullTree.idealPrune(10000) = " << fullTree.idealPrune(10000) << endl;
*/

   // Test some creation/deletion functions
   Quadtree fullTree2;
   fullTree2 = fullTree;
   imgOut = fullTree2.decompress();
   imgOut.WriteToFile("outCopy.bmp");


   // test clockwiseRotate
   fullTree.clockwiseRotate();
   imgOut = fullTree.decompress();
   imgOut.WriteToFile("outRotated.bmp");


   // test prune
   fullTree = fullTree2;
   fullTree.prune(1000);
   imgOut = fullTree.decompress();
   imgOut.WriteToFile("outPruned.bmp");

/*
   // test several functions in succession
   Quadtree fullTree3(fullTree2);
   fullTree3.clockwiseRotate();
   fullTree3.prune(10000);
   fullTree3.clockwiseRotate();
   fullTree3.clockwiseRotate();
   fullTree3.clockwiseRotate();
   imgOut = fullTree3.decompress();
   imgOut.WriteToFile("outEtc.bmp");

   // ensure that printTree still works
   Quadtree tinyTree(imgIn, 32);
   cout << "Printing tinyTree:\n";
   tinyTree.prune(100);
   tinyTree.printTree();
*/
   return 0;
}
