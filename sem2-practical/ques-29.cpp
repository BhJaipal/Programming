#include <iostream>
using namespace std;

template <class T>
T Min(T arr[], int n) {
	T min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) { min = arr[i]; }
	}
	return min;
}
int main() {
	float arr[] = {5.3, 2.3, 8.5, 0.3};
	cout << "Minimum: " << Min(arr, 4) << "\n";
	return 0;
}
/*
Output:
Minimum: 0.3
*/
