#ifndef QUEUE_EXCEPTION
#define QUEUE_EXCEPTION

#include <stdexcept>

class QueueException : public std::runtime_error
{
public:
	QueueException(const char* message) : std::runtime_error(message)
	{  }
};

class EmptyQueueException : public QueueException
{
public:
	EmptyQueueException(const char* message) : QueueException(message)
	{  }
};


#endif // QUEUE_EXCEPTION
