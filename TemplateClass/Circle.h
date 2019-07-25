#pragma once
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:
	int center_x_, center_y_, raius_;

	Circle(); //You need to define 


	Circle(const int& _x, const int& _y, const int& _r);

	void init(const int& _x, const int& _y, const int& _r);
	void  draw();
};