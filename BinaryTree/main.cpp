#include <iostream>
#include <crtdbg.h>
#include "BinaryTree.h"

int main()
{
	{
		BinaryTree<int> tree;
		tree.insert(5);
		tree.insert(1);
		tree.insert(10);
		tree.insert(3);
		tree.insert(7);
		tree.insert(17);
		BinaryTree<int>::Node* res = tree.search(7);
		std::cout << res->data << std::endl;

		tree.print();
	}

	_CrtDumpMemoryLeaks();

	return 0;
}
