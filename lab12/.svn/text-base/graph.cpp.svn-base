/*
    Lab 12: Graph Implementation
    Written by Sean Massung for CS 225 Spring 2011
    
    - The graphs make heavy use of Lab 10's hash tables (from Spring 2011)
*/

#include "graph.h"

/**********************************************************************
 * Constructors, Copy Constructor, operator=, destructor              *
 **********************************************************************/

Graph::Graph(bool isWeighted, int numVertices, unsigned long seed) : data(256, hasher){

    if(numVertices < 2){
        cerr << "Graph Error: make numVertices higher!\n";
        return;
    }

    weighted = isWeighted;
    data = SCHashTable<string, EdgeList>(256, hasher);    
    vector<int> vertices;
    seedLFSR(seed);

    for(size_t i = 0; i < numVertices; ++i){
        vertices.push_back(i);
        insertVertex(toString(i));
    }

    // make sure all vertices are connected
    randomShuffle(vertices);
    int cur = vertices[0];
    for(size_t i = 0; i < vertices.size()-1; ++i){
        int next = vertices[i+1];
        insertEdge(toString(cur), toString(next));
        if(weighted){
            int weight = randomInt();
            setEdgeWeight(toString(cur), toString(next), weight);
        }
        cur = next;
    }
    
    // keep the graph from being overpopulated with edges,
    //  while still maintaining a little randomness
    int numFailures = 0;
    size_t idx = 0;
    randomShuffle(vertices);
    while(numFailures < 2){ // find a better formula...
        if( !insertEdge(toString(vertices[idx]), toString(vertices[idx+1])) )
            ++numFailures;
        else {
        	// if insertEdge() succeeded...
        	if(isWeighted)
            	setEdgeWeight(toString(vertices[idx]), toString(vertices[idx+1]), randomInt());

        	idx++;
        	if(idx >= numVertices - 2){
        		idx = 0;
        		randomShuffle(vertices);
        	}
        }
    }
}

/**********************************************************************
 * Return a vector of all adjacent vertices to the parameter vertex   *
 **********************************************************************/

vector<string> Graph::getAdjacent(string label) const {

    if(!data.keyExists(label)){
        cerr << "Graph Error: attempted to get adjacent edges "
                "of a nonexisting vertex\n";
        return vector<string>();
    }

    vector<string> ret;
    SCHashTable<string, pair<string, int> > edges = data.find(label).edges;
    SCHashTable<string, pair<string, int> >::iterator it;
    for(it = edges.begin(); it != edges.end(); ++it)
        ret.push_back(it->first);
    return ret;
}

/**********************************************************************
 * Return a vector of all edges in the graph                          *
 **********************************************************************/

vector<EdgeData> Graph::getEdges() const {

    if(data.begin() == data.end()){
        cerr << "Graph Error: called getAllEdges() on an empty graph\n";
        return vector<EdgeData>();
    }    
    
    vector<EdgeData> ret;
    set< pair<string, string> > seen;
    SCHashTable<string, EdgeList>::iterator it;
    
    for(it = data.begin(); it != data.end(); ++it){
        vector<string> adj = getAdjacent(it->first);
        for(size_t i = 0; i < adj.size(); ++i){
            if( seen.find(make_pair(it->first, adj[i])) == seen.end() &&
                seen.find(make_pair(adj[i], it->first)) == seen.end()    ){
                EdgeData ed;
                ed.v1 = it->first;
                ed.v2 = adj[i];
                ed.label = getEdgeMark(it->first, adj[i]);
                ed.weight = (weighted)?(getEdgeWeight(it->first, adj[i])):(-1);
                ret.push_back(ed);
                seen.insert(make_pair(it->first, adj[i]));
            }
        }
    }
    
    return ret;
}

/**********************************************************************
 * Return a vector of all edges in the graph                          *
 **********************************************************************/

