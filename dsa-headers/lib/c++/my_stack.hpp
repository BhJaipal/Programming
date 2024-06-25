#ifndef CXX_STACK
#define CXX_STACK
#include "data_models.hpp"
#include <cstdlib>
#include <iostream>

namespace MyDSA {
/**
 * @tparam T type of elements in stack
 */
template <typename T> class Stack : public Model<T> {
	T *arr;
	int len;

  public:
	/**
	 * @brief Construct a new Stack object
	 */
	Stack() {
		arr = new T[0];
		len = 0;
	}
	/**
	 * @brief Construct a new Stack object
	 * @param first First element of a stack
	 */
	Stack(T first) {
		arr = new T[1];
		arr[0] = first;
		len = 1;
	}
	/**
	 * @brief Returns last element of stack without removing it
	 * @return last element of stack
	 */
	T peek() {
		if (isEmpty()) return 0;
		return this->arr[this->len - 1];
	}
	/**
	 * @brief Adds a new element at the end of stack
	 * @param data Element to be added in stack
	 */
	void push(T data) {
		arr = (T *)std::realloc(arr, sizeof(T) * (++len));
		arr[len - 1] = data;
	}
	/**
	 * @brief Removes last element of stack
	 * @return last element of stack
	 */
	T pop() {
		if (isEmpty()) return 0;
		T last = arr[--len];
		arr = (T *)std::realloc(arr, sizeof(T) * len);
		return last;
	}
	/**
	 * @brief Prints stack in an array like form
	 */
	void toString() {
		std::cout << "[ ";
		if (!isEmpty()) {
			for (int i = 0; i < len - 1; i++) { std::cout << arr[i] << ", "; }
			std::cout << arr[len - 1] << " ";
		}
		std::cout << "]";
	}
	/**
	 * @brief Checks if stack is empty
	 */
	int isEmpty() { return len == 0; }
	~Stack() { delete arr; }
};
} // namespace MyDSA

#endif