// **************************************************************
// *                                                            *
// *  quadtree.cpp                                              *
// *                                                            *
// *  A quadtree class                                          *
// *                                                            *
// *  CS 225 Fall 2006                                          *
// *                                                            *
// **************************************************************

#include <cstddef>
#include <iostream>

using namespace std;

#include "quadtree.h"

#include "EasyBMP.h"


//typedef Quadtree::QuadtreeNode QuadtreeNode;




/**** Testing/grading functions ****/


// printTree (public interface)
//   - parameters: none
//   - prints the contents of the Quadtree using a preorder traversal
void Quadtree::printTree() const {
   if (root == NULL)
      cout << "Empty tree.\n";
   else
      printTree(root, 1);
}


// operator<< (not a member function)
//   - parameters: ostream & - output stream to be used for output
//                 RGBApixel const & pixel - pixel to be output
//   - prints the contents of the given RGBApixel to the given output stream
ostream & operator<<(ostream & out, RGBApixel const & pixel) {
   out << "(" << (int) pixel.Red << "," << (int) pixel.Green 
       << "," << (int) pixel.Blue << ")";
   return out;
}


// printTree (private helper)
//   - parameters: QuadtreeNode *current - pointer to the root of the
//                    subQuadtree which we wish to print
//                 int level - the current recursion depth; used for
//                 d/2,d/2   determining when to terminate recursion (see note below)
//   - prints the leaves of the Quadtree using a preorder traversal
void Quadtree::printTree(QuadtreeNode const * current, int level) const {
   // Is this a leaf?
   // Note: it suffices to check only one of the child pointers,
   // since each node should have exactly zero or four children.
   if (current->neChild == NULL) {
      cout << current->element << " at depth " << level << "\n";
      return;
   }

   // This clause added for the sake of grading; we will never call
   // printTree() on quadtrees larger than  512x512.  (This is a
   // necessary restriction, as the grading scripts choke on programs
   // which produce excessive amounts of output.)
   if (level > 7) {
      cout << "Error: infinite loop detected in printTree();"
           << " quadtree has a loop.\n";
      cout << "Aborting program.\n";
      exit(1);
   }

   // Standard preorder traversal
   printTree(current->neChild, level + 1);
   printTree(current->seChild, level + 1);
   printTree(current->swChild, level + 1);
   printTree(current->nwChild, level + 1);

   return;
}


// operator==
//   - parameters: Quadtree const & other - reference to a const Quadtree
//                    object, against which the current Quadtree will be
//                    compared
//   - return value: a boolean which is true if the Quadtrees are deemed
//        "equal", and false otherwise
//   - compares the current Quadtree with the parameter Quadtree, and
//        determines whether or not the two are the same
// Note: this method relies on the private helper method compareTrees()
bool Quadtree::operator==(Quadtree const & other) const {
   return compareTrees(root, other.root);
}


// compareTrees
//   - parameters: QuadtreeNode const * firstPtr - pointer to the root
//                    of a subtree of the "first" Quadtree under
//                    consideration
//                 QuadtreeNode const * secondPtr - pointer to the root
//                    of a subtree of the "second" Quadtree under
//                    consideration
//   - return value: a boolean which is true if the subQuadtrees are deemed
//        "equal", and false otherwise
//   - compares the subQuadtree rooted at firstPtr with the subQuadtree
//        rooted at secondPtr, and determines whether the two are the same
//   - this function only compares the leaves of the trees, as we did not
//     impose any requirements on what you should do with interior nodes
bool Quadtree::compareTrees(QuadtreeNode const * firstPtr,
                            QuadtreeNode const * secondPtr) const {
   if (firstPtr == NULL && secondPtr == NULL)
      return true;

   if (firstPtr == NULL || secondPtr == NULL)
      return false;

   // if they're both leaves, see if their elements are equal
   // note: child pointers should _all_ either be NULL or non-NULL,
   // so it suffices to check only one of each
   if (firstPtr->neChild == NULL && secondPtr->neChild == NULL) {
      if (firstPtr->element.Red != secondPtr->element.Red ||
         firstPtr->element.Green != secondPtr->element.Green ||
         firstPtr->element.Blue != secondPtr->element.Blue)
         return false;
      else
         return true;
   }

   // they aren't both leaves, so recurse
   return (compareTrees(firstPtr->neChild, secondPtr->neChild) &&
           compareTrees(firstPtr->nwChild, secondPtr->nwChild) &&
           compareTrees(firstPtr->seChild, secondPtr->seChild) &&
           compareTrees(firstPtr->swChild, secondPtr->swChild));
}


