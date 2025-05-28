#include <iostream>
const int M = 3;

// Template and error handling
// NOTE  idhh
template <typename T>
class Stack {
	// NOTE  During Compiling, Stack<T> will create a new class
	T data[M];
	int top;
public:
	class Full{};
	class Empty{};

	Stack(): top(-1) {}
	// If stack is not full, add element
	void push(T val) {
		if (top == M -1) {
			// ERROR on full
			throw Full();
		}
		data[++top] = val;
	}
	T pop() {
		if (top == -1) {
			// ERROR on empty
			throw Empty();
		}
		return data[top--];
	}
	void show() {
		if (top == -1) {
			std::cout << "Stack is empty\n";
			return;
		}
		std::cout << "Stack: ";
		for (int i = top; i > -1; i--) {
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}
};

int main (int argc, char *argv[]) {
	// Template Use
	Stack<int> s;
	try {
		for (int i = 0; i < M + 1; i++) {
			s.push(i);
		}
	}
	// Error handling
	catch (Stack<int>::Full) {
		std::cout << "Stack is full\n";
	}
	s.show();
	try {
		for (int i = 0; i < M + 1; i++) {
			std::cout << "Poped: " << s.pop() << "\n";
		}
	}
	// Error handling
	catch (Stack<int>::Empty) {
		std::cout << "Stack is empty\n";
	}
	return 0;
}
