#ifndef CXX_STACK
#define CXX_STACK
#include "data_models.hpp"
#include <cstdlib>
#include <iostream>

namespace MyDSA {
template <typename T> class Stack : public Model<T> {
	T *arr;
	int len;

  public:
	Stack() {
		arr = new T[0];
		len = 0;
	}
	Stack(T first) {
		arr = new T[1];
		arr[0] = first;
		len = 1;
	}
	T peek() {
		if (isEmpty()) return 0;
		return this->arr[this->len - 1];
	}
	void push(T data) {
		arr = (T *)std::realloc(arr, sizeof(T) * (++len));
		arr[len - 1] = data;
	}
	T pop() {
		if (isEmpty()) return 0;
		T last = arr[--len];
		arr = (T *)std::realloc(arr, sizeof(T) * len);
		return last;
	}
	void toString() {
		std::cout << "[ ";
		if (!isEmpty()) {
			for (int i = 0; i < len - 1; i++) { std::cout << arr[i] << ", "; }
			std::cout << arr[len - 1] << " ";
		}
		std::cout << "]";
	}
	int isEmpty() { return len == 0; }
	~Stack() { delete arr; }
};
} // namespace MyDSA

#endif