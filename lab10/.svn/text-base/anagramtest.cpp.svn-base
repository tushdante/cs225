/*
   Anagram Finder Test (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "anagram_finder.h"
#include <iostream>

using std::cout;
using std::endl;

int main( int argc, char ** argv ) {
    if( argc < 3 ) {
        cout << "Testing with a dumb example..." << endl;
        vector<string> strings;
        strings.push_back("igloo");
        strings.push_back("oolgi");
        strings.push_back("glooi");
        strings.push_back("dog");
        strings.push_back("cat");
        strings.push_back("iglo");

        cout << "finding anagrams..." << endl;
        AnagramFinder finder( strings );
        vector<string> anagrams = finder.getAnagrams("igloo");

        for( unsigned int i = 0; i < anagrams.size(); i++ )
            cout << anagrams[i] << " is an anagram of igloo" << endl;
    } else {
        vector<string> args(argv, argv + argc);
        cout << "Checking file " << args[1] << " for anagrams of " << args[2] <<
            "..." << endl;
        AnagramFinder fileFinder( args[1] );
        fileFinder.writeAnagrams( args[2], "anagrams.txt" );
        vector<string> anagrams = fileFinder.getAnagrams( args[2] );

        for( unsigned int i = 0; i < anagrams.size(); i++ )
            cout << anagrams[i] << " is an anagram of " << args[2] << endl;
    }
    return 0;
}
