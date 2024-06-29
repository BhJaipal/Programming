#pragma once
#include "data_models.hpp"
#include <exception>
#include <functional>
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
	void extends(Array<T> arr2) {
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
	Array<T> slice(int start) { return slice(start, _len, 1); }
	Array<T> slice(int start, int end) { return slice(start, end, 1); }
	Array<T> slice(int start, int end, int jump) {
		Array<T> out;
		for (int i = start; i < end; i += jump) { out.push(arr[i]); }
		return out;
	}
	void forEach(std::function<void(T, int)> callback) {
		for (int i = 0; i < _len; i++) { callback(arr[i], i); }
	}
	template <typename outType>
	Array<outType> map(std::function<outType(T, int)> callback) {
		Array<outType> outs;
		for (int i = 0; i < _len; i++) { outs.push(callback(arr[i], i)); }
	}
	template <typename outType>
	Array<outType> map(std::function<outType(T)> callback) {
		Array<outType> outs;
		for (int i = 0; i < _len; i++) { outs.push(callback(arr[i])); }
	}
	void forEach(std::function<void(T)> callback) {
		for (int i = 0; i < _len; i++) { callback(arr[i]); }
	}
	void setValue(int index, T val) {
		if (index >= _len - 1) {
			arr[_len - 1] = val;
		} else if (index < 0) {
			set(_len + 1 + index, val);
		} else {
			arr[index] = val;
		}
	}
	void reverse() {
		Array<T> rev;
		for (int i = 0; i < _len; i++) { rev.push(0, arr[i]); }
		*this = rev;
	}
	void sort(bool _reverse = false) {
		*this = mergeSort(*this);
		if (_reverse) { reverse(); }
	}
	int count(T val) {
		int _count = 0;
		for (int i = 0; i < _len; i++) {
			if (arr[i] == val) _count++;
		}
		return _count;
	}
	bool operator>(Array<T> arr2) { return length() > arr2.length(); }
	bool operator<(Array<T> arr2) { return length() < arr2.length(); }
	bool operator==(Array<T> arr2) { return length() == arr2.length(); }
	bool operator!=(Array<T> arr2) { return length() != arr2.length(); }
};
template <typename T> Array<T> mergeSort(Array<T> arr) {
	int mid = length() / 2;
	if (length() < 2) return arr;
	Array<T> left = slice(0, mid);
	return merge(mergeSort(left), mergeSort(arr));
}
template <typename T> Array<T> merge(Array<T> left, Array<T> right) {
	Array<T> out;
	while (left.length() && right.length()) {
		if (left[0] < right[0]) {
			out.push(left.shift());
		} else {
			out.push(right.shift());
		}
	}
	while (left.length()) { out.push(left.shift()); }
	while (right.length()) { out.push(right.shift()); }
	return out;
}
} // namespace MyDSA