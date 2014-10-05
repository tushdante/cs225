/*
   Word Frequency Counter (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#ifndef _WORDFREQ_H_
#define _WORDFREQ_H_

#include "schashtable.h"
#include "lphashtable.h"
#include "string_hash.h"
#include "textfile.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

class WordFreq {
    public:
        WordFreq( string filename );
        vector< pair<string, int> > getWords( int threshold );
    private:
        string filename;
};
#endif
