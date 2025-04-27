#pragma once
#include "ptr.hpp"
#include <initializer_list>
#include <iterator>

template <typename T>
class Array {
	Pointer<T> data;
	size_t _len;
public:
	Array(): data(make_ptr<T>(0)), _len(0) {}
	Array(std::initializer_list<T> elems) {
		_len = elems.size();
		data = make_ptr<T>(_len);
		size_t i = 0;
		for (auto el: elems) {
			(data + i).write(el);
			i++;
		}
	}
	const T first() {
		return data[0];
	}
	void push(T el) {
		data.realloc(++_len);
		(data + _len - 1).write(el);
	} 
	const T last() {
		return data[_len - 1];
	}

	const T operator[](size_t i) {
		return data[i];
	}

	class iterator: public std::iterator<std::input_iterator_tag, T, T, const T *, T> {
		std::size_t i = 0;
		Array *arr;
		public:
		explicit iterator(Array *a, std::size_t pos) : i(pos), arr(a) {}
		iterator &operator++() {
			if (i < arr->_len) i++;
			return *this;
		}
		iterator operator++(int) {
			iterator retval = *this;
			++(*this);
			return retval;
		}
		bool operator==(iterator other) const { return i == other.i; }
		bool operator!=(iterator other) const { return !(*this == other); }
		const T operator*() { return arr->data[i]; }
	};
	iterator begin() { return iterator(this, 0); }
	iterator end() { return iterator(this, _len); }
};
