
//needs to be global, otherwise have compiler errors.
struct PIXEL //will be pushing structs that only contain coordinates & not
	{//public //data onto the stack, so as to conserve memory, b/c a full 
	int xcoor;//is unnecessary.
	int ycoor;
	};

animation DFSfill(BMP& img, int x, int y, colorPicker & fillColor, 
						int tolerance, int frameFreq) 
{
	int width=img.TellWidth();
	int height=img.TellHeight();
	
	
	int k=0; //counter used for frame animation
	animation Out;

	if(height==0 && width==0)return Out;
	
	PIXEL current;	//first pixel designated by parameters
	current.xcoor=x;
	current.ycoor=y;
	
	int OriginalRed=img(x,y)->Red; 	  //RGB of pixel designated by param. Used 
	int OriginalGreen=img(x,y)->Green; //for tolerance.
	int OriginalBlue=img(x,y)->Blue;				

	Stack<PIXEL> PIXELstack;	//stack of structs
	PIXELstack.push(current);	//push on pixel designated by param
		
	int processed [width][height];//2d array to keep track of processed pixels
	for (int i =0; i<width ; i++) //initialized to all false
	{	for (int j =0; j<height ; j++)
			processed[i][j]=false;
	}

	//Main algorithm, execute while stack is not empty
	while(PIXELstack.isEmpty()==false)
		{
		current = PIXELstack.pop();
		int XXX=current.xcoor;
		int YYY=current.ycoor;
		int currentRed=img(XXX,YYY)->Red;
		int currentGreen=img(XXX,YYY)->Green;
		int currentBlue=img(XXX,YYY)->Blue;				
		
		int calculatedTolerance=(int)(pow((currentRed-OriginalRed),2) +
												pow((currentGreen-OriginalGreen),2)+ 
												pow((currentBlue-OriginalBlue),2));
		//if pixel hasn't been processed yet and if it is inside of "boundaries"
		//i.e. it is tolerated.								
		if (processed[XXX][YYY]==false && calculatedTolerance<= tolerance)
			{
			processed[XXX][YYY]=true;
			//process pixel
			img(XXX,YYY)->Red=fillColor(XXX,YYY).Red;
			img(XXX,YYY)->Green=fillColor(XXX,YYY).Green;			
			img(XXX,YYY)->Blue=fillColor(XXX,YYY).Blue;			
			
			//update animation
			k++;
			if (k%frameFreq==0) Out.addFrame(img);
			
			
			//push on new pixels
			//right
			if(XXX+1<width && processed[XXX+1][YYY]==false)
				{
				current.xcoor=XXX+1;
				current.ycoor=YYY;				
				PIXELstack.push(current);
				}
			//down	
			if(YYY+1<height && processed[XXX][YYY+1]==false)
				{
				current.xcoor=XXX;
				current.ycoor=YYY+1;
				PIXELstack.push(current);
				}
			//left	
			if(XXX-1>=0 && processed[XXX-1][YYY]==false)
				{
				current.xcoor=XXX-1;
				current.ycoor=YYY;				
				PIXELstack.push(current);
				}
			//up
			if(YYY-1>=0 && processed[XXX][YYY-1]==false)
				{
				current.xcoor=XXX;
				current.ycoor=YYY-1;				
				PIXELstack.push(current);
				}				
			}								
		}	
		
	return Out;	
}


animation DFSfillSolid(BMP& img, int x, int y, RGBApixel fillColor, 
								int tolerance, int frameFreq) 
{
	solidColorPicker SOLID(fillColor);
	return DFSfill(img, x, y, SOLID, tolerance, frameFreq);
}


animation DFSfillGrid(BMP& img, int x, int y, RGBApixel gridColor, 
								int gridSpacing, int tolerance, int frameFreq) 
{
	gridColorPicker GRID(gridColor,gridSpacing);
	return DFSfill(img, x, y, GRID, tolerance, frameFreq);
}

animation DFSfillGradient(BMP& img, int x, int y, RGBApixel fadeColor1, 
					RGBApixel fadeColor2, int radius, int tolerance, int frameFreq) 
{
	gradientColorPicker GRADIENT(fadeColor1, fadeColor2, radius, x, y);
	return DFSfill(img, x, y, GRADIENT, tolerance, frameFreq);
}