//default ctor for Quadtree
Quadtree::Quadtree(){
	root=NULL;
}


//more specific default ctor for Quadtree 
//	parameters:	&BMP img - image passed that will be the foundation
//		for the tree
//					d - variable that tells the dimensions of the 
Quadtree::Quadtree(BMP & img, int d){
	//check if d is in proper range
	if ((d>img.TellWidth())||(d>img.TellHeight())||(d<=0))
		root=NULL;
	//when d is in proper range then make root point to a node and
	//do the BuildTree function
	else{
		root=new QuadtreeNode(d);
		buildTree(img, d);
	}
}


//dtor for Quadtree
Quadtree::~Quadtree(){
	clear();
}


//Quadtree dtor helper
void Quadtree::clear(){
	if (root !=NULL){
		root->clear();
		delete root;
		root=NULL;
	}
}


//default ctor for Quadtreenode
Quadtree::QuadtreeNode::QuadtreeNode(){
	nwChild=NULL;
	neChild=NULL;
	swChild=NULL;
	seChild=NULL;
	
	pixels=0;
}


//more specific default ctor for Quadtreenode
// parameters:	x - x_mid class variable
//					y - y_mid class variable
//					p - pixels class variable

Quadtree::QuadtreeNode::QuadtreeNode(int p){
	nwChild=NULL;
	neChild=NULL;
	swChild=NULL;
	seChild=NULL;
	
	//set helpful values
	pixels = p;
}


//overloaded =operator for Quadtree
Quadtree & Quadtree::operator=(const Quadtree & rhs){
	if (this != &rhs){ 
		//clear lhs
		clear();

		//copy rhs
		copy(rhs);
	}
	return *this;
}


//overloaded =operator for quadtreeNode
Quadtree::QuadtreeNode& Quadtree::QuadtreeNode::operator=(const QuadtreeNode & rhs){
	if (this != &rhs){ 
		//clear lhs
		clear();

		//copy rhs
		copy(rhs);
	}
	return *this;
}


//copy ctor for Quadtree
Quadtree::Quadtree(const Quadtree & orig){
	copy(orig);
}


//copy ctor for QuadtreeNode
Quadtree::QuadtreeNode::QuadtreeNode(const QuadtreeNode & orig){
	copy(orig);
}


//copy helper for Quadtree
void Quadtree::copy(const Quadtree & orig){
	if (orig.root!=NULL){
		root=new QuadtreeNode;
		*root=(*(orig.root));
	}
	else{
		root=NULL;
	}
}


//copy helper for QuadtreeNode
void Quadtree::QuadtreeNode::copy(const QuadtreeNode & orig){	
	//basic soft copy initializations
	pixels=orig.pixels;
	element=orig.element;
	
	//when the original node has children then copy them recursively 
	if (orig.nwChild!=NULL){
		nwChild=new QuadtreeNode;
		nwChild->copy(*(orig.nwChild));
		neChild=new QuadtreeNode;
		neChild->copy(*(orig.neChild));
		swChild=new QuadtreeNode;
		swChild->copy(*(orig.swChild));
		seChild=new QuadtreeNode;
		seChild->copy(*(orig.seChild));
	}
	//if not then set to null
	else{
		nwChild=NULL;
		neChild=NULL;
		swChild=NULL;
		seChild=NULL;
	}
}


//QuadtreeNode dtor
Quadtree::QuadtreeNode::~QuadtreeNode(){
	clear();
}


