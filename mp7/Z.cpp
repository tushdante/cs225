
#include "maze.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
//using std::cout;
//using std::endl;

SquareMaze::SquareMaze(){
srand ( time(NULL) );
}

void SquareMaze::makeMaze(int width, int height){

wid = width;
hei = height;
vector<Block> xycombined;
Block Temp;
vector<int> Wmazeindex;
vector<int> Hmazeindex; 
DisjointSets mazeSet;
//srand ( time(NULL) );

for (int i=0; i<width; i++){
  for (int j=0; j<height; j++){
	maze.push_back(vector<point>(height , point()));
}}

/*cout << "The contents of maze are:";
  for (int i=0; i < wid; i++)
	for (int j=0; j < hei; j++)
{
    cout <<"top:"<< (maze[i][j]).bottom<<"bottom:" << (maze[i][j]).right <<" ";
}
  cout << endl;*/


for (int i=0; i<width; i++){
for (int j=0; j<height; j++){
Temp.Xcord = i;
Temp.Ycord = j;
xycombined.push_back(Temp);}}

/*for (int i=0; i<width; i++){
Wmazeindex.push_back(i);}
for (int j=0; j<height;  ++){
Hmazeindex.push_back(j);}*/

mazeSet.addelements(width*height);

/*random_shuffle ( Wmazeindex.begin(), Wmazeindex.end() );
random_shuffle ( Hmazeindex.begin(), Hmazeindex.end() );*/

random_shuffle (xycombined.begin(), xycombined.end());

/*for (int i=0; i<width; i++){
int ranW = rand() % (width - 1);
Wmazeindex[i] = Wmazeindex[ranW];
Wmazeindex[ranW] = i;}

for (int j=0; j<height; j++){
int ranH = rand() % (height - 1);
Hmazeindex[j] = Hmazeindex[ranH];
Hmazeindex[ranH] = j;}*/

/*for (int i=0; i<height; i++){
cout<<Wmazeindex[i]<<endl;}*/

int x;
int y;

for (int t=0; t < height*width; t++){
//for (int i=0; i < width; i++){
//random_shuffle ( Hmazeindex.begin(), Hmazeindex.end() );
//random_shuffle ( Wmazeindex.begin(), Wmazeindex.end() );
x = xycombined[t].Xcord;
y = xycombined[t].Ycord;

if (y != height - 1){
	if ((mazeSet.find((y + 1)*width + x) != mazeSet.find((y)*width + x)) || (mazeSet.find((y+1)*width + x) == -1 && mazeSet.find((y*width + x) == -1))) {
		maze[x][y].bottom = 0;
		mazeSet.setunion((y+1)*width + x, (y)*width + x);
}}

if (x != width - 1){
if ((mazeSet.find((y)*width + x) != mazeSet.find((y)*width + x + 1)) || (mazeSet.find((y)*width + x + 1) == -1 && mazeSet.find((y)*width + x) == -1)) {

maze[x][y].right = 0;
mazeSet.setunion((y)*width + x + 1, (y)*width + x);
}}
}
//}
}

void SquareMaze::findLongestPathHelper(int x, int y, int CPL){
//CPL++;
//cout << x << " " << y <<endl;
//cout <<canTravel(x,y,0)<<canTravel(x,y,1)<<canTravel(x,y,2)<<canTravel(x,y,3)<<endl;


if(CPL > PathLength && y == hei-1){
PathLength = CPL;
endX = x;
//LongestPathX = pathX;
//LongestPathY = pathY;
solution.resize(Tsolution.size());
for (int i=0; i < (int)solution.size(); i++){
solution[i] = Tsolution[i];}
}

if(CPL == PathLength && y == hei-1 && x < endX){
endX = x;
solution.resize(Tsolution.size());
for (int i=0; i < (int)solution.size(); i++){
solution[i] = Tsolution[i];}
}

if(canTravel(x,y,0)){
CPL++;
//pathX.push_back(x+1);
//pathY.push_back(y);
Tsolution.push_back(0);

setWall(x,y,0,1);
findLongestPathHelper(x+1,y,CPL);
setWall(x,y,0,0);}
if(canTravel(x,y,1)){
CPL++;
//pathX.push_back(x+1);
//pathY.push_back(y);
Tsolution.push_back(1);

setWall(x,y,1,1);
findLongestPathHelper(x,y+1,CPL);
setWall(x,y,1,0);}
if(canTravel(x,y,2)){
CPL++;
//pathX.push_back(x+1);
//pathY.push_back(y);
Tsolution.push_back(2);

setWall(x-1,y,0,1);
findLongestPathHelper(x-1,y,CPL);
setWall(x-1,y,0,0);}
if(canTravel(x,y,3)){
CPL++;
//pathX.push_back(x+1);
//pathY.push_back(y);
Tsolution.push_back(3);

setWall(x,y-1,1,1);
findLongestPathHelper(x,y-1,CPL);
setWall(x,y-1,1,0);}

//pathX.pop_back();
//pathY.pop_back();
Tsolution.pop_back();
}

