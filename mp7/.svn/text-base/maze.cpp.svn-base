/*
MP 7.2
Spring 2011 
CS 225

Create random mazes using dsets to keep track of avoiding cycles w/in maze!
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "maze.h"

/*
This function will make a new square maze of the given height and width. 
If this object already represents a maze it will clear all the existing data 
before doing so. Start with a square grid with the 
specified height and width. Select random walls to delete without 
creating a cycle, until there are no more walls that could be deleted without 
creating a cycle. Do not delete walls on the perimeter of the grid. 
The finished maze is always a tree of corridors.
*/
void SquareMaze::makeMaze(int width, int height)
{
	if(width*height==0) return;
	WIDTH=width;
	HEIGHT=height;
	
	//disjoint set which will represent all cells in maze by complpetion of 
	//makeMaze function call.
	Dset.clear();
	Dset.addelements(width*height);

//1D array Setup
//============================================================================//    

	//1d array that maps onto 2d maze. Each element is a struct containing (x,y)
	//coordinate on maze & which of two walls per cell it attempts to break.
	//(this requires the size of the array to be twice that of the maze)
	int dubSize = 2*width*height;
	deck.resize(0); //clear array 
	deck.resize(dubSize);
	int w=0;
	int h=0;
	int total=0; 
	
	//initialize (x,y) coordinates and calls for rightWall breaking
//	while (total < width*height)
		for(h=0; h < height ; h++)
		  for( w=0 ; w < width ; w++)
		  	{
  //       if(total==(width*height) ) break;
        	deck[total].x=w;
        	deck[total].y=h;
        	deck[total].rightWall=true;
        	deck[total].bottomWall=false;
        	total++;
			}
	h=0; 
	w=0;
	
	//initialize (x,y) coordinates and calls for bottomWall breaking
		for( h=0 ; h < height ; h++)
		  for(w=0 ; w < width ; w++)
		  	{
        	deck[total].x=w;
        	deck[total].y=h;
        	deck[total].rightWall=false;
        	deck[total].bottomWall=true;
        	total++;
			}
	

	//shuffle 1d mapping array for random maze creation
	srand(time(NULL) );
	random_shuffle( deck.begin(), deck.end());

//End of 1d mapping array setup
//===========================//			




//Clear & Setup 2d maze 
//============================================================================//


	//Clear & Resize 2d maze array
	MAZE.resize(0);
	MAZE.resize(height);
  
	for (int i = 0; i < height; ++i)
		{
		MAZE[i].resize(0);	
		MAZE[i].resize(width);
		}

	//Erect walls & mark edges of maze
	for(int j=0 ; j < height; j++)
		for (int i=0 ; i < width ; i ++)
			{
			//Erect walls
			(MAZE[i][j]).Right=true;
			(MAZE[i][j]).Bottom=true;			
			//Generically mark cells to not contain boundary/edge of maze
			(MAZE[i][j]).rightEdge=false;
			(MAZE[i][j]).bottomEdge=false;	
			(MAZE[i][j]).leftEdge=false;	
			(MAZE[i][j]).topEdge=false;
			//for the fewer cases of boundary/edge cells, overwrite & mark
			if (i == 0 ) (MAZE[i][j]).leftEdge=true;	
			if (j == 0 ) (MAZE[i][j]).topEdge=true;	
			if (i == (width-1) ) (MAZE[i][j]).rightEdge=true;	
			if (j == (height-1) ) (MAZE[i][j]).bottomEdge=true;	
			}
			
//End of 2d Maze setup
//==================//			


//Follow 1d array mapping onto maze & randomly break down walls w/o creating
//cycles (using disjoint set to track potential cycles)
//============================================================================//

	for(int i=0 ; i < dubSize ; i++)
		{
		int X=deck[i].x;
		int Y=deck[i].y;
		if(deck[i].rightWall) breakRight(X, Y);
		if(deck[i].bottomWall)breakBottom(X, Y);
		}

//End of breaking down walls: Maze is setup.
//==================//			
}






//helper function for mazeCreation. Knocks down right wall if possible.
void SquareMaze::breakRight(int X, int Y)
{
	//don't break down outer maze edges;
	if((MAZE[X][Y]).rightEdge) return;

	int cell = Y*WIDTH + X;
	int adjacent = cell + 1;
	
	//if 'cell' of interest and the 'adjacent' that is divided by the wall
	//to be knocked down are in the same disjoint set, then knocking down the 
	//wall would create a cycle--so nothing is done
	if(Dset.find(cell) == Dset.find(adjacent) ) return;
	
	
	//otherwise if the two cells aren't in the same set, knock down wall
	else //Dset.find(cell) != Dset.find(adjacent)
		{
		(MAZE[X][Y]).Right=false;
		Dset.setunion (cell, adjacent);
		}
	
}

