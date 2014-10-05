/********************************************************************
*	scene.h -- MP2.2
*	These functions will support creating, modifying, and drawing
*	the collection of images in the Scene.
*	Date:9/13/2010
********************************************************************/

/********************************************************************
*	Class: Scene
*	Derived from: none
*	This class defines functions addpicture(),changemaxlayers(),
*	changelayers(),translate(),deletepicture(),getpicture(),
*	drawscene(), where getpicture() and drawscene() are constant.
*	Also a function is added to overflow the assignment operator.
********************************************************************/

#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "image.h"

class Scene{
	public:
		Scene(int max);
		~Scene();
		Scene(Scene const & source);
		Scene const & operator=(Scene const & course);
		void addpicture(const char* FileName, int index, int x, int y);
		void changemaxlayers(int newmax);
		void changelayer(int index, int newindex);
		void translate(int index, int xcoord, int ycoord);
		void deletepicture(int index);
		Image* getpicture(int index) const;
		Image drawscene() const;
	
	private:
		int* x_arry;
		int* y_arry;
		Image* *img_arry;
		int Mymax;
		void copy(Scene const& cource);
		void clear();
};
#endif
