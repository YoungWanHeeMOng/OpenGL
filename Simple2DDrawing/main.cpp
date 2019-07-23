
#include <GLFW/glfw3.h>
//#include <algorithm>
//#include <math.h>
//#include "drawShader.h"

//#include <stdio.h>

const int width = 640 ;
const int height = 460;

// color is (RED, GREEN, BLUE)
// dynamic memory allocation
float* pixels = new float[width * height * 3];
//float* pixels = (float *)malloc(sizeof(float) * width * height * 3);

void drawPixel(const int& i, const int& j,const float& red, const float& green, const float& blue)
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

void draw()
{
	const int i_center = 50, j_center = 50;
	const int thickness = 5;

	for (int j = j_center - thickness; j < j_center + thickness; j++)
		for (int i = i_center - thickness; i < i_center + thickness; i++)
		{
			drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		}
	drawLine(10, 10, 600, 300, 0.0f, 0.0f, 1.0f);

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

		// assign all pixels red color
		// white background color (1.0f, 1.0f, 1.0f)
		for (int j = 0; j < height; j++)
			for (int i = 0; i < width; i++)
			{
				pixels[(i + width * j) * 3 + 0] = 1.0f;
				pixels[(i + width * j) * 3 + 1] = 1.0f;
				pixels[(i + width * j) * 3 + 2] = 1.0f;
			}
		
		draw();


		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();


		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}



	glfwTerminate();

	delete[] pixels;

	// free(pixels); // inc 
	return 0;
}