vector<string> Graph::getVertices() const {
    vector<string> ret;
    SCHashTable<string, EdgeList>::iterator it;
    for(it = data.begin(); it != data.end(); ++it)
        ret.push_back(it->first);
    return ret;
}

/**********************************************************************
 * Traversal functions                                                *
 **********************************************************************/

bool Graph::setVertexMark(string label, string mark){
	
	if(!data.keyExists(label)){
		cerr << "Graph Error: attempted to set "
				"vertex mark on nonexistent vertex\n";
		return false;
	}
	
	EdgeList el = data.find(label);
	data.remove(label);
	el.mark = mark;
	data.insert(label, el);
	return true;
}

string Graph::getVertexMark(string label) const {

	if(!data.keyExists(label)){
		cerr << "Graph Error: attempted to get "
				"vertex mark on nonexistent vertex\n";
		return NULL;
	}
	
	return data.find(label).mark;
}

bool Graph::setEdgeMark(string a, string b, string mark){

    if(!data.keyExists(a) || !data.keyExists(b)){
        cerr << "Graph Error: attempted to set edge label "
                "between one or more nonexisting vertices\n";
        return false;
    }
    
    // add label to a
    EdgeList aTemp = data.find(a);
    if(!aTemp.edges.keyExists(b)){
        cerr << "Graph Error: attempted to set edge label "
                "between existing, yet unconnected vertices\n";
        return false;
    }    
    data.remove(a);
    int weight = (aTemp.edges.find(b)).second;
    aTemp.edges.remove(b);
    aTemp.edges.insert(b, pair<string, int>(mark, weight));
    data.insert(a, aTemp);
    
    // add label to b
    EdgeList bTemp = data.find(b);
    data.remove(b);
    bTemp.edges.remove(a);
    bTemp.edges.insert(a, pair<string, int>(mark, weight));
    data.insert(b, bTemp);
    
    return true;
}

string Graph::getEdgeMark(string a, string b) const {

    if(!data.keyExists(a) || !data.keyExists(b)){
        cerr << "Graph Error: attempted to get edge label "
                "between one or more nonexisting vertices\n";
        return NULL;
    }

    EdgeList temp = data.find(a);

    if(!temp.edges.keyExists(b)){
        cerr << "Graph Error: attempted to get edge label "
                "between existing, yet unconnected vertices\n";
        // this will cause:
        //    terminate called after throwing an instance of 'std::logic_error'
        //    what():  basic_string::_S_construct NULL not valid
        //    Aborted
        // I don't think this is avoidable
        return "oops";
    }

    return (temp.edges.find(b)).first;
}

int Graph::getEdgeWeight(string a, string b) const {

    if(!weighted){
        cerr << "Graph Error: can't get edge weights on "
                "non-weighted graphs!\n";
        return -9999;
    }

    if(!data.keyExists(a) || !data.keyExists(b)){
        cerr << "Graph Error: attempted to get edge weight "
                "between one or more nonexisting vertices\n";
        return -9999;
    }

    EdgeList temp = data.find(a);

    if(!temp.edges.keyExists(b)){
        cerr << "Graph Error: attempted to get edge weight "
                "between existing, yet unconnected vertices\n";
        return -9999;
    }

    return (temp.edges.find(b)).second;
}

/**********************************************************************
 * Building functions                                                 *
 **********************************************************************/

bool Graph::insertVertex(string label){
    if(data.keyExists(label)){
        cerr << "Graph Error: attempted to insert duplicate "
                "vertex with label \""
             << label << "\"\n";
        return false;
    }
    data.insert(label, EdgeList());
    return true;
}

bool Graph::removeVertex(string label){
    
    if(!data.keyExists(label)){
        cerr << "Graph Error: attempted to remove nonexistent "
                "vertex with label \""
             << label << "\"\n";
        return false;
    }
    
    // first, remove all references to the vertex in every other edge list
    // luckily, we can call getAdjacent and work backwards 
    //  instead of traversing the whole hash table
    vector<string> adjacent = getAdjacent(label);
    for(size_t i = 0; i < adjacent.size(); ++i)
        removeEdge(adjacent[i], label);
    
    // now that all references are gone, we can finally delete the vertex
    data.remove(label);
    return true;
}

