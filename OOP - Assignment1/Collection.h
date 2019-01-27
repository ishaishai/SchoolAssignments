#ifndef COLLECTION_H
#define COLLECTION_H
#include "Circle.h"

class Collection
{
public:
	//Collection set of circles by radius size, height*width amount and a color
	Collection(int radius, int width, int height, int color); 
	~Collection();
	Circle& getCircleAt(const Point &p);
	void print() const;
private:
	int count;
	Circle **circles;
};

#endif