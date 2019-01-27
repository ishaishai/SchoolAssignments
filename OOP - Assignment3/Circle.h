#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
private:
	int radius;
	const Point center;

public:
	
	Circle(const Point&, const int&);
	const double getArea() const;
	const double getPerim() const;
};

#endif