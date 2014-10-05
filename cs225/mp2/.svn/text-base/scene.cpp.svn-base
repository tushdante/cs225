/********************************************************************
*	scene.cpp -- MP2.2
*	Defines functions that will support creating, modifying, and
*	drawing the collection of images in the Scene.
*	Date:9/13/2010
********************************************************************/
#include "scene.h"

using std::cout;
using std::endl;

//Scene
//	-constructs an instance of the class with size max
//	-Paramenters:
//		max: size of Scene
Scene::Scene(int max){
	//cout<<endl<<"Creating Scene..........................."<<endl;
	//arry of image pointers
	img_arry= new Image*[max];
	//arry for coordinates x and y
	x_arry= new int[max];
	y_arry= new int[max];
	//set default values for arrys
	for(int i=0;i<max;i++){
		img_arry[i]=NULL;
		x_arry[i]=0;
		y_arry[i]=0;
	}
	//set Mymax
	Mymax=max;
	//cout<<endl<<"End Creating Scene........................"<<endl;
}
//Scene
//	-destructor that frees all resources that were allocated by the
//	class instance
Scene::~Scene(){
	//cout<<endl<<"Destruct for Scene........................"<<endl;
	//invokes clear helper function
	clear();
	//cout<<endl<<"End Destruct for Scene...................."<<endl;
}

//clear
//	-helper function to clear all resources used by the img_arry
void Scene::clear(){
	//cout<<endl<<"Clear for Scene..........................."<<endl;
	//goes through all values in img_arry
	for(int i=0;i<Mymax;i++){
		//if the pointer points to something then clear what is being 
		//pointed to
		if (img_arry[i]!=NULL)
			delete img_arry[i];
	}
	//when done deleteing all values being pointed to by img_arry
	//delete img_arry
	delete [] img_arry;
	delete [] x_arry;
	delete [] y_arry;
	//cout<<endl<<"End Clear for Scene......................."<<endl;
}

//Scene
//	-Parameters: passes by reference the scene that needs to be copied.
//	-copy constructor that initializes this scene as an independent
//copy of the original
//
Scene::Scene (Scene const & source){
	//cout<<endl<<"Copy Constructor for Scene................"<<endl;
	//invokes the copy helper function
	copy(source);
	//cout<<endl<<"End Copy Contructor for Scene............."<<endl;
}

//copy
//	-helper function that copies a scene
void Scene::copy(Scene const & source){
	//cout<<endl<<"Copy for Scene............................"<<endl;
	//sets Mymax
	Mymax=source.Mymax;
	//creates new arrys that have the same index size as source
	img_arry= new Image*[Mymax];
	x_arry= new int[Mymax];
	y_arry= new int[Mymax];
	//goes through each value in array and sets values the same as source
	for(int i=0;i<Mymax;i++){
		//if pointed to an image, allocate memory and make that memory 
		//contain the same information as source, if not make the pointer null
		if (source.img_arry[i] != NULL)
			img_arry[i]= new Image(*(source.img_arry[i]));
		else
			img_arry[i]=NULL;
		//copy coorinates over from source scene
		x_arry[i]=source.x_arry[i];
		y_arry[i]=source.y_arry[i];
	}
	//cout<<endl<<"End Copy for Scene........................"<<endl;
}

// operator=
//  -assignment operator
//  -makes the current instance a deep copy of the parameter
Scene const & Scene::operator=(Scene const & course){
	//cout<<endl<<"Operator= for Scene......................."<<endl;
   if(this != &course)
   {
		//clear the LHS scene because it's being overwritten	
      clear();
		//create a copy of the RHS
      copy(course);
   }
	//cout<<endl<<"End Operator= for Scene..................."<<endl;
   return *this;

}


