/*
   String Hash Functor (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
   Uses the Bernstein Hash
*/

#include "string_hash.h"

unsigned int StringHash::operator()( string const & key, int size ) {
    unsigned int h = 0;

    for( int i = 0; i < key.length(); i++ )
        h = 33 * h + key[i];

    return h % size;
}
