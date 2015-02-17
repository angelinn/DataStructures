#include <iostream>

void swap(int& a, int& b)
{
	int holder(a);
	a = b;
	b = holder;
}

void swapIf(int&a, int& b)
{
	if (a < b)
		swap(a, b);
}

void selectionSort(int* arr, size_t size)
{
	size_t minIndex = 0;
	for (size_t i = 0; i < size - 1; ++i)
	{
		minIndex = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}

void bubbleSort(int* arr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = size - 1; j > i; --j)
		{
			swapIf(arr[j], arr[j - 1]);
		}
	}
}

void insertionSort(int* arr, size_t size)
{
	int hand = 0;
	size_t j = 0;

	for (size_t i = 1; i < size; ++i)
	{
		hand = arr[i];
		j = i;

		while (arr[j - 1] > hand)
		{
			arr[j] = arr[j - 1];
			--j;
		}

		arr[j] = hand;
	}
}

void countingSort(int* arr, size_t size)
{
	int max = 0;
	for (size_t i = 0; i < size; ++i)
		if (arr[i] > max)
			max = arr[i];

	int* buffer = new int[max + 1];
	memset(buffer, 0, (max + 1) * sizeof(int));

	int* result = new int[size];

	for (size_t i = 0; i < size; ++i)
		buffer[arr[i]]++;

	for (size_t i = 1; i < max + 1; ++i)
		buffer[i] += buffer[i - 1];

	size_t pos = 0;
	for (size_t i = 0; i < size; ++i)
	{
		pos = --buffer[arr[i]];
		result[pos] = arr[i];
	}

	for (size_t i = 0; i < size; ++i)
		arr[i] = result[i];

	delete[] buffer;
}

void printArr(int* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
}

int main()
{
	size_t size = 10;
	int arr[10] {10, 7, 0, 3, 1, 4, 5, 19, 6, 87};
	countingSort(arr, size);
	printArr(arr, size);

}