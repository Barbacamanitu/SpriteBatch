#include "stdafx.h"
#include "SpriteBatch.h"
#include <glm/gtx/transform.hpp>



SpriteBatch::SpriteBatch()
{
}


SpriteBatch::~SpriteBatch()
{
}

int SpriteBatch::addSprite(Sprite spr)
{
	sprites.push_back(spr);
	return sprites.size() - 1;
}

void SpriteBatch::populateVertexArray()
{
	vertices.clear();
	vertices.resize(sprites.size() * VERTEX_SIZE * 4);
	for (auto it = sprites.begin(); it != sprites.end(); it++)
	{
		int offset = std::distance(sprites.begin(), it);
		offset *= VERTEX_SIZE * 4;
		it->pushToVertexArray(&vertices[offset]);
	}
}


