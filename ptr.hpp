#pragma once
#include <stdarg.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define DEBUG 1

template <typename T>
using print_fn_T = void (*)(T);

template <typename T>
void print(T var) {
#if DEBUG == 1
	std::cout << var << "\n";
#endif // DEBUG
}

template <typename T = int>
print_fn_T<T> debug(const char *fmt, ...) {
#if DEBUG == 1
	va_list args;
	va_start(args, fmt);
	printf("\e[34m[DEBUG]: \e[0m");
	vprintf(fmt, args);
	va_end(args);
#endif // DEBUG
	return print;
}

template <typename T = int>
print_fn_T<T> info(const char *fmt, ...) {
#if DEBUG == 1
	va_list args;
	va_start(args, fmt);
	printf("\e[32m[INFO]: \e[0m");
	vprintf(fmt, args);
	va_end(args);
#endif // DEBUG
	return print;
}

template <typename T>
class Pointer {
	T *ptr;
	size_t ptr_size;
	bool can_dealloc;
	bool dealloc_des;
	Pointer(T *_ptr, size_t n) : ptr(_ptr), ptr_size(n) {
		can_dealloc = false,
		dealloc_des = false;
	}

public:
	Pointer() : ptr(nullptr), ptr_size(0) {
		can_dealloc = true,
		dealloc_des = false;
	}

	void error_on_null() {
		if (ptr == nullptr) {
			std::cout << "\e[91m[ERROR]:\e[0m " << "Null pointer exception\n";
			exit(1);
		}
	}
	const T operator*() {
		error_on_null();
		return *ptr;
	}
	T *operator->() {
		error_on_null();
		return ptr;
	}
	const T read() {
		info("ptr.read() fn\n");
		error_on_null();
		return *ptr;
	}
	void alloc(size_t n = 1) {
		if (ptr == nullptr) {
			info("ptr.alloc() fn\n");
			debug("Prev Size: %d, Curr size: %d, Pointer: %p\n", ptr_size, n, ptr);
			ptr = new T[n];
			ptr_size = n;
			debug("Address: %p, size: %d\n", ptr, ptr_size);
		}
	}
	void write(T val) {
		info("ptr.write() fn\n");
		error_on_null();
		debug("Curr size: %d, Pointer: %p\n", ptr_size, ptr);
		*ptr = val;
		debug("Value: ")(*ptr);
	}
	T &get_as_mut(unsigned offset) {
		if (ptr_size <= offset) {
			info("ptr.get_as_mut() fn\n");
			std::cout << "\e[91m[ERROR]:\e[0m " << "Cannot excess access outside scope of pointer\n";
			debug("Pointer: %p, length: %d, value: ", ptr, ptr_size)(*ptr);
			exit(1);
		}
		return ptr[offset];

	}
	const T operator[](unsigned offset) {
		if (ptr_size <= offset) {
			info("ptr[unsigned] operator\n");
			std::cout << "\e[91m[ERROR]:\e[0m " << "Cannot excess access outside scope of pointer\n";
			debug("Pointer: %p, length: %d, value: ", ptr, ptr_size)(*ptr);
			exit(1);
		}
		return ptr[offset];
	}
	Pointer<T> operator+(unsigned offset) {
		if (ptr_size <= offset) {
			info("ptr + unsigned operator\n");
			std::cout << "\e[91m[ERROR]:\e[0m " << "Cannot excess access outside scope of pointer\n";
			exit(1);
		}
		return Pointer((T *)((unsigned *)ptr + offset), ptr_size - offset);
	}
	void realloc(size_t n) {
		info("ptr.realloc() fn\n");
		error_on_null();
		ptr = (T *)::realloc(ptr, sizeof(T[n]));
		ptr_size = n;
		debug("Pointer: %p, length: %d, value: ", ptr, ptr_size)(*ptr);
	}
	void dealloc() {
		if (dealloc_des && ptr != nullptr)
			info("ptr.dealloc()\n");
		if (ptr != nullptr) {
			if (!(can_dealloc || dealloc_des)) {
				std::cout << "\e[91m[ERROR]:\e[0m " <<
					"This pointer does not have permission of dealloc\n";
				debug("Pointer: %p, length: %d, value: ", ptr, ptr_size)(*ptr);
			}
			else if (can_dealloc) delete[] ptr;
		}
		ptr = nullptr;
	}
	~Pointer() {
		if (can_dealloc)
			info("~ptr destructor\n");
		dealloc_des = true;
		dealloc();
	}
};

template <typename T>
Pointer<T> make_ptr(size_t n = 1) {
	Pointer<T> ptr;
	ptr.alloc(n);
	return ptr;
}
