#include <crtdbg.h>
#include <iostream>
#include "DLList.h"

int main()
{
	try
	{
		DLList<int> list;

		for (int i = 0; i < 10; ++i)
			list.push_back(i);

		for (DLList<int>::Iterator iter = list.begin(); iter; ++iter)
		{
			std::cout << (*iter) << std::endl;
		}

		std::cout << list[3];
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	return 0;
}
