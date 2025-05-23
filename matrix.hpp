#pragma once
#include <iostream>

template <typename T, std::size_t row, std::size_t col>
class Matrix {
protected:
	T rows[row][col];
};

#define MatrixBuilder(Name, rows_c, cols_c)                                    \
	template <typename T>                                                      \
	class Name {                                                               \
		T rows[rows_c][cols_c];                                                \
                                                                               \
	public:                                                                    \
		Name(std::initializer_list<T> init) {                                  \
			std::size_t i = 0;                                                 \
			for (auto &&el : init) {                                           \
				rows[i / cols_c][i % cols_c] = el;                             \
				i++;                                                           \
			}                                                                  \
		}                                                                      \
		Name(T init[rows_c][cols_c]) {                                         \
			for (int i = 0; i < rows_c; i++) {                                 \
				for (std::size_t j = 0; j < cols_c; j++) {                     \
					rows[i][j] = init[i][j];                                   \
				}                                                              \
			}                                                                  \
		}                                                                      \
		T *operator[](std::size_t i) { return rows[i]; }                       \
		template <typename U>                                                  \
		friend std::ostream &operator<<(std::ostream &out, Name<U> mat);

#define EndMatrix }

#define MatrixOutput(Name, rows_c, cols_c)                                     \
	template <typename T>                                                      \
	std::ostream &operator<<(std::ostream &out, Name<T> mat) {                 \
		for (int i = 0; i < rows_c; i++) {                                     \
			out << "[ ";                                                       \
			for (size_t j = 0; j < cols_c; j++) {                              \
				out << mat[i][j] << (j == cols_c - 1 ? " " : ", ");            \
			}                                                                  \
			out << (i == rows_c - 1 ? "]\n" : "]\n");                          \
		}                                                                      \
		return out;                                                            \
	}