/*
   Separate Chaining Hash Table Iterator (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

template <class K, class V>
SCHashTable<K,V>::iterator::iterator( SCHashTable<K,V> const * iht, int j, bool ed ) : ht(iht), i(j), end(ed) {
    if( i < ht->size ) {
        it = ht->table[i].begin();
        if( it == ht->table[i].end() )
            operator++();
    }
}

template <class K, class V>
typename SCHashTable<K,V>::iterator & SCHashTable<K,V>::iterator::operator++() {
    if( ++it == ht->table[i].end() ) {
        while( ++i < ht->size && ht->table[i].empty() );
        if( i < ht->size ) {
            it = ht->table[i].begin();
        } else
            end = true;
    }
    return *this;
}

template <class K, class V>
typename SCHashTable<K,V>::iterator SCHashTable<K,V>::iterator::operator++(int) {
    iterator tmp(*this);
    operator++();
    return tmp;
}

template <class K, class V>
bool SCHashTable<K,V>::iterator::operator==( iterator const & rhs ) {
    return ht == rhs.ht && i == rhs.i && ( it == rhs.it || end == rhs.end );
}

template <class K, class V>
bool SCHashTable<K,V>::iterator::operator!=( iterator const & rhs ) {
    return !(operator==(rhs));
}

template <class K, class V>
pair<K,V> const & SCHashTable<K,V>::iterator::operator*() {
    return *it;
}

template <class K, class V>
pair<K,V> const * SCHashTable<K,V>::iterator::operator->() {
    return &(*it);
}
