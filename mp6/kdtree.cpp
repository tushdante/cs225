
/* kdtree.cpp
 * Implementation of KDTree class
 * 
 * Written by Cinda Heeren for CS225 MP6
 * Spring 2009
 * Revision history:
 * 3/31/2009        Created
 * Spring 2011      Modified by Jack Toole
*/

#include <cfloat>

template<int Dim>
KDTree<Dim>::KDTree(const vector< Point<Dim> > & newPoints)
{
	//copy parameter into member variables
	points=newPoints;
	int SIZE=newPoints.size(); 
	point_index.resize( SIZE );
	
	//initialize index array to directly map onto points array
	for( int i=0; i<SIZE; i++ )
		point_index[i]=i;
		
	//make call to recursive function that sorts the point_index array
	//to map out kd-tree without altering points vector.
	if (SIZE!=0) recursiveSelect(0 , SIZE-1, 0);

}

//wrapper recursion fn that orders all of index array
template<int Dim>
void KDTree<Dim>::recursiveSelect(int left,int right, int dim)
{
	if (right>left)
	{
		int mid = (left+right)/2;
		select(left, right, mid, dim);
		
		dim++;
		recursiveSelect( left, mid-1,  dim%Dim);
		recursiveSelect( mid+1 , right , dim%Dim);
	}
	else return;
}

//In quicksort, we recursively sort both branches, leading to best-case 
//O(n log n) time. 

template<int Dim> 
void KDTree<Dim>::select(int left,int right, int k, int dim)
{
     int pivotIndex= ((right+left)/2);
     int pivotNewIndex = partition(left, right, pivotIndex, dim);
     
     if (k == pivotNewIndex) 
     		return;
     else if ( k < pivotNewIndex ) 
     		select(left, pivotNewIndex-1, k, dim);
     else 
     		select(pivotNewIndex+1, right, k, dim);
}

//partions index array around current pivotIndex
template<int Dim>
int KDTree<Dim>::partition(int left, int right, int pivotIndex, int dim)
{
     double pivotValue = points[point_index[pivotIndex]][dim];
     //swap pivot to end
     int temp = point_index[pivotIndex];
     point_index[pivotIndex]= point_index[right];
     point_index[right]=temp;
     
     int storeIndex = left;
     for (int i=left; i<right ; i++)
         if (points[point_index[i]][dim] <= pivotValue)
         	{
             //swap list[storeIndex] and list[i] if less than pivotValue
             temp = point_index[storeIndex];
			    point_index[storeIndex]= point_index[i];
			    point_index[i]=temp;
             storeIndex++;
            }
            
     //swap list[right] and list[storeIndex]  Move pivot to its final place
     temp = point_index[storeIndex];
	  point_index[storeIndex]= point_index[right];
	  point_index[right]=temp;
     return storeIndex;
}


//Takes a reference to a template parameter Point and returns the Point 
//closest to it in the tree.
//wrapper function
template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> & a) const
{
	int size=points.size();
	int root = ( size-1 ) /2; 
	
	int minIndex=0;
	double bestDistance=DBL_MAX;
	
	NNtraversal(root, 0, size-1, 0 , a, minIndex, bestDistance);


	return points[point_index[minIndex]]; 
}

//does all of the kdtree recursion for findNN
template<int Dim>
void KDTree<Dim>::NNtraversal(int subRoot, int lower, int upper, int dim, const Point<Dim> & target,
int & minIndex, double & bestD) const
{
	double d;
	double subRoot_radius;
	double dimensional_distance;

	
	//hit leaf base case--get "best" distance
	if(lower>=upper)
		{
		d = distance(lower, target);
		
		//first time, update best Distance, or leaf has closer distance in general
		if (d < bestD) 
			{
			bestD=d;
			minIndex=lower;
			}
		
		return;	
		}




	//traverse left of subRoot
	if(target[dim] < points[point_index[subRoot]][dim])
		{
		int nextMidRight = (upper + subRoot+1)/2;
		int nextMidLeft = (lower + subRoot-1)/2;

		//traverse
		NNtraversal( nextMidLeft, lower , subRoot-1 , (dim+1) % Dim , target, minIndex, bestD);
		
		//distance from current node (subRoot) to target
		subRoot_radius= distance (subRoot , target);
		
		if (subRoot_radius < bestD) 
			{
			//overwrite bestD on return from traversal
			bestD=subRoot_radius;
			minIndex=subRoot;
			}
			
			
		dimensional_distance = Dim_distance (subRoot, target, dim);
		
		//Distance along subRoot's dimension to target is within the radius of bestD
		if ( dimensional_distance < bestD )
			{
			//traverse onto other side of split dimension
			NNtraversal( nextMidRight , subRoot+1 , upper,  (dim+1) % Dim , target, minIndex, bestD);			
			}
		}





	//traverse right of subRoot
	if(target[dim] >= points[point_index[subRoot]][dim])
		{
		int nextMidRight = (upper + subRoot+1)/2;
		int nextMidLeft = (lower + subRoot-1)/2;

		NNtraversal( nextMidRight , subRoot+1 , upper,  (dim+1) % Dim , target, minIndex, bestD);
		
		//distance from current node (subRoot) to target		
		subRoot_radius= distance (subRoot , target);		
		
		if (subRoot_radius < bestD) 
			{
			//overwrite bestD on return from traversal
			bestD=subRoot_radius;
			minIndex=subRoot;
			}
		
		
		dimensional_distance = Dim_distance (subRoot, target, dim);

		//Distance along subRoot's dimension to target is within the radius of bestD
		if ( dimensional_distance < bestD )
			{
			//traverse onto other side of split dimension
			NNtraversal( nextMidLeft, lower , subRoot-1, (dim+1) % Dim , target, minIndex, bestD);
			}
		}

}

//dimensional distance for tempplate Dim dimensions
template<int Dim>
double KDTree<Dim>::distance(int best , const Point<Dim> & target) const
{
		double d=0;
		for(int i=0; i<Dim; i++)
			d += (target[i]-points[point_index[best]][i])*(target[i]-points[point_index[best]][i]);
		
		return d;
}

//distance along one specified parameter dimension
template<int Dim>
double KDTree<Dim>::Dim_distance (int subRoot, const Point<Dim> & target, int dim ) const
{		
	return (target[dim]-points[point_index[subRoot]][dim])*
											(target[dim]-points[point_index[subRoot]][dim]);
}

