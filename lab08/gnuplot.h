/*
   gnuplot interface (Lab 08)
   Kludged together by Chase Geigle for CS225, Spring 2011
*/
#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <stdio.h>
#include <stdlib.h>

#include <string>
using std::string;

class Gnuplot {
    public:
        Gnuplot();
        ~Gnuplot();
        void graph( string title, string units, string data_file, string
                output_file, bool show_n2 = false, bool show_nlgn = false ) const;

    private:
        FILE * pipe;
        void cmd( string cmd ) const;
};
#endif
