/**********************************************************
  h_chan_test.cpp - a simple test file for mp3.1
    Devised from test cases posted by Henry Chan on
        the newsgroup.
 
    Compiled together into C++ code by Chase Geigle
        who thinks his code here is horribly ugly but
        functional.
  Date: September 21, 2010
**********************************************************/
 
#include "doubly-linked-list.h"
 
using std::cout;
using std::endl;
 
int main() {
    List<int> list;
    List<int> list2;
    List<int> list3;
 
    list.clear();
    list2.clear();
    for( int i = 1; i < 4; i++ )
        list2.insertAfter(i);
 
    cout << "testing append <> to <1,2,3>" << endl;
    list.appendList(list2);
    cout << "this:";
    list.print();
    cout << endl << "endList:";
    list2.print();
    cout << endl;
 
    cout << "testing append <1,2,3> to <>" << endl;
    list2.appendList(list);
    cout << "this:";
    list2.print();
    cout << endl << "endList:";
    list.print();
    cout << endl;
 
    list2.clear();
    list.clear();
    cout << "testing append <> to <>" << endl;
    list.appendList(list2);
    cout << "this:";
    list.print();
    cout << endl << "endList:";
    list2.print();
    cout << endl;
 
    list.clear();
    list2.clear();
    for( int i = 1; i < 6; i++ )
        list.insertAfter(i);
 
    for( int i = 6; i < 9; i++ )
        list2.insertAfter(i);
 
    cout << "testing mix <1,2,3,4,5> with <6,7,8>" << endl;
    list.mixList(list2);
    cout << "this:";
    list.print();
    cout << endl << "secList:";
    list2.print();
    cout << endl;
 
    list.clear();
    list2.clear();
    for( int i = 1; i < 4; i++ )
        list.insertAfter(i);
    list3 = list;
 
    for( int i = 4; i < 9; i++ )
        list2.insertAfter(i);
 
    cout << "testing mix <1,2,3> with <4,5,6,7,8>" << endl;
    list.mixList(list2);
    cout << "this:";
    list.print();
    cout << endl << "secList:";
    list2.print();
    cout << endl;
 
 
    cout << "testing mix <> with <1,2,3>" << endl;
    list.clear();
    list.mixList(list3);
    cout << "this:";
    list.print();
    cout << endl << "secList:";
    list3.print();
    cout << endl;
 
 
    cout << "testing mix <1,2,3> with <>" << endl;
    list3.clear();
    list.mixList(list3);
    cout << "this:";
    list.print();
    cout << endl << "secList:";
    list3.print();
    cout << endl;
 
    list.clear();
    list3.clear();
    cout << "testing mix <> with <>" << endl;
    list.mixList(list3);
    cout << "this:";
    list.print();
    cout << endl << "secList:";
    list3.print();
    cout << endl;
 
    list.clear();
    for( int i = 1; i < 4; i++ )
        list.insertAfter(i);
 
    cout << "testing splitList with <1,2,3> and rank=5" << endl;
 
    list2 = list.splitList(5);
    cout << "this:";
    list.print();
    cout << endl << "returned list:";
    list2.print();
    cout << endl;
 
    cout << "testing splitList with <1,2,3> and rank = 3" << endl;
    list2 = list.splitList(3);
    cout << "this:";
    list.print();
    cout << endl << "returned list:";
    list2.print();
    cout << endl;
 
    list.clear();
    for( int i = 1; i < 4; i++ )
        list.insertAfter(i);
 
    cout << "testing splitList with <1,2,3> and rank = 1" << endl;
    list2 = list.splitList(1);
    cout << "this:";
    list.print();
    cout << endl << "returned list:";
    list2.print();
    cout << endl;
 
}
