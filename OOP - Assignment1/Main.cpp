/*ישי יעיש - 305101560*/
/* תשעט_א_61307 ד"ר נודלמן ולדימיר */

#include "Collection.h"
#include <iostream>


using namespace std;

int main() {
	Collection g(4, 3, 2, 0);
	cout << "-- before setColor(2) --" << endl;
	g.print();
	Point p(5, 1);
	g.getCircleAt(p).setColor(2);
	cout << "-- after setColor(2) --" << endl;
	g.print();

	system("pause");

	return 0;
}