#pragma once
#include <stack>
#include "ErrorHandler.h"

#define  DEVELOPMENT 1

#if defined(DEVELOPMENT)
#define XASSERT(test, msg) do {if (!(test)) ErrorHandler::doError(__LINE__, __FILE__, #test);} while (0)
#else
#define XASSERT(test, msg) ((void)0)
#endif

class ErrorContext
{
public:
	ErrorContext(const char* name, const char* data);
	~ErrorContext();
private:

};

