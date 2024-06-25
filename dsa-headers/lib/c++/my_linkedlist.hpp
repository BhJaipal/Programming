#ifndef CXX_MY_LINKEDLIST
#define CXX_MY_LINKEDLIST
#include <cstdlib>
#include <iostream>

namespace MyDSA {
template <class T> class SingleNode {
  public:
	T data;
	T next;
	SingleNode(int d = 0) : data(d), next(0) {}
};
template <typename T> class SinglyLinkedList {
	SingleNode<T> *arr;
	int len;
	int isCircular;

  public:
	SinglyLinkedList(T x) {
		arr = new SingleNode<T>[1];
		arr[0] = SingleNode<T>(x);
		len = 1;
	}
	void push(T data) {
		SingleNode<T> n(data);
		arr =
			(SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) * (++len));
		arr[len - 1] = n;
		arr[len - 2].next = n.data;
		if (isCircular) circular();
	}
	SingleNode<T> pop() {
		if (isEmpty()) return SingleNode<int>(-1);
		else {
			SingleNode<T> last = arr[len - 1];
			arr = (SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) *
														 (--len));
			if (len - 1 >= 0) arr[len - 1].next = 0;
			if (isCircular) circular();
			return last;
		}
	}
	SingleNode<T> pop(int index) {
		if (isEmpty()) return SingleNode<int>(-1);
		else if (index < 0) return pop(len + index);
		else {
			if (index >= len - 1) {
				SingleNode<T> last = arr[len - 1];
				arr = (SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) *
															 (--len));
				if (len - 1 >= 0) arr[len - 1].next = 0;
				if (isCircular) circular();
				return last;
			} else {
				SingleNode<T> last = arr[index];
				for (int i = index; i < len - 1; i++) { arr[i] = arr[i + 1]; }
				arr = (SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) *
															 (--len));
				if (index - 1 >= 0) arr[index - 1].next = arr[index].data;
				return last;
			}
		}
	}
	void toString() {
		if (isEmpty()) {
			std::cout << "[]";
		} else {
			std::cout << "[\n";
			for (int i = 0; i < len - 1; i++) {
				std::cout << "\t{ data: " << arr[i].data
						  << ", next: " << arr[i].next << " },\n";
			}
			std::cout << "\t{ data: " << arr[len - 1].data
					  << ", next: " << arr[len - 1].next << " }\n";
			std::cout << "]";
		}
	}
	void push(T data, int index) {
		if (index >= len) {
			push(data);
		} else if (index < 0) {
			push(data, len + index);
		} else {
			SingleNode<T> n(data);
			arr = (SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) *
														 (++len));
			for (int i = index; i < len - 1; i++) { arr[i + 1] = arr[i]; }
			arr[index] = n;
			arr[index].next = arr[index + 1].data;
			if (index != 0) arr[index - 1].next = n.data;
		}
	}
	int isEmpty() { return len == 0; }
	~SinglyLinkedList() { delete arr; }
	void setCircular(bool yes = true) { isCircular = yes ? 1 : 0; }
	void circular() { arr[len - 1].next = arr[0].data; }
};
} // namespace MyDSA

#endif