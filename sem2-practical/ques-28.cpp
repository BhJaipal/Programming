#include <iostream>
using namespace std;

template <class T>
void sort(T *arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j && arr[i] > arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main() {
	int arr[] = {4, 2, 11, 5, 9};
	sort(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n";
	return 0;
}
/*
Output:
[2, 4, 5, 9, 11]
*/
