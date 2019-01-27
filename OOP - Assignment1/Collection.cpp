#include "Collection.h"
#include <iostream>


using namespace std;

Collection::Collection(int radius, int width, int height, int color) 
{
	int row = 0;
	this->count = width * height;
	this->circles = new Circle*[count];

	for (int i = 0;i < count;i++)
	{
		this->circles[i] = new Circle((i%width) * 2 * radius, (row%height) * 2 * radius, radius, color);
		if ((i + 1) % width == 0)
		{
			row++;
		}
	}
}

Collection::~Collection()
{
	cout << "\nObject collection was deleted\n";
}

Circle& Collection::getCircleAt(const Point &p)
{
	int i = 0;
	
	for (; i < count; i++)
	{
		if (circles[i]->contains(p))
			return (*(circles[i]));
	}
	return (*(circles)[i - 1]);
}

void Collection::print() const
{
	cout << "Collection Print: " << endl;
	
	for (int i = 0; i < this->count; i++)
	{
		circles[i]->print();
	}
}