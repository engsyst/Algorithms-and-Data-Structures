// arrayList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "arrayList.h"

void printArray(int *arr, int size)
{
	std::cout << "[" << size << "] {";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "}\n";
}

/**
 *	Shifts elements starting from the given position to the right.
 */
void shiftArrayElements(int *arr, int start, int *end)
{
	for (int i = *end - 1; i >= start; i--) // loop must run from the last element to the position
	{
		arr[i + 1] = arr[i];
	}
	++*end;
}

/**
 *	Shifts elements starting at the given position to the right,
 *	then writes the element to that position.
 */
bool insertElement(int *arr, int element, int position, int *size, int N)
{
	// check if the position between 0 .. size
	// return false if no
	// check if enought place to unsert
	// if no return false
	std::cout << "Init size: " << *size << "\n";
	if (position < 0 || position >= *size || *size == N)
	{
		return false;
	}
	shiftArrayElements(arr, position, size);
	arr[position] = element;
	std::cout << "Result size: " << *size << "\n";
	return true;
}

int *increaseArray(int *arr, int fromSize, int toSize) {
	if (toSize < fromSize) {
		return NULL;
	}
	int *temp = new int[toSize];
	for (int i = 0; i < fromSize; i++)
	{
		temp[i] = arr[i];
	}
	delete arr; // should clear previously allocated memory
	return temp;
}


int main()
{
	std::cout << "Hello World!\n";
	int N = 7; // number of elements can be placed in the array
	int *arr = new int[N]; // array

	int size = 5; // actual number of elements in array
	for (int i = 0; i < size; i++)
	{
		arr[i] = i * 2 + 1;
	}
	printArray(arr, size);

	// add an element to the free position
	arr[size] = 8;
	size++; // must be incremented each time then an element is added.
	printArray(arr, size);

	bool result = insertElement(arr, 20, 3, &size, N); // insert new element (20) in 3d position
	if (!result) {
		std::cout << "ERROR\n";
	}
	printArray(arr, size);

	arr = increaseArray(arr, N, N = N + 5);
	insertElement(arr, 27, size - 1, &size, N);
	printArray(arr, size);
	std::cout << N;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
