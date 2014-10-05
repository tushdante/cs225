/********************************************************************
*
*  dsets.cpp - part of MP7
*  The implementation of dsests class
*  Date: December 1, 2010
*
********************************************************************/

#include "dsets.h"

void DisjointSets::addelements(const int Size)
{
   int i;

   for(i=0; i<Size; i++) {
      VectorTree.push_back(-1);
	}

}

int DisjointSets::find(int node)
{
   if (VectorTree[node] < 0)
	
		return node;

	else {
      
		 VectorTree[node] = find(VectorTree[node]);

		return VectorTree[node];
   
	}

}

void DisjointSets::setunion(const int node1, const int node2)
{  
   int root1, root2, newsize;
   
   root1 = find(node1);
   root2 = find(node2);

   if(root1 == root2){
	
		return;
	
	}
	else{
   	
		newsize = VectorTree[root1] + VectorTree[root2];

		if (VectorTree[root1] > VectorTree[root2]){
		  
		   VectorTree[root2] = newsize; 
			VectorTree[root1] = root2;
		
		}  
		else{
		   
			VectorTree[root1] = newsize;
			VectorTree[root2] = root1;
		
		}
   }

}
void DisjointSets::clear()
{
      VectorTree.clear();
}
