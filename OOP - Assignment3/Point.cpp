#include "Point.h"

Point::Point(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
}

Point::Point()
{

}

int Point::getX() const
{
	return this->x;
}

int Point::getY() const
{
	return this->y;
}

Point::~Point() { }

Point& Point::operator=(const Point &p)
{
	this->x = p.x;
	this->y = p.y;

	return (*this);
}