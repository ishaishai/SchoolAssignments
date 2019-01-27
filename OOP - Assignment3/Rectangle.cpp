#include "Rectangle.h"

Rectangle::Rectangle(const Point &a, const Point &b) : Polygon(4)
{
	this->pArr[0] = a;
	this->pArr[1] = b;
	this->pArr[2] = Point(a.getX(), b.getY());
	this->pArr[3] = Point(b.getX(), a.getY());
	
}

const double Rectangle::getArea() const
{
	Point tmp(pArr[1].getX(), pArr[0].getY());

	return findDistance(pArr[0], tmp) * findDistance(pArr[1], tmp);
}

const double Rectangle::getPerim() const
{
	Point tmp(pArr[1].getX(), pArr[0].getY());

	return 2 * findDistance(pArr[0], tmp) + 2 * findDistance(pArr[1], tmp);
}

