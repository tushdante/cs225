/**
 * main.cpp
 *
 * PhotoMosaic main function. Provides control flow for Mosaic generation.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */
#include "imagereader.h"
#include "photomosaic.h"
#include <iostream>

using namespace std;

/**
 * Entry-point to the application
 *
 * @param argc Number of command-line arguments
 * @param argv The array of command-line arguments
 */
int main(int argc, char* argv[])
{
    Magick::InitializeMagick(NULL);//added by j.e. because new version of im requires init

    PhotoMosaic pm;

    if (pm.parse_cli(argc, argv) < 0) {
        pm.print_usage();
        return -1;
    }

    if (pm.generate_photomosaic() < 0)
        return -1;

    return 0;
}
