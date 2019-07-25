#pragma once
#include <iostream>

// interface
class GeometricObject
{
public:
	virtual void draw(); //declaration, definition(body)
	static GeometricObject* getGeometricObject(const std::string& name);

};