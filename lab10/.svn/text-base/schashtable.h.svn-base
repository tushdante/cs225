/*
   Separate-Chaining Based Hash Table (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#ifndef _SCHASHTABLE_H_
#define _SCHASHTABLE_H_

#include "hashtable.h"
#include <list>
using std::list;

template <class K, class V>
class SCHashTable : public HashTable<K,V> {
    public:
        SCHashTable(int tsize, Hash<K> & hash);

        // we allocate dynamic memory, so we need the big three
        virtual ~SCHashTable();
        SCHashTable<K,V> const & operator=( SCHashTable<K,V> const & rhs );
        SCHashTable( SCHashTable<K,V> const & other );

        // hash table functionality
        virtual void insert( K const & key, V const & value );
        virtual void remove( K const & key );
        virtual V find( K const & key ) const;
        virtual bool keyExists( K const & key ) const;
        virtual void clear();
        virtual vector< pair<K,V> > vectorize() const;

    private:
        using HashTable<K,V>::hash;
        using HashTable<K,V>::size;
        using HashTable<K,V>::elems;
        // this is ugly, but this is a dynamic array of lists for the linear probing
        // strategy. The elements inside each list are Key, Value pairs.
        list< pair<K, V> > * table;

        virtual void resizeTable();
};
#include "schashtable.cpp"
#endif
