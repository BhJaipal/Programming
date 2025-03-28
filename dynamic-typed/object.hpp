#pragma once
#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
#include <vector>
typedef unsigned char *ptr_t;
typedef double f32;
typedef std::string str;
class Object;
typedef std::vector<Object> arr;
typedef std::map<Object, Object> dict_t;

enum class ObjectType { INT, FLOAT, STR, ARRAY, DICT };

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
	T to(ObjectType t) {
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
	static Object from(dict_t value) { return from(value, ObjectType::DICT); }

	int to_int() { return to<int>(ObjectType::INT); }
	f32 to_float() { return to<f32>(ObjectType::FLOAT); }
	str to_str() { return to<str>(ObjectType::STR); }
	arr to_arr() { return to<arr>(ObjectType::ARRAY); }
	dict_t to_dict() { return to<dict_t>(ObjectType::DICT); }

	void unref() { delete value_; }

	friend std::ostream &operator<<(std::ostream &cout, Object o);
};

std::ostream &operator<<(std::ostream &out, Object o) {
	switch (o.type) {
		case ObjectType::FLOAT: out << o.to_float(); break;
		case ObjectType::STR:	out << o.to_str(); break;
		case ObjectType::ARRAY:
			for (auto i : o.to_arr()) out << i;
			break;
		default: out << o.to_int(); break;
	}
	return out;
}