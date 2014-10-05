/**
 * plugin.h
 *
 * Provides an abstract Plugin class for obtaining pictures. Plugin class
 * is subclassed to provide a consistent interface over various methods
 * of obtaining sources for the mosaic.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#ifndef _PLUGIN_H
#define _PLUGIN_H

#include <string>
#include <list>

using namespace std;

class Plugin
{
	public:

		/**
		 * Default constructor
		 */
		Plugin();

		/**
		 * Destructor - necessary to chain destructor calls
		 */
		virtual ~Plugin();

		/**
		 * Init function; parse options from the command-line
		 * to initialize the plugin.
		 *
		 * @param argc The count of parameters from the command-line
		 * @param argv The array of parameters from the command-line
		 *
		 * @return 0 on success, or non-zero on failure
		 */
		virtual int init(int argc, char * const *argv) = 0;

		/**
		 * Print a helpful usage-message to stdout of all
		 * command-line parameters accepted.
		 */
		virtual void print_usage() = 0;

		/**
		 * Gather images from the selected plugin.  The exact
		 * function of this method will differ between plugins,
		 * but essentially it will retrieve a list of paths or
		 * urls from which images can be read.
		 *
		 * @param imgBuf Buffer to fill with image paths or URLs
		 * 
		 * @return The number of images returned, or -1 on error
		 */
		virtual int gather_images(list<string> & imgBuf) const = 0;
};

#endif /* _PLUGIN_H */
