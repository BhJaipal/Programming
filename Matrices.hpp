#pragma once
#include "Matrix.hpp"

template <typename T>
class Mat3x3 : public Matrix<3U, 3U, T> {
	using Matrix<3, 3, T>::rows;

public:
	Mat3x3(std::initializer_list<T> init) {
		std::size_t i = 0;
		T a1[3], a2[3], a3[3];
		for (auto &&el : init) {
			if (i < 3) a1[i] = el;
			else if (i >= 3 && i < 6) a2[i % 3] = el;
			else a3[i % 6] = el;
			i++;
		}
	}
	Mat3x3(T init[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (size_t j = 0; j < 3; j++) { rows[i][j] = init[i][j]; }
		}
	}

	Mat3x3(T init[9]) {
		T a1[3] = {init[0], init[1], init[2]},
		  a2[3] = {init[3], init[4], init[5]},
		  a3[3] = {init[6], init[7], init[8]};
		rows[0] = a1;
		rows[1] = a2;
		rows[2] = a3;
	}

	T *operator[](std::size_t i) { return rows[i]; }

	Mat3x3 operator*(Mat3x3 rhs) {
		int arr[3][3] = {// m1 row 1 * m2 cols
						 {rows[0][0] * rhs[0][0] + rows[0][1] * rhs[1][0] +
							  rows[0][2] * rhs[2][0],
						  rows[0][0] * rhs[0][1] + rows[0][1] * rhs[1][1] +
							  rows[0][2] * rhs[2][1],
						  rows[0][0] * rhs[0][2] + rows[0][1] * rhs[1][2] +
							  rows[0][2] * rhs[2][2]},
						 // m1 row 2 * m2 cols
						 {rows[1][0] * rhs[0][0] + rows[1][1] * rhs[1][0] +
							  rows[1][2] * rhs[2][0],
						  rows[1][0] * rhs[0][1] + rows[1][1] * rhs[1][1] +
							  rows[1][2] * rhs[2][1],
						  rows[1][0] * rhs[0][2] + rows[1][1] * rhs[1][2] +
							  rows[1][2] * rhs[2][2]},
						 // m1 row 3 * m2 cols
						 {rows[2][0] * rhs[0][0] + rows[2][1] * rhs[1][0] +
							  rows[2][2] * rhs[2][0],
						  rows[2][0] * rhs[0][1] + rows[2][1] * rhs[1][1] +
							  rows[2][2] * rhs[2][1],
						  rows[2][0] * rhs[0][2] + rows[2][1] * rhs[1][2] +
							  rows[2][2] * rhs[2][2]}};
		return Mat3x3(arr);
	}
};
