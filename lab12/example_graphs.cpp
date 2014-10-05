/*
    Lab 12: Example Graphs
    Written by Sean Massung for CS 225 Spring 2011
    
    - These examples have real weights between cities in miles
    - Unfortunately, GraphViz draws the nodes with a best-fit algorithm,
        so relative locations of cities are wrong
    - These functions are used in *_test.cpp
*/

#ifndef _EXAMPLE_GRAPHS_CPP_
#define _EXAMPLE_GRAPHS_CPP_

Graph createUSMap(bool isWeighted){

    Graph g(isWeighted);
    
    string v[] = { "WashingtonDC", "Champaign", "Chicago", "Cincinnati",
            "KansasCity", "Nashville", "Pittsburgh", "StLouis" };
            
    for(size_t i = 0; i < 8; ++i)
        g.insertVertex(v[i]);
        
    g.insertEdge(v[4], v[2]);
    g.insertEdge(v[4], v[1]);
    g.insertEdge(v[2], v[1]);
    g.insertEdge(v[6], v[0]);
    g.insertEdge(v[2], v[3]);
    g.insertEdge(v[3], v[6]);
    g.insertEdge(v[1], v[3]);
    g.insertEdge(v[3], v[0]);
    g.insertEdge(v[3], v[5]);
    g.insertEdge(v[5], v[0]);
    g.insertEdge(v[4], v[7]);
    g.insertEdge(v[1], v[7]);
    g.insertEdge(v[3], v[7]);
    
    if(isWeighted){
        g.setEdgeWeight(v[4], v[2], 315);
        g.setEdgeWeight(v[4], v[1], 347);
        g.setEdgeWeight(v[2], v[1], 126);
        g.setEdgeWeight(v[6], v[0], 190);
        g.setEdgeWeight(v[2], v[3], 406);
        g.setEdgeWeight(v[3], v[6], 257);
        g.setEdgeWeight(v[1], v[3], 210);
        g.setEdgeWeight(v[3], v[0], 405);
        g.setEdgeWeight(v[3], v[5], 235);
        g.setEdgeWeight(v[5], v[0], 570);
        g.setEdgeWeight(v[4], v[7], 353);
        g.setEdgeWeight(v[1], v[7], 148);
        g.setEdgeWeight(v[3], v[7], 310);
    }
    
    return g;
}

Graph createEuropeMap(bool isWeighted){

    Graph g(isWeighted);
    
    string v[] = { "Barcelona", "Berlin", "Helsinki", "London", "Madrid",
            "Milan", "Paris", "Prague", "Stockholm", "Warsaw" };
            
    for(size_t i = 0; i < 10; ++i)
        g.insertVertex(v[i]);

    g.insertEdge(v[4], v[3]);
    g.insertEdge(v[4], v[0]);
    g.insertEdge(v[0], v[3]);
    g.insertEdge(v[0], v[5]);
    g.insertEdge(v[0], v[6]);
    g.insertEdge(v[3], v[6]);
    g.insertEdge(v[6], v[5]);
    g.insertEdge(v[3], v[8]);
    g.insertEdge(v[3], v[1]);
    g.insertEdge(v[6], v[1]);
    g.insertEdge(v[5], v[1]);
    g.insertEdge(v[5], v[7]);
    g.insertEdge(v[8], v[1]);
    g.insertEdge(v[1], v[7]);
    g.insertEdge(v[1], v[9]);
    g.insertEdge(v[8], v[2]);
    g.insertEdge(v[1], v[2]);
    g.insertEdge(v[2], v[9]);
    
    if(isWeighted){
        g.setEdgeWeight(v[4], v[3], 785);
        g.setEdgeWeight(v[4], v[0], 314);
        g.setEdgeWeight(v[0], v[3], 707);
        g.setEdgeWeight(v[0], v[5], 451);
        g.setEdgeWeight(v[0], v[6], 515);
        g.setEdgeWeight(v[3], v[6], 213);
        g.setEdgeWeight(v[6], v[5], 398);
        g.setEdgeWeight(v[3], v[8], 892);
        g.setEdgeWeight(v[3], v[1], 580);
        g.setEdgeWeight(v[6], v[1], 546);
        g.setEdgeWeight(v[5], v[1], 524);
        g.setEdgeWeight(v[5], v[7], 398);
        g.setEdgeWeight(v[8], v[1], 504);
        g.setEdgeWeight(v[1], v[7], 174);
        g.setEdgeWeight(v[1], v[9], 321);
        g.setEdgeWeight(v[8], v[2], 246);
        g.setEdgeWeight(v[1], v[2], 687);
        g.setEdgeWeight(v[2], v[9], 570);
    }

    return g;
}

Graph createJapanMap(bool isWeighted){

    Graph g(isWeighted);
    
    string v[] = { "Hitachinaka", "Komoro", "Kyoto", "Nagano",
        "Nagoya", "Ome", "Omiya", "Osaka", "Tokyo" };
        
    for(size_t i = 0; i < 9; ++i)
        g.insertVertex(v[i]);
        
    g.insertEdge(v[4], v[3]);
    g.insertEdge(v[3], v[5]);
    g.insertEdge(v[5], v[8]);
    g.insertEdge(v[3], v[1]);
    g.insertEdge(v[5], v[1]);
    g.insertEdge(v[5], v[6]);
    g.insertEdge(v[1], v[6]);
    g.insertEdge(v[6], v[8]);
    g.insertEdge(v[6], v[0]);
    g.insertEdge(v[8], v[0]);
    g.insertEdge(v[7], v[2]);
    g.insertEdge(v[2], v[4]);
    g.insertEdge(v[2], v[8]);
    g.insertEdge(v[4], v[8]);
    g.insertEdge(v[4], v[5]);
    
    if(isWeighted){
        g.setEdgeWeight(v[4], v[3], 124);
        g.setEdgeWeight(v[3], v[5], 85);
        g.setEdgeWeight(v[5], v[8], 24);
        g.setEdgeWeight(v[3], v[1], 26);
        g.setEdgeWeight(v[5], v[1], 62);
        g.setEdgeWeight(v[5], v[6], 21);
        g.setEdgeWeight(v[1], v[6], 73);
        g.setEdgeWeight(v[6], v[8], 15);
        g.setEdgeWeight(v[6], v[0], 60);
        g.setEdgeWeight(v[8], v[0], 63);
        g.setEdgeWeight(v[7], v[2], 27);
        g.setEdgeWeight(v[2], v[4], 65);
        g.setEdgeWeight(v[2], v[8], 226);
        g.setEdgeWeight(v[4], v[8], 160);
        g.setEdgeWeight(v[4], v[5], 140);
    }
    
    return g;
}

#endif
