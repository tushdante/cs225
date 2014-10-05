/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 */

#include <iostream>

#include "EasyBMP.h"
#include "flower.h"

using cs225::Drawable;
using cs225::Flower;
using cs225::Vector2;

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  const int canvas_width = 128;
  const int canvas_height = 128;

  BMP canvas;
  canvas.SetSize(canvas_width, canvas_height);

  const Vector2 flower_center(canvas_width/2, canvas_height/2);

  Drawable* flower = new Flower(flower_center);

  /* TODO: For some reason this flower is not drawing correctly?  The stem,
   * pistil, and leaf are all being drawn as big giant X's. */
  flower->draw(&canvas);

  canvas.WriteToFile("test_slicing.bmp");

  delete flower;
  return 0;
}
