#include "Allocator.hpp"
#include <iostream>

int main() {
	Allocator<int> a;
	a.alloc();
	a.write(7);
	std::cout << "Value: " << a.read() << "\n";
}
