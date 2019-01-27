#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Polygon.h"

class Triangle : public Polygon
{
public:
	Triangle(const Point&, const Point&, const Point&);

	const double getArea() const;
	const double getPerim() const;
};



#endif