/*
   Textfile Reading Interface (Lab 10)
   Created by Chase Geigle for CS255, Spring 2011
*/

#include "textfile.h"

TextFile::TextFile( string filename ) : infile( filename.c_str() ) {
    /* nothing */
}

TextFile::~TextFile() {
    if( infile.is_open() )
        infile.close();
}

bool TextFile::good() {
    return infile.good();
}

string TextFile::getNextWord() {
    string nword = "";
    infile >> nword;

    string bad = ".,!?;:-_[]*/\\'\"`{}()<>&\n\t\r";

    string word = "";
    for( int i = 0; i < nword.length(); i++ ) {
        if( bad.find( nword[i] ) == string::npos )
            word += tolower( nword[i] );
    }
    return word;
}