//helper function for mazeCreation. Knocks down bottom wall if possible.
void SquareMaze::breakBottom(int X,int Y)
{
	//don't break down outer maze edges;
	if((MAZE[X][Y]).bottomEdge) return;


	//2d to 1d index mapping
	int cell = Y*WIDTH + X;
	int adjacent = ((Y+1)*WIDTH) + X;

	//if 'cell' of interest and the 'adjacent' that is divided by the wall
	//to be knocked down are in the same disjoint set, then knocking down the 
	//wall would create a cycle--so nothing is done
	if(Dset.find(cell) == Dset.find(adjacent) ) return;
	
	
	//otherwise knock down wall
	else //Dset.find(cell) != Dset.find(adjacent)
		{
		(MAZE[X][Y]).Bottom=false;
		Dset.setunion (cell, adjacent);
		}

}




/*
This uses my representation of the maze to determine whether it is possible to
travel in the given direction from the square at coordinates (x,y).

For example, after makeMaze(2,2), the possible input coordinates will be:
	(0,0), (0,1), (1,0), and (1,1).

    * dir = 0 represents a rightward step (+1 to the x coordinate)
    * dir = 1 represents a downward step (+1 to the y coordinate)
    * dir = 2 represents a leftward step (-1 to the x coordinate)
    * dir = 3 represents an upward step (-1 to the y coordinate)

Function does not step off the maze, or through a wall.

This function will be very helpful in solving the maze. It will also be used by 
the grading program to verify that your maze is a tree that occupies the whole 
grid, and to verify your maze solution. So make sure that this function works!
*/

bool SquareMaze::canTravel(int x, int y, int dir)
{
	bool gatekeeper=false;

	//extract what wall are set for cell
	bool right = MAZE[x][y].Right || MAZE[x][y].rightEdge;
	bool down  =MAZE[x][y].Bottom || MAZE[x][y].bottomEdge;
	bool left;
	bool up;
			
	if((x-1)<0 ) left=true;	
	else left= MAZE[x-1][y].Right || MAZE[x][y].leftEdge;
	
	if((y-1)<0 ) up=true;
	else up= MAZE[x][y-1].Bottom || MAZE[x][y].topEdge;	



	switch (dir) 
	{
	case 0:
		if ( !right )
   		gatekeeper=true;
   	
   	return gatekeeper;
   	
	case 1:
		if ( !down )
   		gatekeeper=true;
   	
   	return gatekeeper;		

	case 2:
		if ( !left )
   		gatekeeper=true;
   	
   	return gatekeeper;	
	
	case 3:
		if ( !(up) )
   		gatekeeper=true;
   	
   	return gatekeeper;		
		
	default:
    cout << "invalid 'dir' value" << endl;
    return gatekeeper;
  }

}



/*
The setWall Function

This function should set whether or not the specified wall exists. x and y 
specify a square, and dir is either 0 or 1, which specifies which wall of that 
square to set according to the encoding explained in canTravel. You only need to
support setting the bottom and right walls of every square in the grid. This 
function should be fast (constant time). You can assume that in grading we will
not make your maze a non-tree and then call one of the other member functions.
*/
void SquareMaze::setWall(int x, int y, int dir, bool exists)
{

	switch (dir)
	{
	case 0:
		if(x != (WIDTH-1) )//Check that perimeter doesn't get knocked down
		MAZE[x][y].Right=exists;
		
		break;
		
	case 1:
		if(y != (HEIGHT-1) )//Check that perimeter doesn't get knocked down	
		MAZE[x][y].Bottom=exists;
		
		break;
	
	default:
    cout << "invalid 'dir' value" << endl;
    break;
	}
	
}





/*
For each square on the bottom row (maximum y coordinate), there is a distance 
from the origin (i.e. the top-left cell), which is defined as the length 
(measured as a number of steps) of the only path through the maze from the 
origin to that square. The square in the bottom row with the largest 
distance from the origin is the destination of the maze. The winning path 
from the origin to the destination as a vector of integers (public member: 
vector<int> solution), where each integer 
represents the direction of a step, using the same encoding as in canTravel()
(shown below). 

If multiple paths of maximum length exist, the one with the destination cell
 that has the smallest x value will be the soution.

 
    * dir = 0 represents a rightward step (+1 to the x coordinate)
    * dir = 1 represents a downward step (+1 to the y coordinate)
    * dir = 2 represents a leftward step (-1 to the x coordinate)
    * dir = 3 represents an upward step (-1 to the y coordinate)
*/

void SquareMaze::solveMaze()
{
	vector<int> path;
	traversal(0, 0, 0 , 1 , path);
}



