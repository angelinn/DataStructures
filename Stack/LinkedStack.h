#ifndef LINKED_STACK
#define LINKED_STACK

#include <stdlib.h>
#include "StackException.h"

template <class T>
class LinkedStack
{
	struct Node
	{
		Node(const T &, Node *);

		Node* next;
		T data;
	};

public:
	LinkedStack();
	~LinkedStack();

private:
	LinkedStack(const LinkedStack &);
	LinkedStack& operator=(const LinkedStack &);

public:
	void push(const T &);
	T pop();
	T peek() const;
	bool isEmpty() const { return count == 0; }

private:
	Node* top;
	size_t count;
};

template <typename T>
LinkedStack<T>::Node::Node(const T& d, Node* n) : data(d), next(n)
{  }

template <typename T>
LinkedStack<T>::LinkedStack() : top(NULL), count(0)
{  }

template <typename T>
LinkedStack<T>::~LinkedStack()
{
	while (!isEmpty())
		pop();
}

template <typename T>
void LinkedStack<T>::push(const T& data)
{
	Node* newTop = NULL;
	try
	{
		newTop = new Node(data, top);
	}
	catch (std::bad_alloc &)
	{
		delete newTop;
		throw;
	}

	top = newTop;
	++count;
}

template <typename T>
T LinkedStack<T>::pop()
{
	if (isEmpty())
		throw EmptyStackException("pop");

	T data = top->data;
	Node* newTop = top->next;
	top->next = NULL;
	delete top;
	top = newTop;

	--count;
	return data;
}

template <typename T>
T LinkedStack<T>::peek() const
{
	if (isEmpty())
		throw EmptyStackException("peek");

	return top->data;
}

#endif // LINKED_STACK
