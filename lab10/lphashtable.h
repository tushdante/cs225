/*
   Linear-Probing Based Hash Table (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#ifndef _LPHASHTABLE_H_
#define _LPHASHTABLE_H_

#include "hashtable.h"

template <class K, class V>
class LPHashTable : public HashTable<K,V> {
    public:
        LPHashTable(int tsize, Hash<K> & hash);
        
        // we allocate dynamic memory and thus require the big three
        virtual ~LPHashTable();
        LPHashTable<K,V> const & operator=( LPHashTable<K,V> const & rhs );
        LPHashTable( LPHashTable<K,V> const & other );


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
        // with linear probing, we only need the array, not buckets for each
        // array index. note that we use an array of pointers to pairs in this
        // case since the check for an "empty" slot is simply a check against
        // NULL
        pair<K,V> * * table;

        virtual void resizeTable();
};

#include "lphashtable.cpp"
#endif
