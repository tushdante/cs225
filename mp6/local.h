/**
 * local.h
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

#ifndef _LOCAL_H
#define _LOCAL_H

#include <string>
#include <vector>
#include "plugin.h"

class Local : public Plugin
{
	public:

		/**
		 * Default constructor
		 */
		Local();

		/**
		 * Print a usage statement for the Local.  This will print
		 * all of the accepted CLI parameters, as well as a description
		 * of how they function.  
		 */
		void print_usage();

		/**
		 * Initialize the plugin with parameters from the command-line
		 *
		 * @param argc Number of command-line arguments
		 * @param argv The array of command-line arguments
		 *
		 * @return 0 on success, or non-zero otherwise
		 */
		int init(int argc, char* const *argv);

		/**
		 * Gather images from the local directory.  This is
		 * the main worker function and public interface of
		 * the plugin.
		 *
		 * @param imgBuf Buffer to fill with image paths
		 *
		 * @return The number of images found, or -1 on failure
		 */
		int gather_images(list<string>& imgBuf) const;

	private:

		/**
		 * Helper function for init.  Parse local parameters
		 *
		 * @param argc The number of command-line arguments
		 * @param argv The array of command-line arguments
		 *
		 * @return 0 on success, or non-zero on failure
		 */
		int parse_local_params(int argc, char * const *argv);

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
		int parse_home_dir(string& dirString) const;

		/**
		 * The directory to retrieve images from
		 */
		std::string sourceDirectory;

		/**
		 * Vector of all filenames found
		 */
		std::vector<std::string> filenames;
};

#endif /* _LOCAL_H */
