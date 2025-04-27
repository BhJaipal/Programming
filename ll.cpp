#include <iostream>
using namespace std;
const int MAX = 10;

class Stack {
	int data[MAX];

protected:
	int len;

public:
	Stack() : len(0) {}
	void push(int val) { data[len++] = val; }
	int pop() { return data[--len]; }
	void print() {
		cout << "Top:";
		for (int i = len - 1; i >= 0; i--) cout << "\t" << i << endl;
	}
};
class StackLimit : public Stack {
public:
	void push(int val) {
		if (len == MAX) {
			cout << "Stack is full\n";
		} else Stack::push(val);
	}
	int pop() {
		if (len == 0) {
			cout << "Stack is empty\n";
			return -1;
		} else return Stack::pop();
	}
};

int main() {
	StackLimit stack;
	for (int i = 0; i < 11; i++) { stack.push(i); }
	stack.print();
	cout << "Poped: " << stack.pop() << endl;
	for (int i = 0; i < 9; i++) { stack.pop(); }
	cout << "Poping all...\nPoped all\n";
	stack.pop();
	return 0;
}