animation BFSfill(BMP& img, int x, int y, colorPicker & fillColor, 
						int tolerance, int frameFreq) 
{
	int width=img.TellWidth();
	int height=img.TellHeight();
	
	int k=0; //counter used for frame animation
	animation Out;
	
	if(height==0 && width==0)return Out;
	
	PIXEL current;	//first pixel designated by parameters
	current.xcoor=x;
	current.ycoor=y;
	
	int OriginalRed=img(x,y)->Red; 	  //RGB of pixel designated by param. Used 
	int OriginalGreen=img(x,y)->Green; //for tolerance.
	int OriginalBlue=img(x,y)->Blue;				

	Queue<PIXEL> PIXELqueue;	//queue of structs
	PIXELqueue.enqueue(current);	//enqueue on pixel designated by param
		
	int processed [width][height];//2d array to keep track of processed pixels
	for (int i =0; i<width ; i++) //initialized to all false
	{	for (int j =0; j<height ; j++)
			processed[i][j]=false;
	}

	//Main algorithm, execute while stack is not empty
	while(PIXELqueue.isEmpty()==false)
		{
		current = PIXELqueue.dequeue();
		int XXX=current.xcoor;
		int YYY=current.ycoor;
		int currentRed=img(XXX,YYY)->Red;
		int currentGreen=img(XXX,YYY)->Green;
		int currentBlue=img(XXX,YYY)->Blue;				
		
		int calculatedTolerance=(int)(pow((currentRed-OriginalRed),2) +
												pow((currentGreen-OriginalGreen),2)+ 
												pow((currentBlue-OriginalBlue),2));
												
		//if pixel hasn't been processed yet and if it is inside of "boundaries"
		//i.e. it is tolerated.								
		if (processed[XXX][YYY]==false && calculatedTolerance<= tolerance)
			{
			processed[XXX][YYY]=true;

			//process pixel
			img(XXX,YYY)->Red=fillColor(XXX,YYY).Red;
			img(XXX,YYY)->Green=fillColor(XXX,YYY).Green;			
			img(XXX,YYY)->Blue=fillColor(XXX,YYY).Blue;	
			
			//update animation
			k++;
			if (k%frameFreq==0) Out.addFrame(img);
			
			//push adjacent pixels
			//right
			if(XXX+1<width && processed[XXX+1][YYY]==false)
				{
				current.xcoor=XXX+1;
				PIXELqueue.enqueue(current);
				}
			//down	
			if(YYY+1<height && processed[XXX][YYY+1]==false)
				{
				current.xcoor=XXX;
				current.ycoor=YYY+1;
				PIXELqueue.enqueue(current);
				}
			//left
			if(XXX-1>=0 && processed[XXX-1][YYY]==false)
				{
				current.xcoor=XXX-1;
				current.ycoor=YYY;				
				PIXELqueue.enqueue(current);
				}
			//up
			if(YYY-1>=0 && processed[XXX][YYY-1]==false)
				{
				current.xcoor=XXX;
				current.ycoor=YYY-1;				
				PIXELqueue.enqueue(current);
				}				
			}								
		}	
		
	return Out;	

}


animation BFSfillSolid(BMP& img, int x, int y, RGBApixel fillColor, 
								int tolerance, int frameFreq) 
{
	solidColorPicker SOLID(fillColor);
	return BFSfill(img, x, y, SOLID, tolerance, frameFreq);


}

animation BFSfillGrid(BMP& img, int x, int y, RGBApixel gridColor, 
							int gridSpacing, int tolerance, int frameFreq) 
{
	gridColorPicker GRID(gridColor,gridSpacing);
	return BFSfill(img, x, y, GRID, tolerance, frameFreq);

}

animation BFSfillGradient(BMP& img, int x, int y, RGBApixel fadeColor1, 
					RGBApixel fadeColor2, int radius, int tolerance, int frameFreq) 
{
	gradientColorPicker GRADIENT(fadeColor1, fadeColor2, radius, x, y);
	return BFSfill(img, x, y, GRADIENT, tolerance, frameFreq);

}
