/*
   Hash Functor (Lab 10)
   Created by Chase Geigle, Spring 2011
*/

#ifndef _HASH_H_
#define _HASH_H_

template <class K>
class Hash {
    public:
        virtual unsigned int operator()( K const & key, int size ) = 0;
};
#endif
