#ifndef DLLIST
#define DLLIST

#include <stdlib.h>
#include <stdexcept>

template <class T>
class DLList
{
	struct Node
	{
		Node(Node *, const T &, Node *);

		T data;
		Node* next;
		Node* prev;
	};

public:
	class Iterator
	{
	public:
		operator bool() { return current != NULL; }
		Iterator& operator++();
		Iterator& operator--();
		T operator*() const;

	private:
		Iterator(Node *);
		Node* current;

		friend class DLList;
	};

public:
	DLList();
	~DLList();

private:
	DLList(const DLList &);
	DLList& operator=(const DLList &);

public:
	void push_back(const T &);
	void push_front(const T &);
	void push_at(const Iterator &);

	T pop_back();
	T pop_front();
	T pop_at(const Iterator &);

	T front() const;
	T back() const;

	bool isEmpty() const { return count == 0; }
	void clear();
	Iterator begin() const;

public:
	T operator[](size_t);
	const T operator[](size_t) const;

private:
	const Node* getAt(size_t) const;

private:
	Node* first;
	Node* last;

	size_t count;
};

template <typename T>
DLList<T>::DLList() : first(NULL), last(NULL), count(0)
{  }

template <typename T>
DLList<T>::~DLList()
{
	clear();
}

template <typename T>
void DLList<T>::clear()
{
	while (!isEmpty())
		pop_back();
}

template <typename T>
void DLList<T>::push_back(const T& data)
{
	if (!count)
		first = last = new Node(NULL, data, NULL);
	else
	{
		last->next = new Node(last, data, NULL);
		last = last->next;
	}

	++count;
}

template <typename T>
void DLList<T>::push_front(const T& data)
{
	if (!count)
		last = first = new Node(NULL, data, NULL);
	else
	{
		first->prev = new Node(NULL, data, first);
		first = first->prev;
	}

	++count;
}

template <typename T>
void DLList<T>::push_at(const Iterator& iter)
{

}

template <typename T>
T DLList<T>::pop_back()
{
	if (isEmpty())
		throw std::exception("empty");


	T data = last->data;
	Node* preLast = last->prev;
	last->prev = NULL;
	delete last;

	last = preLast;
	--count;

	if (isEmpty())
		first = NULL;
	else
		last->next = NULL;

	return data;
}

template <typename T>
T DLList<T>::pop_front()
{
	if (isEmpty())
		throw std::exception("empty");

	if (count == 1)
		return pop_back();

	T data = first->data;
	Node* second = first->next;
	first->next = NULL;
	delete first;

	first = second;
	--count;

	if (isEmpty())
		last = NULL;
	else
		first->prev = NULL;

	return data;
}

template <typename T>
T DLList<T>::pop_at(const Iterator& iter)
{

}

template <typename T>
typename DLList<T>::Iterator DLList<T>::begin() const
{
	return Iterator(first);
}

template <typename T>
DLList<T>::Node::Node(Node* p, const T& d, Node* n) : prev(p), next(n), data(d)
{  }

template <typename T>
DLList<T>::Iterator::Iterator(Node* c) : current(c)
{  }

template <typename T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator++()
{
	if (current)
		current = current->next;

	return *this;
}

template <typename T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator--()
{
	if (current)
		current = current->prev;

	return *this;
}

template <typename T>
T DLList<T>::Iterator::operator*() const
{
	if (!current)
		throw std::exception("current = NULL");

	return current->data;
}

template <typename T>
const T DLList<T>::operator[](size_t index) const
{
	return getAt(index - 1)->data;
}

template <typename T>
T DLList<T>::operator[](size_t index)
{
	return static_cast<const DLList<T> &>(*this)[index];
}

template <typename T>
const typename DLList<T>::Node* DLList<T>::getAt(size_t index) const
{
	if (!count)
		throw std::exception("empty");

	if (index < 0 || index > count)
		throw std::out_of_range("index out of range");

	Node* current = NULL;
	if (index > count / 2)
	{
		current = last;
		while (index < count - 1)
		{
			current = current->prev;
			++index;
		}
	}

	else
	{
		current = first;
		while (index > 0)
		{
			current = current->next;
			--index;
		}
	}

	return current;
}

//template <typename T>
//T& DLList<T>::Iterator::operator*()
//{
//	return const_cast<DLList<T>::Iterator &>(static_cast<const DLList<T>::Iterator &>(this).operator*());
//}

#endif // DLLIST
