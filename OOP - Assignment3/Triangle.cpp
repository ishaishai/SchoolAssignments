#include "Triangle.h"
#include <cmath>

Triangle::Triangle(const Point& o, const Point& a, const Point& b) : Polygon(3)
{
	this->pArr[0] = o;
	this->pArr[1] = a;
	this->pArr[2] = b;
}

const double Triangle::getArea() const
{
	return 0.5*((pArr[0].getX()*(pArr[2].getY() - pArr[1].getY())) +
		(pArr[1].getX() * (pArr[0].getY() - pArr[2].getY())) +
		(pArr[2].getX() * (pArr[1].getY() - pArr[0].getY())));
}

const double Triangle::getPerim() const
{
	return findDistance(pArr[0], pArr[1]) +
		findDistance(pArr[1], pArr[2]) +
		findDistance(pArr[2], pArr[0]);
}
