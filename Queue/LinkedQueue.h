#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include <stdlib.h>
#include "QueueException.h"

template <class T>
class LinkedQueue
{
	struct Node
	{
		Node(const T &, Node *);

		Node* next;
		T data;
	};

public:
	LinkedQueue();
	~LinkedQueue();

private:
	LinkedQueue(const LinkedQueue &);
	LinkedQueue& operator=(const LinkedQueue &);

public:
	void enqueue(const T &);
	T dequeue();
	T peek() const;

	bool isEmpty() { return count == 0; }

private:
	Node* first;
	Node* last;

	size_t count;
};

template <typename T>
LinkedQueue<T>::Node::Node(const T& d, Node* n) : data(d), next(n)
{  }

template <typename T>
LinkedQueue<T>::LinkedQueue() : first(NULL), last(NULL), count(0)
{  }

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	while (!isEmpty())
		dequeue();
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& data)
{
	if (isEmpty())
		last = new Node(data, NULL);
	else
	{
		last->next = new Node(data, NULL);
		last = last->next;
	}

	if (!count++)
		first = last;
}

template <typename T>
T LinkedQueue<T>::dequeue()
{
	if (isEmpty())
		throw EmptyQueueException("dequeue");

	T data = first->data;
	Node* second = first->next;

	delete first;
	first = second;

	--count;
	return data;
}

template <typename T>
T LinkedQueue<T>::peek() const
{
	if (isEmpty())
		throw EmptyQueueException("peek");

	return first->data;
}




#endif // LINKED_QUEUE
