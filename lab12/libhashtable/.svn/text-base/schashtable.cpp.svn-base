/*
   Separate-Chaining Based Hash Table (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "schashtable.h"

// iterator
#include "sciterator.cpp"

template <class K, class V>
SCHashTable<K,V>::SCHashTable( int tsize, Hash<K> & hash ) : HashTable<K,V>(hash) {
    if( tsize <= 0 )
        tsize = 16;
    table = new list< pair<K,V> >[tsize];
    size = tsize;
    elems = 0;
}

template <class K, class V>
SCHashTable<K,V>::~SCHashTable() {
    delete [] table;
}

template <class K, class V>
SCHashTable<K,V> const & SCHashTable<K,V>::operator=( SCHashTable<K,V> const & rhs ) {
    if( this != &rhs ) {
        delete [] table;
        table = new list< pair<K,V> >[rhs.size];
        for( int i = 0; i < rhs.size; i++ )
            table[i] = rhs.table[i];
        size = rhs.size;
        elems = rhs.elems;
        hash = rhs.hash;
    }
    return *this;
}

template <class K, class V>
SCHashTable<K,V>::SCHashTable( SCHashTable<K,V> const & other ) : HashTable<K,V>( other.hash ) {
    table = new list< pair<K,V> >[other.size];
    for( int i = 0; i < other.size; i++ )
        table[i] = other.table[i];
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void SCHashTable<K,V>::insert( K const & key, V const & value ) {
    if( (double)elems/size >= 0.7 )
        resizeTable();
    pair<K,V> p( key, value );
    int idx = hash( key, size );
    table[idx].push_front( p );
    elems++;
}

template <class K, class V>
void SCHashTable<K,V>::remove( K const & key ) {
    int idx = hash( key, size );
    typename list< pair<K,V> >::iterator it;
    for( it = table[idx].begin(); it != table[idx].end(); it++ ) {
        if( it->first == key ) {
            table[idx].erase( it );
            elems--;
            break;
        }
    }
}

template <class K, class V>
V SCHashTable<K,V>::find( K const & key ) const {
    int idx = hash( key, size );
    typename list< pair<K,V> >::iterator it;
    for( it = table[idx].begin(); it != table[idx].end(); it++ ) {
        if( it->first == key )
            return it->second;
    }
    return V();
}

template <class K, class V>
bool SCHashTable<K,V>::keyExists( K const & key ) const {
    int idx = hash( key, size );
    typename list< pair<K,V> >::iterator it;
    for( it = table[idx].begin(); it != table[idx].end(); it++ ) {
        if( it->first == key )
            return true;
    }
    return false;
}

template <class K, class V>
void SCHashTable<K,V>::clear() {
    delete [] table;
    table = new list< pair<K,V> >[16];
    size = 16;
    elems = 0;
}

template <class K, class V>
void SCHashTable<K,V>::resizeTable() {
    list< pair<K,V> > * temp = new list< pair<K,V> >[size*2];
    for( int i = 0; i < size; i++ ) {
        typename list< pair<K,V> >::iterator it;
        for( it = table[i].begin(); it != table[i].end(); it++ ) {
            int idx = hash( it->first, size * 2 );
            temp[idx].push_front( *it );
        }
    }
    delete [] table;
    table = temp;
    size *= 2;
}

template <class K, class V>
vector< pair<K,V> > SCHashTable<K,V>::vectorize() const {
    iterator it;
    vector< pair<K,V> > ret;
    for( it = begin(); it != end(); it++ )
        ret.push_back( *it );
    return ret;
}

