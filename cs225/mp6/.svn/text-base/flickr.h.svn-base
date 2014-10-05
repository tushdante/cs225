/**
 * flickr.h
 *
 * Subclasses the Plugin class to allow Flickr-obtained images.
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#ifndef _FLICKR_H
#define _FLICKR_H

#include <string>
#include "plugin.h"

using namespace std;

/**
 * Forward-declaration of flickcurl_s struct
 */
struct flickcurl_s;
/**
 * Forward-declaration of flickcurl typedef
 */
typedef struct flickcurl_s flickcurl;

class Flickr : public Plugin
{
	public:
		/**
		 * Number of results to return per query.  There is a maximum of 500
		 * results per "page"
		 */
		static const int MAX_RESULTS_PER_PAGE = 500;
		
		/**
		 * Default number of images to query Flickr for.  500
		 * will take one query.
		 */
		static const int DEFAULT_NUM_PICS_TO_QUERY = 500;

		/**
		 * Default constructor
		 */
		Flickr();
		/**
		 * Copy constructor
		 *
		 * @param source The Flickr object to copy
		 */
		Flickr(const Flickr& source);
		/**
		 * Assignment Operator
		 *
		 * @param source The Flickr object to copy
		 * @returns an identical, deep-copied Flickr object
		 */
		const Flickr& operator=(const Flickr& source);
		/**
		 * Destructor
		 */
		virtual ~Flickr();

		/**
		 * Print a usage statement for the Flickr.  This will print
		 * all of the accepted CLI parameters, as well as a description
		 * of how they function.  
		 */
		void print_usage();

		/**
		 * Initialization function
		 * @param argc The number of parameters
		 * @param argv The arguments passed to the Flickr object
		 * for initialization
		 * @return 0 on success, or non-zero otherwise
		 */
		int init(int argc, char * const *argv);	
		
		/**
		 * Retrieve a list images from Flickr.  This is the main
		 * work-horse function of the Flickr class.  Search parameters
		 * should be set via the init method before calling gather_images.
		 *
		 * @param urlBuf A list buffer object to store results in
		 * @return The number of images returned, or -1 on failure
		 */
		int gather_images(list<string>& urlBuf) const;

	private:
		/**
		 * Cleans up dynamically allocated memory
		 */
		void destruct();

		/**
		 * Performs a deep copy of source into this
		 *
		 * @param source The source Flickr object to copy.
		 */
		void copy(const Flickr& source);

		/**
		 * Initialize a new flickcurl object
		 *
		 * @return a new flickcurl object to be used for a photomosaic session
		 */
		flickcurl* initialize_fc() const;

		/**
		 * API key from Flickr
		 */
		static const char API_KEY[];

		/**
		 * Shared secret for API key from Flickr
		 */
		static const char API_SECRET[];

		/**
		 * The main interface into the flickcurl library
		 */
		flickcurl* fc;
		
		/**
		 * Search term for the flickr query
		 */
		char *searchString;

		/**
		 * Number of images to query Flickr for
		 */
		int numPicsToQuery;
};

#endif /* _FLICKR_H */
