#include <iostream>

void swap(int& a, int& b)
{
	int holder(a);
	a = b;
	b = holder;
}

void swapIf(int& a, int& b)
{
	if (a > b)
		swap(a, b);
}

/// best  average  worst
/// n^2     n^2     n^2
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

/// best  average  worst
///  n     n^2     n^2
void bubbleSort(int* arr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = size - 1; j > i; --j)
		{
			swapIf(arr[j - 1], arr[j]);
		}
	}
}

/// best  average  worst
///  n     n^2     n^2
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

/// best  average  worst
/// n+k     n+k     n^2
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

void step(int *, size_t, size_t, int *);
void merge(int *, size_t, size_t, size_t, size_t, int *);


/// best  average  worst
/// nlogn   nlogn  nlogn
void mergeSort(int* arr, size_t size)
{
	int* buffer = new int[size];
	size_t beg = 0;
	size_t end = size - 1;

	step(arr, beg, end, buffer);
	delete[] buffer;
}

void step(int* arr, size_t beg, size_t end, int* buffer)
{
	if (beg < end)
	{
		size_t middle = (beg + end) / 2;

		step(arr, beg, middle, buffer);
		step(arr, middle + 1, end, buffer);
		merge(arr, beg, middle, middle + 1, end, buffer);
	}
}

void merge(int* arr, size_t firstStart, size_t firstEnd, size_t secondStart, size_t secondEnd, int* buffer)
{
	size_t firstStartCopy = firstStart;
	size_t bufferIndex = firstStart;

	while (firstStartCopy <= firstEnd && secondStart <= secondEnd)
	{
		if (arr[firstStartCopy] < arr[secondStart])
			buffer[bufferIndex++] = arr[firstStartCopy++];
		else
			buffer[bufferIndex++] = arr[secondStart++];
	}

	while (firstStartCopy <= firstEnd)
		buffer[bufferIndex++] = arr[firstStartCopy++];

	while (secondStart <= secondEnd)
		buffer[bufferIndex++] = arr[secondStart++];

	for (size_t i = firstStart; i <= secondEnd; ++i)
		arr[i] = buffer[i];
}

size_t partition(int *, size_t);

void quickSort(int* arr, size_t size)
{
	if (size <= 1 || !arr)
		return;

	size_t pos = partition(arr, size);
	quickSort(arr, pos);
	quickSort(arr + pos, size - pos);
}

size_t partition(int* arr, size_t size)
{
	std::cout << size << std::endl;
	if (size == 2)
	{
		swapIf(arr[0], arr[1]);
		return 1;
	}

	size_t middle = size / 2;

	swapIf(arr[0], arr[middle]);
	swapIf(arr[0], arr[size - 1]);
	swapIf(arr[middle], arr[size - 1]);
	swap(arr[middle], arr[size - 2]);

	int& pivot = arr[size - 2];
	size_t left = 0;
	size_t right = size - 2;

	while (true)
	{
		while (arr[++left] < pivot)
		{   }

		while (arr[--right] > pivot)
		{
			if (left == right)
				break;
		}

		if (left >= right)
			break;

		swap(arr[left], arr[right]);
	}
	swap(arr[left], pivot);
	return left;
}

void shakerSort(int* arr, size_t size)
{
	size_t left = 0;
	size_t right = size - 1;

	while (left < right)
	{
		for (size_t r = right; r > left; --r)
			swapIf(arr[r - 1], arr[r]);

		++left;

		for (size_t l = left + 1; l <= right; ++l)
			swapIf(arr[l - 1], arr[l]);

		--right;
	}
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
	int arr[] = {10, 7, 0, 3, 1, 4, 5, 19, 6, 87};
	int sho[] = { 1, 100, 2 };
	int other[5] {5, 2, 3, 1, 4};
	printArr(arr, size);
	shakerSort(arr, size);
	printArr(arr, size);

}