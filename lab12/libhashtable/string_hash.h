/*
   String Hash Functor (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
   Uses the Bernstein Hash
*/

#ifndef _STRING_HASH_H_
#define _STRING_HASH_H_
#include <string>
using std::string;

#include "hash.h"

class StringHash : public Hash<string> {
    public:
        virtual unsigned int operator()( string const & key, int size );
};
#endif
