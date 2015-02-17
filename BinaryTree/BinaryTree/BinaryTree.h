#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdlib.h>
#include <iostream>

template <class T>
class BinaryTree
{
public:
	struct Node
	{
		Node(const T &, Node *, Node *);
		T data;

		Node* left;
		Node* right;
	};

public:
	BinaryTree();
	~BinaryTree();

public:
	void insert(const T &);
	Node* search(const T &);
	void print() const;
	void print(Node *) const;

private:
	void insertRecursive(const T &, Node *);
	Node* searchRecursive(const T &, Node *);
	void deleteTree(Node *);

private:
	BinaryTree(const BinaryTree &);
	BinaryTree& operator=(const BinaryTree &);

private:
	Node* root;
};

template <typename T>
BinaryTree<T>::Node::Node(const T& d, Node* l, Node* r) : left(l), right(r), data(d)
{  }

template <typename T>
BinaryTree<T>::BinaryTree() : root(NULL)
{  }

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	deleteTree(root);
}

template <typename T>
void BinaryTree<T>::deleteTree(Node* node)
{
	if (node)
	{
		deleteTree(node->left);
		deleteTree(node->right);

		delete node;
	}
}

template <typename T>
void BinaryTree<T>::insert(const T& data)
{
	if (root)
		insertRecursive(data, root);
	else
		root = new Node(data, NULL, NULL);
}

template <typename T>
void BinaryTree<T>::insertRecursive(const T& data, Node* node)
{
	if (data < node->data)
	{
		if (node->left)
			insertRecursive(data, node->left);
		else
			node->left = new Node(data, NULL, NULL);
	}
	else
	{
		if (node->right)
			insertRecursive(data, node->right);
		else
			node->right = new Node(data, NULL, NULL);
	}
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::search(const T& data)
{
	return searchRecursive(data, root);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::searchRecursive(const T& data, Node* node)
{
	if (node)
	{
		if (data == node->data)
			return node;

		if (data < node->data)
			return searchRecursive(data, node->left);

		return searchRecursive(data, node->right);
	}
	return NULL;
}

template <typename T>
void BinaryTree<T>::print() const
{
	print(root);
}

template <typename T>
void BinaryTree<T>::print(Node* node) const
{
	if (node)
	{
		print(node->left);
		std::cout << "left of " << node->data << std::endl;
		print(node->right);
		std::cout << "right of " << node->data << std::endl;
		std::cout << node->data << std::endl;
	}
}


#endif // BINARY_TREE
