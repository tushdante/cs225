/**
 * photomosaic.cpp
 *
 * High-level PhotoMosaic class that provides the highest abstraction over the
 * steps needed to generate a mosaic.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#include "photomosaic.h"

#include <iostream>

#include <pwd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "imagereader.h"
#include "kdtilemapper.h"

using namespace std;

/**
 * Default constructor
 */
PhotoMosaic::PhotoMosaic() 
    : inputFileName(""), outputFileName(""), 
    resolution(DEFAULT_RESOLUTION), dimensionScale(1.0), plugin(NULL) {
        // Nothing to do here
    }

/**
 * Parse command-line input.  Iterate through the parameters
 * passed into the main function, and initialize members accordingly.
 * Extra or unknown command-line options are passed to the correct
 * Plugin interface before being discards and invoking an error.
 *
 * @param argc Number of parameters
 * @param argv Input from the commandline
 *
 * @return 0 on success, or non-zero otherwise
 */
int PhotoMosaic::parse_cli(int argc, char* argv[]) {
#ifdef PHOTOMOSAIC_DEBUG
    cout << "argc = " << argc << endl;
    cout << "argv = " << endl;
    for (int i = 0; i < argc; i++)
        cout << "\t[" << i << "] " << argv[i] << endl;
#endif

    int c = 0, option_index = 0;
    int plugin_optidx = -1;

    // Struct containing options to be parsed
    static struct option long_options[] =
    {
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {"resolution", required_argument, 0, 'r'},
        {"scale", required_argument, 0, 'x'},
        {"plugin", required_argument, 0, 'p'},
        {0, 0, 0, 0}
    };

    // Don't output error messages
    opterr = 0;

    bool foundUnknown = false;
    while(!foundUnknown){
        option_index = 0;

        // Obtain the next argument
        c = getopt_long(argc, argv, "", long_options, &option_index);

        if (c == -1) {
            // No more known-options
#ifdef PHOTOMOSAIC_DEBUG
            cout << "Ran out of known-options, optind = " << optind << endl;
#endif
            plugin_optidx = optind;
            break;
        }

        switch(c){
            case 'i' : // input
                if (parse_input_arg(optarg) < 0) {
                    cout << "Error reading input file argument" << endl;
                    return -1;
                }
                break;

            case 'o' : // output
                if (parse_output_arg(optarg) < 0) {
                    cout << "Error reading output file argument" << endl;
                    return -1;
                }
                break;

            case 'r' : // resolution
                if (parse_resolution_arg(optarg) < 0) {
                    cout << "Error reading resolution argument" << endl;
                    return -1;
                }
                break;

            case 'x' : // scale
                if (parse_scale_arg(optarg) < 0) {
                    cout << "Error reading scale argument" << endl;
                    return -1;
                }
                break;

            case 'p' : // plugin
                if (parse_plugin_arg(optarg) < 0) {
                    cout << "Error reading plugin argument" << endl;
                    return -1;
                }
                break;

            case '?' : // signals an unknown parameter
#ifdef PHOTOMOSAIC_DEBUG
                cout << "Unknown parameter, optind = " << optind << endl;
#endif
                plugin_optidx = optind -1;
                foundUnknown = true;
                break;

            default : // should never get here
#ifdef PHOTOMOSAIC_DEBUG
                cout << "Default case ??" << endl;
#endif
                return -1;
        }

    }

#ifdef PHOTOMOSAIC_DEBUG
    cout << "Done parsing photomosaic parameters" << endl;
#endif

    // Make sure our input and output filenames have been set
    if (inputFileName == "") {
        cout << "Error: an input file must be specified via the '--input' parameter" << endl;
        return -1;
    }
    if (outputFileName == "") {
        cout << "Error: an output file must be specified via the '--output' parameter" << endl;
        return -1;
    }
    // Make sure a plugin has been set
    if (plugin == NULL) {
        cout << "Error: a plugin must be speficied via the '--plugin' parameter," << endl;
        cout << "       either 'flickr' or 'local'" << endl;
        return -1;
    }

    // Construct parameters to send to the Plugin
    int plugin_argc = argc - plugin_optidx + 1;
    char* plugin_argv[plugin_argc];
    plugin_argv[0] = argv[0];
    for (int i = 1; i < plugin_argc; i++)
        plugin_argv[i] = argv[plugin_optidx + i -1];
#ifdef PHOTOMOSAIC_DEBUG
    cout << "plugin_argc = " << plugin_argc << endl;
    cout << "plugin_argv = " << endl;
    for (int i = 0; i < plugin_argc; i++)
        cout << "\t[" << i << "] " << plugin_argv[i] << endl;
#endif

    if (plugin->init(plugin_argc, plugin_argv) < 0) {
        cout << "Error parsing commandline parameters" << endl;
        return -1;
    }

    return 0;
}

