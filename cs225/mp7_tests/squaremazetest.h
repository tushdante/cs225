
/* Test cases

Mazes (70 points):
------

makeMaze() - 20 points
#7 (5) -- small maze (2x2)
#8 (5) -- is the maze connected?  (15x15)
#9 (5) -- is the maze cycle-free?  (15x15)
#10 (5) -- the whole shebang (1000x1000)

solveMaze() - 21 points

#11 (5) -- is the solution a valid path (i.e., crosses no walls)?    
#12 (5) -- does the solution reach the correct square?
#13 (5) -- small maze (2x2)
#14 (6) -- large maze (700x700)

drawMaze() - 17 points

#15 (5) -- small maze (2x2), no exit
#16 (5) -- medium maze (50x50), no exit
#17 (7) -- large maze (700x700)

drawMazeWithSolution() - 12 points

#18 (5) -- #16, with solution
#19 (7) -- #17, with solution

NOTE: canTravel() and setwall() are not individually tested,
since they are used extensively in the other test cases.

To be checked manually:
 - some sort of randomness in maze creation (-20 points)
Note: this will be incurred as a deduction if necessary.  You are
not awarded 20 points just for trying to use randomness somehow.  
Rather, you will be penalized 20 points if you failed to use some
sort of randomness.  (Essentially, we will revoke credit for
makeMaze().)
*/

#include "maze.h"
#include "goodmaze.h"

namespace SquareMazeTest {

typedef std::pair<std::string, bool (*)()> TestCase;

bool mazeStatusCheck(int check);
void recDFS(int x, int y);
void makeMazeCopy(SquareMaze &dest, GoodMaze &source);

bool testMakeSmallMaze();
bool testMakeMazeConnected();
bool testMakeMazeCycleFree();
bool testMakeMazeAll();

bool testSolveMazeValidPath();
bool testSolutionCorrectSquare();
bool testSolveSmallMaze();
bool testSolveLargeMaze();

bool testDrawSmallMaze();
bool testDrawMediumMaze();
bool testDrawLargeMaze();

bool testDrawMazeWithSolution1();
bool testDrawMazeWithSolution2();

void runTest(unsigned int testCaseNumber);

}

