#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>


Circle::Circle(const Point& o, const int& r) : center(o),radius(r)
{
}

const double Circle::getArea() const
{
	return radius * radius * M_PI;
}

const double Circle::getPerim() const
{
	return 2 * M_PI * radius;
}