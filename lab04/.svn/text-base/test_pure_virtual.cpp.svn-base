/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 */

#include <iostream>

#include "truck.h"

using cs225::Drawable;
using cs225::Truck;
using cs225::Vector2;

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  BMP canvas;
  canvas.SetSize(128, 128);

  const Vector2 truck_center(64, 64);

  /* TODO: Why can't I construct a new Truck?  Is should be a valid Drawable.
   * Could it be missing something that would prevent it from being constructed?
   */
  Drawable* truck = new Truck(truck_center);

  truck->draw(&canvas);

  canvas.WriteToFile("test_pure_virtual.bmp");

  delete truck;
  return 0;
}
