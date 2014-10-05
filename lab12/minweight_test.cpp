/*
    Lab 12: Minimum Weight Test
    Written by Sean Massung for CS 225 Spring 2011
*/

#include <iostream>
#include <string>
#include "graph.h"
#include "minweight.h"
#include "example_graphs.cpp"

using std::string;
using std::cerr;
using std::cout;
using std::endl;

void error(){
    cerr << "usage:"
         << "\t./minweighttest\n"
         << "\t./minweighttest <numVertices> <seed>\n"
         << "\t./minweighttest <us> | <europe> | <japan>\n"
         << "Check ./images/*.png for correct output\n"
         << "Make sure you label the lightest weight edge as \"MIN\"\n";
    exit(1);
}

void mapGraph(char c){

    Graph* g;
    int w;
        
    switch(c){
    case 'u':
        g = new Graph(createUSMap(true));
        w = minWeight(*g);
        g->printPNG("minweight-us");
        break;
    case 'e':
        g = new Graph(createEuropeMap(true));
        w = minWeight(*g);
        g->printPNG("minweight-europe");
        break;
    case 'j':
        g = new Graph(createJapanMap(true));
        w = minWeight(*g);
        g->printPNG("minweight-japan");
        break;
    default:
        error();
    }
    
    g->print();
    delete g;
    cout << "Minimum weight: " << w << endl;
}

void randomGraph(int numVertices, unsigned long seed){
    Graph g(true, numVertices, seed);
    int w = minWeight(g);
    g.print();
    g.printPNG("minweight-random");
    cout << numVertices << " vertices with seed " << seed << endl
         << "Minimum weight: " << w << endl;
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
