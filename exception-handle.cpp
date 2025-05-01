#include <iostream>
using namespace std;
const int MAX = 10;

class Stack {
	int data[MAX];
	int top;

public:
	class Full {};
	class Empty {};
	Stack() : top(-1) {}
	void push(int elem) {
		if (top == MAX - 1) throw Full();
		data[++top] = elem;
	}
	int pop() {
		if (top == -1) throw Empty();
		return data[top--];
	}
	void show() {
		if (top == -1) {
			cout << "Stack is empty\n";
			return;
		}
		cout << "Stack: ";
		for (int i = top; i > -1; i--) { cout << data[i] << " "; }
		cout << "\n";
	}
};

int main() {
	Stack s;
	for (int i = 0; i < 10; i++) { s.push(i); }
	try {
		s.push(100);
	} catch (Stack::Full) { cout << "[Error]: Stack is full\n"; }

	s.show();
	cout << endl;

	try {
		for (int i = 0; i < 11; i++) { cout << "Poped: " << s.pop() << "\n"; }
	} catch (Stack::Empty) { cout << "[Error]: Stack is empty\n"; }

	return 0;
}