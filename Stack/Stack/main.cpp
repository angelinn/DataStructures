#include <iostream>
#include "LinkedStack.h"
#include <crtdbg.h>
#include "FixedStack.h"

int main()
{
	try
	{
		FixedStack<int> stack(10000);
		for (int i = 0; i < 10000; ++i)
			stack.push(i);

		for (int i = 0; i < 10000; ++i)
			std::cout << stack.pop() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	_CrtDumpMemoryLeaks();


	return 0;
}