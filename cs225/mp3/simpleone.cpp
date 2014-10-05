/**********************************************************
  simpletestpartone.cpp - a simple test case file for mp3.1
    Just does some simple functions from the first part of
        the MP to test your mp3.1 functionality in a more
        immediately obvious manner than the image testing.
  Date: September 20, 2010
**********************************************************/
 
#include "doubly-linked-list.h"
 
using std::cout;
using std::endl;
 
int main() {
 
    // Using arrays initially for ease of debugging on your
    // part. You know how these work, so understanding why
    // the output should be what it is should be easier.
    // Go ahead and ask on the newsgroup if you need an
    // explanation from me though.
 
    int x[5] = {1,2,3,4,5};
    int y[7] = {6,7,8,9,10,11,12};
 
    // Set up our lists.
    List<int> list;
    List<int> list2;
    List<int> list3;
    List<int> list4;
 
    list.clear();
 
    for( int i = 0; i < 5; i++ )
        list.insertAfter(x[i]);
 
    for( int j = 0; j < 7; j++ )
        list2.insertAfter(y[j]);
 
    // Test your appendList function
 
    list.appendList(list2);
 
    cout << "printing values for appendList:" << endl;
    cout << "list: ";
    list.print();
 
    cout << endl << "size is:" << list.length();
    cout << endl;
 
    cout << "list2: ";
    list2.print();
    cout << endl << "size is:" << list2.length() << endl;
 
    // Test your splitList function
 
    list3 = list.splitList(6);
 
    cout << "printing values for splitList:" << endl;
    list.print();
    cout << endl;
    list3.print();
    cout << endl;
 
    // Test your mixList function
 
    list2 = list;
    list4 = list3;
 
    list.mixList(list3);
    cout << "printing values for mixList:" << endl;
    list.print();
    cout << endl << "size is:" << list.length() << endl;
    list3.print();
    cout << endl << "size is:" << list3.length() << endl;
 
 
    // Test your mixList function again
 
    list4.mixList(list2);
    cout << "printing values for mixList 2:" << endl;
    list4.print();
    cout << endl << "size is:" << list4.length() << endl;
    list2.print();
    cout << endl << "size is:" << list2.length() << endl;
 
 
    // yeah yeah I know I should have function-ized this...
}
