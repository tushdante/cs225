/*
   gnuplot interface
   Kludged together by Chase Geigle for CS225, Spring 2011
*/

#include "gnuplot.h"

Gnuplot::Gnuplot() {
    pipe = popen( "gnuplot -persist > /dev/null 2>&1", "w" );
    cmd("set terminal png");
    cmd("f(x) = a1*x**2+b1*x+c1");
    cmd("g(x) = a2*x+b2");
    cmd("h(x) = a3*(log10(x)/log10(2))+b3");
    cmd("k(x) = a4*x*(log10(x)/log10(2))+b4*x+c4");
}

Gnuplot::~Gnuplot() {
    pclose( pipe );
}

void Gnuplot::cmd( string cmd ) const {
    fputs( (cmd+"\n").c_str(), pipe );
    fflush( pipe );
}

void Gnuplot::graph( string title, string units, string data_file, string
        output_file, bool show_n2, bool show_nlgn ) const {
    // this is terribad, don't do it ever. hack for time.
    data_file = "\"" + data_file + "\"";
    output_file = "\"" + output_file + "\"";

    string fx = "";
    string kx = "";
    string bound = "[] [0:]";
    if( show_n2 )
        fx = "f(x) title \"O(n^2)\", ";

    if( show_nlgn )
        kx = ", k(x) title \"O(n lg(n))\"";

    cmd("set output "+ output_file);
    cmd("fit f(x) "+ data_file +" using 1:2 via a1, b1, c1");
    cmd("fit g(x) "+ data_file +" using 1:2 via a2, b2");
    cmd("fit h(x) "+ data_file +" using 1:2 via a3, b3");
    cmd("fit k(x) "+ data_file +" using 1:2 via a4, b4, c4");
    cmd("set title \""+title+"\"");
    cmd("set xlabel \"Size\"");
    cmd("set ylabel \""+units+"\"");
    string cmd_string = "plot "+ data_file +" title \"Data\", "
        + fx
        + "g(x) title \"O(n)\", "
        + "h(x) title \"O(lg(n))\""
        + kx;
    cmd(cmd_string);
}
