#include "image.h"
#include "scene.h"
#include <iostream>

#include "EasyBMP.h"
#include "EasyBMP_BMP.h"
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"

using namespace std;





/*
Scene's Contsructor.
1) Allocates dynamic memory for the array of images--size determined by parameter
used by client. Initializes each pointer within array to NULL before 
specific Images are added.
2) Allocates memory for 2 arrays which contain the x and y coordinate 
associated to each image.
3) 2Set's Scene's member of the maximum number of images in array.
*/
Scene::Scene (int max)
{
	imageArray=new Image*[max];

	for (int i=0; i<max ; i++)
		{
		imageArray[i]=NULL;	
		}

	xcoordinate= new int[max];
	ycoordinate= new int[max];

	Max=max;
}




/*
Scene's destructor. Actual code is in helper function "clear()".
*/
Scene::~Scene()
{
	clear();
}



/*
Scene's Copy Constructor. Has itself as a parameter, without a return.
Actual code implementation in helper function "copy(source)".
*/
Scene::Scene(const Scene & source)
{
	copy(source);
}



/*
Implementation of the destructor.
1) If the pointer in the array is not set to null, the Image is deleted via loop.
2) Then the array containing the pointers is deleted, as well as the two 
arrays containing the x and y coordinates for the images.
3) Initial pointers to all 3 arrays are set to NULL.
*/
void Scene::clear( )
{
	int size = Max;

	for(int x=0; x<size; x++)
		{
		if(imageArray[x] != NULL) 
			{
			delete imageArray[x];
			}
     	}
            

   delete [] imageArray;
   delete [] xcoordinate;
   delete [] ycoordinate;
   imageArray = NULL;
   xcoordinate=NULL;
   ycoordinate=NULL;
}





/*
Actual implementation of the copy constructor.
1) Allocates necessary memory of Scene to be copied--3 arrays.
2) Copies over the parameter's dynamic memory via loops.
3) Sets the new member variable Max (index value) to the parameters.
*/
void Scene::copy(const Scene & copyScene)
{
	int size=(copyScene.Max);
	imageArray = new Image*[size];
	xcoordinate= new int[size];
	ycoordinate= new int[size];

	for(int x=0; x<size; x++)
	{
		if(copyScene.imageArray[x] == NULL) 
			{
			imageArray[x] = NULL;
			xcoordinate[x]=copyScene.xcoordinate[x];
     		ycoordinate[x]=copyScene.ycoordinate[x];
			}
				

     	else 
     		{ 
     		imageArray[x] = new Image(*copyScene.imageArray[x]);
     		xcoordinate[x]=copyScene.xcoordinate[x];
     		ycoordinate[x]=copyScene.ycoordinate[x];
     		}
	}
	
   Max=copyScene.Max;
}






/*
Overloads the "=" operator when used with Scenes.
1) Checks for self assignment.
2) Otherwise, calls the destructor implementation to clear the class to be 
	written into and then copies over the parameter via the copy constructor's 
	helper function.
3) Returns reference to new copied Scene class.
*/
Scene const & Scene::operator=(Scene const & source)
{
	if (&source == this)
		{
		return *this;
		}
		
	clear();
	copy(source);

	return *this;
}





/*
Adds a bmp into the array of images of defined Scene class.
1) Error checks if index is out of the bounds of allocated array/mem/index.
2) Otherwise, allocates memory for a new image and writes the bmp into it.
3) Sets the x,y coordinates associated to it from the parameters.
*/
void Scene::addpicture(const char* FileName, int index, int x, int y)
{
	if (index>=Max || index<0)
		{
		cout << "index out of bounds" << endl;
		}
		
	imageArray[index]= new Image();
	((imageArray[index])->ReadFromFile(FileName));
	xcoordinate[index]=x;
	ycoordinate[index]=y;
}



/*
Expands the index associated to current class and thus the amount of memory
already allocated in its image array.
-Function broken up into 3 parts:
	1) If the new maximum amount of bmps associated with the class is intended
		to be smaller than the original, changemaxlayers checks if any of the 
		places in the array that will be cut due to rescaling point to existing
		images. If so, nothing is done and the function exits. If locations in
		the array to be deleted only have NULL pointers, the function proceeds. 
	2) The array is reallocated into a shorter array if the new maximum is less
		than the original. The old array is deleted.
	3) The array is reallocated into a larger array if the new maximum is greater
		than the original. The old array is deleted.
Also, the member of Scene that holds the maximum index is overwritten to reflect
changes.
*/
void Scene::changemaxlayers(int newmax)
{
	/*
	Checking for Non-Null pointers in the imageArray in the case that our new
	array is supposed to be smaller than our original, in which case we could 
	lose pointers to images.
	*/
	
	if (newmax<Max)
		{
		for(int i=newmax ; i<Max ; i++)
			{
			if (imageArray[i]!=NULL)
				{
				cout << "invalid newmax" << endl;
				return;
				}
			}
		}

	Image** tempArray;
	tempArray=new Image*[newmax];
/*
If we intend to shorten the imageArray, we just copy all of the pointers in the 
array over to a temporary array. Then we reset the original pointer 
pointing to imageArray to point to the temp array and delete the original.
*/

	if (newmax<=Max)
	{
		for (int i=0; i<newmax ; i++)
			{
			tempArray[i]=imageArray[i];	
			}
		
		delete [] imageArray;
		imageArray=NULL;
		imageArray=tempArray;
		Max=newmax;
		return;
	}
	
	
/*
If we wish to extend our array, we copy over all of the pointers from imageArray
into a tempory array (And change pointers pointing from imageArray to tempArray
like above). The remaining open slots in our new array are filled with NULL.
*/
		
	else if (newmax>Max)
		{
		for (int i=0; i<Max ; i++)
			{
			tempArray[i]=imageArray[i];
			}


		for (int j=Max; j<newmax ; j++)
			{
			imageArray[j]=NULL;
			}					
			
				
		delete [] imageArray;
		imageArray=NULL;
		imageArray=tempArray;
		
		
		//Resize xcoordinate/ycoordinate array.
		
		int* tempxcoordinate=new int[newmax];
		int* tempycoordinate=new int[newmax];

		for (int i=0; i<Max ; i++)
			{
			tempxcoordinate[i]=xcoordinate[i];	
			tempycoordinate[i]=ycoordinate[i];
			}
			
		delete [] xcoordinate;
		delete [] ycoordinate;

		xcoordinate= tempxcoordinate;
		ycoordinate= tempycoordinate;

	
		Max=newmax;
		return;
		}
		
	else 
		{
		cout << "murrrrr" << endl;
		return;		
		}
		
}




