
#include "squaremazetest.h"
#include <iostream>

namespace SquareMazeTest {

// Never do this.
SquareMaze *globalMaze;
int width, height;
int calls, components;
bool **visited;

bool mazeStatusCheck(int check) {
   visited = new bool *[width];
   for (int i = 0; i < width; i++) {
      visited[i] = new bool[height];
      for (int j = 0; j < height; j++)
         visited[i][j] = false;
   }

   components = 0;
   calls = 0;

   for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
         if (!visited[i][j]) {
            recDFS(i, j);
            components++;
         }
      }
   }

   // check 1 -- is it acyclic?
   // check 2 -- is it connected?
   // check 3 -- both at once

   if (check == 1 || check == 3)
      if (calls + components != width*height*2)
         return false;
   if (check == 2 || check == 3)
      if (components != 1)
         return false;
   return true;
}

void recDFS(int x, int y) {
   calls++;
   if (visited[x][y])
      return;
   visited[x][y] = true;

   if (x < width-1 && globalMaze->canTravel(x, y, 0))
      recDFS(x+1, y);
   if (y < height-1 && globalMaze->canTravel(x, y, 1))
      recDFS(x, y+1);
   if (x > 0 && globalMaze->canTravel(x, y, 2))
      recDFS(x-1, y);
   if (y > 0 && globalMaze->canTravel(x, y, 3))
      recDFS(x, y-1);
}

void makeMazeCopy(SquareMaze &dest, GoodMaze &source) {
   dest.makeMaze(width, height);
   for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
         if (i < width-1)
            dest.setWall(i, j, 0, !source.canTravel(i, j, 0));
         if (j < height-1)
            dest.setWall(i, j, 1, !source.canTravel(i, j, 1));
      }
   }
}

bool testMakeSmallMaze()
{
   SquareMaze userMaze;
   width = height = 2;
   userMaze.makeMaze(width, height);
   globalMaze = &userMaze;
   if (mazeStatusCheck(3))
      std::cout << "Maze is a spanning tree.\n";
   else
      std::cout << "Maze is not a spanning tree.\n";
   return true;
}

bool testMakeMazeConnected()
{
   SquareMaze userMaze;
   width = height = 15;
   userMaze.makeMaze(width, height);
   globalMaze = &userMaze;
   if (mazeStatusCheck(1))
      std::cout << "Maze is acyclic.\n";
   else
      std::cout << "Maze is not acyclic.\n";
   return true;
}

bool testMakeMazeCycleFree()
{
   SquareMaze userMaze;
   width = height = 15;
   userMaze.makeMaze(width, height);
   globalMaze = &userMaze;
   if (mazeStatusCheck(2))
      std::cout << "Maze is spanning.\n";
   else
      std::cout << "Maze is not spanning.\n";
   return true;
}

bool testMakeMazeAll()
{
   SquareMaze userMaze;
   width = height = 1000;
   userMaze.makeMaze(width, height);
   globalMaze = &userMaze;
   if (mazeStatusCheck(3))
      std::cout << "Maze is a spanning tree.\n";
   else
      std::cout << "Maze is not a spanning tree.\n";
   return true;
}

bool testSolveMazeValidPath()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 15;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   userMaze.solveMaze();

   if (userMaze.solution.size() == 0)
      std::cout << "No solution was generated.\n";
   int x = 0, y = 0;
   for (int i = 0; i < (int)userMaze.solution.size(); i++) {
      if (goodMaze.canTravel(x, y, userMaze.solution[i])) {
         if (userMaze.solution[i] == 0)
            x++;
         else if (userMaze.solution[i] == 1)
            y++;
         else if (userMaze.solution[i] == 2)
            x--;
         else if (userMaze.solution[i] == 3)
            y--;
      } else {
         std::cout << "Illegal solution -- there's a wall in the way.\n";
         return 0;
      }
   }
   std::cout << "Legal solution -- no walls were crossed.\n";
   return true;
}

bool testSolutionCorrectSquare()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 15;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   goodMaze.solveMaze();
   userMaze.solveMaze();

   int x = 0, y = 0;
   for (int i = 0; i < (int)userMaze.solution.size(); i++) {
      if (userMaze.solution[i] == 0)
         x++;
      else if (userMaze.solution[i] == 1)
         y++;
      else if (userMaze.solution[i] == 2)
         x--;
      else if (userMaze.solution[i] == 3)
         y--;
   }
   if (x == goodMaze.destination_x && y == height - 1)
      std::cout << "Reached the proper destination.\n";
   else
      std::cout << "Didn't reach the proper destination.\n";
   return true;
}

