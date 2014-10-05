/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 *
 * Please see rectangle.h for documentation of the Rectangle class
 */

#include "rectangle.h"

#include <cstdio>

namespace cs225 {

Rectangle::Rectangle(const Vector2& center, const RGBApixel& color,
                     int width, int height)
: Shape(center, color),
  width_(width),
  height_(height) {
  /* Nothing.  See initialization list. */
}

int Rectangle::area() const {
  return this->width_ * this->height_;
}

int Rectangle::perimeter() const {
  return 2 * (this->width_ + this->height_);
}

bool Rectangle::contains(const Vector2& p) const {
  const Vector2 top_left_corner(this->center().x()-(this->width_/2),
                                this->center().y()-(this->height_/2));
  const Vector2 bottom_right_corner(this->center().x()+(this->width_/2),
                                    this->center().y()+(this->height_/2));
  const bool inside_top_left = (p == top_left_corner) ||
                               (p.isSouthEastOf(top_left_corner));
  const bool inside_bottom_right = (p == bottom_right_corner) ||
                                   (p.isNorthWestOf(bottom_right_corner));
  return inside_top_left || inside_bottom_right;
}

void Rectangle::draw(BMP* canvas) const {
  RGBApixel* pixel;
  const int x_offset = static_cast<int>(this->center().x() - (this->width_ / 2));
  const int y_offset = static_cast<int>(this->center().y() - (this->height_ / 2));
  for (int i = 0; i < this->width_; i++) {
    for (int j = 0; j < this->height_; j++) {
      pixel = (*canvas)(x_offset+i, y_offset+j);
      *pixel = this->color();
    }
  }
}

int Rectangle::width() const {
  return this->width_;
}

void Rectangle::set_width(int width) {
  this->width_ = width;
}

int Rectangle::height() const {
  return this->height_;
}

void Rectangle::set_height(int height) {
  this->height_ = height;
}

}  // namespace cs225
