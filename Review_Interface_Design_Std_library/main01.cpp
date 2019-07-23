//2019-07-22

#include <iostream>
#include <vector>
#include "GeometricObject.h"
#include "Circle.h"
#include "Box.h"






int main()
{
	//GeometricObject ** array_pointer_of_Go = new...;

	std::vector< GeometricObject*> go_vector;

	go_vector.push_back(new Circle(100, 100, 10));
	go_vector.push_back(new Box);

	//for (auto itr = go_vector.begin(); itr != go_vector.end(); itr++)
	/*for (std::vector< GeometricObject*>::iterator itr=go_vector.begin(); itr != go_vector.end(); itr++)*/
	for (auto itr:go_vector)
	{
		/*(*itr)->draw();*/
		itr->draw();
	}


	//for (int i = 0; i < go_vector.size(); i++)
	//{
	//	go_vector[i]->draw();
	//}

	/*GeometricObject* my_circle = new Circle(100, 100, 10);
	GeometricObject* my_Box = new Box();

	my_circle->draw();
	my_Box->draw();*/
}