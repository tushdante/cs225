/*
	point.h

	Written by Matt Sachtler for CS225 MP6
	Spring 2009
	Revision history:
		3/21/2009        Created
*/

#ifndef __POINT_H__
#define __POINT_H__

#include <stdexcept>
#include <iostream>
using std::out_of_range;
using std::cout;
using std::endl;

template<int Dim>
class Point{
	double vals[Dim];

	public:
		Point(double arr[Dim]);
		Point();

		double operator[](int index) const;
		bool operator==(const Point<Dim> p) const;
		bool operator!=(const Point<Dim> p) const;
		bool operator<(const Point<Dim> p) const;

		void set(int index, double val);

		void print() const;

};

#include "point.cpp"

#endif
