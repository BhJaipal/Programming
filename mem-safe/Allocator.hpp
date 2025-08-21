#include "option.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

template <typename T>
class Allocator {
	Option<T*> val;
	std::size_t value_size;
	bool unassigned;
public:
	Allocator(): val(Option<T*>::None()), value_size(0), unassigned(true) {}

	const T read() {
		if (val.is_none()) {
			std::cout << "Err on Allocator::read: value is nullpointer, allocate memory to use\n";
			exit(1);
		}
		if (unassigned) {
			std::cout << "Err on Allocator::read: value is unassigned\n";
			exit(1);
		}
		return *val.unwrap();
	}
	void free() {
		delete val.unwrap();
		val = Option<T*>::None();
		value_size = 0;
		unassigned = true;
	}
	T& read_as_mut() {
		return *val.unwrap();
	}
	void write(T value) {
		if (val.is_none()) {
			std::cout << "Err on Allocator::write: value is nullpointer, allocate memory to use\n";
			exit(1);
		}
		unassigned = false;
		read_as_mut() = value;
	}
	void alloc(size_t size = 1) {
		val = Option<T*>::Some(new T[size]);
		value_size = sizeof(T[size]);
	}
	bool is_null() {
		return val.is_none() || !value_size;
	}
	Option<T> operator[](size_t index) {
		if (val.is_none()) {
			std::cout << "Err at Allocator::[]: accessing unallocated pointer\n";
			return Option<T>::None();
		}
		size_t size = value_size/sizeof(T);
		if (size <= index) {
			std::cout << "Err at Allocator::[]: index " << index << " bigger than pointer/array of " << size << "\n";
			return Option<T>::None();
		}
		return Option<T>::Some(val.unwrap()[index]);
	}
	~Allocator() {
		if (val.is_none()) return;
		delete val.unwrap();
		val = Option<T*>::None();
		value_size = 0;
		unassigned = true;
	}
};
