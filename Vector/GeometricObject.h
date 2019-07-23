#pragma once

#include <iostream>

// interface
class GeometricObject
{
public:
	virtual void draw(); //declaration, definition(body)
	static GeometricObject* getGeometricObject(const std::string& name);
	//{
//	if (name == "Box")
//		return new Box;
//	else if (name == "Circle")
//		return new Circle;
//
//	return nullptr;
//}
};


