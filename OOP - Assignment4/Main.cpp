/*ישי יעיש - 305101560*/
/* תשעט_א_61307 ד"ר נודלמן ולדימיר */

#include <iostream>
#include "Node.h"
#include "Tree.h"




void main()
{
	Tree<double> t_double;
	Tree<int> t_int;
	t_double.add(4.22);
	t_double.add(2.41);
	t_double.add(5.61);
	t_double.add(1.12);
	t_double.add(10.9);
	t_double.add(3.2);
	
	std::cout << "--Double Tree--" << std::endl;
	std::cout << t_double;
	std::cout << std::endl << std::endl;
	t_double.search(5.6);
	t_double.search(2.41);

	t_double.size();

	std::cout << std::endl << std::endl;

	t_int.add(3);
	t_int.add(2);
	t_int.add(5);
	t_int.add(1);
	t_int.add(10);
	t_int.add(4);


	std::cout << "--Integer Tree--" << std::endl;
	std::cout << t_int;
	std::cout << std::endl << std::endl;
	t_int.search(6);
	t_int.search(4);

	t_int.size();

	std::cout << std::endl << std::endl;
}