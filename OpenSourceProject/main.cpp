
#include <iostream>
#include <GLFW/glfw3.h>    //https://www.glfw.org/documentation.html

const int width = 680;
const int height = 460;

// color is (RED, GREEN, BLUE)
// dynamic memory allocation
float* pixels = new float[width * height * 3];
//float* pixels = (float *)malloc(sizeof(float) * width * height * 3);

void drawOnePixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width * j) * 3 + 0] = red;
	pixels[(i + width * j) * 3 + 1] = green;
	pixels[(i + width * j) * 3 + 2] = blue;
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

void clearBackGround()
{/*배경  BackGround Cleanig*/
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
			drawOnePixel(i, j, 1.0f, 1.0f, 1.0f);
	}
}
void drawEmptySquare()
{ /*빈사각형  Empty Square*/
	drawLine(200, 400, 250, 400, 0.0f, 0.0f, 1.0f);
	drawLine(200, 350, 250, 350, 0.0f, 0.0f, 1.0f);
	drawLine(200, 350, 200, 400, 0.0f, 0.0f, 1.0f);
	drawLine(250, 350, 250, 400, 0.0f, 0.0f, 1.0f);
}

//Object , clasee, Instance
class Line
{
public : // public, private, protected
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

const int num_lines = 10;

Line* my_lines = new Line[num_lines];

void initializeLines()
{
	for (int i = 0; i < num_lines; i++)
	{
		
		my_lines[i].initializeLine(100 * i + 10, 10 , 100 * i + 50, 50 );
	}
}

void draw()
{
	/*배경  BackGround Cleanig*/
	clearBackGround();

	
	for (int i = 0; i < num_lines; i++)
		my_lines[i].draw();


	/*사선*/
	for (int i = 50; i >= 46; i--)
	{
		static int y = 350;

		for (int j = 0; j < 3; j++)
		{
			drawLine(i, y + j, i + 50, (y + j) + 50, 0.0f, 0.0f, 1.0f);
		}

		y += 2;
		if (y >= 360)
			y = 350;
	}


	/*빈사각형  Empty Square*/
	drawEmptySquare();


	/*채운사각형*/
	for (int j = 350; j < 400; j++)
	{
		for (int i = 300; i < 350; i++)
			drawOnePixel(i, j, 0.0f, 0.0f, 1.0f);
	}


}


int main(void)
{
	initializeLines();
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

		draw();    // draw figure


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