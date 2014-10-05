// **************************************************************
// *                                                            *
// *  quadtree.h                                                *
// *                                                            *
// *  Quadtree class                                            *
// *                                                            *
// *  CS 225 Spring 2007                                        *
// *                                                            *
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "EasyBMP.h"

class Quadtree
{
public:
	Quadtree();
	Quadtree(BMP & img, int d);
	
	//big 3
	~Quadtree();
	Quadtree(const Quadtree & orig);
	Quadtree& operator=(const Quadtree & orig);

	//helper functions
	void copy(const Quadtree & orig);
	void clear();

	//mp5.1
	BMP decompress();
	void buildTree(BMP & img, int  d);
	RGBApixel getPixel(const int x, const int y);
	
	//mp5.2
	int pruneSize(const int tolerance);
	int idealPrune(const int numLeaves);
	void clockwiseRotate();
	void prune(const int tolerence);
	

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


private:

   // A simple class representing a single node of a Quadtree.
   // You may want to add to this class; in particular, it could probably
   // use a constructor or two...
   class QuadtreeNode
   {
   public:
		QuadtreeNode();
		QuadtreeNode(int p);
      
		//big 3
		~QuadtreeNode();
		QuadtreeNode(const QuadtreeNode & orig);
		Quadtree::QuadtreeNode& operator=(const QuadtreeNode & orig);

		//helper functions
		void copy(const QuadtreeNode & orig);
		void clear();
		int diff(RGBApixel element1, RGBApixel element2);
		bool nwtolerance(const RGBApixel element, const int tolerance, const int dimension);
		bool netolerance(const RGBApixel element, const int tolerance, const int dimension);
		bool swtolerance(const RGBApixel element, const int tolerance, const int dimension);
		bool setolerance(const RGBApixel element, const int tolerance, const int dimension);

		int difference(const RGBApixel color1);
		int nwdiff(const RGBApixel element, const int dimension);
		int nediff(const RGBApixel element, const int dimension);
		int swdiff(const RGBApixel element, const int dimension);
		int sediff(const RGBApixel element, const int dimension);
		QuadtreeNode* nwChild;  // pointer to northwest child
      QuadtreeNode* neChild;  // pointer to northeast child
      QuadtreeNode* swChild;  // pointer to southwest child
      QuadtreeNode* seChild;  // pointer to southeast child

		//mp5.2
		int pruneSize(const int tolerance);
		int idealPrune(const int numLeaves);
		void clockwiseRotate();
		void prune(const int tolerence);
   
		RGBApixel element;  // the pixel stored as this node's "data"
		
		// holds dimension information. demension is pixels x pixels
		int pixels;
		
   	void BuildtreeNode(BMP & img, int d);
		void copyPixels(BMP &Source, int SourceL, int SourceR, int SourceB, int SourceT,
					BMP &Dest, int DestX, int DestY);
		RGBApixel getPixel(const int x, const int y);

	};

   QuadtreeNode* root;    // pointer to root of quadtree

					
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

};

#endif
