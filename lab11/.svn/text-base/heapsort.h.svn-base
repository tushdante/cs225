#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <vector>

using std::vector;

// Main HeapSort algorithm
void heapSort(vector<int> & input);

// HeapSort helpers
// These implement a maxheap as an array starting at index 0
namespace heapsort
{

// Creates a heap from an array
void buildHeap(vector<int> & array);

// Bubbles the first element down the heap
// size should be the current size of the heap portion of the array
// (If you just removed an element, this should be the decremented value)
void heapifyDown(vector<int> & array, unsigned int size);

// Bubbles the last element up the heap
// size should be the size of the heap including the last un-heaped element
void heapifyUp(vector<int> & array, unsigned int size);

}

#endif
