#pragma once
#include "allocator.hpp"
#include "option.hpp"
#include <functional>

template <typename T>
class Array {
protected:
	Allocator<T> data;
	size_t len;

public:
	Array(): len(0) {}

	void append(T val) {
		if (data.is_null()) {
			data.alloc();
			data.write(val);
			len = 1;
			return;
		}
		data.realloc(++len);
		data.mut_offset(len - 1) = val;
	}
	Option<T> pop_last() {
		if (len == 0 || data.is_null()) {
			return Option<T>::None();
		}
		T last = data[--len].unwrap();
		data.realloc(len);
		return Option<T>::Some(last);
	}

	template <typename U>
	Array<U> map(std::function<U(std::size_t, T)> fn) {
		Array<U> out;
		for (size_t i = 0; i < len; i++) {
			out.append(fn(i, data[i].unwrap()));
		}
		return out;
	}
	template <typename U>
	Array<U> map(std::function<U(T)> fn) {
		Array<U> out;
		for (size_t i = 0; i < len; i++) {
			out.append(fn(data[i].unwrap()));
		}
		return out;
	}
	void for_each(std::function<void(std::size_t, T)> fn) {
		for (size_t i = 0; i < len; i++) {
			fn(i, data[i].unwrap());
		}
	}
	void for_each(std::function<void(T)> fn) {
		for (size_t i = 0; i < len; i++) {
			fn(data[i].unwrap());
		}
	}
	Array<T> filter(std::function<bool(std::size_t, T)> fn) {
		Array<T> out;
		for (size_t i = 0; i < len; i++) {
			if (fn(i, data[i].unwrap()))
				out.append(data[i].unwrap());
		}
		return out;
	}
	Array<T> filter(std::function<bool(T)> fn) {
		Array<T> out;
		for (size_t i = 0; i < len; i++) {
			if (fn(i, data[i].unwrap()))
				out.append(data[i].unwrap());
		}
		return out;
	}
	Option<T> operator[](size_t index) {
		if (index < len) {
			return Option<T>::Some(data[index].unwrap());
		}
		return Option<T>::None();
	}
	Option<size_t> search(T val) {
		for (size_t i = 0; i < len; i++) {
			if (val == data[i].unwrap()) {
				return Option<size_t>::Some(i);
			}
		}
		Option<size_t>::None();
	}
};