//QuadtreeNode dtor helper
void Quadtree::QuadtreeNode::clear(){

	if (nwChild !=NULL){
		//full 4-ary tree so all leaves are on the same level so not all children
		// need to be checked
		//leaves will have no children - then delete
		if (nwChild->nwChild==NULL){
			delete nwChild;
			nwChild=NULL;
			delete neChild;
			neChild=NULL;
			delete swChild;
			swChild=NULL;
			delete seChild;
			seChild=NULL;
			return;
		}

	
		//traverse tree till top condition is reached
		//when return to parent delete child that was looked at
		nwChild->clear();
		delete nwChild;
		nwChild=NULL;
		neChild->clear();
		delete neChild;
		neChild=NULL;
		swChild->clear();
		delete swChild;
		swChild=NULL;
		seChild->clear();
		delete seChild;
		seChild=NULL;
	}
	
}


//	BuildTree
//	-parameters:	&BMP img - passes the original image that the tree will be
//		created using.d/2,d/2
//						d - dimensions of the picture
//

void Quadtree::buildTree(BMP & img, int  d){
	clear();

	if (root==NULL)
		root=new QuadtreeNode(d);
	//do BuildTreeNode inside root
	root->BuildtreeNode(img,d);

}


// BuildtreeNode
//	-parameters:	&BMP img- passes in image that tree will be created on
//						d-dimensions of the picture each node is representing
//	-builds the tree a node at a timae by recursion.

void Quadtree::QuadtreeNode::BuildtreeNode(BMP & img, int d){
	//when d is not in proper range
	if ((d>pixels)||(d<=0))
		return;
	
	//when there is 1 pixel then copy the color information into tree and return
	if (pixels==1){
		nwChild = NULL;
		neChild = NULL;
		swChild = NULL;
		seChild = NULL;
		element = *(img(0,0));
		return;
	}

	//when d is range and when img isn't a single pixel
	
	//what part of the picture the node is responsible for
	BMP pass;
	pass.SetSize(d/2,d/2); 

	//set up node	
	nwChild=new QuadtreeNode(d/2);
	//copy over the nw part of the original image
	copyPixels(img,0,d/2-1,d/2-1,0,pass,0,0);
	//do recurse for nw
	nwChild->BuildtreeNode(pass,d/2);

	//set up node	
	neChild=new QuadtreeNode(d/2);
	//copy over the ne part of the original image
	copyPixels(img,d/2,d-1,d/2-1,0,pass,0,0);
	//do recurse for ne
	neChild->BuildtreeNode(pass,d/2);

	//set up node	
	swChild=new QuadtreeNode(d/2);
	//copy over the sw part of the original image
	copyPixels(img,0,d/2-1,d-1,d/2,pass,0,0); 
	//do recurse for sw
	swChild->BuildtreeNode(pass,d/2);
	
	//set up node	
	seChild=new QuadtreeNode(d/2);
	//copy over the se part of the original image
	copyPixels(img,d/2,d-1,d-1,d/2,pass,0,0); 
	//do recurse for se
	seChild->BuildtreeNode(pass,d/2);

	if (nwChild != NULL){
		RGBApixel avg;
		avg.Red   = ( ( (nwChild->element).Red   + (neChild->element).Red +
			 	  	       (swChild->element).Red   + (seChild->element).Red)/4);
		avg.Green = ( ( (nwChild->element).Green + (neChild->element).Green +
   	  	 		       (swChild->element).Green + (seChild->element).Green)/4);
		avg.Blue  = ( ( (nwChild->element).Blue  + (neChild->element).Blue +
			 		       (swChild->element).Blue  + (seChild->element).Blue)/4);
		element=avg;

	//	cout<<"--------------------check avg---------------------------"<<endl;
	//	cout<<"("<<avg.Red<<","<<avg.Blue<<","<<avg.Green<<")"<<endl;
	//	if (neChild != NULL)
	//		cout<<"children"<<endl;
	//	else
	//		cout<<"no children"<<endl;
	}
}


//copyPixels
//	parameters: Source - img source has coordinates left, right, bottom, top
//					Dest - img destination, has coordinates x and y where 
void Quadtree::QuadtreeNode::copyPixels(BMP &Source, int SourceL, int SourceR, int SourceB, int SourceT,
					BMP &Dest, int DestX, int DestY){
	for(int j=SourceT,y=DestY ; j <= SourceB ; j++,y++ ){ 
		for(int i=SourceL,x=DestX ; i <= SourceR ; i++,x++ ){
			*(Dest(x,y))=*(Source(i,j));
		}
	}
}


