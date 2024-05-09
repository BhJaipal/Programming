#include <iostream>
using namespace std;

class Array {
	int arr[10];

public:
	Array() {
		cout << "Enter 10 elements: ";
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
		}
		cout << "\n";
	}
	int operator[](int i) {
		if (i >= 0 && i < 10) {
			return arr[i];
		} else {
			cout << "Index out of bounds\t";
			return -1;
		}
	}
};
int main() {
	Array a;
	cout << "5th element: " << a[4] << "\n";
	cout << "15th element: " << a[14] << "\n";
	return 0;
}
/*
output:
Enter 10 elements: 5 2 7 3 8 4 3 6 2 9

5th element: 8
15th element: Index out of bounds  -1
*/
