#include "Polygon.h"
#include <cmath>

Polygon::Polygon(const int& size)
{
	this->pArr = new Point[size];
	this->size = size;
}


Polygon::~Polygon()
{
	delete[] this->pArr;
}

const double findDistance(const Point& a, const Point& b) // function finds distance from point to point
{
	return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

const double Polygon::getArea() const // function divides every polygon into small rectangles and adds all areas together
{
	double area = 0;
	double edge1, edge2, edge3;

	for (int i = 0; i < this->size - 2; i++)
	{
		edge1 = findDistance(this->pArr[0], this->pArr[i + 1]);
		edge2 = findDistance(this->pArr[i+1], this->pArr[i + 2]);
		edge3 = findDistance(this->pArr[0], this->pArr[i + 2]);

		area += calcTriangleArea(edge1, edge2, edge3);
	}

	return area;
}


double Polygon::calcTriangleArea(double edge1, double edge2, double edge3) const
{
	//formula for calculating rectangle area taken from assignment
	return (0.25 * (sqrt((edge1 + edge2 + edge3)*(edge1 + edge2 - edge3)*(edge1 - edge2 + edge3)*(-edge1 + edge2 + edge3))));
}