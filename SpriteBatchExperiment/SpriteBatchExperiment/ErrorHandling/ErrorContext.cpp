#include "stdafx.h"
#include "ErrorContext.h"


ErrorContext::ErrorContext(const char* name, const char* data)
{
	ErrorHandler::push(name, data);
}


ErrorContext::~ErrorContext()
{
	ErrorHandler::pop();
}