bool Graph::insertEdge(string a, string b){  
      
    if(!data.keyExists(a) || !data.keyExists(b)){
        cerr << "Graph Error: attempted to add an edge "
                "between one or more nonexisting vertices\n";
        return false;
    }
    
    // add edge to a
    EdgeList aTemp = data.find(a);
    
    // "fail" silently for random graph generation
    if(aTemp.edges.keyExists(b))
        return false;
        
    data.remove(a);
    aTemp.edges.insert(b, pair<string, int>("UNEXPLORED", -1));
    data.insert(a, aTemp);
    
    // add edge to b
    EdgeList bTemp = data.find(b);
    data.remove(b);
    bTemp.edges.insert(a, pair<string, int>("UNEXPLORED", -1));
    data.insert(b, bTemp);
    
    return true;
}

bool Graph::removeEdge(string a, string b){

    if(!data.keyExists(a) || !data.keyExists(b)){
        cerr << "Graph Error: attempted to remove an edge "
                "between one or more nonexisting vertices\n";
        return false;
    }
    
    // remove edge from a
    EdgeList aTemp = data.find(a);
    data.remove(a);
    aTemp.edges.remove(b);
    data.insert(a, aTemp);
    
    // remove edge from b
    EdgeList bTemp = data.find(b);
    data.remove(b);
    bTemp.edges.remove(a);
    data.insert(b, bTemp);
    
    return true;
}

bool Graph::setEdgeWeight(string a, string b, int weight){

    if(!weighted){
        cerr << "Graph Error: can't set edge weights on "
                "non-weighted graphs!\n";
        return false;
    }

    if(!data.keyExists(a) || !data.keyExists(b)){
        cerr << "Graph Error: attempted to set edge weight "
                "between one or more nonexisting vertices\n";
        return false;
    }
    
    // add weight to a
    EdgeList aTemp = data.find(a);
    if(!aTemp.edges.keyExists(b)){
        cerr << "Graph Error: attempted to set edge weight "
                "between existing, yet unconnected vertices\n";
        return false;
    }    
    data.remove(a);
    string label = (aTemp.edges.find(b)).first;
    aTemp.edges.remove(b);
    aTemp.edges.insert(b, pair<string, int>(label, weight));
    data.insert(a, aTemp);
    
    // add weight to b
    EdgeList bTemp = data.find(b);
    data.remove(b);
    bTemp.edges.remove(a);
    bTemp.edges.insert(a, pair<string, int>(label, weight));
    data.insert(b, bTemp);

    return true;
}

/**********************************************************************
 *  Print functions                                                   *
 **********************************************************************/

void Graph::initSnapshot(string title){
    picNum  = 0;
    picName = title;
}

void Graph::snapshot(){
    string newName = picName + toString(picNum);
    printPNG(newName);
    ++picNum;
}

void Graph::print() const {
    
    SCHashTable<string, EdgeList>::iterator it;
    for(it = data.begin(); it != data.end(); ++it){
        cout << it->first << endl;
        SCHashTable<string, pair<string, int> >::iterator git;
        for(git = it->second.edges.begin(); git != it->second.edges.end(); ++git){
            cout << "\t=> " << git->first
                 << "\t\tedge mark = \"" << git->second.first << "\"";
            if(weighted)
                cout << "\tweight = " << git->second.second;
            cout << endl;
        }
        cout << endl;
    }
}

