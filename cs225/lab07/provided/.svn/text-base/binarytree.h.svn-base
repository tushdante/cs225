#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class BinaryTree
{
	private:
	struct Node
	{
		T elem;
		Node * left;
		Node * right;

		Node(const T & element)
			: elem(element), left(NULL), right(NULL)
		{ }
	};
	
	public:
	// Constructors & Big Three
	BinaryTree();
	BinaryTree(const BinaryTree & other);
	~BinaryTree();
	const BinaryTree & operator=(const BinaryTree & rhs);
	void clear();
	
	// Insertion and printing
	void insert(const T & elem, bool sorted = false);
	void print() const;

	// Helper functions to implement for this lab
	int  height() const;
	void mirror();
	bool isOrdered() const;
	void printPaths() const;
	
	private:
	Node * root;
	
	// Private helper methods
	// You're welcome to add your own helper functions
	int height(const Node * subRoot) const;
	
	
	
	
	// insertion helper
	void insert(Node * & node, const T & elem, bool sorted);
	
	// Private print helpers
	int getPrintData(const Node * node) const;
	void print(const Node * node, vector<string> & output,
	           int left, int top, int width) const;
	
	// Private big three helper functions
	Node * copy(const Node * subRoot);
	void clear(Node * subRoot);
};

// You can declare functions inline so they get placed into the
// calling code by the compiler, rather than as actual function calls,
// but they then must be declared in the header file
// This should only be done for short, non recursive functions
// Here we let you ignore the implementation of the big three
// while writing your helper functions
template <typename T>
inline BinaryTree<T>::BinaryTree()
	: root(NULL)
{ }


template <typename T>
inline BinaryTree<T>::BinaryTree(const BinaryTree & other)
	: root(copy(other.root))
{ }


template <typename T>
inline BinaryTree<T>::~BinaryTree()
{
	clear(root);
}


template <typename T>
inline const BinaryTree<T> & BinaryTree<T>::operator=(const BinaryTree<T> & rhs)
{
	if (this != &rhs)
	{
		clear(root);
		root = copy(rhs.root);
	}
	return *this;
}


template <typename T>
inline void BinaryTree<T>::clear()
{
	clear(root);
	root = NULL;
}


#include "binarytree.cpp"
#include "extras.cpp"
#endif
