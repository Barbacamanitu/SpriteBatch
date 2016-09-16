#pragma once
#include <vector>
#include <glm\glm.hpp>
#include "Sprite.h"


class SpriteBatch
{
public:
	SpriteBatch();
	~SpriteBatch();
	int addSprite(Sprite spr);

	std::vector<float> vertices; //Vertices sent to gpu
private:
	std::vector<Sprite> sprites;
	void populateVertexArray();
	
};

