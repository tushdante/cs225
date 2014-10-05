#include <iostream>

#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "flickr.h"
#include "imagereader.h"

using namespace std;

/**
 * Create a "safe" file name from any given string.
 * This will convert any special characters into the
 * underscore character.  It will also attempt to
 * detect the file extension, and preserve it.
 *
 * @param url The string to use as a base
 *
 * @returns A safe filename
 */
string safeFilename(string url) {
	char *filename = strdup(url.c_str());
	for (int i = 0; i < (int)url.length(); i++) {
		if (isalnum( url[i] ))
			continue;

		if (url[i] != '.') {
			filename[i] = '_';
			continue;
		}

		// url[i] == '.'
		if ((i == (int)url.length() - 3) || (i == (int)url.length() - 4))
			continue;

		// not an extension dot either
		filename[i] = '_';
	}

	return string(filename);
	
}

/**
 * Determine if a file exists on the file system.
 * Not only will this detect if the file doesn't exist,
 * but will also detect if some subfolder leading up to the
 * path doesn't.
 *
 * @param fileName The path of the file to check
 *
 * @return true if the file exists, false otherwise
 */
bool fileExists(string fileName) {
	struct stat statBuf;

	return (stat(fileName.c_str(), &statBuf) >= 0);
}

/**
 * Entry point to the application
 *
 * @param argc Number of program arguments
 * @param argv Array of program arguments
 *
 * @return 0 on success, non-zero on failure
 */
int main(int argc, char* argv[]) {

	if (argc != 3) {
		cout << "Usage: " << argv[0] << " [searchTerm] [numImages]" << endl;
		return -1;
	}

	char search[] = "-s";
	char* searchTerm = argv[1];
	char num[] = "-n";
	char* numImages = argv[2];

	char* flickrFlags[] = { argv[0], search, searchTerm, num, numImages };
	Flickr flickr;
	if (flickr.init(5, flickrFlags) < 0) {
		cout << "Error initializing flickr!" << endl;
		return -1;
	}

	list<string> urlBuf;
	if (flickr.gather_images(urlBuf) < 0) {
		cout << "Error querying Flickr for images!" << endl;
		return -1;
	}

	ImageReader ir;
	TileImage tile;
	for (list<string>::iterator i = urlBuf.begin(); i != urlBuf.end(); i++) {
		string url = *i;
		string fileName = safeFilename(url);
		if (fileExists(fileName)) {
			cout << "Exists: " << fileName << endl;
			continue;
		}

		if (ir.read_tile_image(url, tile) < 0) {
			cout << "Error reading url: " << url << endl;
			continue;
		}

		try {
			Magick::Image image(tile.get_magick());
			image.write(fileName);
		} catch (Magick::Exception ex) {
			cout << "Error saving file: " << fileName << endl;
			continue;
		}

		cout << "Saved: " << fileName << endl;
	}

	return 0;
}
