#include "object.hpp"

// class _Dict {
template <class T>
void _Dict<T>::unref() {
	for (int i = 0; i < len_; i++) {
		pairs[i].key.unref();
		pairs[i].value.unref();
	}
}

std::ostream &operator<<(std::ostream &out, Dict dict) {
	std::cout << "{ ";
	for (int i = 0; i < dict.len(); i++) {
		auto pair = dict.pairs[i];
		std::cout << pair.key << " => " << pair.value;
		if (i != dict.len() - 1) { std::cout << ", "; }
	}
	std::cout << " }";
	return out;
}
// }

// class Object {
template <class T>
Object Object::from(T val, ObjectType t) {
	T *ptr = new T(val);
	return Object((ptr_t)ptr, t);
}

template <class T>
T &Object::to(ObjectType t) {
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

ObjectType Object::get_type() { return type; }
Object Object::from(int value) { return Object::from(value, ObjectType::INT); }
Object Object::from(f32 value) {
	return Object::from(value, ObjectType::FLOAT);
}
Object Object::from(str value) { return Object::from(value, ObjectType::STR); }
Object Object::from(arr value) {
	return Object::from(value, ObjectType::ARRAY);
}
Object Object::from(Dict value) {
	return Object::from(value, ObjectType::DICT);
}

int &Object::to_int() { return Object::to<int>(ObjectType::INT); }
f32 &Object::to_float() { return Object::to<f32>(ObjectType::FLOAT); }
str &Object::to_str() { return Object::to<str>(ObjectType::STR); }
arr &Object::to_arr() { return Object::to<arr>(ObjectType::ARRAY); }
Dict &Object::to_dict() { return Object::to<Dict>(ObjectType::DICT); }

void Object::unref() {
	if (type == ObjectType::DICT) to_dict().unref();
	else if (type == ObjectType::ARRAY) {
		for (auto el : to_arr()) { el.unref(); }
	}
	delete value_;
}

std::ostream &print(std::ostream &out, arr o) {
	out << "[ ";
	for (std::size_t i = 0; i < o.size(); i++) {
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
// }