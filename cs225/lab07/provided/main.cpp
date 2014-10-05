// *****************************************************
// *                                                   *
// *   main.cpp                                        *
// *                                                   *
// *   File for compilation/output testing of          *
// *    organizational tree class                      *
// *                                                   *
// *   Written March 2009 Daniel Hoodin                *
// *                                                   *
// *****************************************************
 
#include <iostream>
#include "binarytree.h"

using namespace std;

template <typename T>
void printTreeInfo(const BinaryTree<T> & tree, string name);

int main()
{
	// Seed the random generator
	// This can be your favorite number; it's just to set up a
	// pseudorandom sequence that will be predictable
	srand(36);

	// Make a random unsorted tree with nodes for 1 through 10
	BinaryTree<int> myTree;
	for (int i = 1; i <= 10; i++)
		myTree.insert(i);

	// Print the tree
	printTreeInfo(myTree, "Tree");

	// Mirror the tree
	myTree.mirror();
	printTreeInfo(myTree, "Mirrored");



	// Make a sorted tree
	// First, create a random ordering to insert 1..10 into the tree
	vector<int> ordering;
	ordering.reserve(10);
	for (int num = 1; num <= 10; num++)
		ordering.push_back(num);
	random_shuffle<vector<int>::iterator>(ordering.begin(), ordering.end());

	// Then create a tree and insert 1..10 shuffled
	BinaryTree<int> myBST;
	for (int index = 0; index < 10; index++)
		myBST.insert(ordering[index], true);
	
	// Print the tree
	printTreeInfo(myBST, "BST:");

	// Mirror the tree
	myBST.mirror();
	printTreeInfo(myBST, "BST Mirrored");



	// Make an almost sorted tree
	srand(6);
	random_shuffle<vector<int>::iterator>(ordering.begin(), ordering.end());

	// Then create a tree and insert 1..10 shuffled
	myBST.clear();
	for (int index = 0; index < 4; index++)
		myBST.insert(ordering[index], true);
	myBST.insert(11, false);

	printTreeInfo(myBST, "Almost BST");
}

template <typename T>
void printTreeInfo(const BinaryTree<T> & tree, string name)
{
	cout << name << ':' << endl;
	cout << "height = " << tree.height() << endl;
	cout << "ordered: " << tree.isOrdered() << endl;
	tree.print();
	tree.printPaths();
	cout << endl;
}
