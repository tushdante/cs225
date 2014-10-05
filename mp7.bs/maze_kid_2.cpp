/* maze.cpp
 * Implementation of SquareMaze class
 * Fall 2010 December 07
*/

#include "maze.h"
#include <cstdlib>

using std::cout;
using std::endl;

// SquareMaze::SquareMaze() 
SquareMaze::SquareMaze(){
	//seed random the first time it is being called
	srand( time(NULL) );
}

// SquareMaze::SquareNode::SquareNode() 
SquareMaze::SquareNode::SquareNode() {
	bottom = 1;
	right = 1;
}

// void SquareMaze::makeMaze(int width, int height) 
void SquareMaze::makeMaze(int width, int height) {
	
	int nJoint,j,i,index1,index2,random;
	
	//delete existing data
	maze.clear();
	tree.clear();
	solution.clear();
	currentBest.clear();
	bestX = width;
	maxLength = -1;

	//set width and height
	w = width;
	h = height;

	//make an 2-d vector of square Node
	vector<SquareNode> a;
	for (int x = 0; x < w; x++){
		for (int y = 0; y < h; y++){
			a.push_back(SquareNode());
		}
		maze.push_back(a);
	}
	//add width*height elements to the DisjointSets
	tree.addelements(width*height);
	nJoint = 0;
	//select random walls to delete without creating a cycle until all the nodes are connected
	while(nJoint != w*h-1) {
		i = rand()%w;
		j = rand()%h;
		random = rand()%3;
		//try to remove right wall
		if (random == 0  && i != w-1) {
			index1 = Dindex(i,j);
			index2 = Dindex(i+1,j);
			if (tree.find(index1) != tree.find(index2)) {
				setWall(i,j,0,false);
				tree.setunion(index1,index2);
				nJoint++;
			}
		}
		//try to remove bottom wall
		else if (random == 1 && j != h-1) {
			index1 = Dindex(i,j);
			index2 = Dindex(i,j+1);
			if (tree.find(index1) != tree.find(index2)) {
				setWall(i,j,1,false);
				tree.setunion(index1,index2);
				nJoint++;	
			}
		}			
	}
}

//	int SquareMaze::Dindex(int x, int y)
int SquareMaze::Dindex(int x, int y) {
	return x+w*y;
}

// bool SquareMaze::canTravel(int x, int y, int dir)
bool SquareMaze::canTravel(int x, int y, int dir) {
	//prevent out of bound
	if( (dir==3 && y==0) || (dir==1 && y== h-1)||(dir==0 && x==w-1) || (dir==2 && x==0) ){
		return false;
	}

	//check if it is possible to travel
	if( (dir == 0 && maze[x][y].right == 0)||(dir == 2 && maze[x-1][y].right == 0) ||
		(dir == 1 && maze[x][y].bottom == 0)||(dir == 3 && maze[x][y-1].bottom == 0) ){
		return true;
	}
	else
		return false;
}

// void SquareMaze::setWall(int x, int y, int dir, bool exists) 
void SquareMaze::setWall(int x, int y, int dir, bool exists) {
	//left wall
	if (dir == 1){
		if (exists)
			maze[x][y].bottom = 1;
		else 
			maze[x][y].bottom = 0;
	}
	//right wall
	else if(dir == 0){
		if (exists)
			maze[x][y].right = 1;
		else
			maze[x][y].right = 0;
	}

}

// void SquareMaze::solveMaze() 
void SquareMaze::solveMaze() {
	solve(0,0);
}

// void SquareMaze::solve(int x, int y) 
void SquareMaze::solve(int x, int y) {
	if (y == h-1) {
		int distance = currentBest.size();
		if (distance > maxLength) {
			bestX = x;
			maxLength = distance;
			solution = currentBest;
		}

		if (distance == maxLength) {
			if (x < bestX) {
				bestX = x;
				solution = currentBest;
			}
		}
	}

	//right
	if(canTravel(x,y,0)==true){
		currentBest.push_back(0);
		setWall(x,y,0,true);
		solve(x+1,y);
		setWall(x,y,0,false);
		currentBest.pop_back();
	}
	//down
	if(canTravel(x,y,1)==true){
		currentBest.push_back(1);
		setWall(x,y,1,true);
		solve(x,y+1);
		setWall(x,y,1,false);
		currentBest.pop_back();
	}
	//left
	if(canTravel(x,y,2)==true){
		currentBest.push_back(2);
		setWall(x-1,y,0,true);
		solve(x-1,y);
		setWall(x-1,y,0,false);
		currentBest.pop_back();
	}
	//up
	if(canTravel(x,y,3)==true){
		currentBest.push_back(3);
		setWall(x,y-1,1,true);
		solve(x,y-1);
		setWall(x,y-1,1,false);
		currentBest.pop_back();
	}
	return;
}

