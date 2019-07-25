//2019-07-25
// Template programming

#include <iostream>
#include <vector>
#include "GeometricObject.h"
#include "TestClass.h"

template<class T>
class MyObject
{
public:
	T my_variable;

	void draw()
	{
		std::cout << "MyObject::Draw()" << std::endl;
	}
	friend std::ostream& operator<< (std::ostream& os, const MyObject& vec)
	{
		os << vec.x_ << " " << vec.y_;
		return os;
	}
};
//template  templatize

template<class T_OBJECT>
void draw(T_OBJECT& obj)
{
	obj.draw();
}

template<class T>
class Vector
{
public:
	T x_, y_;

	friend std::ostream& operator<< (std::ostream& os, const Vector& vec)
	{
		os << vec.x_ << " " << vec.y_;
		return os;
	}
	friend Vector operator + (Vector lhs, const Vector& rhs)
	{
		lhs.x_ += rhs.x_;
		lhs.y_ += rhs.y_;
		return lhs;
	}
};
class VectorFloat2D
{
public:
	float x, y;
};

class VectorDouble2D
{
public:
	double x, y;
};
class VectorInt2D
{
public:
	int x, y;
};

// generic function
template<class T_CLASS>
void print(const T_CLASS& input)
{
	std::cout << input << std::endl;
}
template <class T_A, class T_B>
class Box
{
public:
	T_A a_v;
	T_B b_v;
};

int main()
{

	Vector<float> my_vector, my_vector2, my_vector3;
	my_vector.x_ = 1.0f;
	my_vector.y_ = 2.0f;

	my_vector2.x_ = 3.0f;
	my_vector2.y_ = 4.0f;

	my_vector3 = my_vector + my_vector2;

	print(my_vector3);


	Vector<MyObject<Box<int, float> > > my_vector1;
	print(my_vector);

	TestClass<int> tc;

	std::vector< GeometricObject*> go_vector;

	go_vector.push_back(GeometricObject::getGeometricObject("Circle"));
	go_vector.push_back(GeometricObject::getGeometricObject("Box"));

	for (auto itr : go_vector)
	{
		itr->draw();
	}

	for (auto itr : go_vector)
	{
		delete itr;
	}

	return 0;
}