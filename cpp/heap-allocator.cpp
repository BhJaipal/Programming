#include <cstdarg>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <sys/mman.h>

template <class T>
class option {
	T value_;
	bool some_;

public:
	option(T value) {
		value_ = value;
		some_ = true;
	}
	option() { some_ = false; }
	static option<T> some(T value) { return option<T>(value); }
	static option<T> none() { return option(); }

	T unwrap() {
		if (some_) return value_;
		throw "Value is none\n";
	}
	bool is_some() { return some_; }
	template<class U>
	friend std::ostream& operator<<(std::ostream&, option<U>);
};

template<class T>
std::ostream& operator<<(std::ostream& o, option<T> val) {
	if (val.some_) {
		o << "Some(" << val.unwrap() << ")";
	} else o << "None";
	return o;
}

class memory_pool;

template <class T>
class pointer {
protected:
	T *data;
	memory_pool *parent;
	friend class memory_pool;
	std::size_t size_;

	template<class U>
	pointer(U *data_, size_t size): data((T*)data_), size_(size) {}
public:
	pointer() {
		data = nullptr;
		size_ = 0;
	}
	template<class U>
	pointer(U *data_): data((T*)data_)  {
		size_ = sizeof(*data_);
		parent = nullptr;
	}

	template<class U>
	operator pointer<U>() {
		return pointer((U*)data, size_);
	}

	option<T> operator[](size_t i) {
		return data[i];
	}
	T *raw_ptr() {
		return data;
	}
	void write(T value) {
		*data = value;
	}
	template <class U>
	pointer<T>& copy_from(U *ptr, size_t size) {
		for (size_t i = 0; i < size_; i++) {
			((char*)data)[i] = ptr[i];
		}
		size_ = size;
		return *this;
	}

	pointer<T>& write_bytes(size_t size, ...) {
		va_list args;
		va_start(args, size);
		for (size_t i = 0; i < size_; i++) {
			((char*)data)[i] = va_arg(args, int);
		}
		va_end(args);
		size_ = size;
		return *this;
	}
	option<T> operator*() {
		if (!(data && size_)) return option<T>::none();
		return option<T>::some(*data);
	}

	pointer<T>& copy_from(pointer<char> ptr) {
		for (size_t i = 0; i < size_; i++) {
			((char*)data)[i] = ptr[i].unwrap();
		}
		size_ = ptr.size_;
		return *this;
	}
	size_t size() { return size_; }
	
	template<class U>
	friend std::ostream& operator<<(std::ostream& o, pointer<U>);
};

template<class U>
std::ostream& operator<<(std::ostream& o, pointer<U> ptr) {
	o << ptr.data;
	return o;
}


class memory_pool {
protected:
	struct ptr_t: public pointer<char> {
	public:
		bool is_free = true;
		ptr_t *next;
		ptr_t *prev;

		ptr_t(void *data_, size_t size) {
			data = (char*)data_;
			size_ = size;
		}
	};
	size_t total;
	int flags_;
	int fd_;
	int prot_;
	ptr_t *head;
	bool init_done = false;
	void write(ptr_t *ptr, void *data, size_t size) {
		ptr->data = (char*)data;
		ptr->size_ = size;
	}

public:
	memory_pool(int prot = PROT_READ | PROT_WRITE, int flags = MAP_ANONYMOUS | MAP_PRIVATE, int fd = -1): prot_(prot), flags_(flags), fd_(fd) {}
	void *next_mem_loc() {
		if (!init_done) return NULL;
		ptr_t *curr = head;
		while (curr->next) {
			curr = curr->next;
		}
		return curr->data + curr->size_;
	}
	memory_pool& prot(int prot__) {
		prot_ = prot__;
		return *this;
	}
	memory_pool& flags(int flags__) {
		flags_ = flags__;
		return *this;
	}
	memory_pool& fd(int fd__) {
		fd_ = fd__;
		return *this;
	}
	ptr_t allocate(size_t size) {
		void *raw_ptr = mmap(next_mem_loc(), size, prot_, flags_, fd_, 0);
		ptr_t ptr_obj(raw_ptr, size);
		total += size;
		return ptr_obj;
	}
	void label_free(void *ptr) {
		ptr_t *curr = head;
		while (curr->next && curr->data != ptr) {
			curr = curr->next;
		}
		if (curr->data != ptr) return;
		curr->is_free = true;
	}
};

int main() {
	memory_pool a;
	auto b = a.allocate(8);
	b.write_bytes(3, 0x4a, 0x61, 0x69);
	std::cout << b << "\n";
}
