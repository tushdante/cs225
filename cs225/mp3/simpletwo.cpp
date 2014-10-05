/**********************************************************
  simpletwo.cpp - a simple test case file for mp3.2
    Just does some simple functions from the first part of
        the MP to test your mp3.2 functionality in a more
        immediately obvious manner than the iamge testing.
  Date: September 23, 2010
  Author: Chase Geigle
**********************************************************/

#include "doubly-linked-list.h"
#include <sstream>

using std::cout;
using std::endl;
using std::stringstream;

// perpares the argument list with the numbers 1-11 linked.
void prepList( List<int> & list ) {
    list.clear();
    for( int i = 1; i <= 11; i++ )
        list.insertAfter(i);
}

// inelegantly prints the parameter list backwards.
void printBack( List<int> & list ) {
    cout << "printing list backwards (lots of warnings may ensue):" << endl;
    int size = list.length();
    if( size != 0 )
        list.back();
    stringstream out;
    out << "< ";
    if( size != 0 ) {
        for( int i = 0; i < size; i++ ) {
            int x = list.retrieve();
            out << x <<  " ";
            if( i != size-1 )
                list.backwardOne();
        }
    } else
        out <<  "empty list ";
    out << ">";
    cout << out.str() << endl;
}

int main() {

    List<int> list;
    prepList(list);

    list.print();
    cout << endl << "running removeNth with N=2 and blockSize=3:" << endl;
    list.removeNth(2,3);
    list.print();
    cout << endl << "length: " <<  list.length() << endl;
    printBack(list);

    prepList(list);
    list.print();
    cout << endl << "running removeNth with N=1 and blockSize=3:" << endl;
    list.removeNth(1,3);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    prepList(list);
    list.print();
    cout << endl << "running removeNth with N=2 and blockSize=11:"<< endl;
    list.removeNth(2,11);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    prepList(list);
    list.print();
    cout << endl << "running removeNth with N=2 and blockSize=2:" << endl;
    list.removeNth(2,2);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    list.clear();
    list.print();
    cout << endl << "running removeNth with N=2 and blocksize=2:" << endl;
    list.removeNth(2,2);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    prepList(list);
    list.insertAfter(12);
    list.print();
    cout << endl << "running removeNth with N=2 and blocksize=2" << endl;
    list.removeNth(2,2);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    prepList(list);
    list.insertAfter(12);
    list.print();
    cout << endl << "running removeNth with N=4 and blocksize=2" << endl;
    list.removeNth(4,2);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);


    prepList(list);
    list.print();
    cout << endl << "running tripleRotate with blockSize=2" << endl;
    list.tripleRotate(2);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    prepList(list);
    list.insertAfter(12);
    list.print();
    cout << endl << "running tripleRotate with blockSize=2" << endl;
    list.tripleRotate(2);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    prepList(list);
    list.print();
    cout << endl << "running tripleRotate with blockSize=12" << endl;
    list.tripleRotate(12);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    prepList(list);
    list.insertAfter(12);
    list.print();
    cout << endl << "running tripleRotate with blockSize=3" << endl;
    list.tripleRotate(3);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    list.clear();
    list.print();
    cout << endl << "running tripleRotate with blockSize=1" << endl;
    list.tripleRotate(1);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

    prepList(list);
    list.print();
    cout << endl << "running tripleRotate with blockSize=1" << endl;
    list.tripleRotate(1);
    list.print();
    cout << endl << "length: " << list.length() << endl;
    printBack(list);

}
