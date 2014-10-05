#include <iostream>
#include <cstdlib>
#include "EasyBMP.h"
#include "quadtree.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
   Quadtree *first, *second;
   BMP large;
   large.ReadFromFile("large.bmp");
   BMP const constBMP(large);

   // testing to make sure that the needed functions are const
   // this code will compile if and only if they are

   first = new Quadtree(constBMP, 128);

   Quadtree const constTree(*first);
   Quadtree copyTree(constTree);
   copyTree = constTree;
   BMP temp = constTree.decompress();
   int moretemp = constTree.pruneSize(74);
   moretemp = constTree.idealPrune(102);
   RGBApixel temppixel = constTree.getPixel(3, 3);

   return 0;
}
