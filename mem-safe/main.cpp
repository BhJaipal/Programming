#include "array.hpp"
#include "lib.hpp"
#include <iostream>

int main() {
	Array<int> a;
	a.append(5);
	a.append(9);
	a.append(4);
	a.for_each([](int el) {
			std::cout << el << " ";
	});
	std::cout << std::endl;
	
	a.pop_last();
	a.pop_last();
	a.pop_last();
	if (a.pop_last().is_none()) {
		std::cout << "Empty array\n";
	};
}
