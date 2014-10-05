/*
   Heap Testing Code (Lab 11)
   Created by Jack Toole for CS225, Fall 2011
    - Updated (Gnuplot) by Chase Geigle, Spring 2011
*/
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <time.h>
#include <utility>
#include "minheap.h"
#include "heapsort.h"
#include "verify.h"
#include "gnuplot.h"

using namespace std;

double timeHeap(const vector<int> & input, bool fast, int times = 1000);
double getTime();
unsigned int getTimeSeed();
void testCompileOnly();
void runTimeHeap( bool wc = true );

int main(int argc, const char ** argv)
{
    cout << endl;
    bool netid = (argc < 2);
    bool testonly = false;
    unsigned int seed;

    // Get random seed
    if (netid)
    {
        cout << "Running for " << getNetid() << endl;
        seed = getSeed();
    }
    else if (tolower(argv[1][0]) == 't')
    {
        testonly = true;
        seed = getTimeSeed();
    }
    else if (tolower(argv[1][0]) == 'r')
        seed = getTimeSeed();
    else
    {
        testonly = true;
        seed = atoi(argv[1]);
    }

    // Heap verification variables
    MinHeap<int> myHeap;
    Verifier verify(seed);
    srand(seed);

    int count    = 50;
    int inserts  = 0;
    int removals = 0;

    cout << "Testing heapifyDown..." << endl;
    if (netid) cout << "Removals:";
    else cout << "Seed " << seed;

    // Verify the heap's correctness
    while (removals < count)
    {
        // Randomly choose insertion/removal
        if (myHeap.isEmpty() || rand() % 2 != 0)
        {
            myHeap.insert(rand() % 50);
            inserts++;
        }
        else
        {
            int myItem   = myHeap.removeMin();
            removals++;

            // Dump failure information
            if (verify(myItem) == false)
            {
                cout << endl << "Failed on " << removals << "th removal:"
                    " returned incorrect " << myItem << endl;

                cout << "Heap: ";
                myHeap.print();
                cout << endl << endl;

                return removals;
            }
            else if (netid)
                cout << ' ' << myItem;
        }
    }

    cout << endl << "Passed" << endl << endl;

    // Verify buildheap
    cout << "Testing buildheap constructor..." << endl;
    vector<int> randoms;
    randoms.resize(100);
    for (unsigned int i = 0; i < randoms.size(); i++)
        randoms[i] = rand() % randoms.size();

    MinHeap<int> slowBuildHeap(randoms, false);
    MinHeap<int> fastBuildHeap(randoms, true );
    sort(randoms.begin(), randoms.end());

    for (unsigned int i = 0; i < randoms.size(); i++)
    {
        if (randoms[i] != slowBuildHeap.removeMin() ||
                randoms[i] != fastBuildHeap.removeMin() )
        {
            cout << "Failed on " << i << "th removal. "
                "expected " << randoms[i] << endl;
            return i;
        }
    }

    cout << "Passed" << endl << endl;


    if (!testonly)
    {
        // Measure buildheap running time
        cout << "Running buildheap on worst case input..." << endl;
        runTimeHeap();
        cout << "Running buildHeap on random input..." << endl;
        runTimeHeap(false);
    }


    // Verify heapsort
    cout << "Testing heapSort..." << endl;

    for (int length = 5; length <= 120; length *= 2)
    {

        randoms.resize(length);
        for (unsigned int i = 0; i < randoms.size(); i++)
            randoms[i] = rand() % randoms.size();
        vector<int> solution = randoms;
        vector<int> hsorted  = randoms;

        sort(solution.begin(), solution.end());
        heapSort(hsorted);

        if (hsorted != solution)
        {
            cout << "Failed" << endl;

            cout << "Input Array:  [ ";
            for (unsigned int i = 0; i < randoms.size(); i++)
                cout << randoms[i] << ' ';
            cout << ']' << endl << endl;

            cout << "Sorted Array: [ ";
            for (unsigned int i = 0; i < hsorted.size(); i++)
                cout << hsorted[i] << ' ';
            cout << ']' << endl << endl;

            return -1;
        }
    }

    cout << "Passed" << endl << endl;

    testCompileOnly();

    return 0;
}

void runTimeHeap( bool wc ) {
    double small1Time;
    double small2Time;
    double large1Time;
    double large2Time;
    ofstream outfile1;
    ofstream outfile2;
    if( wc ) {
        outfile1.open( "n_inserts_wc.dat", ios::out | ios::trunc );
        outfile2.open( "buildheap_wc.dat", ios::out | ios::trunc );
    }
    for( int s = 500; s <= 500 << 9; s *= 2) {
        vector<int> randoms;
        randoms.resize(s);
        for (unsigned int i = 0; i < randoms.size(); i++)
            randoms[i] = ( wc ) ? randoms.size() - i : rand() % randoms.size();

        int times = 10000;
        if( s >= 128000 )
            times = 1;
        else if( s >= 64000 )
            times = 10;
        else if( s >= 16000 )
            times = 100;
        else if( s >= 2000 )
            times = 1000;
        double time1 = timeHeap(randoms, false, times);
        double time2 = timeHeap(randoms, true, times);
        cout << endl;

        if( wc ) {
            outfile1 << s << " " << time1 << endl;
            outfile2 << s << " " << time2 << endl;
        }

        if( s == 500 ) {
            small1Time = time1;
            small2Time = time2;
        } else if( s == 1000 ) {
            large1Time = time1;
            large2Time = time2;
        }

    }
    cout << "N inserts ratio (size 1000 over size 500): " << large1Time/small1Time << endl;
    cout << "BuildHeap ratio (size 1000 over size 500): " << large2Time/small2Time << endl << endl;

    if( wc ) {
        outfile1.close();
        outfile2.close();

        Gnuplot g;
        cout << "Drawing graphs...";
        fflush(stdout);

        g.graph( "N Inserts (worst case)", "ms", "n_inserts_wc.dat",
                "n_inserts_wc.png", false, true );

        g.graph( "BuildHeap (worst case)", "ms", "buildheap_wc.dat",
                "buildheap_wc.png", false, true );

        cout << "Done." << endl << endl;
    }
}



double timeHeap(const vector<int> & input, bool fast, int times)
{
    double startTime  = getTime();
    for (int i = 0; i < times; i++)
        MinHeap<int> large2(input, fast);
    double diffTime = (getTime() - startTime) / times;
    cout << (fast?"Buildheap":"N inserts") << " on size " << input.size() <<
        " input: " << diffTime<< "ms" << endl;
    return diffTime;
}


double getTime()
{
    timespec ts;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return ts.tv_sec * 1000 + (double) ts.tv_nsec / 1000000;
}

unsigned int getTimeSeed()
{
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec ^ ts.tv_nsec;
}


typedef struct you_used_a_value_instead_of_an_index
{
    int a;
    you_used_a_value_instead_of_an_index()      { a = 0; }
    you_used_a_value_instead_of_an_index(int b) { a = b; }
    bool operator<(const you_used_a_value_instead_of_an_index & other) const
    { return a < other.a; }
} cTestStruct;
using namespace std::rel_ops;

void testCompileOnly()
{
    vector<cTestStruct> input;
    input.push_back(cTestStruct(1));
    input.push_back(cTestStruct(0));
    input.push_back(cTestStruct(2));
    MinHeap<cTestStruct> testDouble(input, true);
    testDouble.removeMin();
    MinHeap<cTestStruct> testDoubleS(input, false);
    testDouble.removeMin();
}
