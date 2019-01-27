#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(const int& x, const int& y);
	Point();
	~Point();

	int getX() const;
	int getY() const;
	Point& operator=(const Point &p);
};

#endif