//addapicture
//	-adds a picture to the scene
//	-Parameters:
//		FileName: name of file to be added
//		index: where in array it should be added
//		x,y: coordinates of where the picture will be located 
void Scene::addpicture(const char* FileName, int index, int x, int y){
	//cout<<endl<<"Addpicture for Scene......................"<<endl;
	Image picture;
	bool success;
	//check to make sure image is in the correct range
	if ((index>=0) && (index<Mymax)){
		//stores file into picture
		success=picture.ReadFromFile(FileName);
		//cout<<"Image loaded= "<<success<<endl;
		//make the index point to this picture
		//if pointer points to memory overwrite the picture
		if (img_arry[index]!=NULL)
			*img_arry[index]= picture;
		//if not then create memory and have that memory contain picture
		else
			img_arry[index]=new Image(picture);
		//save coordinates specified
		x_arry[index]=x;
		y_arry[index]=y;
	}
	else{
		cout << "index out of bounds" << endl;
	}
	//cout<<endl<<"End Addpicture for Scene.................."<<endl;
}

//changemaxlayers
//	-modifies the size of the arrays
//	-Parameters:
//		newmax: the new max
void Scene::changemaxlayers(int newmax){
	//cout<<endl<<"Changemaxlayers for Scene................."<<endl;
	int *temp_x,*temp_y,i;
	Image* *temp_img;
	//check when newmax<Mymax, since everything will work when newmax>=Mymax
	if (newmax<Mymax){
		//go through each location from newmax to Mymax and check if all the values
		//that won't be copied contain NULL
		for(int i=newmax;i<Mymax;i++){
			//if any value contains a non NULL then return error and return
			//aka cannot shrink array because it would result in a loss of data
			if (img_arry[i] != NULL){
				cout << "invalid newmax" << endl;
				return;
			}
		}
	}
	//if check above was successful then create a new copy of scene values
	
	//temp arrys initialized
	temp_x= new int[newmax];
	temp_y= new int[newmax];
	temp_img=new Image*[newmax];

	//go through all the values of img_arry
	for(i=0;i<Mymax;i++){
		//check if pointer is not NULL, then copy informaiton at locaiton
		if (img_arry[i]!=NULL)
			temp_img[i]=new Image(*img_arry[i]);
		//if pointer is NULL then store NULL as pointer
		else
			temp_img[i]=NULL;
		//copy coordinates
		temp_x[i]=x_arry[i];
		temp_y[i]=y_arry[i];
	}

	//initialize the rest of the scene's indices when newman>Mymax
	if (newmax>Mymax){
		for(i=Mymax;i<newmax;i++){
			temp_img[i]=NULL;
			temp_x[i]=0;
			temp_y[i]=0;
		}
	}

	//deletes private members
	clear();

	//re-initializes private members
	Mymax=newmax;
	img_arry= new Image*[Mymax];
	x_arry= new int[Mymax];
	y_arry= new int[Mymax];
	for(i=0;i<Mymax;i++){
		//sets img_arry pointers and temp_img pointers equal to each other
		img_arry[i]=temp_img[i];
		//copies over coordinates
		x_arry[i]=temp_x[i];
		y_arry[i]=temp_y[i];
	}

	//clears temp
	delete [] temp_img;
	delete [] temp_x;
	delete [] temp_y;
	//cout<<endl<<"End Changemaxlayers for Scene............."<<endl;
}

//changelayer
//	-moves an Image from location index to newindex
//	-Parameters:
//		index: location to be moved
//		newindex: destination
void Scene::changelayer(int index, int newindex){
	//cout<<endl<<"Changlayers for Scene....................."<<endl;
	//when index==newindex do nothing
	if (index==newindex)
		return;

	//when index and newindex are both >=0 and <Mymax
	if ((index<Mymax && newindex<Mymax) && (index>=0 && newindex>=0)){
		//free memory that is at the newindex since it'll be overwritten
		delete img_arry[newindex];
		//copy pointer
		img_arry[newindex]=img_arry[index];
		//copy coordinates
		x_arry[newindex]=x_arry[index];
		y_arry[newindex]=y_arry[index];
		//set index pointer to NULL
		img_arry[index]=NULL;
		//set coordinates to default
		x_arry[index]=0;
		y_arry[index]=0;             
		
	}
	//index or newindex isn't in the proper range
	else
		cout << "invalid index" << endl;
	//cout<<endl<<"End Changlayers for Scene................."<<endl;
}

