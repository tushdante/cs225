/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 */

#include "flower.h"

#include <cmath>
#include <cstdio>

#include "circle.h"
#include "color.h"
#include "rectangle.h"
#include "triangle.h"

namespace cs225 {

namespace {

const int STEM_HEIGHT = 32;
const int STEM_WIDTH = 2;
const RGBApixel STEM_COLOR = color::GREEN;

const int LEAF_WIDTH = 8;
const int LEAF_HEIGHT = 8;
const RGBApixel LEAF_COLOR = color::GREEN;

const int PISTIL_RADIUS = 12;
const RGBApixel PISTIL_COLOR = color::YELLOW;

const int PEDAL_RADIUS = 2;
const RGBApixel PEDAL_COLOR = color::RED;

}  // namespace

Flower::Flower(const Vector2& center)
 {
  const Vector2 stem_center(center.x(), center.y()+STEM_HEIGHT/2);
  //Rectangle my_stem(stem_center, STEM_COLOR, STEM_WIDTH, STEM_HEIGHT);
  stem = new Rectangle(stem_center, STEM_COLOR, STEM_WIDTH, STEM_HEIGHT);; 

  pistil =new Circle(Vector2(center.x(), center.y() - PISTIL_RADIUS/2), PISTIL_COLOR, PISTIL_RADIUS);;

  const Vector2 leaf_center(stem_center.x() - LEAF_WIDTH, stem_center.y() +
      LEAF_HEIGHT);
  
  leaf = new Triangle(LEAF_COLOR,
                   leaf_center,
                   Vector2(leaf_center.x() - LEAF_WIDTH, stem->center().y() - LEAF_HEIGHT),
                   Vector2(leaf_center.x() + LEAF_WIDTH, stem->center().y()));
}


void Flower::drawPedals(BMP* canvas, const Vector2& center, int x, int y) const {
  Circle pedal(center, PEDAL_COLOR, PEDAL_RADIUS);
  pedal.set_center(Vector2(center.x()+x, center.y()+y));
  pedal.draw(canvas);
  pedal.set_center(Vector2(center.x()+x, center.y()-y));
  pedal.draw(canvas);
  pedal.set_center(Vector2(center.x()-x, center.y()+y));
  pedal.draw(canvas);
  pedal.set_center(Vector2(center.x()-x, center.y()-y));
  pedal.draw(canvas);
  pedal.set_center(Vector2(center.x()+y, center.y()+x));
  pedal.draw(canvas);
  pedal.set_center(Vector2(center.x()+y, center.y()-x));
  pedal.draw(canvas);
  pedal.set_center(Vector2(center.x()-y, center.y()+x));
  pedal.draw(canvas);
  pedal.set_center(Vector2(center.x()-y, center.y()-x));
  pedal.draw(canvas);
}

void Flower::draw(BMP* canvas) const {
  stem->draw(canvas);
  pistil->draw(canvas);
  leaf->draw(canvas);
  for (int x = 0; x < PISTIL_RADIUS; x++) {
    const double radius2 = PISTIL_RADIUS * PISTIL_RADIUS;
    const int y = static_cast<int>(sqrt(radius2 - (x * x)));
    drawPedals(canvas, pistil->center(), x, y);
  }
}

}  // namespace cs225
