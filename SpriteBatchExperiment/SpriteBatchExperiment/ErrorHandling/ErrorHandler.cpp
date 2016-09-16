#include "stdafx.h"
#include "ErrorHandler.h"
#include <iostream>
std::stack<ErrorData> ErrorHandler::errorStack;

void ErrorHandler::push(const char* name, const char* data)
{
	errorStack.push(ErrorData(name, data));
}

void ErrorHandler::pop()
{
	errorStack.pop();
}



void ErrorHandler::doError(int line, const char* filename, const char* testString)
{
	std::cout << "Failed Assertion: " << testString << std::endl;
	std::cout << "Line: " << line << std::endl;
	std::cout << "File: " << filename << std::endl;

	std::cout << "----- Error Stack -----" << std::endl;
	int counter = 0;
	while (errorStack.size() > 0)
	{
		ErrorData err = errorStack.top();
		std::cout << counter << ") ";
		std::cout << err.name << ": " << err.data << std::endl;
		errorStack.pop();
		counter++;
	}
	std::cout << "----- End Stack -----" << std::endl;
	abort();
}

