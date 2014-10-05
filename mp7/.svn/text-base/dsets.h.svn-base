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

#ifndef __DSETS_H__
#define __DSETS_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DisjointSets
{

private:
vector<int> VectorSet;


public:
void addelements (int n);
int find(int i);
void setunion (int A , int B);
void clear();

};



#endif
