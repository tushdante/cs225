// *****************************************************
// *																	*
// *  heap.h														 *
// *																	*
// *  Interface for a simple generalized (template)	 *
// *	 min-heap class, where the values of the		  *
// *	 generic type that are being stored, are		  *
// *	 also the priorities.									*
// *																	*
// *  Written October 2005 by Jason Zych					*
// *  Modified October 2007 by Cinda Heeren				*
// *  Modified November 2010 by Jack Toole				 *
// *																	* 
// *****************************************************

#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
using std::vector;

template <typename T>
class MinHeap
{
public:

	// MinHeap
	//	 - constructor
	//	 - initializes heap to be empty
	//	 - and numElements to be zero
	MinHeap();

	// MinHeap
	//	 - constructor
	//	 - parameters : oneDatum - a single piece of data 
	//	 - initializes the heap vector and places the data elt in 
	//		 cell 1.
	MinHeap(const vector<T> & unsortedArray, bool fast = true);


	// clear
	//	 - removes all values from heap 
	void clear();


	// findMin
	//	 - return value : reference to an element in the heap;  
	//							 the heap element cannot be changed through
	//							 the returned reference
	//	 - returns the element in the heap with the minimum priority;
	//	 - assumes heap is not empty.
	T const & findMin() const;


	// removeMin
	//	 - return value : an element in the heap 
	//	 - removes the element in the heap with the minimum priority,
	//			and returns it; an assertion is triggered if the heap
	//			is empty
	T removeMin();


	// insert
	//	 - parameters : insElem - the item to be inserted into the
	//							 min-heap
	//	 - inserts the parameter item into the min-heap
	void insert(T const & insElem);


	// isEmpty
	//	 - return value : boolean value equalling true if heap is empty
	//	 - returns true if heap is empty; else returns false
	bool isEmpty() const;


	// size
	//	 - return value : non-negative integer holding the number
	//			of elements in the heap
	//	 - returns the number of elements in heap
	int size() const;

	// print
	//	 - prints out the heap's array
	void print() const;

	// operator==
	//	 - compares two heaps
	bool operator==(const MinHeap & rhs) { return array == rhs.array; }

private:

	std::vector<T> array;  // dynamically allocated array for the heap

	// private helper functions
	void heapifyUp(int cIndex);
	void heapifyDown(int cIndex);
	int parent(int cIndex) const;
	bool hasAChild(int cIndex);
	int minChild(int cIndex);
	void swap(T & a, T & b);

};


#include "minheap.cpp"
#endif

