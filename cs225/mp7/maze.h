/************************************************
 * maze.h
 * List all the functions of a SquareMaze class
 * Written by Anonymous for CS225 MP 7
 * Fall 2010 December 07
************************************************/

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "dsets.h"
#include "EasyBMP.h"

using std::vector;

/**********************************************
*  Class:  SquareMaze 
*  A SquareMaze which used 2-D vector and 
*	DisjointSets to works
*********************************************/
class SquareMaze {
	public:

		// SquareMaze::SquareMaze() 
		// 	This is a constructor of SquareMaze
		//		where it basically seed the random to generate random maze		
		SquareMaze();

		// void SquareMaze::makeMaze(int width, int height) 
		// 	This is a public function that will create the maze base
		//		on the parameter pass in
		//
		//		@param width, the width of the maze
		//		@param height, the height of the maze
		void makeMaze(int width, int height);

		// bool SquareMaze::canTravel(int x, int y, int dir)
		// 	This is a public function will check 
		//		whether it is possible to travel for coordinate x and y one step in given direction
		//
		//		@param x, is the x coordinate
		//		@param y, is the y coordinate
		//		@param dir, is the direction (0 = right, 1 = down, 2 = left and 3 = up)
		//		@return bool, whether it is possible to travel for coordinate x and y one step in given direction
		bool canTravel(int x, int y, int dir);

		// void SquareMaze::setWall(int x, int y, int dir, bool exists) 
		// 	This is a public function will set the wall of a square node to exist or not
		//
		//		@param x, is the x coordinate
		//		@param y, is the y coordinate
		//		@param dir, represent which wall (0 = right wall, 1 = bottom wall)
		//		@param exist, determine whether the wall exist or not (true = exist, false = doesn't exist)
		void setWall(int x, int y, int dir, bool exists);

		// void SquareMaze::solveMaze() 
		// 	This is a public function will solve the maze by calling solve private function
		void solveMaze();

		// BMP* SquareMaze::drawMaze()
		// 	This is a public function that will draw the maze
		//
		//		@return BMP*, the pointer to the maze image that just been drawn
		BMP* drawMaze();

		// BMP* SquareMaze::drawMazeWithSolution() 
		// 	This is a public function to draw the solved maze image. 
		//
		//		@param BMP*, the pointer to the solved maze image that just been drawn
		BMP* drawMazeWithSolution();

		//public solution vector for the maze
		vector<int> solution;
	
	private:
		/**********************************************
		*  Class:  SquareNode 
		*  This class is what will be used by SquareMaze
		*	which represent one block of square
		*	that can control whether 
		*	bottom and right wall exist
		*********************************************/
		class SquareNode {
			public:
				// SquareMaze::SquareNode::SquareNode() 
				// 	This is a constructor of SquareNode
				//		that will set both bottom and right wall to true (exist)
				SquareNode();

				//represent bottom wall
				int bottom;

				//represent right wall
				int right;
		};

		//	int SquareMaze::Dindex(int x, int y)
		//		This private function will change from 2 coordinate system index
		//		to one coordinate system that can be used for the Dsets vector index
		//
		//		@param x, is the x coordinate
		//		@param y, is the y coordinate
		int Dindex(int x, int y);

		// void SquareMaze::solve(int x, int y) 
		// 	This is a private recursive function to solve the maze
		//		From the starting point, it will move to all possible direction one step at each time
		//		until it go to all squareNode in the maze
		//		if it is on the lowest row, it will check whether it is greatest distance
		//		if yes, then that is the solution. Same distance will result in lower x to be chosen
		//
		//		@param x, is the starting x coordinate
		//		@param y, is the starting y coordinate
		void solve(int x, int y);

		//2-D vector of SquareNode which represent the maze
		vector< vector<SquareNode> > maze;

		//DisjointSets of all the nodes in the maze
		DisjointSets tree;

		//keep track the best vector solution, used for comparison
		vector<int> currentBest;

		//the width of the maze
		int w;

		//the height of the maze
		int h;

		//the best X coordinate solution to the maze
		int bestX;

		//current best length/distance of solution vector
		int maxLength;
};
#endif

