/**
 * flickr.cpp
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

#include <iostream>

#include <assert.h>
#include <string.h>
#include <getopt.h>
#include <string.h>

#include "flickr.h"
#include "flickcurl.h"

using namespace std;

/**
 * Default constructor.  Do the work of creating the
 * plugin, but leave any initialization that needs
 * user-specified parameters to the init function
 */
Flickr::Flickr() {
	// Set pointers to null -- we will set them later
	fc = initialize_fc();

	searchString = NULL;
	numPicsToQuery = DEFAULT_NUM_PICS_TO_QUERY;
}

/**
 * Copy constructor
 *
 * @param source The Flickr object to copy
 */
Flickr::Flickr(const Flickr& source) {
	copy(source);
}

/**
 * Assignment Operator
 *
 * @param source The Flickr object to copy
 * @returns an identical, deep-copied Flickr object
 */
const Flickr&  Flickr::operator=(const Flickr& source) {
	if(this != &source){
		destruct();
		Plugin::operator=(source);
		copy(source);
	}
	
	return *this;
}

/**
 * Destructor
 */
Flickr::~Flickr() {
	destruct();
}

/**
 * Print a usage statement for the Flickr.  This will print
 * all of the accepted CLI parameters, as well as a description
 * of how they function.  
 */
void Flickr::print_usage() {
	cout << "\t--search=SEARCH\t\tThe query to search Flickr images for"	<< endl;
	cout << "\t--num-images=X\t\tMaximum number of images to retrieve"	<< endl;
	cout << "\t\t\t\t[default=" << DEFAULT_NUM_PICS_TO_QUERY << "]"		<< endl;
}

/**
 * Initialization function
 * @param argc The number of parameters
 * @param argv The arguments passed to the Flickr object
 * for initialization
 * @return 0 on success, or non-zero otherwise
 */
int Flickr::init(int argc, char * const *argv) {
	if ((argc < 1) || (argv == NULL))
		return -1;

	int c = 0, option_index = 0;
	// Reset optind, because we are probably being called from
	// another script with command-line parsing
	optind = 0;

	// Struct containing options to be parsed
	static struct option long_options[] =
	{
		{"search", required_argument, 0, 's'},
		{"num-images", required_argument, 0, 'n'},
		{0, 0, 0, 0}
	};

	while(1){
		option_index = 0;
		
		// Obtain the next argument
		c = getopt_long(argc, argv, "s:n:", long_options, &option_index);

		// Finish if c == -1
		if (c == -1)
			break;


		int numImages = 0;
		switch(c){
			// Search term
			case 's':
#ifdef FLICKR_DEBUG
				cout << "found search string: " << optarg << endl;
#endif
				searchString = strdup(optarg);
				break;

			// Number of images to search for
			case 'n':
				numImages = -1;
#ifdef FLICKR_DEBUG
				cout << "found numImages: " << optarg << endl;
#endif
				if ((EOF == sscanf(optarg, "%d", &numImages))
				 || (numImages < 0)) {
					//Error
#ifdef FLICKR_DEBUG
					cout << "unrecognized number set" << endl;
#endif
					return -1;
				}
				numPicsToQuery = numImages;
				break;

			case '?':
			default:
				// Error
#ifdef FLICKR_DEBUG
				cout << "Error, got to default clause" << endl;
#endif
				return -1;
				break;
		}

	}

#ifdef FLICKR_DEBUG
	if(optind < argc){
		cout << "Extra arguments:" << endl;
		while (optind < argc){
			cout << argv[optind++] << endl;
		}
	}
#endif 

	if (searchString == NULL) {
#ifdef FLICKR_DEBUG
		cout << "Error: searchString never set" << endl;
#endif
		return -1;
	}
	
#ifdef FLICKR_DEBUG
	cout << "Success! Return 0" << endl;
#endif
	return 0;
}

/**
 * Retrieve a list images from Flickr.  This is the main
 * work-horse function of the Flickr class.  Search parameters
 * should be set via the init method before calling gather_images.
 *
 * @param urlBuf A list buffer object to store results in
 * @return The number of images returned, or -1 on failure
 */
int Flickr::gather_images(list<string> & urlBuf) const {
	// Make sure we've already initialized sufficiently
	if (searchString == NULL)
		return -1;

	// Initialize our parameters (this should be a separate function,
	// but we can't forward-declare the anonymous struct flickcurl_search_params.
	// grrrrrr...
	flickcurl_search_params params;
	flickcurl_search_params_init(&params);
	params.text = searchString;
	
	// This is needed on each iteration
	flickcurl_photo **ret_photos = NULL;
	
	// Calculate the number of queries we'll need.  Be careful of incomplete
	// queries
	int currPicsToQuery = numPicsToQuery;
	int numQueries = numPicsToQuery / MAX_RESULTS_PER_PAGE
		+ ((numPicsToQuery % MAX_RESULTS_PER_PAGE == 0) ? 0 : 1);

	for (int queryNum = 0; queryNum < numQueries; queryNum++) {
		// Iteration variables
		int currPerPage = currPicsToQuery < MAX_RESULTS_PER_PAGE ?
			currPicsToQuery : MAX_RESULTS_PER_PAGE;
		params.per_page = currPerPage;
		params.page = queryNum +1;
		currPicsToQuery -= currPerPage;

		// Make the query
		ret_photos = flickcurl_photos_search(fc, &params);
		if (ret_photos == NULL) 
			// The query failed
			return -1;

		int picNum = 0;
		char* curUrl = NULL;
		while(ret_photos[picNum] != NULL) {
			curUrl = flickcurl_photo_as_source_uri(ret_photos[picNum], 's');
			if (curUrl == NULL) { // Error!
				flickcurl_free_photos(ret_photos);
				return -1;
			}

			urlBuf.push_back(string(curUrl));
			free(curUrl);

			picNum++;
		}

		flickcurl_free_photos(ret_photos);
		
		if (picNum < currPerPage) {
			// We received less photos than we wanted.  Not necessarily
			// an error, but break out of the loop
			break;
		}
	}

	// If we get here, we're done!
	return urlBuf.size();
}

/**
 * Destructor and operator= helper function
 */
void Flickr::destruct() {
	assert(fc != NULL);
	flickcurl_free(fc);
	fc = 0;
	free(searchString);
	searchString = 0;
}

/**
 * Copy constructor and operator= helper function
 */
void Flickr::copy(const Flickr& source) {
	// Don't copy fc, since we have problems with "incomplete struct
	// Instead, create a new one.
	fc = initialize_fc();
	if (source.searchString != NULL)
		searchString = strdup(source.searchString);
	numPicsToQuery = source.numPicsToQuery;
}

/**
 * Initialize a new flickcurl object
 *
 * @return a new flickcurl object to be used for a photomosaic session
 */
flickcurl* Flickr::initialize_fc() const {

	flickcurl *f = flickcurl_new();
	assert(f != NULL);
	flickcurl_set_api_key(f, API_KEY);
	flickcurl_set_shared_secret(f, API_SECRET);

	return f;
}

/**
 * API key from Flickr
 */
const char Flickr::API_KEY[] = "149e20572d673fa56f46a0ed0afe464f";

/**
 * Shared secret for API key from Flickr
 */
const char Flickr::API_SECRET[] = "35e3f7923939e71a";



