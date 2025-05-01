#pragma once
#include "matrix.hpp"
#include <iostream>

MatrixBuilder(3, 3) Mat3x3 operator*(Mat3x3 rhs) {
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
EndMatrix;

MatrixBuilder(2, 3) Mat2x3 operator*(Mat3x3<T> rhs) {
	int arr[2][3] = {
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
	};
	return Mat2x3(arr);
}
EndMatrix;

MatrixOutput(2, 3);

MatrixOutput(3, 3);
