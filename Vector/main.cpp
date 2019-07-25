//2019-07-22

#include <iostream>
#include <vector>
#include "GeometricObject.h"


//
//class Test
//{
//public:
//	int a_;
//
//
//	Test(const int& _a)
//		:a_(_a)
//	{
//		std::cout << &a_ << std::endl;
//		std::cout << "Int constructor" << std::endl;
//	}
//	
//	Test(const Test& _test)
//		:a_(_test.a_)
//	{
//		std::cout << &_test << std::endl;
//		std::cout << "Copy constructor" << std::endl;
//	}
//
//	void print()
//	{
//		std::cout << a_ << std::endl;
//	}
//};
//
//void printTest(Test test)
//{
//	std::cout << &test << std::endl;
//	test.print();
//}
//
//void printTestRef(Test& test)
//{
//	std::cout << &test << std::endl;
//	test.print();
//}
//
//typedef Test* PTR_TEST;
//
//void printTestPtr(PTR_TEST test)
//{
//	std::cout << &test << std::endl;
//	test->print();
//}


int main()
{
	/*Test my_test(123);

	std::cout << "PrintTest" << std::endl;
	printTest(my_test);

	std::cout << "PrintTestRef" << std::endl;
	printTestRef(my_test);

	std::cout << "PrintTestPtr" << std::endl;
	printTestPtr(&my_test);*/

	//GeometricObject go;

	std::vector< GeometricObject*> go_vector;
	
	// read script
	// for (script commend)
	go_vector.push_back(GeometricObject::getGeometricObject("Circle"));
	go_vector.push_back(GeometricObject::getGeometricObject("Box"));
	//go_vector.push_back(go.getGeometricObject("Circle"));
	//go_vector.push_back(go.getGeometricObject("Box"));

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