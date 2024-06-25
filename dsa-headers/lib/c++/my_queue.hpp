#ifndef CXX_QUEUE
#define CXX_QUEUE
#include "data_models.hpp"
#include <cstdlib>
#include <iostream>

/**
 * @tparam T type of elements in queue
 */
namespace MyDSA {
template <typename T> class Queue : MyDSA::Model<T> {
	T *arr;
	int len;

  public:
	/**
	 * @brief Construct a new Queue object
	 */
	Queue() {
		arr = new T[0];
		len = 0;
	}
	/**
	 * @brief Construct a new Queue object
	 * @param first First element of a queue
	 */
	Queue(T first) {
		arr = new T[1];
		len = 1;
		arr[0] = first;
	}
	/**
	 * @brief Adds a new element at the end of queue
	 * @param data Element ot be added in queue
	 */
	void push(T data) {
		arr = (T *)std::realloc(arr, sizeof(T) * (++len));
		arr[len - 1] = data;
	}
	/**
	 * @brief Removes first element of queue
	 * @return first element of queue
	 */
	T pop() {
		if (isEmpty()) return 0;
		T first = arr[0];
		for (int i = 0; i < len - 1; i++) { arr[i] = arr[i + 1]; }
		arr = (T *)std::realloc(arr, sizeof(T) * (--len));
		return first;
	}
	/**
	 * @brief Prints queue in an array like form
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
	 * @brief Returns first element of queue without removing it
	 * @return T first element of queue
	 */
	T peek() {
		if (isEmpty()) return 0;
		return arr[0];
	}
	/**
	 * @brief Checks if queue is empty
	 */
	int isEmpty() { return len == 0; }
	~Queue() { delete arr; }
};
} // namespace MyDSA

#endif