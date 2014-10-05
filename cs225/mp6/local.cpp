/**
 * local.cpp
 *
 * Subclasses the Plugin class to allow for a local directory of source images.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#include "local.h"
#include <iostream>
#include <dirent.h>
#include <getopt.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>

using namespace std;

/**
 * Default constructor
 */
Local::Local()  {
	sourceDirectory = "";
}

/**
 * Print a usage statement for the Local.  This will print
 * all of the accepted CLI parameters, as well as a description
 * of how they function.  
 */
void Local::print_usage() {
	cout << "\t--folder=DIR\t\tFolder to look for images in" << endl;
}

/**
 * Initialize the plugin with parameters from the command-line
 *
 * @param argc Number of command-line arguments
 * @param argv The array of command-line arguments
 *
 * @return 0 on success, or non-zero otherwise
 */
int Local::init(int argc, char * const *argv) {
	if(parse_local_params(argc, argv) == 1) {
		return -1;
	}

	return 0;
}

/**
 * Gather images from the local directory.  This is
 * the main worker function and public interface of
 * the plugin.
 *
 * @param imgBuf Buffer to fill with image paths
 *
 * @return The number of images found, or -1 on failure
 */
int Local::gather_images(list<string> & imgBuf) const {
	string dir(sourceDirectory);

	// Make sure we don't have a home dir "~" path
	if (parse_home_dir(dir) < 0) {
		cerr << "Error reading source directory '" << 
			sourceDirectory << "'" << endl;
		return -1;
	}

	// Open the directory, check for errors
	DIR* source_dir = opendir(dir.c_str());
	if(source_dir == NULL){
		cerr << "Error reading source directory '" << 
			dir << "'" << endl;
		return -1;
	}

	struct dirent* dent;
	string name;
	// Read the directory contents, pushing into imgBuf if
	// not '.', '..', or '.svn'.
	while((dent = readdir(source_dir))){
		name = dent->d_name;
		if(name != "." && name!= ".." && name != ".svn"){
			imgBuf.push_back(dir + "/" + name);
		}
	}

	closedir(source_dir);

	return imgBuf.size();
}

/**
 * Helper function for init.  Parse local parameters
 *
 * @param argc The number of command-line arguments
 * @param argv The array of command-line arguments
 *
 * @return 0 on success, or non-zero on failure
 */
int Local::parse_local_params(int argc, char* const *argv) {
	int c = 0, option_index = 0;
	// Reset optind, because we are probably being called from
	// another script with command-line parsing
	optind = 0;

	// Struct containing options to be parsed
	static struct option long_options[] =
	{
		{"folder", required_argument, 0, 'f'},
		{0, 0, 0, 0}
	};

	while(1){
		option_index = 0;
		
		// Obtain the next argument
		c = getopt_long(argc, argv, "f:", long_options, &option_index);

		// Finish if c == -1
		if (c == -1)
			break;

		switch(c){
			// Search term
			case 'f':
				sourceDirectory = optarg;
				break;

			default:
				break;
		}

	}

	if (sourceDirectory == "") {
		cerr << "Error: Must include --folder <path> option for Local plugin.\n" << endl;
		return -1;
	}

	return 0;
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
int Local::parse_home_dir(string& dirString) const {
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
