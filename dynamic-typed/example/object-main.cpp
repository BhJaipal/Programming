#include "../dynamic-typed.h"
#include <iostream>

int main() {
	std::vector<Object> arr;
	arr.push_back(Object::from(5));
	arr.push_back(Object::from(43.5f));
	arr.push_back(Object::from("Jaipal"));
	std::cout << arr[0].to_int() << std::endl;
	std::cout << arr[1].to_float() << std::endl;
	std::cout << arr[2].to_str() << std::endl;
	for (auto o : arr) o.unref();

	return 0;
}