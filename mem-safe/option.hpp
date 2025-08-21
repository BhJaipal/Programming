#include <cstdlib>
#include <iostream>

template <typename T>
class Option {
	bool _some;
	T value;
	Option(bool some, T val): _some(some), value(val) {}
	Option(bool some): _some(some) {}
public:
	static const Option None() {
		return Option(false);
	}
	static Option Some(T val) {
		return Option(true, val);
	}

	bool is_some() {
		return _some;
	}
	bool is_none() {
		return !_some;
	}
	T unwrap() {
		if (!_some) {
			std::cout << "Err at Option::unwrap(): value is None\n";
			exit(1);
		}
		return value;
	}
};