//translate	 
//	-changes the x and y coordinates of the Image in layer index
//	-Parameters:
//		index: current location
//		xcoord,ycoord: new x and y values
void Scene::translate(int index, int xcoord, int ycoord){
	//cout<<endl<<"Translate for Scene......................."<<endl;
	//when 0<=index<Mymax and img_arry[index] contains a pointer
	if ((index>=0) && (index<Mymax) && (img_arry[index] !=NULL)){
		//store x and y coord
		x_arry[index]=xcoord;
		y_arry[index]=ycoord;
	}
	//index isn't in proper range or pointer ==NULL
	else
		cout << "invalid index" << endl;
	//cout<<endl<<"End Translate for Scene..................."<<endl;
}	

//deletepicture
//	-deletes the Image at the given index
//	-parameters:
//		index:location
void Scene::deletepicture(int index){
	//cout<<endl<<"Deletepicture for Scene..................."<<endl;
	//when 0<=index<Mymax and img_arry[index] contains a pointer
	if ((index>=0) && (index<Mymax) && (img_arry[index] !=NULL)){
		//clear image at index
		delete img_arry[index];
		//change pointer to NULL so it doesn't point to 
		img_arry[index]=NULL;	}
	//index isn't in proper range or pointer ==NULL
	else
		cout << "invalid index" << endl;
	//cout<<endl<<"End Deletepicture for Scene..............."<<endl;
}

//getpicture
//	-returns a pointer to the Image at the specified index
//	-Parameters:
//		index: location
Image* Scene::getpicture(int index) const{
	//cout<<endl<<"Getpicture for Scene......................"<<endl;
	//when 0<=index<Mymax and img_arry[index] contains a pointer
	if ((index>=0) && (index<Mymax) && (img_arry[index] !=NULL)){
		//cout<<endl<<"End Getpicture for Scene.................."<<endl;
		return img_arry[index];
	//index isn't in proper range or pointer ==NULL
	}
	else{
		cout << "invalid index" << endl;
		//cout<<endl<<"End Getpicture for Scene.................."<<endl;
		return NULL;
	}

}

//drawscene
//	-draws the whole scene on one Image
//	-returns Image by value
Image Scene::drawscene() const{
	//cout<<endl<<"Drawscene for Scene......................."<<endl;
	int max_w=0,max_h=0,w,h;
	int temp_w,temp_h;
	int c_x,c_h,c_w,c_y;
	for(int i=0;i<Mymax;i++){
		if (img_arry[i]!=NULL){
			w=(img_arry[i]->TellWidth());
			h=(img_arry[i]->TellHeight());
			temp_w=x_arry[i]+w;
			temp_h=y_arry[i]+h;
			if (temp_w>max_w)
				max_w=temp_w;
			if (temp_h>max_h)
				max_h=temp_h;
		}
	}

	Image out;
	RGBApixel *color,*str_color;
	out.SetSize(max_w,max_h);
	for(int img_count=0;img_count<Mymax;img_count++){
			if (img_arry[img_count]!=NULL){
				//current image x
				c_x=x_arry[img_count];
				//current image y
				c_y=y_arry[img_count];
				//current image width
				c_w=img_arry[img_count]->TellWidth();
				//current image height
				c_h=img_arry[img_count]->TellHeight();
			}
		for(int i=0;i<c_w;i++){
			for(int j=0;j<c_h;j++){
				if (img_arry[img_count]==NULL)
					break;
				color=(*(img_arry[img_count]))(i,j);
				str_color=out(i+c_x,j+c_y);
				str_color->Red=color->Red;
				str_color->Green=color->Green;
				str_color->Blue=color->Blue;
			}
		}
	}
	
	//cout<<endl<<"End Drawscene for Scene..................."<<endl;
	return out;
}

