#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	virtual const double getArea() const = 0;
	virtual const double getPerim() const = 0;
	virtual ~Shape() {};
};

#endif