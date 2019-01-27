#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include "Point.h"

class Polygon : public Shape
{
protected:
	Point *pArr;
	int size;

public:
	Polygon(const int&);
	virtual ~Polygon(); // the only derived destructor which exists and is virtual, in order to delete triangle\rectangle we need to de-allocate pArr which is common to them in Polygon
	
	const double getArea() const;
	double calcTriangleArea(double edge1, double edge2, double edge3) const;
};

const double findDistance(const Point&, const Point&);

#endif