SquareMaze::point::point(){
bottom = 1;
right = 1;
}



bool SquareMaze::canTravel(int x, int y, int dir){
if (dir == 3 && y == 0){return false;}
if (dir == 2 && x == 0){return false;}
if (dir == 1 && y == hei - 1){return false;}
if (dir == 0 && x == wid - 1){return false;}

if (dir == 0){
if((maze[x][y]).right == 1){return false;}
else return true;
}else if (dir == 1){
if((maze[x][y]).bottom == 1){return false;}
else return true;
}else if (dir == 2){
if((maze[x-1][y]).right == 1){return false;}
else return true;
}else{
if((maze[x][y-1]).bottom == 1){return false;}
else return true;
}
}
               
void SquareMaze::setWall(int x, int y, int dir, bool exists){
if (dir == 1){
if (exists == 1){
	maze[x][y].bottom = 1;
}else
	maze[x][y].bottom = 0;
}
if (dir == 0){
if (exists == 1){
        maze[x][y].right = 1;
}else
        maze[x][y].right = 0;
}
}
                
void SquareMaze::solveMaze(){
PathLength = 0;
findLongestPathHelper(0,0,0);
}

BMP* SquareMaze::drawMaze(){
BMP* img = new BMP;

img->SetSize(wid*10+1, hei*10+1);

for(int i=0; i < wid * 10 + 1; i++){
(*img)(i,0) -> Red = 0;
(*img)(i,0) -> Green = 0;
(*img)(i,0) -> Blue = 0;}

for(int i=0; i < hei * 10 + 1; i++){
(*img)(0,i) -> Red = 0;
(*img)(0,i) -> Green = 0;
(*img)(0,i) -> Blue = 0;}


for(int i = 1; i<10; i++){
(*img)(i,0) -> Red = 255;
(*img)(i,0) -> Green = 255;
(*img)(i,0) -> Blue = 255;}

for (int i=0; i < wid; i++){
  for (int j=0; j < hei; j++){
	if (maze[i][j].right == 1){
	for (int x=0; x < 11; x++){
	(*img)((i+1)*10, j*10+x) -> Red = 0;
	(*img)((i+1)*10, j*10+x) -> Green = 0;
	(*img)((i+1)*10, j*10+x) -> Blue = 0;}}

	if (maze[i][j].bottom == 1){
        for (int x=0; x < 11; x++){
        (*img)(i*10+x, (j+1)*10) -> Red = 0;
        (*img)(i*10+x, (j+1)*10) -> Green = 0;
        (*img)(i*10+x, (j+1)*10) -> Blue = 0;}}

}}

return img;
}

BMP* SquareMaze::drawMazeWithSolution(){
BMP* img = drawMaze();

int X = 5;
int Y = 5;
int size = solution.size();
int Xupdated = X;
int Yupdated = Y;

for (int i=0; i<size; i++){
X = Xupdated;
Y = Yupdated;

 if (solution[i] == 0){
	Xupdated = X + 10;
	
	for(int k = X; k <= Xupdated; k++){
	(*img)(k,Yupdated) -> Red = 255;
	(*img)(k,Yupdated) -> Green = 0;
	(*img)(k,Yupdated) -> Blue = 0;}}
 else if (solution[i] == 1){
        Yupdated = Y + 10;

        for(int k = Y; k <= Yupdated; k++){
        (*img)(Xupdated, k) -> Red = 255;
        (*img)(Xupdated, k) -> Green = 0;
        (*img)(Xupdated, k) -> Blue = 0;}}
 else if (solution[i] == 2){
        Xupdated = X - 10;

        for(int k = X; k >= Xupdated; k--){
        (*img)(k,Yupdated) -> Red = 255;
        (*img)(k,Yupdated) -> Green = 0;
        (*img)(k,Yupdated) -> Blue = 0;}}
 else if (solution[i] == 3){
        Yupdated = Y - 10;

        for(int k = Y; k >= Yupdated; k--){
        (*img)(Xupdated, k) -> Red = 255;
        (*img)(Xupdated, k) -> Green = 0;
        (*img)(Xupdated, k) -> Blue = 0;}}
}

for(int i = 1; i < 10; i++){
(*img)(endX*10 + i, hei * 10) -> Red = 255;
(*img)(endX*10 + i, hei * 10) -> Green = 255;
(*img)(endX*10 + i, hei * 10) -> Blue = 255;
}

return img;
}




