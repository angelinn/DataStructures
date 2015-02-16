#ifndef STACK_EXCEPTION
#define STACK_EXCEPTION

#include <stdexcept>

class StackException : public std::runtime_error
{
public:
	StackException(const char* message) : std::runtime_error(message)
	{  }
};

class EmptyStackException : public StackException
{
public:
	EmptyStackException(const char* message) : StackException(message)
	{  }
};

class FullStackException : public StackException
{
public:
	FullStackException(const char* message) : StackException(message)
	{  }
};

#endif // STACK_EXCEPTION
