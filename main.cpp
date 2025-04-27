#include "array.hpp"

int main() {
	Array<int> arr = {4, 2, 8};
	for (auto el: arr) {
		std::cout << el << " ";
	}
	std::cout << "\n";
	return 0;
}
