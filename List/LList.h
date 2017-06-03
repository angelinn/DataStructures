#ifndef LLIST
#define LLIST

#include <stdlib.h>
#include <stdexcept>

template <class T>
class LList
{
	struct Node
	{
		Node(const T &, Node *);

		T data;
		Node* next;
	};

public:
	class Iterator
	{
	public:
		operator bool() { return current != NULL; }
		Iterator& operator++();
		T operator*() const;

	private:
		Iterator(Node *);
		Node* current;

		friend class LList;
	};

public:
	LList();
	~LList();

private:
	LList(const LList &);
	LList& operator=(const LList &);

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
	T operator[](int);
	const T operator[](int) const;

private:
	Node* getAt(int) const;

private:
	Node* first;
	Node* last;

	int count;

};

template <typename T>
LList<T>::LList() : first(NULL), last(NULL), count(0)
{  }

template <typename T>
LList<T>::~LList()
{
	clear();
}

template <typename T>
void LList<T>::clear()
{
	while (!isEmpty())
		pop_front();
}

template <typename T>
void LList<T>::push_back(const T& data)
{
	if (!count)
		first = last = new Node(data, NULL);
	else
	{
		last->next = new Node(data, NULL);
		last = last->next;
	}

	++count;
}

template <typename T>
void LList<T>::push_front(const T& data)
{
	if (!count)
		last = first = new Node(data, NULL);
	else
	{
		Node* newFirst = new Node(data, first);
		first = newFirst;
	}

	++count;
}

template <typename T>
void LList<T>::push_at(const Iterator& iter)
{

}

template <typename T>
T LList<T>::pop_back()
{
	if (isEmpty())
		throw std::exception("empty");


	T data = last->data;
	Node* preLast = getAt(count - 2);
	delete last;

	last = preLast;
	--count;

	if (isEmpty())
		first = NULL;
	else if (last)
		last->next = NULL;

	return data;
}

template <typename T>
T LList<T>::pop_front()
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

	return data;
}

template <typename T>
T LList<T>::pop_at(const Iterator& iter)
{

}

template <typename T>
typename LList<T>::Iterator LList<T>::begin() const
{
	return Iterator(first);
}

template <typename T>
LList<T>::Node::Node(const T& d, Node* n) : next(n), data(d)
{  }

template <typename T>
LList<T>::Iterator::Iterator(Node* c) : current(c)
{  }

template <typename T>
typename LList<T>::Iterator& LList<T>::Iterator::operator++()
{
	if (current)
		current = current->next;

	return *this;
}

template <typename T>
T LList<T>::Iterator::operator*() const
{
	if (!current)
		throw std::exception("current = NULL");

	return current->data;
}

template <typename T>
const T LList<T>::operator[](int index) const
{
	return getAt(index)->data;
}

template <typename T>
T LList<T>::operator[](int index)
{
	return static_cast<const LList<T> &>(*this)[index];
}

template <typename T>
typename LList<T>::Node* LList<T>::getAt(int index) const
{
	if (!count)
		throw std::exception("empty");

	if (index < 0 || index > count)
		return NULL;

	Node* current = first;
	while (index > 0)
	{
		current = current->next;
		--index;
	}

	return current;
}


#endif // LLIST
