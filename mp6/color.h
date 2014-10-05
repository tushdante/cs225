/**
 * color.h
 *
 * A simple structure representing color data.  We represent color data
 * in only RGB format.  That is, there is a 0-255 value for red, green,
 * and blue channels
 *
 * Authors:
 * Matt Sachtler
 * Scott Wegner
 *
 * Developed for CS225 PhotoMosaic MP
 * Fall 2008
 */

#ifndef _COLOR_H
#define _COLOR_H

struct Color {
    /**
     * The red channel value
     */
    int rValue;
    /**
     * The green channel value
     */
    int gValue;
    /**
     * The blue channel value
     */
    int bValue;
};

#endif /* _COLOR_H */
