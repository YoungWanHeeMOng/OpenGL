#include "Circle.h"


Circle::Circle() //You need to define 
{}

Circle::Circle(const int& _x, const int& _y, const int& _r)
	: center_x_(_x), center_y_(_y), raius_(_r)
{
	init(_x, _y, _r);  //I recommend this because this re0uses init function
}
void Circle::init(const int& _x, const int& _y, const int& _r)
{
	center_x_ = _x;
	center_y_ = _y;
	raius_ = _r;
}

void  Circle::draw()
{

	std::cout << "Circle:: GeometricObject" << std::endl;
}