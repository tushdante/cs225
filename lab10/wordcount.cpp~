/*
   Word Count Frequency Tester (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "word_counter.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

int main( int argc, char ** argv ) {
    vector<string> args(argv, argv+argc);
    int arg = 500;
    string file = "data/metamorphoses.txt";
    if( argc > 2 ) {
        istringstream iss( args[2] );
        iss >> arg;
        file = args[1];
    }
    cout << "Finding words in " << file << " with frequency >= " << arg << "..."
        << endl;
    WordFreq wf( file );
    vector< pair<string, int> > ret = wf.getWords( arg );
    for( unsigned int i = 0; i < ret.size(); i++ )
        cout << ret[i].first << " " << ret[i].second << endl;
}
