#include "bst.h"
#include "gnuplot.h"
#include "seed.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>

#define SIZE_STEP 2000

// below is how many trees to generate for each of the three types
#define NUM_TREES 5

using std::cout;
using std::ios;
using std::endl;
using std::vector;
using std::random_shuffle;
using std::pair;
using std::sort;
using std::string;
using std::ofstream;

enum insert_type { increasing = 1, alternating, randm };

double get_time_ms() {
    timespec ts;
    clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &ts );
    return ts.tv_sec * 1000 + (double) ts.tv_nsec / 1000000;
}

double get_time_ns() {
    timespec ts;
    clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &ts );
    return ts.tv_sec * 1000000000 + (double) ts.tv_nsec;
}

pair< double, vector<int> > buildTree( BST<int, int> & tree, insert_type type, int size ) {
    double start_time;
    vector<int> vect;
    vect.resize(size);
    vector<int> last_four;
    int j;
    switch( type ) {
        case increasing:
            start_time = get_time_ms();
            for( int i = 0; i < size; i++ )
                tree.insert( i, i );
        break;

        case randm:
            for( int i = 0; i < size; i++ )
                vect[i] = i;

            random_shuffle( vect.begin(), vect.end() );
            last_four.resize(4);
            j = 0;

            start_time = get_time_ms();
            for( int i = 0; i < size; i++ ) {
                if( i > size - 5 )
                    last_four[j++] = vect[i];
                tree.insert( vect[i], vect[i] );
            }
        break;

        case alternating:
            for( int i = 0; i < size; i++ ) {
                if( i % 2 == 0 ) 
                    vect[i] = i/2;
                else
                    vect[i] = size - i/2 - 1;
            }

            start_time = get_time_ms();
            for( int i = 0; i < size; i++ )
                tree.insert( vect[i], vect[i] );
            break;
    }
    return pair< double, vector<int> >(get_time_ms() - start_time, last_four);
}

double findKeys( BST<int, int> const & tree, int size, int loopcount = 1) {
    double start_time = get_time_ms();
    for (int l = 0; l < loopcount; l++)
        for(int i = 0; i < size; i++ ) {
            int val = tree.find( i );
            assert( val == i );
        }
    return ( (get_time_ms() - start_time) / size ) / loopcount;
}

double keySort( BST<int, int> const & tree, int loopcount = 1000 ) {
    double avg = 0;
    for( int l = 0; l < loopcount; l++ ) {
        double start_time = get_time_ms();
        vector<int> vect = tree.keySort(); 
        double ret = get_time_ms() - start_time;

        vector<int> comp = vect;
        sort( vect.begin(), vect.end() );
        assert( vect == comp );
        avg += ret;
    }

    return avg / loopcount;
}

double levelOrder( BST<int, int> const & tree, int loopcount = 1000 ) {
    double start_time = get_time_ms();
    for( int l = 0; l < loopcount; l++ )
        tree.levelOrder();
    return ( get_time_ms() - start_time ) / loopcount;
}

void generateGraphs( Gnuplot const & g, string func ) {
    cout << endl << "Generating "+func+" graphs...";
    fflush( stdout );
    bool show_n2 = func == "buildTree";
    g.graph("Increasing Inserts: "+func, "ms", func+"Increasing.dat",
            func+"Increasing.png", show_n2, show_n2 );
    g.graph("Alternating Inserts: "+func, "ms", func+"Alternating.dat",
            func+"Alternating.png", show_n2, show_n2 );
    g.graph("Random Inserts: "+func, "ms", func+"Random.dat",
            func+"Random.png", false, show_n2 );
    cout << " Done." << endl;
}

void testRandomHeights( Gnuplot const & g ) {

    cout << "Building random trees..." << endl;

    ofstream outfile;
    outfile.open( "randomHeights.dat", ios::out | ios::trunc );

    int max_trees = 200;

    int size = SIZE_STEP*2;
    vector< BST<int, int> > trees;
    trees.resize(NUM_TREES*max_trees);
    int i = 0;
    for( int x = 0; x < NUM_TREES; x++ ) {
        cout << "Trees of size " << size << "... ";
        fflush(stdout);
        for( int j = 0; j < max_trees; j++ )
            buildTree( trees[i++], randm, size );
        size *= 2;
        cout << "Done." << endl;
    }

    i = 0;
    size = SIZE_STEP*2;
    for( int x = 0; x < NUM_TREES; x++ ) {
        cout << "Average height of size " << size << ": ";
        fflush(stdout);
        int avg = 0;
        for( int j = 0; j < max_trees; j++ )
            avg += trees[i++].height();
        avg = avg / max_trees;
        cout << avg << endl;
        outfile << size << " " << avg << endl;

        size *= 2;
    }
    outfile.close();

    cout << endl << "Generating graph... ";
    fflush(stdout);
    g.graph("Average Case Tree Height", "Height", "randomHeights.dat",
            "randomHeights.png", false, false);
    cout << "Done." << endl << endl;

}

