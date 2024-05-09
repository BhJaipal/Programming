#include <iostream>
using namespace std;

template <class T>
int linearSearch(T *arr, int size, T elem)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == elem)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
int binarySearch(T arr[], int s, T elem)
{
	int index = -1;
	int middleIndex = s / 2;

	if (sizeof(arr) == 0)
	{
		return -1;
	}

	if (elem == arr[middleIndex])
	{
		return middleIndex;
	}
	else if (elem < arr[middleIndex])
	{
		int arr2[middleIndex];
		for (int i = 0; i < middleIndex; i++)
		{
			arr2[i] = arr[i];
		}
		return binarySearch(arr2, middleIndex, elem);
	}
	else
	{
		int arr2[s - middleIndex];
		for (int i = 0; i < s - middleIndex; i++)
		{
			arr2[i] = arr[i + middleIndex];
		}

		return middleIndex + binarySearch(arr2, s - middleIndex, elem);
	}
}
int main()
{
	int arr[5] = {5, 2, 8, 4, 0};
	int sortedArr[] = {2, 4, 5, 7, 9, 10, 11, 12, 15};
	cout << linearSearch(arr, 5, 8) << "\nBinary Search: ";
	cout << binarySearch(sortedArr, 9, 11) << "\n";
	return 0;
}
