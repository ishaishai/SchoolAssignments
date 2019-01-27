////////////////////////////////////////////////////////////////////////////////////
////////// OOP - Assignment 2 - Class number: 61307 - ד"ר נודלמן ולדימיר //////////
//////////																  //////////
//////////				ID: 305101560 - Name: Ishai Yaish		          //////////
////////////////////////////////////////////////////////////////////////////////////
 
#include <iostream>
#include "Matrix.h"

using namespace std;

void main() 
{
	Matrix m(2, 2);
	m[0][0] = 2;
	m[1][1] = 2;
	cout << m << endl;
	m = m;
	const Matrix s = -m;
	cout << m << endl << s << endl;
	m = s + 2 * - m * m * 2 - s;
	
	cout << m << endl << s << endl;
	cout << s[1][1] << endl;
}
