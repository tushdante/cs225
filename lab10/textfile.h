/*
   Textfile Reading Interface (Lab 10)
   Created by Chase Geigle for CS225, Spring 2011
*/

#ifndef _TEXTFILE_H_
#define _TEXTFILE_H_

#include <fstream>
#include <string>
using std::ifstream;
using std::string;

class TextFile {
    public:
        TextFile( string filename );
        ~TextFile();
        bool good();
        string getNextWord();
    private:
        ifstream infile;
};
#endif
