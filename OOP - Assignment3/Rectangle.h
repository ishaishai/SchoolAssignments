#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"
#include "Polygon.h"

class Rectangle : public Polygon
{
public:
	Rectangle(Point const& a, Point const& b);
	const double getArea() const;
	const double getPerim() const;
};


#endif