#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#define VERTEX_SIZE 5
struct Sprite
{
	glm::vec3 position;
	glm::vec2 frameLocation;
	glm::vec2 frameSize;
	glm::vec2 texCoords[4];
	float rotation;
	glm::vec2 size;
	glm::vec4 corners[4];
	glm::vec4 transformedCorners[4];
	void rotate(float degrees);
	void pushToVertexArray(float* firstElement);
private:
	void calculateCorners();
	void calculateTransformedCorners();
};