/*
    Lab 12: Graph Implementation Demo Area
    Written by Sean Massung for CS 225 Spring 2011
    
    - This space is just to show how the graph class can be used
    - Feel free to play around in this area
*/

#include <iostream>
#include <string>
#include "graph.h"
#include "example_graphs.cpp"

using std::string;
using std::cout;
using std::endl;

int main(){

    // draw the three example graphs with weights
    Graph us = createUSMap(true);
    Graph europe = createEuropeMap(true);
    Graph japan = createJapanMap(true);
    
    // pretend we found the minimum spanning tree via Kruskal's algorithm
    us.setEdgeMark("KansasCity", "Chicago", "MST");
    us.setEdgeMark("Chicago", "Champaign", "MST");
    us.setEdgeMark("Champaign", "Cincinnati", "MST");
    us.setEdgeMark("Champaign", "StLouis", "MST");
    us.setEdgeMark("Cincinnati", "Nashville", "MST");
    us.setEdgeMark("Cincinnati", "Pittsburgh", "MST");
    us.setEdgeMark("Pittsburgh", "WashingtonDC", "MST");
    
    // all printed Neato graphs are in lab12/images/
    us.printPNG("us-mst");
    europe.printPNG("europe");
    japan.printPNG("japan");
    
    // print the Europe map to stdout
    cout << "\n******************************** Europe ********************************\n\n";
    europe.print();
    
    // draw and the US map without weights
    Graph us_uw = createUSMap(false);
    us_uw.printPNG("us-unweighted");
    
    // create and print a weighted graph with 9 vertices and random seed 777
    Graph r(true, 9, 777);
    r.printPNG("random-demo-graph");
    
    // build your own weighted graph
    cout << "******************************** Built Graph ********************************\n\n";
    Graph g(true);
    g.insertVertex("A");
    g.insertVertex("B");
    g.insertVertex("C");
    g.insertEdge("A", "B");
    g.insertEdge("A", "C");
    g.setEdgeWeight("A", "B", 7);
    g.setEdgeWeight("A", "C", 11);
    g.setEdgeMark("A", "C", "MY EDGE LABEL");
    g.printPNG("built-graph");
    g.print();

    return 0;
}
