/*
   Anagram Finder (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#ifndef _ANAGRAM_FINDER_H_
#define _ANAGRAM_FINDER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "schashtable.h"
#include "lphashtable.h"
#include "letter_hash.h"
#include "textfile.h"

using std::string;
using std::vector;
using std::ofstream;
using std::endl;

class AnagramFinder {
    public:
        // constructors for the finder
        AnagramFinder( string filename );
        AnagramFinder( vector<string> strings );

        // anagram finder
        vector<string> getAnagrams( string word );

        // writes anagrams to a file rather than placing them in a vector
        void writeAnagrams( string word, string filename );

    private:
        // indicates where to read data from
        bool file;
        string filename;        // only set if the filename constructor used
        vector<string> strings; // only set if the vector constructor used

        // checks if a word is an anagram using an initialized hash table and
        // adds it to the vector ret if it is
        bool checkWord( string const & word, string const & test );
};
#endif
