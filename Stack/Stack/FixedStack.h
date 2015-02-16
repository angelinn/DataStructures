#ifndef FIXED_STACK
#define FIXED_STACK

#include "StackException.h"

template <class T>
class FixedStack
{
public:
	FixedStack(size_t);
	~FixedStack();

private:
	FixedStack(const FixedStack &);
	FixedStack& operator=(const FixedStack &);

public:
	void push(const T &);
	T pop();
	T peek() const;

	bool isEmpty() const { return count == 0; }
	bool isFull() const { return count >= allocated; }

private:
	T* data;
	size_t allocated;
	size_t count;
};

template <typename T>
FixedStack<T>::FixedStack(size_t size) : allocated(size), count(0)
{
	try
	{
		data = new T[allocated];
	}
	catch (std::bad_alloc &)
	{
		delete[] data;
		data = NULL;

		throw;
	}
}

template <typename T>
FixedStack<T>::~FixedStack()
{
	delete[] data;
}

template <typename T>
void FixedStack<T>::push(const T& item)
{
	if (isFull())
		throw FullStackException("push");

	data[count++] = item;
}


template <typename T>
T FixedStack<T>::pop()
{
	if (isEmpty())
		throw EmptyStackException("pop");

	return data[--count];
}

template <typename T>
T FixedStack<T>::peek() const
{
	if (isEmpty())
		throw EmptyStackException("peek");

	return data[count - 1];
}

#endif // FIXED_STACK
