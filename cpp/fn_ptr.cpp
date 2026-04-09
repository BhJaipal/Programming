#include <bits/invoke.h>
#include <functional>
#include <iostream>
int main() {
	int c = 7;
	auto max = [c](int a, int b) {return a > b ? (a>c?a:c) : (b>c?b:c); };
	auto max_ = [](int a, int b) {return a > b ? a : b; };
	std::function fn = max;
	std::cout << max(3,5) << "\n";
	fn = max_;
	std::cout << max(3,5) << "\n";
}
