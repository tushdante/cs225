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
#include "coloredout.h"

using namespace std;

template <typename T>
void printTreeInfo(const BinaryTree<T> & tree, string name);

int main(int argc, char ** argv)
{
	// Color the output
	bool is_colored = (argc > 1 && tolower(argv[1][0]) == 'c') && isatty(STDOUT_FILENO);
	colored_out coloroutput;
	if (is_colored)
	{
		coloroutput.set_expected_file("soln_treefun.out");
		int status = coloroutput.start();
		if (status < 0) return 0;
	}

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
	srand(10);
	random_shuffle<vector<int>::iterator>(ordering.begin(), ordering.end());

	// Then create a tree and insert 1..10 shuffled
	BinaryTree<int> myBST;
	for (int index = 0; index < 10; index++)
		myBST.insert(ordering[index], true);
	
	// Print the tree
	printTreeInfo(myBST, "BST");

	// Mirror the tree
	myBST.mirror();
	printTreeInfo(myBST, "BST Mirrored");


	// Make an almost sorted tree
	srand(11);
	for (int num = 1; num <= 10; num++)
		ordering[num-1] = num;
	random_shuffle<vector<int>::iterator>(ordering.begin(), ordering.end());

	// Then create a tree and insert 1..10 shuffled
	myBST.clear();
	for (int index = 0; index < 4; index++)
		myBST.insert(ordering[index], true);
	myBST.insert(4, false);

	printTreeInfo(myBST, "Almost BST");


	if (is_colored)
		cout << '\0';
	return 0;
}

template <typename T>
void printTreeInfo(const BinaryTree<T> & tree, string name)
{
	cout << "================================================================" << endl;
	cout << name << ':' << endl;
	cout << "height: " << tree.height() << endl;
	cout << "ordered: " << boolalpha << tree.isOrdered() << endl;
	cout << "sumDistances: " << tree.sumDistances() << endl;
	tree.print();
	cout << endl;
	cout << "printLeftRight: ";
	tree.printLeftToRight();
	tree.printPaths();
	cout << endl << endl;
}
