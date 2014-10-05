/*
   Binary Search Tree (Lab 08)
   Created by Chase Geigle for CS225, Spring 2011
*/
#ifndef BST_H
#define BST_H

#include <vector>
#include <queue>
#include <sstream>
#include <iostream>

using namespace std;
using std::max;

// BST is templated: stores key, value pairs
//  - We assume that the "K" class is comparable (operator overloads)
template <class K, class V>
class BST {
    public:
        // BSTs allocate memory with "new", require big three
        BST();
        BST( BST const & orig );
        ~BST();
        BST const & operator=( BST const & rhs );

        /*
           Dictionary Abstract Data Type functions
            - These are implemented so our BST fits the ADT
        */

        // insert()
        //  - Parameters: key, value
        //      The key, value pair to be inserted
        void insert( K const & key, V const & value );

        // find()
        //  - Parameter: key
        //  - Returns: The value of the node with key == parameter
        V find( K const & key ) const;

        // remove()
        //  - Parameter: key
        //      Removes the node with key == parameter
        void remove( K const & key );

        /*
           Extra functions
            - These are outside of the scope of the Dictionary ADT
         */

        // print()
        //  - prints out the tree
        void print() const;

        // keySort()
        //  - Returns: a vector of values, which have been sorted by their
        //      respective keys in the structure
        vector<V> keySort() const;

        // levelOrder()
        //  - Returns: a vector of values, which are arranged by a level-order
        //      traversal of the internal structure
        vector<V> levelOrder() const;

        // height()
        // - Returns the height of the tree
        int height() const;

    private:
        // node class, private just like linked lists
        class Node {
            public:
                K key;
                V value;

                int size; // number of nodes in this subtree

                Node * left;
                Node * right;

                // constructor for a node---implemented here since this is the only
                // function we really need
                Node( K const & nkey, V const & nvalue ) : key(nkey), value(nvalue), left(NULL), right(NULL) {
                    /* nothing */
                }
        };

        Node * root;

        // helpers for big three
        void clear( Node * croot );
        Node * copy( Node const * croot );

        // helpers for ADT implementation
        void insert( Node * & croot, K const & key, V const & value );
        void remove( Node * & croot, K const & key );
        V find( Node const * croot, K const & key ) const;

        // helpers for additional functions
        int getPrintData(const Node * node) const;
        void print(const Node * node, vector<string> & output, int left, int top, int width) const;
        int height( Node const * croot ) const;

        // your helper functions here
};

// needed for template instantiation
#include "bst.cpp"
#endif
