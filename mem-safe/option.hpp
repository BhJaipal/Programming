#pragma once
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
	Option def(T val) {
		value = val;
		return *this;
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


template <typename T>
class OptionRef {
	bool _some;
	T value;
	OptionRef(bool some, T val): _some(some), value(val) {}
	OptionRef(bool some): _some(some) {}
public:
	static const OptionRef None() {
		return OptionRef(false);
	}
	static OptionRef Some(T& val) {
		return OptionRef(true, val);
	}

	bool is_some() {
		return _some;
	}
	OptionRef def(T val) {
		value = val;
		return *this;
	}
	bool is_none() {
		return !_some;
	}
	T& unwrap() {
		if (!_some) {
			std::cout << "Err at Option::unwrap(): value is None\n";
			exit(1);
		}
		return value;
	}
};
