#pragma once
#include "stdafx.h"
#include "Sprite.h"

void Sprite::pushToVertexArray(float* firstElement)
{
	for (int i = 0; i < 4; i++)
	{
		firstElement[(i * VERTEX_SIZE) + 0] = transformedCorners[i].x;
		firstElement[(i * VERTEX_SIZE) + 1] = transformedCorners[i].y;
		firstElement[(i * VERTEX_SIZE) + 2] = transformedCorners[i].z;

		firstElement[(i * VERTEX_SIZE) + 3] = texCoords[i].x;
		firstElement[(i * VERTEX_SIZE) + 4] = texCoords[i].y;
	}
}

void Sprite::calculateCorners()
{
	//Only call this when the sprite size has changed.
	corners[0].x = position.x - (size.x * .5f);
	corners[0].y = position.y + (size.x * .5f);

	corners[1].x = position.x + (size.x * .5f);
	corners[1].y = position.y + (size.x * .5f);

	corners[2].x = position.x + (size.x * .5f);
	corners[2].y = position.y - (size.x * .5f);

	corners[3].x = position.x - (size.x * .5f);
	corners[3].y = position.y - (size.x * .5f);

	texCoords[0].x = frameLocation.x;
	texCoords[0].y = frameLocation.y + frameSize.y;

	texCoords[1].x = frameLocation.x + frameSize.x;
	texCoords[1].y = frameLocation.y + frameSize.y;

	texCoords[2].x = frameLocation.x + frameSize.x;
	texCoords[2].y = frameLocation.y;

	texCoords[3].x = frameLocation.x;
	texCoords[3].y = frameLocation.y;

	for (int i = 0; i < 4; i++)
	{
		corners[i].z = position.z;
		corners[i].w = 1;
	}
}

void Sprite::calculateTransformedCorners()
{
	glm::mat4x4 mat_translation = glm::translate(position);
	glm::mat4x4 mat_rotation = glm::rotate(glm::radians(rotation), glm::vec3(0.f, 0.f, 1.0));
	glm::mat4x4 mat_scale = glm::scale(glm::vec3(1.f, 1.f, 1.f));
	glm::mat4x4 modelMat = mat_translation * mat_rotation * mat_scale;
	for (int i = 0; i < 4; i++)
	{
		transformedCorners[i] = modelMat * corners[i];
	}
}
