#pragma once
#include "allocator.hpp"
#include "option.hpp"
#include <cstddef>
#include <cstring>
#include <ostream>
#include <string>

class String {
	Allocator<char> data;
	std::size_t _len;

public:
	String() : _len(0) {
		data.alloc();
		data.write(0);
	}
	String(const char *str) { *this = str; }
	size_t len() { return _len; }
	const char *const c_str();
	void operator=(std::string str) { *this = str.c_str(); }
	void operator=(const char *str);
	~String() { data.free(); }

	void append(char val);
	void append(char *str);

	void operator+=(char val) {
		append(val);
	}
	void operator+=(const char *val) {
		append((char*)val);
	}
	void operator+=(String val) {
		append((char*)val.c_str());
	}
	operator const char*() {
		return c_str();
	}
	String clone() {
		String out;
		for (size_t i = 0; i < _len; i++) {
			out += data[i].unwrap();
		}
		return out;
	}
	String reverse() {
		String out = clone();
		for (size_t i = 0; i < _len / 2; i++) {
			char a = out.data.mut_offset(i);
			out.data.mut_offset(i) = out.data.mut_offset(_len - i - 1);
			out.data.mut_offset(_len - i - 1) = a;
		}
		return out;
	}

	Option<char> operator[](size_t index) {
		if (index >= _len) {
			return Option<char>::None();
		}
		return data[index];
	}

	OptionRef<char> mut_at(size_t index) {
		if (index >= _len) {
			return OptionRef<char>::None();
		}
		return OptionRef<char>::Some(data.mut_offset(index));
	}
	String substr(size_t start, size_t end);
	bool is_empty() { return _len == 0; }
};
std::ostream& operator<<(std::ostream &os, String &str);
