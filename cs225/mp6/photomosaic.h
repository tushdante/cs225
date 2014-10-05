/**
 * photomosaic.h
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

#ifndef _PHOTOMOSAIC_H
#define _PHOTOMOSAIC_H

#include "local.h"
#include "flickr.h"

class PhotoMosaic {
	public:
		/**
		 * Default constructor
		 */
		PhotoMosaic();

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
		int parse_cli(int argc, char* argv[]);

		/**
		 * Print a usage statement for the program.  This will print
		 * all of the accepted CLI parameters, as well as a description
		 * of how they function.  This should even print options for
		 * each of the supported plugins
		 */
		void print_usage();

		/**
		 * Generate a photomosaic.  Use the options passed in and the
		 * helper classes provided to create a mosaic.  This is the
		 * main worker method of the photomosaic class, which brings
		 * together all of other actual pieces of the application.
		 *
		 * @return 0 on success, or non-zero otherwise
		 */
		int generate_photomosaic();

		/**
		 * Destructor
		 */
		virtual ~PhotoMosaic();
		/**
		 * Copy constructor
		 *
		 * @param source PhotoMosaic object to copy
		 */
		PhotoMosaic(const PhotoMosaic& source);
		/**
		 * Assignment operator
		 *
		 * @param source PhotoMosaic object to copy
		 */
		const PhotoMosaic& operator=(const PhotoMosaic& source);

	private:
		/**
		 * Parse the command-line option for 'plugin'
		 *
		 * @arg option The option to parse
		 *
		 * @return 0 on success, or non-zero otherwise
		 */
		int parse_plugin_arg(const char *option);

		/**
		 * Parse the command-line option for 'input'
		 *
		 * @arg option The option to parse
		 *
		 * @return 0 on success, or non-zero otherwise
		 */
		int parse_input_arg(const char *option);

		/**
		 * Parse the command-line option for 'output'
		 *
		 * @arg option The option to parse
		 *
		 * @return 0 on success, or non-zero otherwise
		 */
		int parse_output_arg(const char *option);

		/**
		 * Parse the command-line option for 'resolution'
		 *
		 * @arg option The option to parse
		 *
		 * @return 0 on success, or non-zero otherwise
		 */
		int parse_resolution_arg(const char *option);

		/**
		 * Parse the command-line option for 'scale'
		 *
		 * @arg option The option to parse
		 *
		 * @return 0 on success, or non-zero otherwise
		 */
		int parse_scale_arg(const char *option);

		/**
		 * Cleans up dynamically allocated memory
		 */
		void destruct();

		/**
		 * Performs a deep copy of source into this
		 *
		 * @param source The source PhotoMosaic object to copy.
		 */
		void copy(const PhotoMosaic& source);

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
		 * The default resolution for new mosaics
		 */
		static const int DEFAULT_RESOLUTION = 35;

		/**
		 * The default scale to save mosaics at
		 */
		static const double DEFAULT_SCALE = 3.0;

		/**
		 * The input image fileName
		 */
		string inputFileName;

		/**
		 * The output image fileName
		 */
		string outputFileName;

		/**
		 * The resolution of the mosaic tiles
		 */
		int resolution;

		/**
		 * The dimensional ratio for saving the output image
		 */
		double dimensionScale;

		/**
		 * The Plugin object to gather TileImages from
		 */
		Plugin *plugin;
};

#endif /* _PHOTOMOSAIC_H */
