// binarysearch.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.

#include <iostream>


int binary_search_iterative(int A[], int N, int k) 	// N is array size. n is list size.	
{	// Element A[0] is not used. List items A[1],...,A[n] are sorted in ascending order.
	// first and last are the indexes of the first and last items of a current sublist. 

	int n = N - 1, first = 1, last = n, middle;
	while (first <= last)
	{
		middle = (first + last) / 2;	//integer division
		//std::cout << "k: " << k << " first: " << first << " middle: " << middle << " last: " << last << "\n";
		if (A[middle] == k)
		{
			return	 middle;
		}
		else if (A[middle] < k) {
			first = middle + 1;
		}
		else {
			last = middle - 1;
		}
	}//while
	return -1;          //k is not in the list: A[1],...,A[n]; 		
} //binary_search_iterative

int main()
{
	int length = 10;
    std::cout << "Binary search\n";
	int *arr = new int[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = i * 2 + 1;
	}

	std::cout << "[";
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "]\n";
	
	for (int e = -1; e < length * 2 + 2; e++)
	{
		int idx = binary_search_iterative(arr, length, e);
		std::cout << "Element: " << e << ", Index: " << idx << "\n";
	}
	return 1;
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


