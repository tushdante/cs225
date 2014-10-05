/*
Disjoint Sets
MP 7.1
CS 225
Spring 2011

Overview

Each DisjointSets object will represent a family of disjoint sets, where each 
element has an integer index. It is implemented as up-trees stored in a single 
vector of ints. Path compression and union-by-size are used. 
Each place in the vector represents a node. 
A nonnegative number is the index of the parent of the current node; 
a negative number in a root node is the negative of the set size.
*/

#include "dsets.h"




/*
The addelements Function
Takes a single integer argument and returns nothing. This function creates n 
unconnected root nodes at the end of the vector.
*/
void DisjointSets::addelements (int n)
{
	for (int i=0 ; i<n ; i++)
		{
		VectorSet.push_back(-1);
		}
}

//for 7.2 clear dset if makeMaze is called twice
void DisjointSets::clear()
{
	VectorSet.resize(0);
}

/*
The Find Function
Takes a single integer argument and returns an integer. Returns the index of the
 root of the up-tree in which the parameter element resides. This function 
should compress paths and works as described in lecture.
*/
int DisjointSets::find(int i) 
{
	if (VectorSet[i] < 0) return i;
	else return VectorSet[i] = find(VectorSet[i]);
}




/*
Union by Size
Takes two integer arguments and returns nothing. T
When two disjoint sets are unioned, the smaller (in terms of number of nodes)
will point at the larger.
If the two sets are the same size, the tree containing the second argument 
points to the tree containing the first. 
*/
void DisjointSets::setunion (int one , int two)
{
	one=find(one);
	two=find(two);
	
	int sizeOne=VectorSet[one];
	int sizeTwo=VectorSet[two];
	int sizeTotal=sizeOne+sizeTwo;
	


	//Set two has greater size
	if(sizeOne>sizeTwo)
		{
		VectorSet[one]=two;
		VectorSet[two]=sizeTotal;
		}
	
	//Set one has greater size	
	else
		{
		VectorSet[two]=one;
		VectorSet[one]=sizeTotal;
		}

}
