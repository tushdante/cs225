/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 */

#ifndef LINE_H_
#define LINE_H_

#include <vector>

#include "drawable.h"
#include "vector2.h"

namespace cs225 {

/**
 * @brief The Line class is a subclass of Drawable and represents a line in 2D
 * space
 */
class Line : public Drawable {
 private:
  Vector2 a_;
  Vector2 b_;
  RGBApixel color_;

 public:

  /**
   * @brief Constructs a new Line going from Point a to Point b
   *
   * @param a
   * @param b
   * @param color of the new Line
   */
  Line(const Vector2& a, const Vector2& b, const RGBApixel& color);

  /**
   * @brief Draws the Line onto the canvas
   *
   * @param canvas
   */
  void draw(BMP* canvas) const;

  /**
   * @brief Gets starting point of the Line
   *
   * @return the starting point of the Line
   */
  Vector2 a() const;

  /**
   * @brief Sets the starting point of the Line
   *
   * @param a the new starting point of the Line
   */
  void set_a(const Vector2& a);

  /**
   * @brief Gets the ending point of the Line
   *
   * @return the ending point of the Line
   */
  Vector2 b() const;

  /**
   * @brief Sets the ending point of the Line
   *
   * @param b the new ending point of the Line
   */
  void set_b(const Vector2& b);

  /**
   * @brief Gets the color of the Line
   *
   * @return the color of the Line
   */
  RGBApixel color() const;

  /**
   * @brief Sets the color of the Line
   *
   * @param color the new color of the Line
   */
  void set_color(const RGBApixel& color);

  static std::vector<double> linearInterpolation(const Vector2& a,
                                                 const Vector2& b);

};

}  // namespace cs225

#endif  // LINE_H_
