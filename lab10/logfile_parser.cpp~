/*
   Logfile Parser (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "logfile_parser.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdlib.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;
using std::stringstream;
using std::istringstream;



// creates a LogLine from the given line---you can ignore this.
LogfileParser::LogLine::LogLine( string line ) {
    istringstream iss( line );
    iss >> customer;
    customer = customer.substr(1, customer.length()-3);
    iss >> url;
    string dte = "";
    string dline;
    do {
        iss >> dline;
        dte += dline;
    } while( iss );

    date = time(NULL);
    tm * tme = localtime( &date );
    strptime( dte.c_str(), "%c", tme );
    date = mktime( tme );
}

LogfileParser::LogfileParser( string fname ) : whenVisitedTable(256, hasher) 
{
    SCHashTable< string, bool > pageVisitedTable(256, hasher);
    string temp;
    ifstream infile( fname.c_str() );
    string line;
    
    while( infile.good() ) 
    {
        getline( infile, line );
        
        // if the line's length is 0, move to the next loop iteration
        if( line.length() == 0 )
            continue;

			
        LogLine ll( line );
        // given the LogLine above, update the member variable hash table and
        // any other hash tables necessary to solve this problem. this should
        // also build the uniqueURLs vector.
      temp = ll.url + ll.customer;
      
		if( whenVisitedTable.keyExists(temp) )     
			{
			if(whenVisitedTable.find(temp) < ll.date)
				{
				whenVisitedTable.remove(temp);
				whenVisitedTable.insert( temp , ll.date);
				}
			}
		else
			{
			
			whenVisitedTable.insert( temp , ll.date);
			}
       
   //set up unique urls array    
   if( !pageVisitedTable.keyExists( ll.url) || (pageVisitedTable.find( ll.url) == false) )
   	{
 	   pageVisitedTable.insert( ll.url , true );
		uniqueURLs.push_back (ll.url);
		}
	//else if (pageVisitedTable.find( ll.url) == true) continue;
    }
}

pair< bool, time_t > LogfileParser::dateVisited( string customer, string url ) {
    pair< bool, time_t > ret;
    string temp=url+customer;
    
	 	   	 
    ret.first=whenVisitedTable.keyExists(temp);
    if (ret.first) 
    	{
   
    	ret.second=whenVisitedTable.find(temp);
    	}
	    
    // your code here! query your hash table for this function---should be short
    return ret;
}

vector<string> LogfileParser::uniquePages() {
    return uniqueURLs;
}
