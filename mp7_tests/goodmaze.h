
#ifndef GOODMAZE_H
#define GOODMAZE_H

#include <vector>
#include "EasyBMP.h"

#define right 0
#define down 1
#define left 2
#define up 3

class GoodMaze
{
public: //for grading purposes, more is public
   std::vector< std::vector< std::vector<bool> > > walls;
   std::vector<int> solution;
   int destination_x;

   GoodMaze() : destination_x(0){};
   void makeMaze(int width, int height);
   bool canTravel(int x, int y, int direction);
   void solveMaze();
   BMP* drawMaze();
   BMP* drawMazeWithSolution();
};

#endif

