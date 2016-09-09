// SpriteBatchExperiment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "RenderWindow.h"
#include <memory>


int main()
{
	std::unique_ptr<RenderWindow> renderWindow(new RenderWindow());
	renderWindow->Initialize();
	renderWindow->MainLoop();
	int a;
	std::cin >> a;
    return 0;
}

