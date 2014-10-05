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
    private:
        // so we can refer to hash, elems, and size directly
        using HashTable<K,V>::hash;
        using HashTable<K,V>::elems;
        using HashTable<K,V>::size;

    public:
        class iterator : public std::iterator<std::input_iterator_tag, pair<K,V> > {
            // we first define our iterator class
            public:
                // hash table can build iterators with our private constructor
                // with this
                friend class SCHashTable<K,V>;

                // default constructor
                iterator() : ht(NULL), i(0), end(true) { /* nothing */ }

                // cctor
                iterator( iterator const & other ) : ht(other.ht), i(other.i), it(other.it), end(other.end) { /* nothing */ }

                // iterator functions
                iterator & operator++();
                iterator operator++(int);
                bool operator==( iterator const & rhs );
                bool operator!=( iterator const & rhs );
                pair<K,V> const & operator*();
                pair<K,V> const * operator->();

            private:
                // member vars
                SCHashTable<K,V> const * ht;
                int i;
                typename list< pair<K,V> >::iterator it;
                bool end;

                // private ctor
                iterator( SCHashTable const * ht, int i, bool ed );
        };

        // we first define our iterator class
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

        iterator begin() const {
            return iterator( this, 0, false );
        }

        iterator end() const {
            return iterator( this, size, true );
        }

    private:
        // this is ugly, but this is a dynamic array of lists for the linear probing
        // strategy. The elements inside each list are Key, Value pairs.
        list< pair<K, V> > * table;

        virtual void resizeTable();
};
#include "schashtable.cpp"
#endif
