/*��� ���� - 305101560*/
/* ����_�_61307 �"� ������ ������� */

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