void testBuildTree( vector< BST<int, int> > & trees, Gnuplot const & g ) {

    ofstream incFile;
    ofstream altFile;
    ofstream rndFile;

    incFile.open( "buildTreeIncreasing.dat", ios::out | ios::trunc );
    altFile.open( "buildTreeAlternating.dat", ios::out | ios::trunc );
    rndFile.open( "buildTreeRandom.dat", ios::out | ios::trunc );

    trees.resize(15);
    int i = 0;
    int size = SIZE_STEP;
    for( int x = 0; x < NUM_TREES; x++ ) {

        cout << endl;

        cout << "buildTree with strictly increasing inserts (" << size << "): ";
        fflush(stdout);
        pair< double, vector<int> > p = buildTree( trees[i++], increasing, size );
        cout << p.first << "ms" << endl;
        incFile << size << " " << p.first << endl;

        cout << "buildTree with alternating inserts (" << size << "): ";
        fflush(stdout);
        p = buildTree( trees[i++], alternating, size );
        cout << p.first << "ms" << endl;
        altFile << size << " " << p.first << endl;

        cout << "buildTree with random inserts (" << size << "): ";
        fflush(stdout);
        p = buildTree( trees[i++], randm, size );
        cout << p.first << "ms" << endl;
        rndFile << size << " " << p.first << endl;

        cout << "Last four inserts:";
        for( int j = 0; j < 4; j++ )
            cout << " " << p.second[j];
        cout << endl;

        size *= 2;

    }
    incFile.close();
    altFile.close();
    rndFile.close();

    generateGraphs( g, "buildTree" );
}

void testFindKeys( vector< BST<int, int> > const & trees, Gnuplot const & g ) {

    ofstream incFile;
    ofstream altFile;
    ofstream rndFile;

    incFile.open( "findIncreasing.dat", ios::out | ios::trunc );
    altFile.open( "findAlternating.dat", ios::out | ios::trunc );
    rndFile.open( "findRandom.dat", ios::out | ios::trunc );

    int i = 0;
    int size = SIZE_STEP;
    for( int x = 0; x < NUM_TREES; x++ ) {

        cout << endl;

        cout << "Find on strictly increasing inserts (" << size << "): ";
        fflush(stdout);
        double p = findKeys( trees[i++], size );
        cout << p << "ms (avg)" << endl;
        incFile << size << " " << p << endl;

        cout << "Find on alernating inserts (" << size << "): ";
        fflush(stdout);
        p = findKeys( trees[i++], size );
        cout << p << "ms (avg)" << endl;
        altFile << size << " " << p << endl;

        cout << "Find on random inserts (" << size << "): ";
        fflush(stdout);
        p = findKeys( trees[i++], size, 1000 );
        cout << p << "ms (avg)" << endl;
        rndFile << size << " " << p << endl;

        size *= 2;

    }
    incFile.close();
    altFile.close();
    rndFile.close();

    generateGraphs( g, "find" );
}

void testKeySort( vector< BST<int, int> > const & trees, Gnuplot const & g ) {

    ofstream incFile;
    ofstream altFile;
    ofstream rndFile;

    incFile.open( "keySortIncreasing.dat", ios::out | ios::trunc );
    altFile.open( "keySortAlternating.dat", ios::out | ios::trunc );
    rndFile.open( "keySortRandom.dat", ios::out | ios::trunc );

    int i = 0;
    int size = SIZE_STEP;
    for( int x = 0; x < NUM_TREES; x++ ) {

        cout << endl;

        cout << "keySort on strictly increasing inserts (" << size << "): ";
        fflush(stdout);
        double t = keySort( trees[i++] );
        cout << t << "ms" << endl;
        incFile << size << " " << t << endl;

        cout << "keySort on alternating inserts (" << size << "): ";
        fflush(stdout);
        t = keySort( trees[i++] );
        cout << t << "ms" << endl;
        altFile << size << " " << t << endl;

        cout << "keySort on random inserts (" << size << "): ";
        t = keySort( trees[i++] );
        cout << t << "ms" << endl;
        rndFile << size << " " << t << endl;

        size *= 2;

    }
    incFile.close();
    altFile.close();
    rndFile.close();

    generateGraphs( g, "keySort" );
}

void testLevelOrder( vector< BST<int, int> > const & trees, Gnuplot const & g ) {

    ofstream incFile;
    ofstream altFile;
    ofstream rndFile;

    incFile.open( "levelOrderIncreasing.dat", ios::out | ios::trunc );
    altFile.open( "levelOrderAlternating.dat", ios::out | ios::trunc );
    rndFile.open( "levelOrderRandom.dat", ios::out | ios::trunc );

    int i = 0;
    int size = SIZE_STEP;
    for( int x = 0; x < NUM_TREES; x++ ) {

        cout << endl;

        cout << "levelOrder on strictly increasing inserts (" << size << "): ";
        fflush(stdout);
        double t = levelOrder( trees[i++] );
        cout << t << "ms" << endl;
        incFile << size << " " << t << endl;

        cout << "levelOrder on alternating inserts (" << size << "): ";
        fflush(stdout);
        t = levelOrder( trees[i++] );
        cout << t << "ms" << endl;
        altFile << size << " " << t << endl;

        cout << "levelOrder on random inserts (" << size << "): ";
        t = levelOrder( trees[i++] );
        cout << t << "ms" << endl;
        rndFile << size << " " << t << endl;

        size *= 2;

    }
    incFile.close();
    altFile.close();
    rndFile.close();

    generateGraphs( g, "levelOrder" );
}

int main() {
    vector< BST<int, int> > trees;
    Gnuplot g;

    cout << "Begin running for " << get_netid() << endl;

    srand( getSeed() );

    cout << "Starting random tree height tests..." << endl;
    cout << "===========================" << endl;
    testRandomHeights( g );

    cout << "Starting buildTree tests..." << endl;
    cout << "===========================";
    testBuildTree( trees, g );

    cout << endl;
    cout << "Starting find tests..." << endl;
    cout << "===========================";
    testFindKeys( trees, g );

    cout << endl;
    cout << "Starting keySort tests..." << endl;
    cout << "===========================";
    testKeySort( trees, g );

    cout << endl;
    cout << "Starting levelOrder tests..." << endl;
    cout << "===========================";
    testLevelOrder( trees, g );

    cout << endl;

    return 0;
}
