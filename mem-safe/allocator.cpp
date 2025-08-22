#include "allocator.hpp"

template <typename T>
const T Allocator<T>::read() {
	if (status == AllocatorStatus::Unallocated) {
		std::cout << "Err on Allocator::read: value is nullpointer, allocate memory to use\n";
		exit(1);
	}
	if (status == AllocatorStatus::Unassigned) {
		std::cout << "Err on Allocator::read: value is unassigned\n";
		exit(1);
	}
	return *data;
}

template <typename T>
void Allocator<T>::free() {
	if (status == AllocatorStatus::Unallocated) return;
	delete data;
	data = NULL;
	value_size = 0;
	status = AllocatorStatus::Unallocated;
}

template <typename T>
void Allocator<T>::write(T value) {
	if (!data) {
		std::cout << "Err on Allocator::write: value is nullpointer, allocate memory to use\n";
		exit(1);
	}
	status = AllocatorStatus::Assigned;
	read_as_mut() = value;
}

template <typename T>
void Allocator<T>::realloc(size_t size) {
	if (status == AllocatorStatus::Unallocated) {
		alloc(size);
		return;
	}
	data = (T*)std::realloc(data, sizeof(T[size]));
	value_size = sizeof(T[size]);
}
template <typename T>
Option<T> Allocator<T>::operator[](size_t index) {
	if (status == AllocatorStatus::Unallocated) {
		std::cout << "Err at Allocator::[]: accessing unallocated pointer\n";
		return Option<T>::None();
	}
	size_t size = value_size/sizeof(T);
	if (size <= index) {
		std::cout << "Err at Allocator::[]: index must be less than pointer/array of " << size << "\n";
		return Option<T>::None();
	}
	return Option<T>::Some((const T)(data[index]));
}
template <typename T>
T& Allocator<T>::mut_offset(size_t index) {
	if (status == AllocatorStatus::Unallocated) {
		std::cout << "Err at Allocator::[]: accessing unallocated pointer\n";
		exit(1);
	}
	size_t size = value_size/sizeof(T);
	if (size <= index) {
		std::cout << "Err at Allocator::[]: index must be less than pointer/array of " << size << "\n";
		exit(1);
	}
	return data[index];
}