bool testSolveSmallMaze()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 2;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   goodMaze.solveMaze();
   userMaze.solveMaze();
 
   if (goodMaze.solution == userMaze.solution)
      std::cout << "Solution is correct.\n";
   else
      std::cout << "Solution is incorrect.\n";
   return true;
}

bool testSolveLargeMaze()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 700;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   goodMaze.solveMaze();
   userMaze.solveMaze();

   if (goodMaze.solution == userMaze.solution)
      std::cout << "Solution is correct.\n";
   else
      std::cout << "Solution is incorrect.\n";      
   return true;
}

bool testDrawSmallMaze()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 2;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   userMaze.solveMaze();
   goodMaze.solveMaze();
   BMP *userDrawing = userMaze.drawMaze();
   BMP *goodDrawing = goodMaze.drawMaze();
   int bmpWidth = goodDrawing->TellWidth();
   int bmpHeight = goodDrawing->TellHeight();
   
   if (userDrawing->TellWidth() != bmpWidth ||
      userDrawing->TellHeight() != bmpHeight) {
      std::cout << "Incorrect dimensions on output BMP.\n";
      return 0;
   }
   for (int i = 1; i < bmpWidth -1; i++) {
      for (int j = 1; j < bmpHeight - 1; j++) {
         RGBApixel userPixel = *((*userDrawing)(i, j));
         RGBApixel goodPixel = *((*goodDrawing)(i, j));
         if (userPixel.Red != goodPixel.Red ||
            userPixel.Green != goodPixel.Green ||
            userPixel.Blue != goodPixel.Blue) {
            std::cout << "Drawings don't match.\n";
            return 0;
         }
      }
   }
   std::cout << "Drawings match.\n";
   delete userDrawing;
   delete goodDrawing;
   return true;
}

bool testDrawMediumMaze()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 50;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   userMaze.solveMaze();
   goodMaze.solveMaze();
   BMP *userDrawing = userMaze.drawMaze();
   BMP *goodDrawing = goodMaze.drawMaze();
   int bmpWidth = goodDrawing->TellWidth();
   int bmpHeight = goodDrawing->TellHeight();
   
   if (userDrawing->TellWidth() != bmpWidth ||
      userDrawing->TellHeight() != bmpHeight) {
      std::cout << "Incorrect dimensions on output BMP.\n";
      return 0;
   }
   for (int i = 1; i < bmpWidth -1; i++) {
      for (int j = 1; j < bmpHeight - 1; j++) {
         RGBApixel userPixel = *((*userDrawing)(i, j));
         RGBApixel goodPixel = *((*goodDrawing)(i, j));
         if (userPixel.Red != goodPixel.Red ||
               userPixel.Green != goodPixel.Green ||
               userPixel.Blue != goodPixel.Blue) {
            std::cout << "Drawings don't match.\n";
            return 0;
         }
      }
   }
   
   std::cout << "Drawings match.\n";
   delete userDrawing;
   delete goodDrawing;
   return true;
}

bool testDrawLargeMaze()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 500;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   userMaze.solveMaze();
   goodMaze.solveMaze();
   BMP *userDrawing = userMaze.drawMaze();
   BMP *goodDrawing = goodMaze.drawMaze();
   int bmpWidth = goodDrawing->TellWidth();
   int bmpHeight = goodDrawing->TellHeight();
   
   if (userDrawing->TellWidth() != bmpWidth ||
         userDrawing->TellHeight() != bmpHeight) {
      std::cout << "Incorrect dimensions on output BMP.\n";
      return 0;
   }
   for (int i = 0; i < bmpWidth; i++) {
      for (int j = 0; j < bmpHeight; j++) {
         RGBApixel userPixel = *((*userDrawing)(i, j));
         RGBApixel goodPixel = *((*goodDrawing)(i, j));
         if (userPixel.Red != goodPixel.Red ||
            userPixel.Green != goodPixel.Green ||
            userPixel.Blue != goodPixel.Blue) {
            std::cout << "Drawings don't match.\n";
            return 0;
         }
      }
   }
   std::cout << "Drawings match.\n";
   delete userDrawing;
   delete goodDrawing;
   return true;
}

