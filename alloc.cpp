#include <iostream>
#include <malloc.h>
#include <string>
#include <vector>
using std::cout;
using std::string;
typedef float f32;
typedef int i32;
typedef short i16;
typedef char i8;
typedef long int ptr_t;

enum class ObjectType { I32, I16, F32 };

class Object {
	ptr_t *value_;
	ObjectType type_;

	Object() = default;
	Object(ptr_t *value, ObjectType type) : value_(value), type_(type) {}

	template <typename T = i32>
	static Object from(T value, ObjectType type) {
		T *ptr = (T *)malloc(sizeof(T));
		*ptr = value;
		return Object((ptr_t *)ptr, type);
	}

public:
	static Object from_f32(f32 value) {
		return from<f32>(value, ObjectType::F32);
	}
	static Object from(i32 value) { return from(value, ObjectType::I32); }
	static Object from_i32(i32 value) { return from(value, ObjectType::I32); }
	static Object from_i16(i16 value) {
		return from<i32>(value, ObjectType::I16);
	}

	friend std::ostream &operator<<(std::ostream &out, Object obj);
};

std::ostream &operator<<(std::ostream &out, Object obj) {
	switch (obj.type_) {
		case ObjectType::F32: out << *((f32 *)obj.value_); break;
		case ObjectType::I16: out << *((i16 *)obj.value_); break;
		default:			  out << *((i32 *)obj.value_); break;
	};
	return out;
}

int main() {
	std::vector<Object> objs{};
	objs.push_back(Object::from_i16(5));
	objs.push_back(Object::from_f32(7.9));
	objs.push_back(Object::from_i32(52277));
	for (auto &&i : objs) { cout << i << '\n'; }
	int i = objs.size() - 1;
	while (objs.size() != 0) {
		Object &obj = objs[i];
		i--;
		objs.pop_back();
	}
	return 0;
}