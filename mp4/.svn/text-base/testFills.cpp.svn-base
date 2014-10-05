#include <iostream>
#include <EasyBMP.h>
#include "fills.h"
#include "rainbowColorPicker.h"

using std::cout;
using std::endl;

#define FUNCTORTESTHEIGHT 60
#define FUNCTORTESTWIDTH 60
#define FUNCTORTESTFREQ 10
#define FUNCTORTESTX 40
#define FUNCTORTESTY 10
#define FUNCTORTESTRADIUS 35
#define FUNCTORTESTGRIDSPACING 8

#define SOLIDX 43
#define SOLIDY 15
#define SOLIDTOLERANCE 700
#define SOLIDTESTIMAGE "solidTest.bmp"
#define SOLIDFRAMEFREQ 130

#define GRIDX 40
#define GRIDY 25
#define GRIDTOLERANCE 7000
#define GRIDTESTIMAGE "gridTest.bmp"
#define GRIDFRAMEFREQ 20
#define GRIDGRIDSPACING 3

#define GRADIENTX 80
#define GRADIENTY 80
#define GRADIENTTOLERANCE 8500
#define GRADIENTTESTIMAGE "gradientTest.bmp"
#define GRADIENTFRAMEFREQ 150 
#define GRADIENTRADIUS 25

BMP testColorPicker(colorPicker * picker) {
	BMP img;
	img.SetSize(FUNCTORTESTWIDTH, FUNCTORTESTHEIGHT);
	RGBApixel px;

	for(int x = 1; x < FUNCTORTESTWIDTH; x = x + x)
		for(int y = 1; y < FUNCTORTESTHEIGHT; y = y + y) {
			px = (*picker)(x, y);
			cout << "\toperator()(" << x << ", " << y << ") = {" << (int)px.Red << ", ";
			cout << (int)px.Green << ", " << (int)px.Blue << "}" << endl;
		}

	for(int x = 0; x < FUNCTORTESTWIDTH; x++)
		for(int y = 0; y < FUNCTORTESTHEIGHT; y++){
			*img(x, y) = (*picker)(x, y);
		}

	return img;
}

void testSolidPicker() {
		RGBApixel px;
		px.Red = 255;
		px.Blue = px.Green = 100;
		solidColorPicker solidPicker(px);

		testColorPicker(&solidPicker).WriteToFile("solidColorPickerTest.bmp");
		cout << "\tsolidColorPickerTest.gif written to disk." << endl;
}

void testGradientPicker() {
		RGBApixel px1, px2;
		px1.Red = 255;
		px1.Blue = px1.Green = 100;
		px2.Blue = 255;
		px2.Green = px2.Red = 10;
		gradientColorPicker gradientPicker(px1, px2, FUNCTORTESTRADIUS, FUNCTORTESTX, FUNCTORTESTY);

		testColorPicker(&gradientPicker).WriteToFile("gradientColorPickerTest.bmp");
		cout << "\tgradientColorPickerTest.gif written to disk." << endl;
}

void testGridPicker() {
		RGBApixel px1;
		px1.Green = 255;
		px1.Blue = px1.Red = 110;
		gridColorPicker gridPicker(px1, FUNCTORTESTGRIDSPACING);

		testColorPicker(&gridPicker).WriteToFile("gridColorPickerTest.bmp");
		cout << "\tgridColorPickerTest.gif written to disk." << endl;
}

void testColorPickers() {
	cout << "Testing solidColorPicker:" << endl;
		testSolidPicker();
	cout << "Testing GradientColorPicker:" << endl;
		testGradientPicker();
	cout << "Testing GridColorPicker:" << endl;
		testGridPicker();
}

void testSolidFills() {
	BMP img;
	img.ReadFromFile(SOLIDTESTIMAGE);
	RGBApixel px;
	px.Red = 70;
	px.Green = 50;
	px.Blue = 13;

	animation anim = DFSfillSolid(img, SOLIDX, SOLIDY, px, SOLIDTOLERANCE, SOLIDFRAMEFREQ);
	anim.write("dfsSolidTest.gif");
	cout << "\tWrote dfsSolidTest.gif" << endl;
	img.ReadFromFile(SOLIDTESTIMAGE);
	anim = BFSfillSolid(img, SOLIDX, SOLIDY, px, SOLIDTOLERANCE, SOLIDFRAMEFREQ);
	anim.write("bfsSolidTest.gif");
	cout << "\tWrote bfsSolidTest.gif" << endl;
}

void testGridFills() {
	BMP img;
	img.ReadFromFile(GRIDTESTIMAGE);
	RGBApixel px;
	px.Red = px.Blue = 70;
	px.Green = 25;

	animation anim = BFSfillGrid(img, GRIDX, GRIDY, px, GRIDGRIDSPACING, GRIDTOLERANCE, GRIDFRAMEFREQ);
	anim.write("bfsGridTest.gif");
	cout << "\tWrote bfsGridTest.gif" << endl;
	img.ReadFromFile(GRIDTESTIMAGE);
	anim = DFSfillGrid(img, GRIDX, GRIDY, px, GRIDGRIDSPACING, GRIDTOLERANCE, GRIDFRAMEFREQ);
	anim.write("dfsGridTest.gif");
	cout << "\tWrote dfsGridTest.gif" << endl;
}

