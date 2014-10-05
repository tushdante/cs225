/**
scene.h -- part of MP2.2
	This class provides the ability to create a scene composed of a 
	collection of images in a single BMP. Each Image in the Scene will have an 
	index, an x coordinate, and a y coordinate. The user can request an Image 
	object in which all the Images in the scene are drawn, in order from index 
	0 to the maximum index, at their coordinates with only one image per index.

Date: February 5, 2011
*/
 
#include "EasyBMP.h"
#include "image.h"

#ifndef SCENE_H
#define SCENE_H

class Scene 
{

public:
Scene (int max);
~Scene();
Scene(Scene const & source);
Scene const & operator=(Scene const & source);
void addpicture(const char* FileName, int index, int x, int y);
void changemaxlayers(int newmax);
void changelayer(int index, int newindex);
void translate(int index, int xcoord, int ycoord);
void deletepicture(int index);
Image* getpicture (int index) const;
Image drawscene() const;


private:
Image** imageArray;
int Max;
int* xcoordinate;
int* ycoordinate;
void copy(const Scene & copyScene);
void clear();
};

#endif
