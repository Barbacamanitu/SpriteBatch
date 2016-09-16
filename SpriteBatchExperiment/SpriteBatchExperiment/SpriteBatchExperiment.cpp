// SpriteBatchExperiment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "RenderWindow.h"
#include <memory>
#include "GLHelpers\ImageLoader.hpp"
#include "GLHelpers\ShaderFactory.h"
#include "ErrorHandling\ErrorContext.h"
#include "SpriteBatch.h"
int main()
{
	std::unique_ptr<RenderWindow> renderWindow(new RenderWindow());
	renderWindow->Initialize();

	GLuint myTexture = ImageLoader::createTextureFromFile("Sprites\\sheet.png");
	GLuint shader = ShaderFactory::CreateSpriteProgram("Shaders\\sprite_fragment.gl", "Shaders\\sprite_vertex.gl");

	Sprite s1;
	Sprite s2;

	SpriteBatch* sprBatch = new SpriteBatch();
	std::vector<int> sprIds;

	sprIds.push_back(sprBatch->addSprite(s1));
	sprIds.push_back(sprBatch->addSprite(s2));
	while (renderWindow->isOpen())
	{
		renderWindow->preRender();
		renderWindow->postRender();
	}
	
	int a;
	std::cin >> a;
    return 0;
}

