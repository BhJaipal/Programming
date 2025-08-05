#include <stdio.h>

int main() {
	int arr[] = {5, 2, 7, 3, 8, 6};
	for (char i = 0; i < 6; i++) {
		for (char j = 0; j < 6 - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				arr[j] += arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] -= arr[j+1];
			}
		}
	}
	for (char i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