//helper function for solveMaze. Traverses maze and overwrites path & it's 
//length to member variables once successful base case is reached
void SquareMaze::traversal(int x, int y , int length , int cameFrom, 
																				vector<int> path)
{

	//base case: hit bottom
	if (y == (HEIGHT-1) )  
	    	{
			overwriteSolution( path, length, x);
         }              
              
	//base case: hit a dead end
	if( DeadEnd(x, y, cameFrom)  )
		{
		if (y == (HEIGHT-1)) overwriteSolution( path, length, x);
    	return;
    	}
    	
    
//traversal

	//traverse right
	if (canTravel(x, y , 0) && cameFrom !=2)
		{
		path.push_back(0);
		traversal(x+1, y, (length+1), 0, path );
		path.pop_back();
		}

	//traverse down
	if (canTravel(x, y , 1) && cameFrom !=3)
		{
		path.push_back(1);
		traversal(x, y+1, (length+1), 1, path );
		path.pop_back();
		}
	
	//traverse left
	if (canTravel(x, y , 2) && cameFrom !=0)
		{
		path.push_back(2);
		traversal(x-1, y, (length+1), 2, path);
		path.pop_back();
		}
		
	//traverse up	
	if (canTravel(x, y , 3) && cameFrom !=1)
		{
		path.push_back(3);
		traversal(x, y-1, (length+1), 3 , path );
		path.pop_back();
		}
}



/*
overwriteSolution

Helper function for solveMaze (for traversal)
overwrite solution path if:
 1) path is equal to that of soultion & ending cell is left of
current solution's cell
 2) a longer path to the bottom of the maze is found
*/
void SquareMaze::overwriteSolution( vector<int> & path, int length, int x)
{	  
  	if ( ( (path.size() == solution.size()) && x<xIndex) 		|| 
	    													( path.size() > solution.size() ) )
		{
		solution=path;
		solutionLength=length;
		xIndex=x;
      } 
}


/*
DeadEnd

Helper function for solveMaze (for traversal). 
Determines if traversal has led to a dead end constituting of 3 walls 
and the path that you came from to get there.
*/
bool SquareMaze::DeadEnd(int x, int y, int cameFrom)
{


	bool DeadEnd=false;

	//extract what wall are set for cell
	bool right = MAZE[x][y].Right || MAZE[x][y].rightEdge;
	bool down  =MAZE[x][y].Bottom || MAZE[x][y].bottomEdge;
	bool left;
	bool up;
			
	if((x-1)<0 ) left=true;	
	else left=MAZE[x-1][y].Right || MAZE[x][y].leftEdge;
	
	if ((y-1)<0 ) up=true;	
	else up=MAZE[x][y-1].Bottom ||  MAZE[x][y].topEdge;

	switch (cameFrom) 
	{
	//came from right traversal: check top, right, & bottom of current cell
	case 0:
		if ( up && right && down )
   		DeadEnd=true;
   	
   	return DeadEnd;

   //came from downward traversal: check left, bottom, & right of current cell
	case 1:
		if ( down && left && right )
   		DeadEnd=true;
   	
   	return DeadEnd;		

	//came from left traversal: check top, left, & bottom wall of current cell
	case 2:
		if ( up && left && down )
   		DeadEnd=true;
   	
   	return DeadEnd;	

	//came from upward traversal: check top , left, & right wall of current cell
	case 3:
		if ( up && left && right )
   		DeadEnd=true;
   	
   	return DeadEnd;		
		
	default:
    return true;
  }

}


