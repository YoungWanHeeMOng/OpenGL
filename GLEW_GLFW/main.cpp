

#include <GLFW/glfw3.h>
#include <algorithm>
#include <math.h>
//#include "drawShader.h"

//#include <stdio.h>

const int width = 680;
const int height = 460;
const float PI = 3.141592;

float* pixels = new float[width * height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width * j) * 3 + 0] = red;
	pixels[(i + width * j) * 3 + 1] = green;
	pixels[(i + width * j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i < i1; i++)
	{
		const int j = (j1 - j0) * (i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawCicle(const int& r, const int& x, const int& y, const float& red, const float& green, const float& blue)
{
	for (int i = -2*r; i <=2*r; i += 1)
	{
		for (int j = -r; j <= r; j++)
		{
			if ((i * i + j * j) >= r * r - r / 1.3 && (i * i + j * j) <= r *r + r / 1.3)
			{
				drawPixel(x +r-i, y +r-j, red, green, blue);

			}

		}
	}
}


void drawRectangleFill( const int& x0 , const int& y0, const int& x1, const int& y1, const float& red, const float& green, const float& blue)
{
	for (int i = x0; i <= x1; i++)
	{
		for (int j = y0; j <= y1; j++)
		{
			
			drawPixel(i, j, red, green, blue);
		}
	}
}

void drawRectangle(const int& x0, const int& y0, const int& x1, const int& y1, const float& red, const float& green, const float& blue)
{
	for (int i = x0; i <= x1; i++)
	{
		drawPixel(i, y0, red, green, blue);
		
	}
	
	for (int i = x0; i <= x1; i++)
	{
		drawPixel(i, y1, red, green, blue);

	}
	for (int i = y0; i <= y1; i++)
	{
		drawPixel(x0, i, red, green, blue);

	}
	for (int i = y0; i <= y1; i++)
	{
		drawPixel(x1, i, red, green, blue);

	}

}


void DrawTriangle(const int& r, const int& x0, const int& y0, const int& x1, const int& y1, const float& red, const float& green, const float& blue)
{
	const int center =(int) (x0 + x1) / r;

	drawLine(x0, y0, center, y1, red, green, blue);
	drawLine(center, y1, x1, y0, red, green, blue);
	drawLine(x0, y0, x1, y0, red, green, blue);

}
void DrawTriangleFill(const int& r, const int& x0, const int& y0, const int& x1, const int& y1, const float& red, const float& green, const float& blue)
{
	const int center = (int)(x0 + x1) / r;

	for (int i=x0; i <= center ; i++)
	{
		for (int j =y0; j <=y1; j++)
				drawLine(i,y0,center,j, red, green, blue);
	}

	for (int i = center; i <= x1; i++)
	{
		for (int j = y1; j >= y0; j--)
			drawLine(center, j, i,y0, red, green, blue);
	}
	
}

int main(void)
{
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

	//glClearColor(0, 0, 1, 0);   // draw base color

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		std::fill_n(pixels, width * height * 3, 1.0f);
			
		// Darw Point
		drawPixel(25, 25, 1.0f, 0.0f, 0.0f);

		// Draw Line
		drawLine(0, 0, 550, 350, 0.0f, 1.0f, 0.0f);

		// Draw Cicles
		drawCicle(70, 150, 150, 1.0f, 0.0f, 0.0f); 

		// Draw Ractangles
		drawRectangleFill(100,100 ,200, 200, 1.0f, 0.5f, 0.5f);
		drawRectangle(300, 300, 400, 400, 0.0f, 1.0f, 0.0f);

		// Draw Triangle
		DrawTriangle(2, 250, 150, 350, 250, 0.0f, 0.0f, 1.0f);
		DrawTriangleFill(2, 50, 350, 150, 450, 0.0f, 0.0f, 1.0f);

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	

	delete[] pixels;

	glfwTerminate();
	return 0;
}