#include "Circle.h"

#include <iostream>

using namespace std;

Circle::Circle(int x, int y, int r, int color) : center(x,y)
{
	this->radius = r;
	this->color = color;
}

int Circle::getColor() const
{
	return this->color;
}

void Circle::setColor(int color)
{
	this->color = color;
}

bool Circle::contains(const Point &p) const
{
	if (((p.getX() - this->center.getX())*(p.getX() - this->center.getX())) +
		((p.getY() - this->center.getY())*(p.getY() - this->center.getY())) <= (this->radius)*(this->radius))
	{
		return true;
	}
	return false;
}

void Circle::print() const
{
	cout << "Circle center = ";
	this->center.print();
	cout<< " Radius = " << this->radius << " color = " << this->color << endl;
}