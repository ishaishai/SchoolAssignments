#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
class Circle
{
public:
	//Circle set by (x,y) radius and color has contains(p) to find if a point exists
	Circle(int x, int y, int r, int color);
	int getColor() const;
	void setColor(int color);
	bool contains(const Point &p) const;
	void print() const;
private:
	const Point center;
	int radius, color;
};


#endif