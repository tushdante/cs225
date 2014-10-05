#include<iostream>
#include<EasyBMP.h>
#include"fills.h"

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

animation testColorPicker(colorPicker * picker) {
  BMP img;
  img.SetSize(FUNCTORTESTWIDTH, FUNCTORTESTHEIGHT);
  animation anim;
  RGBApixel px;

  int frameCount = 0;

  for(int x = 1; x < FUNCTORTESTWIDTH; x = x + x)
    for(int y = 1; y < FUNCTORTESTHEIGHT; y = y + y) {
      px = (*picker)(x, y);
      cout << "\toperator()(" << x << ", " << y << ") = {" << (int)px.Red << ", ";
      cout << (int)px.Green << ", " << (int)px.Blue << "}" << endl;
    }

  for(int x = 0; x < FUNCTORTESTWIDTH; x++)
    for(int y = 0; y < FUNCTORTESTHEIGHT; y++){
      if(frameCount++ % FUNCTORTESTFREQ == 0)
        anim.addFrame(img);
      *img(x, y) = (*picker)(x, y);
    }

  return anim;
}

void testSolidPicker() {
    RGBApixel px;
    px.Red = 255;
    px.Blue = px.Green = 100;
    solidColorPicker solidPicker(px);

    testColorPicker(&solidPicker).write("solidColorPickerTest.gif");
    cout << "\tsolidColorPickerTest.gif written to disk." << endl;
}

void testGradientPicker() {
    RGBApixel px1, px2;
    px1.Red = 255;
    px1.Blue = px1.Green = 100;
    px2.Blue = 255;
    px2.Green = px2.Red = 10;
    gradientColorPicker gradientPicker(px1, px2, FUNCTORTESTRADIUS, FUNCTORTESTX, FUNCTORTESTY);

    testColorPicker(&gradientPicker).write("gradientColorPickerTest.gif");
    cout << "\tgradientColorPickerTest.gif written to disk." << endl;
}

void testGridPicker() {
    RGBApixel px1;
    px1.Green = 255;
    px1.Blue = px1.Red = 110;
    gridColorPicker gridPicker(px1, FUNCTORTESTGRIDSPACING);

    testColorPicker(&gridPicker).write("gridColorPickerTest.gif");
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

void testFills() {
  cout << "Testing solid fills" << endl;
    testSolidFills();
  cout << "Testing grid fills" << endl;
    testGridFills();
  cout << "Testing gradient fills" << endl;
    testGradientFills();
}

int main() {

  //Testing the functors
  testColorPickers();

  //Testing the fills themselves.  Note that this uses the functors, so make sure those
  //are working first
  testFills();
  return 0;
}
