#include "stdafx.h"
#include "ShaderFactory.h"
#include <fstream>
#include <streambuf>
#include <iostream>
#include <sstream>
#include "../ErrorHandling/ErrorContext.h"
ShaderFactory::ShaderFactory()
{
}


ShaderFactory::~ShaderFactory()
{
}


GLuint ShaderFactory::CreateSpriteProgram(std::string fragment, std::string vertex)
{
	std::string fragSource = ReadTextFromFile(fragment);
	std::string vertSource = ReadTextFromFile(vertex);
	
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);

	const GLchar* fragmentSource = fragSource.c_str();
	const GLchar* vertexSource = vertSource.c_str();

	glShaderSource(vertShader, 1, &vertexSource, NULL);
	glShaderSource(fragShader, 1, &fragmentSource, NULL);
	
	ErrorContext* fCont = new ErrorContext("Compile Shader", "Fragment Shader");
	compileShader(fragShader);
	delete fCont;


	ErrorContext *vCont = new ErrorContext("Compile Shader", "Vertex Shader");
	compileShader(vertShader);
	delete vCont;

	ErrorContext err("Link Shader Program", "");
	GLuint program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		char* infoLog = new char[maxLength];
		glGetProgramInfoLog(program, maxLength, &maxLength, infoLog);

		//We don't need the program anymore.
		glDeleteProgram(program);
		//Don't leak shaders either.
		glDeleteShader(vertShader);
		glDeleteShader(fragShader);
		XASSERT(isLinked == GL_TRUE, "Shader Program Linkage Error");
	}

	return program;
}

std::string ShaderFactory::ReadTextFromFile(std::string filename)
{
	std::ifstream theFile(filename);
	std::string str;

	theFile.seekg(0, std::ios::end);
	str.reserve(theFile.tellg());
	theFile.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(theFile)),
		std::istreambuf_iterator<char>());
	return str;
}

void ShaderFactory::compileShader(GLuint shader)
{
	glCompileShader(shader);
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	std::stringstream str;
	str << shader;


	if (status != GL_TRUE)
	{
		char buffer[512];
		glGetShaderInfoLog(shader, 512, NULL, buffer);
		const char* buf = buffer;
		ErrorContext ec("Compilation Log", buf);
		XASSERT(status == GL_TRUE, "Compilation Failed.");
	}
}


