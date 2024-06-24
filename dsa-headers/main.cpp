#include "lib/c++/my_queue.hpp"
#include "lib/c++/my_stack.hpp"

int main() {
	MyDSA::Stack<int> s;
	s.push(5);
	s.push(9);
	s.push(6);
	std::cout << "Stack: ";
	s.toString();
	std::cout << "\n";
	std::cout << "Poped: " << s.pop() << '\n';
	s.push(7);
	std::cout << "Stack: ";
	s.toString();
	std::cout << "\n\n";

	MyDSA::Queue<int> q(5);
	q.push(9);
	q.push(6);
	q.push(7);
	std::cout << "Queue: ";
	q.toString();
	std::cout << "\n";
	std::cout << "Poped: " << q.pop() << '\n';
	std::cout << "Queue: ";
	q.toString();
	std::cout << "\n\n";
	return 0;
}
