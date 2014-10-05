/*
   Logfile Parser (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#ifndef _LOGFILE_PARSE_H_
#define _LOGFILE_PARSE_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>

using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::stringstream;
using std::pair;

#include "lphashtable.h"
#include "schashtable.h"
#include "string_hash.h"

class LogfileParser {
    public:
        LogfileParser( string fname );

        pair< bool, time_t > dateVisited( string customer, string url );
        vector< string > uniquePages();

    private:
        class LogLine {
            public:
                LogLine( string line );
                string customer;
                string url;
                time_t date;
        };

        StringHash hasher;
        LPHashTable<string, time_t> whenVisitedTable;
        vector< string > uniqueURLs;

};
#endif
