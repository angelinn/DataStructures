#include <iostream>
#include <crtdbg.h>
#include "LinkedQueue.h"

int main()
{
	try
	{
		LinkedQueue<int> queue;

		for (int i = 0; i < 10000; ++i)
			queue.enqueue(i);
		
		for (int i = 0; i < 10000; ++i)
			std::cout << queue.dequeue() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	_CrtDumpMemoryLeaks();
}

