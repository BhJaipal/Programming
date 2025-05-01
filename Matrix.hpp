#pragma once
#include <initializer_list>
#include <iostream>

template <std::size_t row_size, std::size_t col_size, typename T>
class Matrix {
protected:
	T rows[row_size][col_size];

public:
	T *operator[](std::size_t i) { return rows[i]; }

	template <std::size_t row, std::size_t col, typename U>
	friend std::ostream &operator<<(std::ostream &out, Matrix<row, col, U> mat);

	class iterator
		: public std::iterator<std::input_iterator_tag, T, T, const T *, T> {
		std::size_t i = 0;
		T arr[row_size][col_size];

	public:
		explicit iterator(T a[row_size][col_size], std::size_t pos)
			: i(pos), arr(a) {}
		iterator &operator++() {
			i++;
			return *this;
		}
		iterator operator++(int) {
			iterator retval = *this;
			++(*this);
			return retval;
		}
		bool operator==(iterator other) const { return i == other.i; }
		bool operator!=(iterator other) const { return !(*this == other); }
		const T *operator*() { return arr[i]; }
	};
	iterator begin() { return iterator(rows, 0); }
	iterator end() { return iterator(rows, row_size); }
};

template <std::size_t row_size, std::size_t col_size, typename T>
std::ostream &operator<<(std::ostream &out, Matrix<row_size, col_size, T> mat) {
	out << "[";
	for (int i = 0; i < row_size; i++) {
		out << "[ ";
		for (size_t j = 0; j < col_size; j++) {
			out << mat[i][j] << (j == col_size - 1 ? "" : ", ");
		}
		out << (i == row_size - 1 ? "]" : "], ");
	}
	out << "]\n";
	return out;
}
