// 2019-07-19

#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

//glfw
const int width = 640;
const int height = 480;

const int num_lines = 5;
const int num_boxes = 10;

float* pixels = new float[width * height * 3];

void drawLine(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue);
void drawSquare(int thickness, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawOnePixel(const int& i, const int& j, const float& red, const float& green, const float& blue);
void drawRect(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawOnPixelBuffer();

//////////////////////////////////////////////////////////////////////////////
void drawOnePixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width * j) * 3 + 0] = red;
	pixels[(i + width * j) * 3 + 1] = green;
	pixels[(i + width * j) * 3 + 2] = blue;
}

void drawSquare(int thickness, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	int i_center = (i0 + i1) / 2;
	int j_center = (j0 + j1) / 2;

	for (int j = j_center - thickness; j < j_center + thickness; j++) {
		for (int i = i_center - thickness; i < i_center + thickness; i++) {
			drawOnePixel(i, j, red, green, blue);
		}
	}
}

void drawRect(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	int i, j;
	for (i=i0; i <=i1; i++)
		drawOnePixel(i, j0, red, green, blue);
	for (i = i0; i <= i1; i++)
		drawOnePixel(i, j1, red, green, blue);

	for (j = j0; j <= j1; j++)
		drawOnePixel(i0, j, red, green, blue);
	for (j = j0;j <= j1; j++)
		drawOnePixel(i1, j, red, green, blue);
}
void drawLine(const int& x_s, const int& y_s, const int& x_e, const int& y_e, const float& red, const float& green, const float& blue)
{
	if (x_e == x_s)
	{
		for (int y = y_s; y <= y_e; y++)
			drawOnePixel(x_s, y, red, green, blue);
	}
	else
	{
		for (int i = x_s; i <= x_e; i++)
		{
			const int j = (y_e - y_s) * (i - x_s) / (x_e - x_s) + y_s;
			drawOnePixel(i, j, red, green, blue);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//Object , clasee, Instance
class GeometricObject
{
public:
	virtual void draw()
	{
		std::cout << "GeometricObject::Draw" << std::endl;
	}
};

class Line : public GeometricObject
{
public: // public, private, protected
	int start_x, start_y;  // member variables
	int end_x, end_y;

	void initializeLine(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;

		end_x = _end_x;
		end_y = _end_y;
	}

	void draw()  //member fuynction
	{
		// Draw line
		drawLine(start_x, start_y, end_x, end_y, 0.0f, 0.0f, 1.0f);
	}
};

class Box : public GeometricObject
{
public: // public, private, protected
	int start_x, start_y;  // member variables
	int end_x, end_y;

public:
	Box()
	{
	}

	//constructor
	Box(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		initializeLine(_start_x, _start_y, _end_x, _end_y);
	}

	void initializeLine(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;

		end_x = _end_x;
		end_y = _end_y;
	}

	void draw()
	{
		drawRect(start_x, start_y, end_x, end_y, 0.0f, 0.0f, 1.0f);
	}
};


//Line** my_lines = new Line*[num_lines];
//Box** my_boxes = new Box*[num_boxes];
GeometricObject** my_objects = new GeometricObject * [num_boxes];
	

void drawOnPixelBuffer()
{
	//std::memsset(pixels, 1.0f, sizeof(float)*width*hight*3)
	std::fill_n(pixels, width * height * 3, 1.0f);

	/*for (int i=0; i< num_lines; i++)
		my_lines[i]->draw();

	
	for (int i = 0; i < num_boxes; i++)
	{
		my_boxes[i]->draw();
	}*/
	for (int i = 0; i < num_boxes; i++)
		my_objects[i]->draw();

}


int main(void)
{

	int count = 0;

	GeometricObject *my_geo=new GeometricObject;
	my_geo->draw();

	//Boxes *my_box=new Boxes;
	GeometricObject* my_box = new Box;  // polymorphism
	//my_box->draw();

	//initialize lines
	for (int i = 0; i < 5; i++)
	{
		Line* temp = new Line;
		
		temp->start_x = 0 + 50 * i;
		temp->start_y = 0;

		temp ->end_x = 50 + 50 * i;
		temp->end_y = 50;

		my_objects[i] = temp;
	}

	//initialize boxes
	for (int i =5; i < num_boxes; i++)
	{
		my_objects[i]=new Box(i + 50, 50, i * 50 + 100, 100);
			//my_boxes[i]->initializeLine(i+50, 50, i*50 + 100, 100);

	}

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}