/*
This function will draw the maze, without a solution. First, create a new BMP. 
Set the dimensions of the BMP to (width*10+1,height*10+1). where height and 
width were the arguments to makeMaze. Blacken the entire topmost row and 
leftmost column of pixels, except the entrance (1,0) through (9,0). For each 
square in the maze, call its maze coordinates (x,y). If the right wall exists, 
then blacken the pixels with coordinates ((x+1)*10,y*10+k) for k from 0 to 10. 
If the bottom wall exists, then blacken the pixels with coordinates (x*10+k, 
(y+1)*10) for k from 0 to 10. Then the resulting BMP will look like the sample 
image, except there will be no exit from the maze and the red line will be 
missing.
*/
BMP* SquareMaze::drawMaze()
{
	BMP* maze = new BMP();
	int black = 0;
	
	//i & j counters map out on 2D Maze Array
	//x & y counters map out on BMP pixel range
	//k is offset between the two mappings
	int i=0, j=0;
	int x=0, y=0;
	int k=0;
	
	maze->SetSize( (WIDTH*10)+1 , (HEIGHT*10)+1 );
	
	
	
	//loop through 2d Maze & project cells into BMP by factor of 10
	for(j=0; j < HEIGHT; j++)
		for (i=0 ; i < WIDTH ; i ++)
			{
						
			//If the right wall exists, blacken the pixels with coordinates 
			// ( (x+1)*10,  y*10+k ) for k from 0 to 10. 
			if( (MAZE[i][j]).Right==true ||  (MAZE[i][j]).rightEdge)
				{
				for (k=0 ; k <=10 ; k++)
					{
					x=((i+1)*10);
					y=(j*10)+k;

					((*maze)(x,y)->Red)=black;
					((*maze)(x,y)->Green)=black;
					((*maze)(x,y)->Blue)=black;								
					}
				}
				
			//If the bottom wall exists, blacken the pixels with coordinates 
			//(x*10+k, (y+1)*10) for k from 0 to 10. 	
			//color bottom walls
			if( (MAZE[i][j]).Bottom==true || (MAZE[i][j]).bottomEdge)
				{
				for (k=0 ; k <=10 ; k++)
					{
					x=(i*10)+k;
					y=((j+1)*10);

					((*maze)(x,y)->Red)=black;
					((*maze)(x,y)->Green)=black;
					((*maze)(x,y)->Blue)=black;								
					}
				}
				
							
			//Blacken the entire topmost row and except the entrance (1,0) - (9,0). 
			if( (MAZE[i][j]).topEdge==true )
				{
				for (k=0 ; k <=10 ; k++)
					{
					x=(i*10)+k;
					
					if(x>9 || x==0) //don't block enterance!
						{
						((*maze)(x,0)->Red)=black;
						((*maze)(x,0)->Green)=black;
						((*maze)(x,0)->Blue)=black;								
						}
					}
			
				}
				


			//color left edges
			if( (MAZE[i][j]).leftEdge==true || i ==0)
				{
				for (k=0 ; k <=10 ; k++)
					{
					y=(j*10)+k;

					((*maze)(0,y)->Red)=black;
					((*maze)(0,y)->Green)=black;
					((*maze)(0,y)->Blue)=black;								
					}
				}

			}

	return maze;	
}


/*
This function will modify the resulting bitmap from drawMaze to show the 
solution and the exit. Starting at pixel (5,5) each direction in the solution 
vector corresponds to a trail of 11 red pixels in the given direction. 

If the first step is downward, pixels (5,5) through (5,15) are colored red. 
Then if the second step is right, pixels (5,15) through (15,15) are colored red. 
Then if the third step is up, pixels (15,15) through (15,5) are colored red. 
etc.

The exit is also undone.

*/
BMP* SquareMaze::drawMazeWithSolution()
{


	
	int x=5, y=5;
	int nextX=x , nextY=y;
	int k=0;
	int size =(int) solution.size();
	
	BMP* maze= drawMaze();
	

	for (int i = 0 ; i < size ; i++)
		{
		
		//move right
		if(solution[i]==0)
			{
			nextX=x+10;
			//for red line by exit
			if(i==size-1) nextX++;
			
			
			for( ; x<nextX ; x++)
				{
				((*maze)(x,y)->Red)=255;
				((*maze)(x,y)->Green)=0;
				((*maze)(x,y)->Blue)=0;
				}
			}
			
			
			
		
		//move down	
		else if(solution[i]==1)
			{
			nextY=y+10;

			//for red line by exit			
			if(i==size-1) nextY++;
						
			for( ; y<nextY ; y++)
				{

				((*maze)(x,y)->Red)=255;
				((*maze)(x,y)->Green)=0;
				((*maze)(x,y)->Blue)=0;
				}
			}
		
		//move left	
		else if(solution[i]==2)
			{
			nextX=x-10;

			//for red line by exit			
			if(i==size-1) nextX--;
			
			
			for( ; x>nextX ; x--)
				{
				((*maze)(x,y)->Red)=255;
				((*maze)(x,y)->Green)=0;
				((*maze)(x,y)->Blue)=0;
				}			
			
			}
		
		//move up
		else if(solution[i]==3)						
			{
			nextY = y-10;

			
			for(; y>nextY ; y--)
				{
				((*maze)(x,y)->Red)=255;
				((*maze)(x,y)->Green)=0;
				((*maze)(x,y)->Blue)=0;
				}			
			}
		
		}

	

	//create exit  whiten the pixels with coordinates 
	//(x*10+k, (y+1)*10) for k from 1 to 9.
	for (k=1 ; k <=9 ; k++)
		{
		x= (xIndex*10)+k;
		y= (HEIGHT)*10;
		((*maze)(x,y)->Red)=255;
		((*maze)(x,y)->Green)=255;
		((*maze)(x,y)->Blue)=255;
		}
	

		
	return maze;


}
