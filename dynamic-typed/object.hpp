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

	void unref();

	typedef _Dict<Object> Dict;
	friend std::ostream &operator<<(std::ostream &out, Dict dict);
};

typedef _Dict<Object> Dict;
class Object {
	ptr_t value_;
	ObjectType type;
	Object(ptr_t value, ObjectType t) : value_(value), type(t) {}
	Object() = default;

	template <class T>
	static Object from(T val, ObjectType t);

	template <class T>
	T &to(ObjectType t);

public:
	ObjectType get_type();
	static Object from(int value);
	static Object from(f32 value);
	static Object from(str value);
	static Object from(arr value);
	static Object from(Dict value);

	int &to_int();
	f32 &to_float();
	str &to_str();
	arr &to_arr();
	Dict &to_dict();

	void unref();
	friend std::ostream &operator<<(std::ostream &out, Object o);
};

std::ostream &print(std::ostream &out, arr o);