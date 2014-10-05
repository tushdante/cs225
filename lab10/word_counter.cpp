/*
   Word Frequency Counter (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#include "word_counter.h"
#include "letter_hash.h"

WordFreq::WordFreq( string infile ) : filename(infile) { /* nothing */ }

vector< pair<string, int> > WordFreq::getWords( int threshold ) {
    vector< pair<string, int> > ret;

    // note: see char_counter.cpp if you're having trouble.
    TextFile infile( filename );
    StringHash hasher;


    int length = filename.length();
    int words = 1;                          
	 int freq = 1;  	

    for (int size = 0; size < length ; size++)
   	 if (filename[size] == ' ' && filename[size-1] != ' ') words++;

    SCHashTable<string, int> hashTable( words , hasher);

    while( infile.good() ) {
        string word = infile.getNextWord();
               
        if( hashTable.keyExists( word ) )
				{		
				freq = hashTable.find( word ); 
   	      hashTable.remove( word );
	         hashTable.insert( word, freq + 1 );
				}
		  else
		  		{
		  		hashTable.insert( word, 1);
		  		}
    }
    vector< pair<string, int> > vect = hashTable.vectorize();
	 pair<string,int> p;
	 
    for( unsigned int i = 0; i < vect.size(); i++ ) 
    {
        if( vect[i].second >= threshold )
        	{
        	p = make_pair( vect[i].first , vect[i].second );
         ret.push_back(p);
         }
    }
   
    return ret;
}
