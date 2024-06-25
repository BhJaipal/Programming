#include "lib/c++/my_linkedlist.hpp"
#include "lib/c++/my_queue.hpp"
#include "lib/c++/my_stack.hpp"

int main() {
	// Stack
	// MyDSA::Stack<int> s;
	// s.push(5);
	// s.push(9);
	// s.push(6);
	// std::cout << "Stack: ";
	// s.toString();
	// std::cout << "\n";
	// std::cout << "Poped: " << s.pop() << '\n';
	// s.push(7);
	// std::cout << "Stack: ";
	// s.toString();
	// std::cout << "\n\n";

	// Queue
	// MyDSA::Queue<int> q(5);
	// q.push(9);
	// q.push(6);
	// q.push(7);
	// std::cout << "Queue: ";
	// q.toString();
	// std::cout << "\n";
	// std::cout << "Poped: " << q.pop() << '\n';
	// std::cout << "Queue: ";
	// q.toString();
	// std::cout << "\n\n";

	MyDSA::SinglyLinkedList<int> ll(7);
	ll.push(5);
	ll.push(1, 1);
	ll.pop(1);
	ll.toString();
	std::cout << "\n\n";
	return 0;
}
