// **************************************************************
// *            Roman Levitas                                   *
// *  quadtree.h                                                *
// *                                                            *
// *  Quadtree class                                            *
// *                                                            *
// *  CS 225 Spring 2011                                        *
// *                                                            *
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "EasyBMP.h"

class Quadtree
{

private:

   // A simple class representing a single node of a Quadtree.
   // You may want to add to this class; in particular, it could probably
   // use a constructor or two...
   class QuadtreeNode
   {
   public:
		QuadtreeNode();
		QuadtreeNode(RGBApixel input);
		QuadtreeNode(QuadtreeNode * const & subRoot);
		RGBApixel getPixel(int x, int y, int d) const;
		
//		void prune(int tolerance);
	//	bool TolerateMe( RGBApixel color, const QuadtreeNode * node, int tolerance) const;
    	
    	QuadtreeNode* nwChild;  // pointer to northwest child
      QuadtreeNode* neChild;  // pointer to northeast child
      QuadtreeNode* swChild;  // pointer to southwest child
      QuadtreeNode* seChild;  // pointer to southeast child
		
		int resolution;
      RGBApixel element;  // the pixel stored as this node's "data"
      
      //5.2
      bool pruneNodes(int const tolerance, const RGBApixel tolerateMe);
   };
   
   
	//Helper Functions 5.1
	void choppedByD( BMP & ChopMe,BMP const & fromMe, int d2 );
	void cropped4recursion(BMP & cropMe, BMP & fromMe, int lowX, int lowY, int D);
	void recursiveBuild(BMP & buildMe, QuadtreeNode * & subRoot, int d);
	void clear(QuadtreeNode * & subRoot);

	
	//Helper Functions 5.2		
	void rotateHelper(QuadtreeNode * & subRoot);
	void pruneHelper(int const tolerance , QuadtreeNode* subRoot);
	void pruneSizeHelper(int const tolerance , QuadtreeNode* subRoot, int & totes);
	
	
	//members			
	BMP theImage;	
   QuadtreeNode* root;    // pointer to root of quadtree
   int DIMENSION;			  // d from original constructor






   /*** Testing/grading functions ***/

   // printTree (private helper)
   //   - parameters: QuadtreeNode *current - pointer to the root of the
   //                    subQuadtree which we wish to print
   //                 int level - the current recursion depth; used for
   //                    determining when to terminate recursion (see note below)
   //   - prints the contents of the Quadtree using a preorder traversal
   void printTree(QuadtreeNode const *current, int level) const;

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
   bool compareTrees(QuadtreeNode const *firstPtr,
                     QuadtreeNode const *secondPtr) const;











public:

	//Constructors
	Quadtree();
	Quadtree(const BMP original, int d);
	
	//Big 3
	Quadtree(Quadtree const & source);
	Quadtree const & operator=(Quadtree const & source);
	~Quadtree();
	
	
	//Primary Functionality 5.1
	void buildTree (const BMP & buildMe , int d);
	RGBApixel getPixel(int x, int y) const;
	BMP decompress() const;
	
	//Primary Functionality 5.2
	void clockwiseRotate();
	void prune(int tolerance);
	int pruneSize(int tolerance) const;
	int idealPrune(int numLeaves) const;


	
   /**** Functions added for testing/grading ****/


   // printTree (public interface)
   //   - parameters: none
   //   - prints the leaves of the Quadtree using a preorder traversal
   void printTree() const;


   // operator==
   //   - parameters: Quadtree const & other - reference to a const Quadtree
   //                    object, against which the current Quadtree will be
   //                    compared
   //   - return value: a boolean which is true if the Quadtrees are deemed
   //        "equal", and false otherwise
   //   - compares the current Quadtree with the parameter Quadtree, and
   //        determines whether or not the two are the same
   // Note: this method relies on the private helper method compareTrees()
   bool operator==(Quadtree const & other) const;



};

#endif