// BMP* SquareMaze::drawMaze()
BMP* SquareMaze::drawMaze() {
	BMP* image = new BMP();
	//set the size of the image
	image -> SetSize(w*10+1, h*10+1);
	//blacken the entire topmost row
	for(int i = 0; i < w*10+1; i++){
		(*image)(i,0) -> Red = 0;
		(*image)(i,0) -> Green = 0;
		(*image)(i,0) -> Blue = 0;
	}
	//blacken the entire leftmost column
	for(int i = 0; i < h*10+1; i++){
		(*image)(0,i) -> Red = 0;
		(*image)(0,i) -> Green = 0;
		(*image)(0,i) -> Blue = 0;
	}

	//whiten entrance(1,0) to (9,0)
	for(int i = 1; i < 10; i++) {
		(*image)(i,0) -> Red = 255;
		(*image)(i,0) -> Green = 255;
		(*image)(i,0) -> Blue = 255;
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			//if right wall exist, blacken them
			if (maze[i][j].right == 1) {
				for (int k = 0; k <= 10; k++) {
					(*image)((i+1)*10,j*10+k) -> Red = 0;
					(*image)((i+1)*10,j*10+k) -> Green = 0;
					(*image)((i+1)*10,j*10+k) -> Blue = 0;
				}
			}
			//if bottom wall exist, blacken them
			if (maze[i][j].bottom == 1) {
				for (int k = 0; k <= 10; k++) {
					(*image)(i*10+k, (j+1)*10) -> Red = 0;
					(*image)(i*10+k, (j+1)*10) -> Green = 0;
					(*image)(i*10+k, (j+1)*10) -> Blue = 0;
				}
			}
		}
	}
	return image;
}

// BMP* SquareMaze::drawMazeWithSolution() 
BMP* SquareMaze::drawMazeWithSolution() {
	BMP* image = drawMaze();
	
	//initial location
	int currentX = 5;
	int currentY = 5;
	int newX = currentX;
	int newY = currentY;
	int size = solution.size();

	//go through solution vector from beginning till the end
	//draw them to the image based on direction
	for (int i = 0; i < size; i++) {
		int dir = solution[i];
		if (dir == 0) {
			newX = currentX + 10;
			newY = newY;

			for(int t = currentX; t <= newX; t++) {
				(*image)(t,newY) -> Red = 255;
				(*image)(t,newY) -> Green = 0;
				(*image)(t,newY) -> Blue = 0;
			}

		}
		else if (dir == 1){
			newX = currentX;
			newY = currentY + 10;

			for(int t = currentY; t <= newY; t++) {
				(*image)(newX,t) -> Red = 255;
				(*image)(newX,t) -> Green = 0;
				(*image)(newX,t) -> Blue = 0;
			}

		}
		else if (dir == 2){
			newX = currentX - 10;
			newY = currentY;

			for(int t = currentX; t >= newX; t--) {
				(*image)(t,newY) -> Red = 255;
				(*image)(t,newY) -> Green = 0;
				(*image)(t,newY) -> Blue = 0;
			}

		}
		else if (dir == 3){
			newX = currentX;
			newY = currentY - 10;

			for(int t = currentY; t >= newY; t--) {
				(*image)(newX,t) -> Red = 255;
				(*image)(newX,t) -> Green = 0;
				(*image)(newX,t) -> Blue = 0;
			}

		}
		//update the coordinate
		currentX = newX;
		currentY = newY;
	}

	//exit
	for(int i = 1; i < 10; i++) {
		(*image)(bestX*10+i,h*10) -> Red = 255;
		(*image)(bestX*10+i,h*10) -> Green = 255;
		(*image)(bestX*10+i,h*10) -> Blue = 255;
	}

	return image;
}

