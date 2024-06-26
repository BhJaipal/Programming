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
template <typename _Key, typename _Value> class Pair {
  public:
	_Key key;
	_Value value;
	Pair(_Key k, _Value v) : key(k), value(v) {}
};

/**
 * @brief Hashmap class
 * @tparam _Key key type
 * @tparam _Value value type
 */
template <typename _Key = int, typename _Value = int> class Hashmap {
	Pair<_Key, _Value> *arr;
	int len;

  public:
	Hashmap(_Key first_key, _Value first_val) {
		arr = new Pair<_Key, _Value>[1] { Pair(first_key, first_val) };
		// arr[0] = Pair<_Key, _Value>(first_key, first_val);
		len = 1;
	}
	void put(_Key k, _Value v) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) {
				arr[i].value = v;
				return;
			}
		}
		arr = (Pair<_Key, _Value> *)std::realloc(
			arr, sizeof(Pair<_Key, _Value>) * (++len));
		Pair<_Key, _Value> p(k, v);
		arr[len - 1] = p;
	}
	void putIfAbsent(_Key k, _Value v) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) { return; }
		}
		arr = (Pair<_Key, _Value> *)std::realloc(
			arr, sizeof(Pair<_Key, _Value>) * (++len));
		Pair<_Key, _Value> p(k, v);
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
	int replace(_Key k, _Value v) {
		for (int i = 0; i < len; i++) {
			if (arr[i].key == k) {
				arr[i].value = v;
				return 1;
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
	~Hashmap() { delete[] arr; }
};
} // namespace MyDSA

#endif