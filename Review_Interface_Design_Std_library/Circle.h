#pragma once
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:
	int center_x_, center_y_, raius_;

	Circle() //You need to define 
	{}

	Circle(const int& _x, const int& _y, const int& _r)
		: center_x_(_x), center_y_(_y), raius_(_r)
	{
		init(_x, _y, _r);  //I recommend this because this re0uses init function
	}

	void init(const int& _x, const int& _y, const int& _r)
	{
		center_x_ = _x;
		center_y_ = _y;
		raius_ = _r;
	}

	void draw()
	{
		// dreaw this Circle using cneter_x_, center_y_, radius
		std::cout << "Circle:: GeometricObject" << std::endl;
	}
};