/**
 * Print a usage statement for the program.  This will print
 * all of the accepted CLI parameters, as well as a description
 * of how they function.  This should even print options for
 * each of the supported plugins
 */
void PhotoMosaic::print_usage() {
    cout << "Usage: photomosaic [options] [plugin-options]"     << endl;
    cout                                << endl;
    cout << "Options:"                        << endl;
    cout << "\t--input=FILE\t\tThe image to create a mosaic of"    << endl;
    cout << "\t--output=FILE\t\tThe file to save the mosaic to"    << endl;
    cout << "\t--resolution=X\t\tResolution of mosaic tiles"    << endl;
    cout << "\t\t\t\t[default=" << DEFAULT_RESOLUTION << "]"    << endl;
    cout << "\t--scale=X\t\tScale factor for mosaic dimensions"    << endl;
    cout << "\t\t\t\t[default=" << DEFAULT_SCALE << "]"        << endl;
    cout << "\t--plugin=TYPE\t\tThe image plugin to use,"        << endl;
    cout <<                "\t\t\t\teither 'flickr' or 'local'"    << endl;
    cout                                << endl;
    cout << "Flickr Options:"                    << endl;
    Flickr f; f.print_usage();
    cout                                << endl;
    cout << "Local Options:"                    << endl;
    Local l; l.print_usage();
    cout                                << endl;
    cout << "Examples:"                        << endl;
    cout << "\tMake a mosaic from an image called 'mydog.png', using a Flickr" << endl;
    cout << "\tsearch for 'dogs', and save the result as 'dogmosaic.jpg'" << endl;
    cout << "\t\tphotomosaic --input=mydog.png --output=dogmosaic.jpg --plugin=flickr --search=dogs" << endl;
    cout                                << endl;
    cout << "\tMake a mosaic from an image called 'mycat.gif', using image inside" << endl;
    cout << "\tdirectory '/home/user/pics', and save the result as 'catmosaic.tiff'" << endl;
    cout << "\t\tphotomosaic --input=mycat.gif --output=catmosaic.tiff --plugin=local --folder=/home/user/pics" << endl;
}

/**
 * Generate a photomosaic.  Use the options passed in and the
 * helper classes provided to create a mosaic.  This is the
 * main worker method of the photomosaic class, which brings
 * together all of other actual pieces of the application.
 *
 * @return 0 on success, or non-zero otherwise
 */
int PhotoMosaic::generate_photomosaic() {
    SourceImage source;
    ImageReader ir;
    if (ir.read_source_image(inputFileName, source, resolution) < 0) {
        cout << "Error opening input image: " << inputFileName << endl;
        return -1;
    }

    cout << "Gathering mosaic tile images" << endl;
    list<string> tilePaths;
    if (plugin->gather_images(tilePaths) < 0) {
        cout << "Error gathering mosaic tiles" << endl;
        return -1;
    }

    vector<TileImage> tiles;
    TileImage tile;
    list<string>::const_iterator i;
    int tileNum = 0;
    for (i = tilePaths.begin(); i != tilePaths.end(); i++) {
        if (tileNum % 50 == 0)
            cout << "\tFetching images (" << tileNum << "/"
                << tilePaths.size() << ")" << endl;
        if (ir.read_tile_image(*i, tile) < 0) {
            cout << "\t\tWarning: could not open image: " << *i
                << ", skipping" << endl;
        } else {
            tiles.push_back(tile);
        }
        tileNum++;
    }

    cout << "Constructing the mosaic" << endl;
    KDTileMapper mapper = KDTileMapper(source, tiles);
    MosaicCanvas* canvas;
    canvas = mapper.map_tiles();
    if (canvas == NULL) {
        cout << "Error constructing mosaic" << endl;
        return -1;
    }

    cout << "Stitching the mosaic" << endl;
    int width = (int)((float)source.get_width() * dimensionScale);
    int height = (int)((float)source.get_height() * dimensionScale);
    if (canvas->save_mosaic(width, height, outputFileName, true) != 0) {
        cout << "Error saving the mosaic to file: " << outputFileName << endl;
        return -1;
    }

    delete canvas;
    canvas = NULL;

    return 0;
}

