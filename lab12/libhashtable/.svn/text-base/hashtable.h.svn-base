/*
   Hash Table (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <vector>
#include "hash.h"
using std::vector;
using std::pair;

template <class K, class V>
class HashTable {
    public:
        HashTable(Hash<K> & ihash) : hash(ihash) { /* nothing */ };
        virtual ~HashTable() { /* nothing */ };
        virtual void insert( K const & key, V const & value ) = 0;
        virtual void remove( K const & key ) = 0;
        virtual V find( K const & key ) const = 0;
        virtual bool keyExists( K const & key ) const = 0;
        virtual void clear() = 0;
        virtual bool isEmpty() const { return elems == 0; }
        virtual vector< pair<K,V> > vectorize() const = 0;

    protected:
        // functor for hashing
        Hash<K> & hash;
        // current number of elements stored
        int elems;
        // size of the current table
        int size;

    private: 
        virtual void resizeTable() = 0;
};
#endif
