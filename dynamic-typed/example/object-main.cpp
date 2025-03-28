#include "../dynamic-typed.h"
#include <iostream>

int main() {
	std::vector<Object> arr;
	arr.push_back(Object::from(5));
	arr.push_back(Object::from(43.5f));
	arr.push_back(Object::from("Jaipal"));
	arr.push_back(Object::from(
		std::vector<Object>{Object::from("Jaipal"), Object::from(7)}));
	arr.push_back(Object::from(Dict(Object::from(9), Object::from(11))));
	for (auto i : arr) { std::cout << i << std::endl; }
	for (auto o : arr) o.unref();
	return 0;
}