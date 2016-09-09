#include "stdafx.h"
#include "RenderWindow.h"
#include <vcruntime_exception.h>

RenderWindow::RenderWindow()
{
	mIsOpen = false;
}


RenderWindow::~RenderWindow()
{
	Destroy();
}

void RenderWindow::HandleEvents()
{

}


bool RenderWindow::isOpen()
{
	return mIsOpen;
}

void RenderWindow::Close()
{
	mIsOpen = false;
	glfwTerminate();
}


void RenderWindow::MainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//RENDER

		/* Swap front and back buffers */
		glfwSwapBuffers(window);



		glfwPollEvents();

	}
}

void RenderWindow::Initialize()
{
	if (!glfwInit())
	{
		// Initialization failed
		throw std::exception("Could not initialize GLFW.");
	}

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		throw std::exception("Could not create window.");
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


}

void RenderWindow::Destroy()
{
	Close();
}

