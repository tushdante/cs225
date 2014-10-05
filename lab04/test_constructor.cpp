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
#include "circle.h"
#include "vector2.h"

using cs225::Shape;
using cs225::Circle;
using cs225::Vector2;
namespace color = cs225::color;

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  const int canvas_width = 128;
  const int canvas_height = 128;

  BMP canvas;
  canvas.SetSize(canvas_width, canvas_height);


  const RGBApixel circle_color = color::ORANGE;
  const Vector2 circle_center(32, 32);
  const int circle_radius = 16;
  Circle* circle = new Circle(circle_center,
                              circle_color,
                              circle_radius);
                              
  circle->draw(&canvas);

  canvas.WriteToFile("test_constructor.bmp");

  /* TODO: For some reason the circle is NOT constructed with the proper color
   * and center position.
   * Can you make it so the circle is constructed with the proper color and
   * center position WITH OUT using set_center() or set_color()? */
  const bool correct_color = (circle->color().Red == circle_color.Red &&
                              circle->color().Green == circle_color.Green &&
                              circle->color().Blue == circle_color.Blue);
  if (correct_color) {
    cout << "Circle's color is correct!" << endl;
  } else {
    cout << "Circle's color is NOT correct!" << endl;
  }

  const bool correct_center = circle->center() == circle_center;
  if (correct_center) {
    cout << "Circle's center is correct!" << endl;
  } else {
    cout << "Circle's center is NOT correct!" << endl;
  }

  delete circle;
  circle = NULL;

  return 0;
}

