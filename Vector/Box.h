#pragma once
#include "GeometricObject.h"

class Box : public GeometricObject
{
public:
	int bottom_left_x_, bottom_left_y_; // right_up
	void draw();
	
};