//decompress
//	reconstructs image by transversing the tree
BMP Quadtree::decompress(){
	BMP ret;

	if (root==NULL)
		return ret;

	int width=root->pixels;
	int height=root->pixels;
	
	//set image size	
	ret.SetSize(width,height);

	for(int y=0;y<height;y++){
		for(int x=0;x<width;x++){
			//get pixel information for specified (x,y)
			*ret(x,y)=getPixel(x,y);
		}
	}
//	cout<<endl;
	return ret;
}

RGBApixel Quadtree::getPixel(const int x, const int y){

	if (root==NULL){
		RGBApixel ret;
		return ret;
	}
	else
		return (root->getPixel(x,y));
}



//getPixel
//	parameters:	x - x coordinate
//					y - y coordinate
//	helper function for decompress
RGBApixel Quadtree::QuadtreeNode::getPixel(const int x,const  int y){

	RGBApixel ret;

	//if one sibling is NULL then all are NULL
	if (nwChild==NULL){	//pixels==1){ 
		ret=element;
//		cout<<(int)ret.Red<<","<<(int)ret.Green<<","<<(int)ret.Blue<<"!!"<<endl;

		return ret;
	}

	//se case
	if ((x>=pixels/2)&&(y>=pixels/2)){
		//cout<<"se, ";
		ret=seChild->getPixel(x-pixels/2,y-pixels/2);
	}
	//ne case
	else if (x>=pixels/2){
		//cout<<"ne, ";
		ret=neChild->getPixel(x-pixels/2,y);
	}
	//sw case
	else if (y>=pixels/2){
		//cout<<"sw, ";
		ret=swChild->getPixel(x,y-pixels/2);
	}
	//nw case
	else{
		//cout<<"nw, ";
		ret=nwChild->getPixel(x,y);
	}
		
//	cout<<(int)ret.Red<<","<<(int)ret.Green<<","<<(int)ret.Blue<<"*"<<endl;
	return ret;
}


//clockwiseRotate
// rotates the image 90 degrees
void Quadtree::clockwiseRotate(){
	if (root != NULL){
		
		//rotate children
		root -> clockwiseRotate();
	}
}

//helper function for clockwise rotate
void Quadtree::QuadtreeNode::clockwiseRotate(){
	//if one child is NULL all children are NULL
	if (nwChild != NULL){
		//keep original values
		QuadtreeNode	*temp  = nwChild,
							*temp2 = neChild,
							*temp3 = swChild,
							*temp4 = seChild;
		
		//rotate inside children
		nwChild->clockwiseRotate();
		neChild->clockwiseRotate();
		swChild->clockwiseRotate();
		seChild->clockwiseRotate();
	
		//rotate children
		nwChild = temp3;
		neChild = temp;
		swChild = temp4;
		seChild = temp2;
	}

	//has no children, do nothing
	else
		return;
}

//prune function
//used to prune the leaves off a tree given a tolerance
void Quadtree::prune(int tolerance){
	if (root != NULL)
		root->prune(tolerance);
	else
		return;
}

//helper function used to calculate the diff between 2 colors
int Quadtree::QuadtreeNode::diff(RGBApixel color1, RGBApixel color2){
	return	(color2.Red   - color1.Red)   * (color2.Red   - color1.Red)   +
				(color2.Green - color1.Green) * (color2.Green - color1.Green) +
				(color2.Blue  - color1.Blue)  * (color2.Blue  - color1.Blue);
}
//helper function used to calculate the max of leaves
int Quadtree::QuadtreeNode::difference(const RGBApixel color1){
	int temp1,temp2,temp3,temp4,max=0;
	
	
	if (nwChild!=NULL){
		temp1=nwChild->difference(color1);
		temp2=neChild->difference(color1);
		temp3=swChild->difference(color1);
		temp4=seChild->difference(color1);

		if (temp1 > max)
			max=temp1;
		
		if (temp2 > max)
			max=temp2;
		
		if (temp3 > max)
			max=temp3;
		
		if (temp4 > max)
			max=temp4;
		
		return max;
	}
	else
		return diff(color1,element);
}


