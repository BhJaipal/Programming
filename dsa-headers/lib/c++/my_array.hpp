#pragma once
#include "data_models.hpp"
#include <exception>
#include <iostream>

namespace MyDSA {
template <typename T> class Array : Model<T> {
	int _len;
	T *arr;

  public:
	Array() : _len(0) { arr = new T[0]; }
	Array(T *arr) {
		_len = sizeof(arr) / sizeof(T);
		this->arr = new T[_len];
		for (int i = 0; i < _len; i++) { this->arr[i] = arr[i]; }
	}
	int length() { return _len; }
	T &operator[](int index) {
		try {
			if (index > length()) {
				throw std::range_error("Index out of range\n");
			}
			return arr[index];
		} catch (const std::exception &err) {
			std::cerr << err.what();
			return -1;
		}
	}
	void push(T val) {
		arr = (T *)std::realloc(arr, sizeof(T) * (++_len));
		arr[_len - 1] = val;
	}
	T pop() {
		try {
			if (_len == 0) { throw std::underflow_error("Array is empty\n"); }
			T last = arr[len - 1];
			return last;
		} catch (const std::exception &err) {
			std::cerr << err.what();
			return -1;
		}
	}
	void toString() {
		if (!length()) {
			std::cout << "[]\n";
		} else {
			std::cout << "[";
			for (int i = 0; i < _len - 1; i++) { std::cout << arr[i] << ", "; }
			std::cout << arr[_len - 1] << " ]\n";
		}
	}
	void push(int index, T val);
	T pop(int index);
	T shift();
	void extend(Array<T> arr2);
	bool includes(T val);
	int indexOf(T val);
	Array<T> slice(int start);
	Array<T> slice(int start, int end);
	Array<T> slice(int start, int end, int jump);
};
} // namespace MyDSA