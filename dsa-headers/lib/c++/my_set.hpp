#pragma once
#include "data_models.hpp"
#include <exception>
#include <iostream>

namespace MyDSA {
template <typename T> class Set : Model<T> {
	int _len;
	T *arr;

  public:
	Set() : _len(0) { arr = new T[0]; }
	Set(T *arr) {
		_len = sizeof(arr) / sizeof(T);
		this->arr = new T[_len];
		for (int i = 0; i < _len; i++) { this->arr[i] = arr[i]; }
	}
	int length() { return _len; }
	T operator[](int index) {
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
		if (includes(val)) return;
		arr = (T *)std::realloc(arr, sizeof(T) * (++_len));
		arr[_len - 1] = val;
	}
	T pop() {
		try {
			if (_len == 0) { throw std::underflow_error("Array is empty\n"); }
			T last = arr[_len - 1];
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
	void push(int index, T val) {
		if (includes(val)) return;
		arr = std::realloc(arr, sizeof(T) * (++len));
		for (int i = index; i < _len - 1; i++) { arr[i + 1] = arr[i]; }
		arr[index] = val;
	}
	T pop(int index) {
		try {
			if (_len == 0) {
				throw std::underflow_error("Array is empty\n");
			} else if (index >= _len - 1) {
				return pop();
			} else if (index < 0) {
				pop(_len + 1 + index);
			} else {
				T last = arr[index];
				for (int i = index; i < _len - 1; i++) { arr[i] = arr[i + 1]; }
				arr = std::realloc(arr, sizeof(T) * (--_len));
				return last;
			}
		} catch (const std::exception &err) {
			std::cerr << err.what();
			return -1;
		}
	}
	T shift() { return pop(0); }
	void extends(Set<T> arr2) {
		for (int i = 0; i < arr2.length(); i++) { push(arr2[i]); }
	}
	bool includes(T val) { return indexOf(val) != -1; }
	int indexOf(T val) {
		for (int i = 0; i < _len; i++) {
			if (arr[i] == val) return i;
		}
		return -1;
	}
	void remove(T val) {
		int i = indexOf(val);
		if (i != -1) { pop(i); }
	}
	Set<T> slice(int start) { return slice(start, _len, 1); }
	Set<T> slice(int start, int end) { return slice(start, end, 1); }
	Set<T> slice(int start, int end, int jump) {
		Set<T> out;
		for (int i = start; i < end; i += jump) { out.push(arr[i]); }
		return out;
	}
	void forEach(std::function<void(T, int)> callback) {
		for (int i = 0; i < _len; i++) { callback(arr[i], i); }
	}
	template <typename outType>
	Set<outType> map(std::function<outType(T, int)> callback) {
		Set<outType> outs;
		for (int i = 0; i < _len; i++) { outs.push(callback(arr[i], i)); }
	}
	template <typename outType>
	Set<outType> map(std::function<outType(T)> callback) {
		Set<outType> outs;
		for (int i = 0; i < _len; i++) { outs.push(callback(arr[i])); }
	}
	void forEach(std::function<void(T)> callback) {
		for (int i = 0; i < _len; i++) { callback(arr[i]); }
	}
	void setValue(int index, T val) {
		if (includes(val)) {
			std::cout << "Similar value already exists, cannot change it\n";
		} else if (index >= _len - 1) {
			arr[_len - 1] = val;
		} else if (index < 0) {
			set(_len + 1 + index, val);
		} else {
			arr[index] = val;
		}
	}
};
} // namespace MyDSA