//2019-07-22

#include <iostream>
#include <vector>
#include "GeometricObject.h"


int main()
{
	//GeometricObject go;

	std::vector< GeometricObject*> go_vector;
	
	go_vector.push_back(GeometricObject::getGeometricObject("Circle"));
	go_vector.push_back(GeometricObject::getGeometricObject("Box"));

	for (auto itr : go_vector)
	{
		
		itr->draw();
	}
	
	for (auto itr : go_vector)
	{
		delete[] itr;
	}

	return 0;
}