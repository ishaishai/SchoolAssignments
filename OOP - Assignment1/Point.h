#ifndef POINT_H
#define POINT_H

class Point
{
public:
	//Point set by (x,y) has getters,setters and print function 
	Point(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void print() const;
private:
	int x, y;
};


#endif