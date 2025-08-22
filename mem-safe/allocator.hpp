#pragma once
#include "option.hpp"
#include <cstddef>
#include <cstdlib>

enum class AllocatorStatus {
	Unallocated,
	Unassigned,
	Assigned
};

template <typename T>
class Allocator {
	T *data;
	std::size_t value_size;
	AllocatorStatus status;
public:
	Allocator(): data(NULL), value_size(0), status(AllocatorStatus::Unallocated) {}

	const T read();
	size_t size() {
		return value_size;
	}
	void free();
	T& read_as_mut() {
		return *data;
	}
	void write(T value);
	void alloc(size_t size = 1) {
		data = new T[size];
		value_size = sizeof(T[size]);
		status = AllocatorStatus::Unassigned;
	}
	bool is_null() {
		return status != AllocatorStatus::Assigned;
	}
	void realloc(size_t size);
	Option<T> operator[](size_t index);
	T& mut_offset(size_t index);
	~Allocator() {
		if (status == AllocatorStatus::Unallocated) return;
		free();
	}
};
