/*
   Character Count Frequency Tester (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "char_counter.h"

#include <iostream>
#include <sstream>
using std::istringstream;
using std::cout;
using std::endl;

int main( int argc, char ** argv ) {
    vector<string> args( argv, argv+argc );
    int arg = 500;
    string file = "data/metamorphoses.txt";
    if( argc > 2 ) {
        istringstream iss( args[2] );
        iss >> arg;
        file = args[1];
    }
    cout << "Finding chars in " << file << " with frequency >= " << arg << "..."
        << endl;
    CharFreq cf( file );
    vector< pair<char, int> > ret = cf.getChars( arg );
    for( unsigned int i = 0; i < ret.size(); i++ )
        cout << ret[i].first << " " << ret[i].second << endl;
}
