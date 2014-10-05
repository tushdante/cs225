/*
    Lab 12: Minimum Path
    Written by Sean Massung for CS 225 Spring 2011
*/ #include "minpath.h" 
int minPath(Graph & g, string start, string end)
{
//	cout << start << endl;
//	cout << end << endl;
	    
    int minLength=0;
    vector<string> AllVerticies = g.getVertices();
    
    StringHash hasher;
    SCHashTable< string, string > predecessorPath(10, hasher);
 	 string curr, prev;
//    g.initSnapshot("myBFS");
	
	//set all verticies to be unexplored (edges already so)
	for (int i=0 ; i<AllVerticies.size() ; i++)
		{
		g.setVertexMark( AllVerticies[i] , "UNEXPLORED" );
		}


	BFShelper( g , start , predecessorPath);
	
	
/*
This screws everything up.


	//BFS search on all nodes in vector in case more than one connected component
	for (int i=0; i<AllVerticies.size() ; i++)
		if ( g.getVertexMark(AllVerticies[i]) == "UNEXPLORED")

*/



	//Mark min path & count lengt
	if( predecessorPath.keyExists( end ) )
		{
		curr = predecessorPath.find(end);
		g.setEdgeMark(curr, end , "MINPATH");
		minLength=1;
		}
		
	while (predecessorPath.keyExists( curr ) && curr != start )
		{
		if( predecessorPath.keyExists( curr ) )
			{
			prev = predecessorPath.find(curr);
			g.setEdgeMark(curr, prev , "MINPATH");
			minLength++;
			curr=prev;
			}
		}
  
   
    return minLength;
}


void BFShelper(Graph &  g , string currentVertex, 
						SCHashTable< string, string > & predecessorPath )
{
    queue<string> minPath;
    vector<string> adjacentVerticies;
	string current;
    
    minPath.push(currentVertex);
	 g.setVertexMark( currentVertex , "VISITED" );

    while(!minPath.empty() )
    {
    current = minPath.front();
    minPath.pop();
	 adjacentVerticies = g.getAdjacent(current); 
	 
	 
    for (int i=0; i < adjacentVerticies.size() ; i++)
        {
       
        //neighbor hasn't been traversed to yet
        if ( g.getVertexMark(adjacentVerticies[i])  == "UNEXPLORED")
            {
            //mark edges/vertecies appropriately 
            g.setEdgeMark(current, adjacentVerticies[i] , "DISCOVERY");
				g.setVertexMark( adjacentVerticies[i] , "VISITED" );
				
				//add neighbor to queue for further traversal
            minPath.push(adjacentVerticies[i]);
				
				
				//add to predecessor path hash table
				predecessorPath.insert(adjacentVerticies[i] , current);
            }
	
        else if (g.getEdgeMark(adjacentVerticies[i], current) == "UNEXPLORED")
        		{
         	//set cross, don't traverse
				g.setEdgeMark( current, adjacentVerticies[i] , "CROSS" ); 
				}
        }
    
    }

}

