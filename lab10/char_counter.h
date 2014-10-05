/*
   Letter Counter (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#ifndef _LETTER_COUNTER_H_
#define _LETTER_COUNTER_H_

#include "schashtable.h"
#include "lphashtable.h"
#include "letter_hash.h"
#include "textfile.h"

#include <vector>
#include <string>
using std::vector;
using std::string;
using std::pair;

class CharFreq {
    public:
        CharFreq( string filename );
        vector< pair<char, int> > getChars( int threshold );
    private:
        string filename;
};
#endif
