#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class RenderWindow
{
public:
	RenderWindow();
	~RenderWindow();
	void Initialize();
	void HandleEvents();
	bool isOpen();
	void Close();
	void MainLoop();
	void preRender();
	void postRender();
private:
	void Destroy();
	bool mIsOpen;

	GLFWwindow* window;

};
