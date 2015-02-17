#include <crtdbg.h>
#include <iostream>
#include "DLList.h"
#include "LList.h"

int main()
{
	try
	{
		LList<int> list;

		for (int i = 0; i < 100; ++i)
			list.push_front(i);

		for (LList<int>::Iterator iter = list.begin(); iter; ++iter)
		{
			std::cout << (*iter) << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	return 0;
}