void testGradientFills() {
	BMP img;
	img.ReadFromFile(GRADIENTTESTIMAGE);
	RGBApixel px;
	px.Red = px.Blue = 0;
	px.Green = 25;
	RGBApixel px2;
	px2.Red = px2.Blue = 200;
	px2.Green = 25;

	animation anim = BFSfillGradient(img, GRADIENTX, GRADIENTY, px, px2, GRADIENTRADIUS, GRADIENTTOLERANCE, GRADIENTFRAMEFREQ);
	anim.write("bfsGradientTest.gif");
	cout << "\tWrote bfsGradientTest.gif" << endl;
	img.ReadFromFile(GRADIENTTESTIMAGE);
	anim = DFSfillGradient(img, GRADIENTX, GRADIENTY, px, px2, GRADIENTRADIUS, GRADIENTTOLERANCE, GRADIENTFRAMEFREQ);
	anim.write("dfsGradientTest.gif");
	cout << "\tWrote dfsGradientTest.gif" << endl;
}


void pacmanTests() {
	cout << "Testing PacMan" << endl;

	// PAC MAN BFS
	BMP img;
	img.ReadFromFile("pacMan.bmp");
	rainbowColorPicker BFSfiller(1.0/1000.0);
	animation pacManBFS = BFSfill(img, img.TellWidth()/2, img.TellHeight()/2,
	                               BFSfiller, 8000, INT_MAX);
	img.WriteToFile("pacManBFS.bmp");
	cout << "\tWrote pacManBFS.bmp" << endl;
	//blueManBFS.write("pacManBFS.gif");

	// PAC MAN DFS
	img.ReadFromFile("pacMan.bmp");
	rainbowColorPicker DFSfiller(1.0/1000.0);
	animation pacManDFS = DFSfill(img, img.TellWidth()/2, img.TellHeight()/2,
	                               DFSfiller, 8000, INT_MAX);
	img.WriteToFile("pacManDFS.bmp");
	cout << "\tWrote pacManDFS.bmp" << endl;


	// Make ANTI image
	BMP antiImg;
	antiImg.ReadFromFile("pacMan.bmp");
	RGBApixel black;
	black.Red = black.Green = black.Blue = 0;
	RGBApixel grey;
	grey.Red = grey.Green = grey.Blue = 1;
	BFSfillSolid(antiImg, 10, 10, grey, 8000, INT_MAX);
	BFSfillSolid(antiImg, antiImg.TellWidth()/2, antiImg.TellHeight()/2, black, 8000, INT_MAX);

	// ANTI PAC MAN BFS
	img = antiImg;
	rainbowColorPicker aBFSfiller(1.0/1000.0);
	animation aManBFS = BFSfill(img, 20, 20, aBFSfiller, 0, 2000);
	//img.WriteToFile("antiPacManBFS.bmp");
	aManBFS.write("antiPacManBFS.gif");
	cout << "\tWrote antiPacManBFS.gif" << endl;

	// ANTI PAC MAN DFS
	img = antiImg;
	rainbowColorPicker aDFSfiller(1.0/1000.0);
	animation aManDFS = DFSfill(img, 20, 20, aDFSfiller, 0, 2000);
	//img.WriteToFile("antiPacManDFS.bmp");
	aManDFS.write("antiPacManDFS.gif");
	cout << "\tWrote antiPacManDFS.gif" << endl;
}

void printUsage(char * arg)
{
		cout << "Usage:" << endl
		     << arg << " colorpickers" << endl
		     << arg << " grid" << endl
		     << arg << " solid" << endl
		     << arg << " gradient" << endl
		     << arg << " pacman" << endl
		     << arg << " all" << endl;
}

int main(int argc, char ** argv) {

	if (argc < 2)
	{
		printUsage(argv[0]);
		return 1;
	}

	bool colors = strcasecmp(argv[1], "colorpickers") == 0;
	bool grid = strcasecmp(argv[1], "grid") == 0;
	bool solid = strcasecmp(argv[1], "solid") == 0;
	bool gradient = strcasecmp(argv[1], "gradient") == 0;
	bool pacman = strcasecmp(argv[1], "pacman") == 0;
	if (strcasecmp(argv[1], "all") == 0) {
		colors = grid = solid = gradient = pacman = true;
	}

	if (!colors && !grid && !solid && !gradient && !pacman)
	{
		cout << "Invalid argument: " << argv[1] << endl;
		printUsage(argv[0]);
		return 1;
	}

	//Testing the functors
	if (colors)
		testColorPickers();

	//Testing the fills themselves.  Note that this uses the functors, so make sure those
	//are working first
	if (solid) {
		cout << "Testing solid fills" << endl;
		testSolidFills();
	}

	if (grid) {
		cout << "Testing grid fills" << endl;
		testGridFills();
	}

	if (gradient) {
		cout << "Testing gradient fills" << endl;
		testGradientFills();
	}

	//Tests Pac-Man!
	if (pacman) {
		pacmanTests();
	}

	return 0;
}
