/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 *
 * Please see circle.h for documentation of the Circle class
 */

#include "circle.h"

#include <cassert>
#include <cstdio>
#include <cmath>

namespace {

const double PI = 3.141592;

}  // namespace

namespace cs225 {

Circle::Circle(const Vector2& center, const RGBApixel& color, int radius)
: Shape(center, color), radius_(radius)  {
  /* Nothing.  See initialization list. */
}

int Circle::area() const {
  const int area = static_cast<int>(PI * radius_ * radius_);
  return area;
}

int Circle::perimeter() const {
  const int perimeter = static_cast<int>(PI * 2 * radius_);
  return perimeter;
}

bool Circle::contains(const Vector2& p) const {
  const double distance = this->center().distanceTo(p);
  return distance <= this->radius_;
}

void Circle::drawPoints(BMP* canvas, int x, int y) const {
  RGBApixel* pixel;
  int i;
  int j;
  while (y > 0) {
    i = static_cast<int>(this->center().x() + x);
    j = static_cast<int>(this->center().y() + y);
    pixel = (*canvas)(i, j);
    *pixel = this->color();

    i = static_cast<int>(this->center().x() + x);
    j = static_cast<int>(this->center().y() - y);
    pixel = (*canvas)(i, j);
    *pixel = this->color();

    i = static_cast<int>(this->center().x() - x);
    j = static_cast<int>(this->center().y() + y);
    pixel = (*canvas)(i, j);
    *pixel = this->color();

    i = static_cast<int>(this->center().x() - x);
    j = static_cast<int>(this->center().y() - y);
    pixel = (*canvas)(i, j);
    *pixel = this->color();

    i = static_cast<int>(this->center().x() + y);
    j = static_cast<int>(this->center().y() + x);
    pixel = (*canvas)(i, j);
    *pixel = this->color();

    i = static_cast<int>(this->center().x() + y);
    j = static_cast<int>(this->center().y() - x);
    pixel = (*canvas)(i, j);
    *pixel = this->color();

    i = static_cast<int>(this->center().x() - y);
    j = static_cast<int>(this->center().y() + x);
    pixel = (*canvas)(i, j);
    *pixel = this->color();

    i = static_cast<int>(this->center().x() - y);
    j = static_cast<int>(this->center().y() - x);
    pixel = (*canvas)(i, j);
    *pixel = this->color();

    y -= 1;
  }
}

void Circle::draw(BMP* canvas) const {
  RGBApixel* pixel = (*canvas)(static_cast<int>(this->center().x()),
                               static_cast<int>(this->center().y()));
  *pixel = this->color();

  int x = 0;
  int y = this->radius_;
  int p = 1 - this->radius_;
  this->drawPoints(canvas, x, y);

  while (x < y) {
    x++;
    if (p < 0) {
      p += 2 * x + 1;
    } else {
      y--;
      p += 2 * (x - y + 1);
    }
    this->drawPoints(canvas, x, y);
  }
}

int Circle::radius() const {
  return this->radius_;
}

void Circle::set_radius(int radius) {
  this->radius_ = radius;
}

}  // namespace cs225