bool testDrawMazeWithSolution1()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 50;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   userMaze.solveMaze();
   goodMaze.solveMaze();
   BMP *userDrawing = userMaze.drawMazeWithSolution();
   BMP *goodDrawing = goodMaze.drawMazeWithSolution();
   int bmpWidth = goodDrawing->TellWidth();
   int bmpHeight = goodDrawing->TellHeight();
      
   if (userDrawing->TellWidth() != bmpWidth ||
         userDrawing->TellHeight() != bmpHeight) {
      std::cout << "Incorrect dimensions on output BMP.\n";
      return 0;
   }
   for (int i = 1; i < bmpWidth -1; i++) {
      for (int j = 1; j < bmpHeight - 1; j++) {
         RGBApixel userPixel = *((*userDrawing)(i, j));
         RGBApixel goodPixel = *((*goodDrawing)(i, j));
         if (userPixel.Red != goodPixel.Red ||
               userPixel.Green != goodPixel.Green ||
               userPixel.Blue != goodPixel.Blue) {
            std::cout << "Drawings don't match.\n";
            return 0;
         }
      }
   }
   std::cout << "Drawings match.\n";
   delete userDrawing;
   delete goodDrawing;
   return true;
}

bool testDrawMazeWithSolution2()
{
   SquareMaze userMaze;
   GoodMaze goodMaze;
   width = height = 500;
   goodMaze.makeMaze(width, height);
   makeMazeCopy(userMaze, goodMaze);
   userMaze.solveMaze();
   goodMaze.solveMaze();
   BMP *userDrawing = userMaze.drawMazeWithSolution();
   BMP *goodDrawing = goodMaze.drawMazeWithSolution();
   int bmpWidth = goodDrawing->TellWidth();
   int bmpHeight = goodDrawing->TellHeight();
   
   if (userDrawing->TellWidth() != bmpWidth ||
         userDrawing->TellHeight() != bmpHeight) {
      std::cout << "Incorrect dimensions on output BMP.\n";
      return 0;
   }
   for (int i = 0; i < bmpWidth; i++) {
      for (int j = 0; j < bmpHeight; j++) {
         RGBApixel userPixel = *((*userDrawing)(i, j));
         RGBApixel goodPixel = *((*goodDrawing)(i, j));
         if (userPixel.Red != goodPixel.Red ||
            userPixel.Green != goodPixel.Green ||
            userPixel.Blue != goodPixel.Blue) {
            std::cout << "Drawings don't match.\n";
            return 0;
         }
      }
   }
   std::cout << "Drawings match.\n";
   delete userDrawing;
   delete goodDrawing;
   return true;
}

void runTest(unsigned int testCaseNumber)
{
   std::vector< TestCase > testCases;
   testCases.push_back(TestCase("testMakeSmallMaze",testMakeSmallMaze));
   testCases.push_back(TestCase("testMakeMazeConnected",testMakeMazeConnected));
   testCases.push_back(TestCase("testMakeMazeCycleFree",testMakeMazeCycleFree));
   testCases.push_back(TestCase("testMakeMazeAll",testMakeMazeAll));
   testCases.push_back(TestCase("testSolveMazeValidPath",testSolveMazeValidPath));
   testCases.push_back(TestCase("testSolutionCorrectSquare",testSolutionCorrectSquare));
   testCases.push_back(TestCase("testSolveSmallMaze",testSolveSmallMaze));
   testCases.push_back(TestCase("testSolveLargeMaze",testSolveLargeMaze));
   testCases.push_back(TestCase("testDrawSmallMaze",testDrawSmallMaze));
   testCases.push_back(TestCase("testDrawMediumMaze",testDrawMediumMaze));
   testCases.push_back(TestCase("testDrawLargeMaze",testDrawLargeMaze));
   testCases.push_back(TestCase("testDrawMazeWithSolution1",testDrawMazeWithSolution1));
   testCases.push_back(TestCase("testDrawMazeWithSolution2",testDrawMazeWithSolution2));
   if (testCaseNumber > 0 && testCaseNumber <= testCases.size())
   {
      testCases[testCaseNumber-1].second();
   }
}

}

