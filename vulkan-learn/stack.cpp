#include <iostream>
using namespace std;

const int MAX = 10;

class Stack {
	int data[MAX];
protected:
	int top;
public:
	Stack(): top(-1) {}
	void push(int val) { data[++top] = val; }
	int pop() { return data[top--]; }

	void show() {
		cout << "Top: ";
		for (int i = top; i >= 0; i--) {
			cout << "\t" << data[i] << '\n';
		}
	}
};

class StackLimit: public Stack {
public:
	void push(int val) {
		if (top == MAX - 1)
			cout << "Error: Stack Overflowed\n";
		else
			Stack::push(val);
	}

	int pop() {
		if (top == -1) {
			std::cout << "Error: Stack is empty\n";
			return -1;
		}
		return Stack::pop();
	}
};

int main() {
	StackLimit s;
	s.push(5);
	s.push(2);
	s.push(6);
	cout << "Poped: " << s.pop() << endl;
	s.push(7);
	s.push(11);
	s.show();
	cout << endl;
	for (int i = 0; i < 7; i++) {
		s.push(8);
	}
	for (int i = 0; i <= MAX; i++) {
		cout << s.pop() << " ";
	}
	cout << endl;
	return 0;
}