/*
Changes the index of image in array and thus the layer in which it will
appear.
1) Checks if the index assignment is the same. Nothing is done.
2) Checks the validity of either indexes--if that memory is even allocated.
3) If there is an image at the index to where picture is supposed to be moved,
	it is deleted.
4) Reallocates the point of the image to that of the new index & the old one
	is set to null.
5) The x,y coordinates arrays have their values copied over to the new index.
*/
void Scene::changelayer(int index, int newindex)
{
	if(newindex==index)
	 	{
	 	return;
	 	}
	 	
	if (index>=Max || index<0 || newindex>=Max || newindex<0)
		{
		cout << "invalid index" << endl;
		}
	
		 	
	if(imageArray[newindex]!=NULL)
		{
		delete imageArray[newindex];
		}
	
	
	imageArray[newindex]=imageArray[index];
	imageArray[index]=NULL;
	
	xcoordinate[newindex]=xcoordinate[index];
	ycoordinate[newindex]=ycoordinate[index];
	
	return;
}


/*
Changes the x,y coordinates of an image at specified parameter index.
Error checks for index's validity.
*/
void Scene::translate(int index, int xcoord, int ycoord)
{
	if (index>=Max || index<0 || imageArray[index]==NULL)
		{
		cout << "invalid index" << endl;
		return;
		}

	xcoordinate[index]= xcoord;
	ycoordinate[index]= ycoord;
}



/*
Deletes image at specified index in the array of images.
Error checks for validity of index.
Set pointer to non-existant image to NULL.
*/
void Scene::deletepicture(int index)
{
	if (index>=Max || index<0 || imageArray[index]==NULL)
		{
		cout << "invalid index" << endl;
		return;
		}
		
	delete imageArray[index];
	imageArray[index]=NULL;

	return;
}


/*
Function error checks for index validity and then returns pointer 
to specified image.
*/
Image* Scene::getpicture (int index) const
{
	if (index>=Max || index<0 || imageArray[index]==NULL)
		{
		cout << "invalid index" << endl;
		return NULL;
		}
		
	return imageArray[index];
}



/*
Function which creates the final scene based on what images are in the array.
1) The size of the scene is determined by the least amount of pixels needed
	to fit all images in their x,y coordinates.
2) All images in the image array are copied, pixel by pixel, via a for loop
	ont othe newly created blank scene bmp starting with index=0 and ending on 
	index=max-1.
3) This scene bmp is then returned by value.
*/
Image Scene::drawscene() const
{
int height, maxheight=0;
int width, maxwidth=0;
int current_width , current_height;
Image layered;


/*
Maximum size is determined by looping through all images sizes and their x/y 
coordinates. These two values are summed and placed into a temporary variable.
On the next iteration of the loop, if the size necessary to hold the current
image is larger than the previous, then the temporary size gets overwritten
with the 2 if statements.
*/
	for(int i=0 ; i<Max ; i++)
		{
		if(imageArray[i]==NULL)
			{
			}
		else
			{
			width=( ((*imageArray[i]).TellWidth()) + xcoordinate[i]);
			if (width>maxwidth)	
				{
				maxwidth=width;
				}

			height=( ( (imageArray[i])->TellHeight() ) + ycoordinate[i]);
			if (height>maxheight)
				{
				maxheight=height;
				}
			}
		}

//Image is created with the size dimensions determined above.
	layered.SetSize (maxwidth, maxheight);
	

/*
The triple nested below pastes all of the images onto the newly created blank 
scene.
	Loop:
	1) Loops through all of the images.
	2) Loops through the scene horizontally and copies over the pixels of the
		current image onto the scene starting at the given x coordinate.
	3) Loops through the scene vertically and copies over the pixels of the
		current image onto the scene starting at the given y coordinate.		
		
The if/else syntax checks if the current index in array contains a NULL and 
skips that iteration.
*/
	for(int k=0; k<Max; k++)
		{
		if(imageArray[k]==NULL)
			{
			}
			
		else	
			{
			current_width=(imageArray[k])->TellWidth();
			current_height=(imageArray[k])->TellHeight();		
				
			for(int i=xcoordinate[k], a=0; a<current_width; i++, a++)
				{
				for(int j=ycoordinate[k], b=0; b<current_height; j++, b++)
					{
					(layered(i,j)->Red)   = ((*imageArray[k])(a,b)->Red);
					(layered(i,j)->Green) = ((*imageArray[k])(a,b)->Green);
					(layered(i,j)->Blue)  = ((*imageArray[k])(a,b)->Blue);								
					}
				}
			}
		}	
		
	return layered;	
}
