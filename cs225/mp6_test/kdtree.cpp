/* kdtree.cpp
 * Implementation of KDTree class
 * 
 * Written by Cinda Heeren for CS225 MP6
 * Spring 2009
 * Revision history:
 * 3/31/2009        Created
*/

// define KDTree member functions here

#include <math.h>

using std::vector;
using std::cout;
using std::endl;

template<int Dim>
std::ostream & operator<<(std::ostream & out, KDTree<Dim> const & tree)
{
   for (unsigned int i = 0; i < tree.points.size(); ++i)
   {
      out << "Point #"<< i << " coords = (";
      for (unsigned int j = 0; j < Dim; ++j)
      {
         if (j > 0)
            out << ", ";
         out << tree.points[i][j];
      }
      out << ") index = " << tree.point_index[i] << std::endl;
   }
   return out;
}

template<int Dim>
KDTree<Dim>::KDTree(const vector< Point<Dim> > &pts){
	min_D=19999;
	

	vector < int > Vl,Vr;

	unsigned int i;

	//load points vector with pts input
	//points.resize(pts.size());
	for(i=0;i<pts.size();i++){
		points.insert(points.begin()+i, pts[i]);
	}
	
	//fill_pts_index	

	for(i=0; i<points.size(); i++){

		point_index.push_back(i);
	
	}
	
	//cout<<"inside point_index"<<endl;
	

	//create tree
	GetMedian(point_index.size()-1,0,0);
	
}

//creates array based tree
template<int Dim>
void KDTree<Dim>::GetMedian(int upper, int lower, int level ){
	
	vector<int> Vl,Vr;

	int median = (upper+lower)/2;


	int Vl_upper,Vl_lower,Vr_upper,Vr_lower,size=upper-lower;

	if (lower>=upper){
		return;
	}

	//sorts point_index based on level
	sort_vector(upper,lower,level);
	
	//when there are 2 or 3 nodes
	if ( (size==1)||(size==2) ){
		return;
	}

	else if (size==3){
		
		Vr_lower=median+1;
		Vr_upper = upper;
		GetMedian(Vr_upper,Vr_lower,level);
	}
	else {	
	
	
		
		// create left side
	
		
		//Vl_lower=median-(size-1)/2;
		Vl_lower = lower;
		Vl_upper=median-1;
		
	
		// create right side
		
		Vr_lower=median+1;
		Vr_upper=median + (size-1)/2;
			
		
		level++;
		
		
		GetMedian(Vl_upper,Vl_lower,level);
		GetMedian(Vr_upper,Vr_lower,level);
	}
}

//point_index is a subset of point_index
template<int Dim>
void KDTree<Dim>::sort_vector(int upper, int lower, const int level){
	int i,j;

	
	if (lower == upper){
		return;
	}
	for(i=lower; i<=upper;i++){
		for(j=i; j<=upper;j++){
		//when current value in points finds a lower value
		//change location in point_index
			if( points[ point_index[i] ][ level % Dim ] > 
	  			 points[ point_index[j] ][ level % Dim ] ){
				
				//we want to save smaller point then delete it from point_index
				//then insert that point infront of bigger point
				if ((unsigned int)(j+1)>=point_index.size()){
					point_index.push_back(point_index[i]);
				}
				
				else{
					point_index.insert(point_index.begin() + j + 1, point_index[i]);
				}

				point_index.erase(point_index.begin()+i);
				
			}					
		}
	}
}
				
//finds nearest point		
template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> &pt){
	Point<Dim> ret;

	min_D = 9999999;
	ret=helper(0,(int)point_index.size()-1, pt, 0);	
	return ret;
}

//helper function for findnearestneighbor that does most of the work
template<int Dim>
Point<Dim> KDTree<Dim>::helper(int min,int max,const Point<Dim> &pt, int level){	

	//median,min,max = refers to position in vector array not value
	int	median = (min+max)/2,
			Vl_lower,
			Vl_upper,
			Vr_lower,
			Vr_upper;

	if ((max-min)!=1){
			Vl_lower= min;
			Vl_upper= median-1;
	}
	Vr_lower= median+1,
	Vr_upper= max;



	double d=0;

	//base case
		//check distance
		//return
	if (min>=max){
		d=0;
		for(int i=0; i<Dim; i++){
			d += (pt[i]-points[ point_index[median] ][i])*(pt[i]-points[ point_index[median] ][i]);
		}
		d=sqrt(d);
	
		if (d < min_D){
			min_D=d;
			index_min_D = median;
//			cout<<"min_D="<<min_D<<" "<<"min_index"<<index_min_D<<endl;
		}
		return points[ point_index[index_min_D] ];

	}
//when not base case
	//check if target >= current (x,y,z determined by level%Dim)
	//go right
	else if (pt[level%Dim] >= points[ point_index[median] ][level%Dim]){
		
		//special case 2 nodes
		//special case 3 nodes
		if ( (max-min==1) || (max-min == 2) )
			helper(Vr_upper,Vr_upper, pt, level+1);
		else{
			//normal case
			helper(Vr_lower,Vr_upper, pt, level+1);
		}

		d=0;
		//check distance
		for(int i=0; i<Dim; i++){
			d += (pt[i]-points[ point_index[median] ][i])*(pt[i]-points[ point_index[median] ][i]);
		}
	
		d=sqrt(d);

		if (d < min_D){
			min_D=d;
			index_min_D = median;
//		cout<<"min_D="<<min_D<<" "<<"min_index"<<index_min_D<<endl;
		}
	
		//distance btwn 2 points < min distance
		//go left
		if ( ( (pt[level%Dim] - points[ point_index[median] ][level%Dim])*
			 (pt[level%Dim] - points[ point_index[median] ][level%Dim]) )
			  <= min_D){
		
			helper(Vl_lower, Vl_upper, pt, level+1);	

		}
	
	}
	//go left
	else{
		
		//special case 3 nodes
		//special case 4 nodes
		if ( (max-min ==2)|| (max-min == 3) )
			helper(Vl_lower,Vl_lower, pt, level+1);
		else if(max-min==1){
		}
		else{
			//normal case
			helper(Vl_lower,Vl_upper, pt, level+1);	
		}
		
		d=0;
		//check distance
		for(int i=0; i<Dim; i++){
			d += (pt[i]-points[ point_index[median] ][i])*(pt[i]-points[ point_index[median] ][i]);
		}
		d=sqrt(d);
	
		if (d < min_D){
			min_D=d;
			index_min_D = median;
	//		cout<<"min_D="<<min_D<<" "<<"min_index"<<index_min_D<<endl;
		}
		
		//distance btwn 2 points < min distance
		//go right
		if ( ( (pt[level%Dim] - points[ point_index[median] ][level%Dim])*
				 (pt[level%Dim] - points[ point_index[median] ][level%Dim]) )
				  <= min_D){
			
			helper(Vr_lower, Vr_upper, pt, level+1);	
	
		}
	
	}
	return points[ point_index[index_min_D] ];
}



		
	
