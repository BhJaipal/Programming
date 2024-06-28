#ifndef MY_HASHMAP
#define MY_HASHMAP
#include <cstdlib>
#include <functional>
#include <iostream>

namespace MyDSA {
/**
 * @brief Pair class for hash map
 * @tparam _Key Key type
 * @tparam _Value Value type
 */
template <typename _Key = int, typename _Value = std::string> struct Pair {
	_Key key;
	_Value value;
};

/**
 * @brief Hashmap class
 * @tparam _Key key type
 * @tparam _Value value type
 */
template <typename _Key = int, typename _Value = std::string> class Hashmap {
	Pair<_Key, _Value> *arr;
	int len;

  public:
	Hashmap(_Key first_key, _Value first_val) {
		arr = new Pair<_Key, _Value>;
		struct Pair<_Key, _Value> p;
		p.key = first_key;
		p.value = first_val;
		arr[0] = p;
		len = 1;
	}
	void put(_Key k, _Value v) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) {
				arr[i].value = v;
				return;
			}
		}
		struct Pair<_Key, _Value> p;
		p.key = k;
		p.value = v;
		arr = (Pair<_Key, _Value> *)std::realloc(arr, sizeof(arr[0]) * (++len));
		arr[len - 1] = p;
	}
	void putIfAbsent(_Key k, _Value v) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) { return; }
		}
		arr = (Pair<_Key, _Value> *)std::realloc(arr, sizeof(arr[0]) * (++len));
		struct Pair<_Key, _Value> p;
		p.key = k;
		p.value = v;
		arr[len - 1] = p;
	}
	_Value get(_Key k) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) { return k; }
		}
		return 0;
	}
	_Value getOrDefault(_Key k, _Value defaultVal) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) { return k; }
		}
		return defaultVal;
	}
	_Value operator[](_Key k) { return get(k); }
	bool containsKey(_Key k) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) return true;
		}
		return false;
	}
	_Key *keys() {
		_Key kys[len];
		for (int i = 0; i < len; i++) { kys[i] = arr[i].key; }
		return kys;
	}
	_Value *values() {
		_Value vals[len];
		for (int i = 0; i < len; i++) { vals[i] = arr[i].value; }
		return vals;
	}
	bool containsValue(_Value v) {
		for (int i = 0; i < len; i++) {
			if (arr[i].value == v) return true;
		}
		return false;
	}
	int replace(_Key k, _Value v) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) {
				arr[i].value = v;
				return 1;
			}
		}
		return 0;
	}
	_Value remove(_Key k) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) {
				_Value val = arr[i].value;
				for (int j = i; j < len - 1; j++) { arr[j] = arr[j + 1]; }
				arr = (Pair<_Key, _Value> *)std::realloc(
					arr, sizeof(Pair<_Key, _Value>) * (--len));
				return val;
			}
		}
		return 0;
	}
	int replace(_Key k, _Value old_val, _Value new_val) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k && arr[i].value == old_val) {
				arr[i].value = new_val;
				return 1;
			}
		}
		return 0;
	}
	int isEmpty() { return len == 0; }
	void toString() {
		if (isEmpty()) std::cout << "{}";
		else {
			std::cout << "{ ";
			for (int i = 0; i < len - 1; i++) {
				std::cout << arr[i].key << "=>" << arr[i].value << ", ";
			}
			std::cout << arr[len - 1].key << "=>" << arr[len - 1].value << " }";
		}
	}
	void forEach(std::function<void(_Key, _Value, int)> callback) {
		for (int i = 0; i < len; i++) { callback(arr[i].key, arr[i].value, i); }
	}
	void forEach(std::function<void(_Key, _Value)> callback) {
		for (int i = 0; i < len; i++) { callback(arr[i].key, arr[i].value); }
	}
	template <typename T> T *map(std::function<T(_Key, _Value, int)> callback) {
		T out[len];
		for (int i = 0; i < len; i++) {
			out[i] = callback(arr[i].key, arr[i].value, i);
		}
		return out;
	}
	T *map(std::function<T(_Key, _Value)> callback) {
		T out[len];
		for (int i = 0; i < len; i++) {
			out[i] = callback(arr[i].key, arr[i].value);
		}
		return out;
	}
};
} // namespace MyDSA

#endif