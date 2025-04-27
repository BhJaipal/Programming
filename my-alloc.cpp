#include <iostream>
#include <iterator>
#include <malloc.h>
#define tem template <typename T>
#define tem_T(_T) template <typename T = _T>
typedef unsigned char u8;

tem class MyAllocator;
tem_T(u8) class pointer {
	T *data;

	pointer(T *data_) : data(data_) {}

public:
	friend class MyAllocator<T>;
	pointer() : data(nullptr) {}
	const T read() { return *data; }
	void write(T value) { *data = value; }
	bool is_null() { return data == nullptr; }
	const T &operator[](std::size_t index) { return data[index]; }
	T &get_as_mut(std::size_t index) { return data[index]; }
	T &operator*() { return *data; }
	pointer<T> operator+(std::size_t val) { return pointer(data + val); }
};

tem_T(u8) class MyAllocator {
	pointer<T> ptr;

public:
	MyAllocator() { ptr.data = nullptr; }
	pointer<T> &alloc(std::size_t size = 1) {
		if (!ptr.is_null()) free(ptr.data);
		ptr.data = (T *)malloc(sizeof(T[size]));
		return ptr;
	}
	void realloc(std::size_t size = 1) {
		if (ptr.is_null()) throw std::logic_error("ptr is nullptr");
		ptr.data = (T *)::realloc((void *)ptr.data, sizeof(T[size]));
	}
	~MyAllocator() {
		if (!ptr.is_null()) free(ptr.data);
	}
};

tem class Array {
	pointer<T> data;
	std::size_t len_;
	MyAllocator<T> alloc;

public:
	Array() : len_(0) {}
	std::size_t len() { return len_; }
	void push(T val) {
		if (len_ == 0) {
			data = alloc.alloc();
			len_++;
			data.write(val);
			return;
		}
		alloc.realloc(++len_);
		data.get_as_mut(len_ - 1) = val;
	}
	T pop() {
		T val = (data + (--len_)).read();
		alloc.realloc(len());
		return val;
	}
	bool is_empty() { return len() == 0; }
	const T operator[](std::size_t index) { return data[index]; }
	const T get(std::size_t index) { return data[index]; }
	T &get_as_mut(std::size_t index) { return data.get_as_mut(index); }

	class iterator
		: public std::iterator<std::input_iterator_tag, T, T, const T *, T> {
		std::size_t i = 0;
		Array *arr;

	public:
		explicit iterator(Array *a, std::size_t pos) : i(pos), arr(a) {}
		iterator &operator++() {
			if (i < arr->len()) i++;
			return *this;
		}
		iterator operator++(int) {
			iterator retval = *this;
			++(*this);
			return retval;
		}
		bool operator==(iterator other) const { return i == other.i; }
		bool operator!=(iterator other) const { return !(*this == other); }
		T &operator*() { return arr->get_as_mut(i); }
	};
	iterator begin() { return iterator(this, 0); }
	iterator end() { return iterator(this, len_ - 1); }

	void for_each(void (*fn)(T item, std::size_t index)) {
		for (std::size_t i = 0; i < len_; i++) { fn(data[i], i); }
	}
	template <class U>
	Array<U> map(U (*fn)(T item, std::size_t index)) {
		Array<U> arr;
		for (std::size_t i = 0; i < len_; i++) { arr.push(fn(data[i], i)); }
		return arr;
	}
};

int main() {
	Array<int> arr;
	for (int i = 0; i < 10; ++i) { arr.push(i); }
	arr.push(74);
	arr.push(37);
	arr.push(94);
	arr.push(62);
	arr.push(26);
	std::cout << "Len: " << arr.len() << "\n";
	for (auto el : arr) { std::cout << el << " "; }
	std::cout << "\n";
	// arr.for_each(
	// 	[](int it, std::size_t i) { std::cout << i << ": " << it << "\n"; });
	return 0;
}