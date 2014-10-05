//=====================================================
// main.cpp -- mp1
// This main allows for an image to be rotated
// 180 degrees.
// Date: Aug 8, 2010
//=====================================================





#include <iostream>
using std::cout;
using std::endl;
#include "EasyBMP.h"
#include "EasyBMP_BMP.h" 
#include "EasyBMP_DataStructures.h"
#include "EasyBMP_VariousBMPutilities.h"
#include <string>

int main (){
   
   // initializing variables

   bool sucess;
   BMP in;
   BMP out;
   int width,height,i,j,new_j,new_i;

   // Set Classes to contain image

   sucess=in.ReadFromFile("in.bmp");
   //cout<<sucess<<endl;
   sucess=out.ReadFromFile("in.bmp");
   //cout<<sucess<<endl;

   // Find height and width
   // starting from 0 not 1 so decrement 
  
   width=(in.TellWidth());
   width--;
   height=in.TellHeight();
   height--;
   //cout<<in.TellWidth()<<endl;
   //cout<<in.TellHeight()<<endl;

   // runs horizontally across the image
   for (i=0;i<=width;i++){

      // runs vertically across image
      for (j=0;j<=height;j++){

         // code for finding pixel to change 
         new_i=width-i;
         new_j=height-j;

         // code for changing output image  
         out(new_i,new_j)->Red =in(i,j)->Red;
         out(new_i,new_j)->Green =in(i,j)->Green;
         out(new_i,new_j)->Blue =in(i,j)->Blue;
        
      }	
   }
   //cout<<"Exiting For loops"<<endl;
   
   // write output image to disk
   out.WriteToFile("out.bmp");
   //cout<<"Finished writing out.bmp"<<endl;
   return 0;
}
