/*
    Lab 12: Kruskal's Algorithm Test
    Written by Sean Massung for CS 225 Spring 2011
*/

#include <iostream>
#include <string>
#include "graph.h"
#include "kruskal.h"
#include "example_graphs.cpp"

using std::string;
using std::cerr;
using std::cout;
using std::endl;

void error(){
    cerr << "usage:"
         << "\t./kruskaltest\n"
         << "\t./kruskaltest <numVertices> <seed>\n"
         << "\t./kruskaltest <us> | <europe> | <japan>\n"
         << "Check ./images/*.png for correct output\n"
         << "Make sure you label the MST edges as \"MST\"\n";
    exit(1);
}

void mapGraph(char c){

    Graph* g;
        
    switch(c){
    case 'u':
        g = new Graph(createUSMap(true));
        findMST(*g);
        g->printPNG("kruskal-us");
        break;
    case 'e':
        g = new Graph(createEuropeMap(true));
        findMST(*g);
        g->printPNG("kruskal-europe");
        break;
    case 'j':
        g = new Graph(createJapanMap(true));
        findMST(*g);
        g->printPNG("kruskal-japan");
        break;
    default:
        error();
    }
    
    g->print();
    delete g;
}

void randomGraph(int numVertices, unsigned long seed){
    Graph g(true, numVertices, seed);
    findMST(g);
    g.print();
    g.printPNG("kruskal-random");
    cout << numVertices << " vertices with seed " << seed << endl;
}

int main(int argc, char** argv){

    switch(argc){
    case 2:
        mapGraph(argv[1][0]);
        break;    
    case 3:
        randomGraph(atoi(argv[1]), atoi(argv[2]));
        break;
    default:
        randomGraph(9, 777);
    }

    return 0;
}
