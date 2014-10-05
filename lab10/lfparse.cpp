/*
   Logfile Parser App (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "logfile_parser.h"

#include <iostream>

using std::cout;
using std::endl;

int main( int argc, char ** argv ) {
    vector<string> args( argv, argv+argc );
    if( argc < 2 ) {
        cout << "Usage: " << args[0] << " filename" << endl;
        cout << "\twhere filename is the logfile to be parsed" << endl;
    } else {
        cout << "Parsing logfile: " << args[1] << "..." << endl;
        LogfileParser lfp( args[1] );
        vector<string> urls = lfp.uniquePages();
        cout << "Number of unique URLs: " << urls.size() << endl;
        if( urls.size() > 100 ) {
            cout << "Too many unique urls, not printing." << endl;
        } else {
            cout << "Printing unique URLs:" << endl;
            for( unsigned int i = 0; i < urls.size(); i++ ) {
                cout << "\t" << urls[i] << endl;
            }
        }

        cout << "Running sample visited queries..." << endl;

        pair< bool, time_t > ret;
        for( int i = 0; i < 1000; i++ ) {
            stringstream product;
            product << "/product/" << i << "/";
            ret = lfp.dateVisited( "chase", product.str() );
            if( ret.first ) {
                cout << "\tchase visited " << product.str() << " on " <<
                    ctime( &ret.second );
            }
        }
    }

    return 0;
}
