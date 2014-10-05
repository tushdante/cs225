/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 */

#include <iostream>

#include "EasyBMP.h"
#include "color.h"
#include "shape.h"
#include "triangle.h"
#include "vector2.h"

using cs225::Shape;
using cs225::Triangle;
using cs225::Vector2;
namespace color = cs225::color;

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  const int canvas_width = 128;
  const int canvas_height = 128;

  BMP canvas;
  canvas.SetSize(canvas_width, canvas_height);


  const RGBApixel triangle_color = color::ORANGE;
  Shape* triangle = new Triangle(triangle_color,
                                 Vector2(32, 32),
                                 Vector2(64, 64),
                                 Vector2(32, 64));

  triangle->draw(&canvas);

  canvas.WriteToFile("test_destructor.bmp");

  /* TODO: Why is this leaking memory?  Triangle does have a valid destructor!?
   * Can you stop it from leaking WITHOUT changing triangle's type from a
   * Shape pointer to a Triangle pointer type? */
  delete triangle;
  triangle = NULL;

  return 0;
}
