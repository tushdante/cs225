/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "shape.h"

namespace cs225 {

/**
 * @brief The Circle class is a subclass of Shape and represents a Circle in a
 * 2D space
 */
class Circle : public Shape {
 private:
  int radius_;
  void drawPoints(BMP* canvas, int x, int y) const;
 public:
  /**
   * @brief Constructs a new Circle with the given center, color, and radius
   *
   * @param center point of the new Circle
   * @param color of the new Circle
   * @param radius of the new Circle in pixels
   */
  Circle(const Vector2& center, const RGBApixel& color, int radius);

  /**
   * @brief Computes and returns the area of the Circle in pixels
   *
   * @return the area of the Circle in pixels
   */
  int area() const;

  /**
   * @brief Computes and returns the perimeter of the Circle in pixels
   *
   * @return the perimeter of the Circle in pixels
   */
  int perimeter() const;

  /**
   * @brief Checks to see if the given point is inside the Circle
   *
   * @param p
   *
   * @return true if p is inside the Circle
   */
  bool contains(const Vector2& p) const;

  /**
   * @brief Draws the Circle to the canvas
   *
   * @param canvas
   */
  void draw(BMP* canvas) const;

  /**
   * @brief Gets the radius of the Circle in pixels
   *
   * @return the radius of the Circle in pixels
   */
  int radius() const;

  /**
   * @brief Sets the radius of the Circle in pixels
   *
   * @param radius the new radius of the Circle in pixels
   */
  void set_radius(int radius);

};

}  // namesapce cs225

#endif  // CIRCLE_H_