/**
 * Destructor
 */
PhotoMosaic::~PhotoMosaic() {
    destruct();
}

/**
 * Copy constructor
 *
 * @param source PhotoMosaic object to copy
 */
PhotoMosaic::PhotoMosaic(const PhotoMosaic& source) {
    copy(source);
}

/**
 * Assignment operator
 *
 * @param source PhotoMosaic object to copy
 */
const PhotoMosaic& PhotoMosaic::operator=(const PhotoMosaic& source) {
    if(this != &source){
        destruct();
        copy(source);
    }

    return *this;
}

/**
 * Parse the command-line option for 'plugin'
 *
 * @arg option The option to parse
 *
 * @return 0 on success, or non-zero otherwise
 */
int PhotoMosaic::parse_plugin_arg(const char *option) {

#ifdef PHOTOMOSAIC_DEBUG
    cout << "Parsing plugin arg: " << option << endl;
#endif

    if ( strcmp("flickr", option) == 0) {
        plugin = new Flickr();

    } else if ( strcmp("local", option) == 0) {
        plugin = new Local();

    } else {
        return -1;
    }

    return 0;
}

/**
 * Parse the command-line option for 'input'
 *
 * @arg option The option to parse
 *
 * @return 0 on success, or non-zero otherwise
 */
int PhotoMosaic::parse_input_arg(const char *option) {

    inputFileName = string(option);
    if (parse_home_dir(inputFileName) < 0)
        return -1;

    return 0;
}

/**
 * Parse the command-line option for 'output'
 *
 * @arg option The option to parse
 *
 * @return 0 on success, or non-zero otherwise
 */
int PhotoMosaic::parse_output_arg(const char *option) {

    outputFileName = string(option);
    if (parse_home_dir(outputFileName) < 0)
        return -1;

    return 0;
}

/**
 * Parse the command-line option for 'resolution'
 *
 * @arg option The option to parse
 *
 * @return 0 on success, or non-zero otherwise
 */
int PhotoMosaic::parse_resolution_arg(const char *option) {
    int newRes = strtol(option, NULL, 10);
    if (newRes <= 0)
        return -1;
    resolution = newRes;
    return 0;
}

/**
 * Parse the command-line option for 'scale'
 *
 * @arg option The option to parse
 *
 * @return 0 on success, or non-zero otherwise
 */
int PhotoMosaic::parse_scale_arg(const char *option) {
    double newScale = strtod(option, NULL);
    if (newScale <= 0)
        return -1;
    dimensionScale = newScale;
    return 0;
}

/**
 * Cleans up dynamically allocated memory
 */
void PhotoMosaic::destruct()
{
    if (plugin != NULL)
        delete plugin;
}

/**
 * Performs a deep copy of source into this
 *
 * @param source The source PhotoMosaic object to copy.
 */
void PhotoMosaic::copy(const PhotoMosaic& source) {
    inputFileName = source.inputFileName;
    outputFileName = source.outputFileName;
    resolution = source.resolution;
    dimensionScale = source.dimensionScale;
    *plugin = *(source.plugin);
}

/**
 * Parse home directory names starting with ~,
 * since opendir doesn't handle it correctly.
 * The new string will be stored in the safe reference
 * to dirString
 *
 * @param dirString A directory string, presumably
 * beginning with a tilda
 *
 * @return 0 on success, or non-zero otherwise
 */
int PhotoMosaic::parse_home_dir(string& dirString) const {
    if ((dirString.length() == 0) || (dirString[0] != '~'))
        // Nothing to do
        return 0;

    if((dirString.length() == 1) || (dirString[1] == '/')) {
        // user's home directory
        string home(getenv("HOME"));

        // print starting after tilda
        if (dirString.length() > 1)
            home += dirString.substr(1);

        dirString = home;
        return 0;
    }

    // else, Another user's home directory
    string userName;
    int i;
    for (i = 1; i < (int)dirString.length() && dirString[i] != '/'; i++)
        userName += dirString[i];


    // Get user information from the passwd file
    struct passwd *pw;
    setpwent();
    while((pw = getpwent()) != NULL) {
        if(strcmp(pw->pw_name, userName.c_str()) == 0) {
            string newDir(pw->pw_dir);

            // print starting after tilda
            if (i < (int)dirString.length())
                newDir += dirString.substr(i);
            dirString = newDir;
            endpwent();
            return 0;
        }
    }

    // If we get here, we couldn't find the usename
    endpwent();
    return -1;
}
