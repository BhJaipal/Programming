#ifndef CXX_MY_LINKEDLIST
#define CXX_MY_LINKEDLIST
#include "data_models.hpp"
#include <cstdlib>
#include <iostream>

namespace MyDSA {
template <class T> class SingleNode {
  public:
	T data;
	T next;
	SingleNode(int d) : data(d), next(0) {}
};
template <typename T> class SinglyLinkedList {
	SingleNode<T> *arr;
	int len;

  public:
	SinglyLinkedList(T x) {
		arr = new SingleNode<T>[1];
		arr[0] = SingleNode<T>(x);
		len = 1;
	}
	void push(T d) {
		SingleNode<T> n(d);
		arr = std::realloc(arr, sizeof(SingleNode<T>) * (++len));
		arr[len - 1] = n;
		arr[len - 2].next = n.data;
	}
	SingleNode<T> pop() {
		if (isEmpty()) return SingleNode<int>(-1);
		else {
			SingleNode<T> last = arr[len];
			arr = std::realloc(arr, sizeof(SingleNode<T>) * (--len));
			arr[len - 1].next = 0;
			return last;
		}
	}
	void toString() {
		if (isEmpty()) {
			std::cout << "[]";
		} else {
			std::cout << "[ ";
			for (int i = 0; i < len - 1; i++) {
				std::cout << "{ data: " << arr[i].data
						  << ", next: " << arr[i].next << "}, \n";
			}
			std::cout << "{ data: " << arr[len - 1].data
					  << ", next: " << arr[len - 1].next << "}, \n";
			std::cout << "]";
		}
	}
	int isEmpty() { return len == 0; }
	~SinglyLinkedList() { delete arr; }
};
} // namespace MyDSA

#endif