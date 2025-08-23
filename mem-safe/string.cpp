#include "string.hpp"
#include "option.hpp"

const char *const String::c_str() { return &data.read_as_mut(); }
void String::operator=(const char *str) {
	_len = strlen(str);
	if (data.is_null()) {
		data.alloc(_len + 1);
		for (size_t i = 0; i < _len; i++) { data.mut_offset(i) = str[i]; };
		return;
	}
	data.alloc(_len + 1);
	for (size_t i = 0; i < _len; i++) { data.mut_offset(i) = str[i]; };
}
void String::append(char val) {
	data.realloc(++_len + 1);
	data.mut_offset(_len - 1) = val;
	data.mut_offset(_len) = 0;
}
void String::append(char *str) {
	size_t slen = strlen(str);
	data.realloc(_len + 1 + slen);
	for (size_t i = 0; i < slen; i++) {
		data.mut_offset(_len + i) = str[i];
	}
	_len += slen;
	data.mut_offset(_len) = 0;
}
Option<String> String::substr(size_t start, size_t end) {
	String res;
	String a = clone();
	if (start >= _len) {
		return Option<String>::None();
	}
	if (end >= _len) {
		end = _len;
	}
	for (size_t i = start; i < end; i++) {
		res += a[i].unwrap();
	}
	return Option<String>::Some(res);
}

std::ostream& operator<<(std::ostream &os, String &str) {
	return os << str.c_str();
}