void Graph::printPNG(string title) const {

    std::ofstream neatoFile;
    string filename = "images/" + title + ".dot";
    neatoFile.open(filename.c_str());

    if(!neatoFile.good()){
	    cerr << "Graph Error: creating " << filename << ".dot\n";
	    return;
    }

    neatoFile << "strict graph G {\n"
              << "\toverlap=\"false\";\n"
              << "\tdpi=\"120\";\n"
              << "\tsep=\"1.5\";\n"
              << "\tnode [fixedsize=\"true\", shape=\"circle\", "
                 "fontsize=\"6.0\"]\n"//, width=\".4\", height=\".4\"];\n"
              << "\tedge [penwidth=\"1.5\", fontsize=\"6.0\"];\n";
              
    SCHashTable<string, EdgeList>::iterator it;
    for(it = data.begin(); it != data.end(); ++it){
        SCHashTable<string, pair<string, int> >::iterator git;
        for(git = it->second.edges.begin(); git != it->second.edges.end(); ++git){
            neatoFile << "\t" << it->first << " -- " << git->first;
            // if this is part of a minimum spanning tree 
            //  or the minimum distance path, color the edge
            if(git->second.first == "MST" || git->second.first == "MIN" || git->second.first == "MINPATH")
                neatoFile << "[color=\"blue\"]";
            else if(git->second.first == "CROSS")
            	neatoFile << "[color=\"red\"]";
            else if(git->second.first == "DISCOVERY")
            	neatoFile << "[color=\"green\"]";
            else if(git->second.first == "VISITED")
            	neatoFile << "[color=\"grey\"]";
            // else color="black" (UNEXPLORED)
            // if there's an edge weight (and it's a weighted graph), print it
            if(weighted && git->second.second != -1)
                neatoFile << "[label=\"" << git->second.second << "\"]";
            neatoFile << ";\n";
        }
    }
    
    neatoFile << "}";
    neatoFile.close();
    // 2>/dev/null to ignore graphviz's "errors" about label sizes (or the lack of graphviz)
    string command = "neato -Tpng " + filename + " -o " + "images/" + title + ".png 2>/dev/null";
    system(command.c_str());
    string rmcommand = "rm -rf " + filename;
    system(rmcommand.c_str());
}

/**********************************************************************
 *  Random graph generation                                           *
 **********************************************************************/

string Graph::toString(int num) const {
    std::stringstream out;
    out << num;
    return out.str();
}

// generate weights in the range [0, 1023]
int Graph::randomInt(){
    int ret = 0;
    for(int pos = 0; pos < 10; ++pos)
        ret |= ( (int)LFSR() << pos);
    return ret;
}

// seedLFSR() and LFSR() from Bruce Schneier's \emph{Applied Cryptography}
void Graph::seedLFSR(unsigned long seed){
    if(seed == 0)   // avoid calamity
        seed = 1;
    shiftRegister = seed;
}

bool Graph::LFSR(){
    if(shiftRegister & 0x00000001){
        shiftRegister = (shiftRegister ^ 0x80000057 >> 1) | 0x80000000;
        return true;
    } else {
        shiftRegister >>= 1;
        return false;
    }
}

void Graph::randomShuffle(vector<int>& a){
    vector<int> t(a.size(), int());
    randomShuffle(a, t, 0, a.size() - 1);
    t.clear();
}

void Graph::randomShuffle(vector<int>& a, vector<int>& t, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        randomShuffle(a, t, left, mid);
        randomShuffle(a, t, mid + 1, right);
        merge(a, t, left, mid + 1, right);
    }
}

void Graph::merge(vector<int>& a, vector<int>& t, int leftPos, int rightPos, int rightEnd){

    int leftEnd = rightPos - 1;
    int tPos = leftPos;
    int n = rightEnd - leftPos + 1;

    while(leftPos <= leftEnd && rightPos <= rightEnd){
        if( LFSR() )
            t[tPos++] = a[leftPos++];
        else
            t[tPos++] = a[rightPos++];
    }

    while(leftPos <= leftEnd)
        t[tPos++] = a[leftPos++];

    while(rightPos <= rightEnd)
        t[tPos++] = a[rightPos++];

    for(size_t i = 0; i < n; ++i, --rightEnd)
        a[rightEnd] = t[rightEnd];
}