//quadtreeNode's prune
//helper function for quadtree
void Quadtree::QuadtreeNode::prune(int tolerance){
	//do recursion until children are NULL
	if (nwChild !=NULL){
		
		//meet tolerence criteria?	
		if (difference(element)<=tolerance){
	
			//cout<<"pruning........"<<endl<<endl;
			
			//delete children
			nwChild->clear();
			delete nwChild;
			nwChild=NULL;

			swChild->clear();
			delete swChild;
			swChild=NULL;
			
			neChild->clear();
			delete neChild;
			neChild=NULL;
			
			seChild->clear();
			delete seChild;
			seChild=NULL;
		}
	
	
		//when tolerance condition doesn't hold go deeper
		//into tree
		else{
			nwChild->prune(tolerance);
			neChild->prune(tolerance);
			swChild->prune(tolerance);
			seChild->prune(tolerance);
		}
	}	
}

//pruneSize
//gives the number of leaves remaining after specified tolerance is used
int Quadtree::pruneSize(int tolerance){
	int ret=0;
	//root points to a node
	if (root != NULL){
		//total number of leaves
		ret=root->pixels*root->pixels;
		//has children
		if (root->nwChild != NULL){
			//subtract from total leaves
			ret-= (((root->nwChild) -> pruneSize(tolerance)) +
					  ((root->neChild) -> pruneSize(tolerance)) +
					  ((root->swChild) -> pruneSize(tolerance)) +
					  ((root->seChild) -> pruneSize(tolerance))); 
			return ret;
		}
		else
			return ret;
	}
	else
		return ret;
}

//helper function for pruneSize
int Quadtree::QuadtreeNode::pruneSize(int tolerance){
	int ret=0;
	//do recursion until children are NULL
	if (nwChild !=NULL){
		
		//meet tolerence criteria?	
		if (difference(element)<=tolerance){
			
			//cout<<"pruning........"<<endl<<endl;
			
			//number of pixels dropped
			ret=pixels*pixels-1;	
		}
	
	
		//when tolerance condition doesn't hold go deeper
		//into tree
		else{
			ret+=nwChild->pruneSize(tolerance);
			ret+=neChild->pruneSize(tolerance);
			ret+=swChild->pruneSize(tolerance);
			ret+=seChild->pruneSize(tolerance);
			
		}
	}	
	return ret;
}

//quadtree ideal prune function
//returns tolerance to get specified number of leaves
int Quadtree::idealPrune(const int numleaves){
	int tolerance;
	if (root!=NULL){
		tolerance=root->idealPrune(numleaves);
		return tolerance;
	}
	else 
		return 0;
}

//ideal prune helper function
//	parameter:
//		numleaves: constant, number of leaves wanted in the final tree
//	return:
//		returns the tolerance to achieve the numleaves, integer
int Quadtree::QuadtreeNode::idealPrune(const int numleaves){
	int max=0,tolerance=0;
	//children exist
	if (nwChild != NULL){
		
		max=difference(element);

		if(pruneSize(max)==numleaves){
			//tolerance found and returned
			return tolerance;
		}

		//go deeper into tree to get bigger pruneSize, less tolerance
		else if(pruneSize(max)<numleaves){
			max=nwChild->idealPrune(numleaves); 
			if (max > tolerance){
				tolerance=max;
				return tolerance;
			}
			max=neChild->idealPrune(numleaves);			
			if (max > tolerance){
				tolerance=max;
				return tolerance;
			}
			max=swChild->idealPrune(numleaves);			
			if (max > tolerance){
				tolerance=max;
				return tolerance;
			}
			max=seChild->idealPrune(numleaves);			
			if (max > tolerance){
				tolerance=max;
				return tolerance;
			}
		}

		//won't be able to find right size, need bigger tolerance, 
		//which is smaller pruneSize
		//which is higher in tree, but this has already been passed
		else if(pruneSize(max)>numleaves){
			return 0;
		}
	}
	return 0;
}
