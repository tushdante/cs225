/*
    Lab 12: Graph Implementation
    Written by Sean Massung for CS 225 Spring 2011
    
    - The graphs make heavy use of Lab 10's hash tables (from Spring 2011)
*/

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "libhashtable/schashtable.h"
#include "libhashtable/string_hash.h"

using std::cerr;
using std::cout;
using std::endl;
using std::pair;
using std::set;
using std::string;
using std::vector;

// used as a hash function for the two hash tables
static StringHash hasher;

// scoped here so other files can access it
struct EdgeData {
    string v1;
    string v2;
    string label;
    int weight;
    bool operator<(const EdgeData & other) const {
        return weight < other.weight;
    }
};

class Graph {

public:

    // constructors, copy constructor, destructor, operator=

    Graph(bool isWeighted) : data(256, hasher), weighted(isWeighted) {/* nothing */};
    Graph(bool isWeighted, int numVertices, unsigned long seed);
    
    // return a vector of all adjacent vertices to the parameter vertex
    vector<string> getAdjacent(string label) const;
    
    // return a vector of all vertices in the graph
    vector<string> getVertices() const;
    
    // return a vector of all edges in the graph
    vector<EdgeData> getEdges() const;
    
    // traversal functions

	bool   setVertexMark(string label, string mark);
    string getVertexMark(string label) const;

    bool   setEdgeMark(string a, string b, string mark);
    string getEdgeMark(string a, string b) const;

    int getEdgeWeight(string a, string b) const;
    
    // building functions
    
    bool insertVertex(string label);
    bool removeVertex(string label);
    
    bool insertEdge(string a, string b);
    bool removeEdge(string a, string b);
    
    bool setEdgeWeight(string a, string b, int weight);

    // printing functions

    void initSnapshot(string title);
    void snapshot();

    void print() const;                 // to stdout
    void printPNG(string title) const;  // to title.png
    
    string toString(int num) const;

private:

    // it's not necessary to understand the private section of this class
    
    struct EdgeList {
        SCHashTable<string, pair<string, int> > edges;
        string mark;
        EdgeList() : edges(8, hasher) {/* nothing */};
    };
    
    bool weighted;
    int picNum;
    string picName;
    unsigned long shiftRegister;
    SCHashTable<string, EdgeList> data;
    
    void seedLFSR(unsigned long seed);
    bool LFSR();
    int  randomInt();
    void randomShuffle(vector<int>& a);
    void randomShuffle(vector<int>& a, vector<int>& t, int left, int right);
    void merge(vector<int>& a, vector<int>& t, int leftPos, int rightPos, int rightEnd);
};

#endif
