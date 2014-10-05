/*
MP 7.2
Spring 2011 
CS 225

Create random mazes using dsets to keep track of avoiding cycles w/in maze!
*/

#ifndef MAZE_H
#define MAZE_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "dsets.h"
#include "EasyBMP.h"

using namespace std;
using std::vector;

class SquareMaze 
{
public: 

void makeMaze(int width, int height);
bool canTravel(int x, int y, int dir);
void setWall(int x, int y, int dir, bool exists);
void solveMaze();
BMP* drawMaze();
BMP* drawMazeWithSolution();

vector<int> solution;


private:
	int WIDTH;
	int HEIGHT;
	int xIndex;
	int solutionLength;

	//used for mapping all coordinates onto 2d maze & randomly break down walls
	class TwoDMapping
	{
	public:
	int x;
	int y;
	bool rightWall;
	bool bottomWall;	
	};
	
	//struct representing bottom & right wall of a cell
	//edges of maze are also initialized to make code more readable
	class Cell
	{
	public:
	bool Right;
	bool Bottom;
	
	bool rightEdge;
	bool bottomEdge;
	bool leftEdge;
	bool topEdge;
	};

	//1d random array that will map wall breaking onto maze
	vector<TwoDMapping> deck;
	//actual maze
	vector< vector<Cell> > MAZE;
	//keeps track of avoiding cycles
	DisjointSets Dset;
    
   //helper functions (explained in context in cpp)
	void breakRight(int X, int Y);
	void breakBottom(int X, int Y);
	void traversal(int x, int y , int length , int cameFrom, vector<int> path);
	void overwriteSolution( vector<int> & path, int length, int x);
	bool DeadEnd(int x, int y, int cameFrom);
};

#endif
