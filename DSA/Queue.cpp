#include <iostream>
#include <string>
#include <list>

using namespace std;
template <class T> class Queue{
private:
	list<T> _list{};
	int _length;
public:
	Queue() {
		this->_list;
		this->_length= 0;
	}
	T deque() {
		T first= this->_list.front();
		this->_list.pop_front();
		this->_length--;
		return first;
	}
	void enque(T elem) {
		this->_list.push_back(elem);
		this->_length++;
	}
	int length() {
		return this->_length;
	}
	list<T> list() {
		return this->_list;
	}
	T peek() {
		return this->_list.front();
	}
};

int main (int argc, char *argv[]) {
	Queue<string> queue;
	queue.enque("SvelteKit");
	queue.enque("Flutter");
	queue.enque("Express");
	queue.enque("NestJS");
	queue.enque("Nuxt");
	queue.enque("Laravel");

	cout << "Elements: " << endl;
	for(string var : queue.list()) {
		cout << var << endl;
	}
	cout << "\nFirst element: " << queue.deque() << endl;
	cout << "After dequing, first element: " << queue.peek() << endl;
	return 0;
}
