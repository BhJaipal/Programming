#pragma once
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

typedef unsigned char *ptr_t;
typedef double f32;
typedef std::string str;
class Object;
typedef std::vector<Object> arr;

enum class ObjectType { INT, FLOAT, STR, ARRAY, DICT };

template <class T>
class _Dict {
	struct Pair {
		T key;
		T value;
		Pair(T k, T v) : key(k), value(v) {}
	};
	int len_;
	std::vector<Pair> pairs;

public:
	_Dict(T k, T v) : len_(1) { pairs.push_back(Pair(k, v)); }
	_Dict() : len_(0) {}
	int len() { return len_; }

	void push(T k, T v) {
		pairs.push_back(Pair(k, v));
		len_++;
	}
	Pair pop() {
		Pair last = pairs[--len_];
		pairs.pop_back();
		return last;
	}
	Pair operator[](int i) { return pairs[i]; }

	void unref() {
		for (int i = 0; i < len_; i++) {
			pairs[i].key.unref();
			pairs[i].value.unref();
		}
	}

	template <class U>
	friend std::ostream &operator<<(std::ostream &out, _Dict<U> dict);
};

/// @brief  Prints the dictionary
/// @param out `std::cout`
/// @param dict Self/ `Dict` object
template <class T = Object>
std::ostream &operator<<(std::ostream &out, _Dict<T> dict) {
	std::cout << "{ ";
	for (int i = 0; i < dict.len(); i++) {
		auto pair = dict.pairs[i];
		std::cout << pair.key << " => " << pair.value;
		if (i != dict.len() - 1) { std::cout << ", "; }
	}
	std::cout << " }";
	return out;
}
typedef _Dict<Object> Dict;

class Object {
	ptr_t value_;
	ObjectType type;
	Object(ptr_t value, ObjectType t) : value_(value), type(t) {}
	Object() = default;

	template <class T>
	static Object from(T val, ObjectType t) {
		T *ptr = new T(val);
		return Object((ptr_t)ptr, t);
	}

	template <class T>
	T &to(ObjectType t) {
		if (t != type) {
			std::cout << "Object is not ";
			switch (t) {
				case ObjectType::STR:	std::cout << "String\n"; break;
				case ObjectType::FLOAT: std::cout << "Float\n"; break;
				case ObjectType::ARRAY: std::cout << "Array\n"; break;
				case ObjectType::DICT:	std::cout << "Dictionary\n"; break;
				default:				std::cout << "Int\n"; break;
			}
			exit(1);
		}
		return *(T *)value_;
	}

public:
	static Object from(int value) { return from(value, ObjectType::INT); }
	static Object from(f32 value) { return from(value, ObjectType::FLOAT); }
	static Object from(str value) { return from(value, ObjectType::STR); }
	static Object from(arr value) { return from(value, ObjectType::ARRAY); }
	static Object from(Object value...) {
		return from(value, ObjectType::ARRAY);
	}
	static Object from(Dict value) { return from(value, ObjectType::DICT); }

	int &to_int() { return to<int>(ObjectType::INT); }
	f32 &to_float() { return to<f32>(ObjectType::FLOAT); }
	str &to_str() { return to<str>(ObjectType::STR); }
	arr &to_arr() { return to<arr>(ObjectType::ARRAY); }
	Dict &to_dict() { return to<Dict>(ObjectType::DICT); }

	void unref() {
		if (type == ObjectType::DICT) to_dict().unref();
		else if (type == ObjectType::ARRAY) {
			for (auto el : to_arr()) { el.unref(); }
		}
		delete value_;
	}
	friend std::ostream &operator<<(std::ostream &cout, Object o);
};

std::ostream &print(std::ostream &out, arr o) {
	out << "[ ";
	for (int i = 0; i < o.size(); i++) {
		out << o[i];
		if (i != o.size() - 1) out << ", ";
	}
	out << " ]";
	return out;
}
std::ostream &operator<<(std::ostream &out, Object o) {
	switch (o.type) {
		case ObjectType::FLOAT:
			out << "\e[38;5;156m" << o.to_float() << "\e[0m";
			break;
		case ObjectType::STR:
			out << "\x1b[38;5;173m\"" << o.to_str() << "\"\e[0m";
			break;
		case ObjectType::DICT:	out << o.to_dict(); break;
		case ObjectType::ARRAY: print(out, o.to_arr()); break;
		default:				out << "\e[38;5;156m" << o.to_int() << "\e[0m"; break;
	}
	return out;
}