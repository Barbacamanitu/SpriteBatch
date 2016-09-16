#pragma once
#include <stack>


struct ErrorData
{
	ErrorData(const char* n, const char* d)
	{
		name = n;
		data = d;
	}
	const char* name;
	const char* data;
};

class ErrorHandler
{
public:
	static void push(const char* name, const char* data);
	static void pop();
	static void doError(int line, const char* filename, const char* testString);
private:
	ErrorHandler() {};
	~ErrorHandler() {};
	static std::stack<ErrorData> errorStack;
};

