#pragma once
#include <string>
#include "GL\glew.h"
#include "GL\GL.h"
class ShaderFactory
{
public:
	ShaderFactory();
	~ShaderFactory();

	static GLuint CreateSpriteProgram(std::string fragment, std::string vertex);

private:
	static std::string ReadTextFromFile(std::string filename);
	static void compileShader(GLuint shader);
};

