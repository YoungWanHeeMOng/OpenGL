#include "GeometricObject.h"
//#include <string>
#include "Box.h"
#include "Circle.h"

// factry pattern
void GeometricObject::draw()
{

	std::cout << "GeometricObject" << std::endl;
}

GeometricObject* GeometricObject::getGeometricObject(const std::string& name)
{
	if (name == "Box")
		return new Box;
	else if (name == "Circle")
		return new Circle;
	else
		return nullptr;
}