/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 */

#ifndef FLOWER_H_
#define FLOWER_H_

#include "shape.h"

namespace cs225 {

class Flower : public Drawable {
 private:
  Shape* stem;
  Shape* pistil;  // center piece of flower
  Shape* leaf;

  void drawPedals(BMP* canvas, const Vector2& center, int x, int y) const;
 public:
  Flower(const Vector2& center);
  void draw(BMP* canvas) const;
};

}  // namespace cs225

#endif  // FLOWER_H_
