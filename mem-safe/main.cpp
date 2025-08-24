#include "lib.hpp"
#include "string.hpp"
#include <iostream>

int main() {
	/*
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
	};*/
	String str = "Jaipal";
	str += " Hema";
	std::cout << str << " " << str.len() << "\n";
	std::cout << "Reversed: " << str.reverse();
	std::cout << ", Original: " << str << "\n";
	std::cout << str.substr(3, 8) << "\n";
	str.mut_at(0).unwrap() = 'A';
	std::cout << str << "\n";
}
