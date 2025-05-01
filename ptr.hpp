#pragma once
#include <iostream>
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1
#define DEBUG_LEVEL 1

template <typename T>
using print_fn_T = void (*)(T);

template <typename T>
void print(T var, int debug_lvl) {
#if DEBUG == 1
	if (debug_lvl <= DEBUG_LEVEL)
		std::cout << var << "\n";
#endif // DEBUG
}

void debug(int debug_lvl, const char *fmt, ...) {
#if DEBUG == 1
	va_list args;
	va_start(args, fmt);
	if (debug_lvl <= DEBUG_LEVEL) printf("\e[34m[DEBUG]: \e[0m");
	if (debug_lvl <= DEBUG_LEVEL) vprintf(fmt, args);
	va_end(args);
#endif // DEBUG
}

void info(const char *fmt, ...) {
#if DEBUG == 1
	va_list args;
	va_start(args, fmt);
	printf("\e[32m[INFO]: \e[0m");
	vprintf(fmt, args);
	va_end(args);
#endif // DEBUG
}

template <typename T>
class Pointer {
	T *ptr;
	size_t ptr_size;
	bool can_dealloc;
	bool dealloc_des;
	Pointer(T *_ptr, size_t n) : ptr(_ptr), ptr_size(n) {
		can_dealloc = false, dealloc_des = false;
	}

public:
	Pointer() : ptr(nullptr), ptr_size(0) {
		can_dealloc = true, dealloc_des = false;
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
			debug(2, "Prev Size: %d, Curr size: %d, Pointer: %p\n", ptr_size, n, ptr);
			ptr = new T[n];
			ptr_size = n;
			debug(2, "Address: %p, size: %d\n", ptr, ptr_size);
		}
	}
	void write(T val) {
		info("ptr.write() fn\n");
		error_on_null();
		debug(1, "Curr size: %d, Pointer: %p, Value: ", ptr_size, ptr);
		*ptr = val;
		print(*ptr, 1);
	}
	T &get_as_mut(unsigned offset) {
		if (ptr_size <= offset) {
			info("ptr.get_as_mut() fn\n");
			std::cout << "\e[91m[ERROR]:\e[0m "
					  << "Cannot excess access outside scope of pointer\n";
			debug(1, "Pointer: %p, length: %d, offset: %d, Value: ", ptr, ptr_size, offset);
			print(*ptr, 1);
			exit(1);
		}
		return ptr[offset];
	}
	const T operator[](unsigned offset) {
		if (ptr_size <= offset) {
			info("ptr[unsigned] operator\n");
			std::cout << "\e[91m[ERROR]:\e[0m "
					  << "Cannot excess access outside scope of pointer\n";
			debug(1, "Pointer: %p, length: %d, value: ", ptr, ptr_size);
			print(*ptr, 1);
			exit(1);
		}
		return ptr[offset];
	}
	Pointer<T> operator+(unsigned offset) {
		if (ptr_size <= offset) {
			info("ptr + unsigned operator\n");
			std::cout << "\e[91m[ERROR]:\e[0m "
					  << "Cannot excess access outside scope of pointer\n";
			exit(1);
		}
		return Pointer((T *)((unsigned *)ptr + offset), ptr_size - offset);
	}
	void realloc(size_t n) {
		info("ptr.realloc() fn\n");
		error_on_null();
		ptr = (T *)::realloc(ptr, sizeof(T[n]));
		ptr_size = n;
		debug(2, "Pointer: %p, length: %d, value: ", ptr, ptr_size);
		print(*ptr, 2);
	}
	void dealloc() {
		if (dealloc_des && ptr != nullptr) info("ptr.dealloc()\n");
		if (ptr != nullptr) {
			if (!(can_dealloc || dealloc_des)) {
				std::cout
					<< "\e[91m[ERROR]:\e[0m "
					<< "This pointer does not have permission of dealloc\n";
				debug(2, "Pointer: %p, length: %d, value: ", ptr, ptr_size);
				print(*ptr, 2);
			} else if (can_dealloc) delete[] ptr;
		}
		ptr = nullptr;
	}
	~Pointer() {
		if (can_dealloc) info("~ptr destructor\n");
		dealloc_des = true;
		dealloc();
	}
};

template <typename T>
Pointer<T> make_ptr(std::size_t n = 1) {
	Pointer<T> ptr;
	ptr.alloc(n);
	return ptr;
}