#pragma once
#include "matrix.hpp"
#include <iostream>

MatrixBuilder(Mat3x3, 3, 3) Mat3x3 operator*(Mat3x3 rhs) {
	int arr[3][3] = {
		// m1 row 1 * m2 cols
		{
			rows[0][0] * rhs[0][0] + rows[0][1] * rhs[1][0] +
				rows[0][2] * rhs[2][0],
			rows[0][0] * rhs[0][1] + rows[0][1] * rhs[1][1] +
				rows[0][2] * rhs[2][1],
			rows[0][0] * rhs[0][2] + rows[0][1] * rhs[1][2] +
				rows[0][2] * rhs[2][2],
		},
		// m1 row 2 * m2 cols
		{
			rows[1][0] * rhs[0][0] + rows[1][1] * rhs[1][0] +
				rows[1][2] * rhs[2][0],
			rows[1][0] * rhs[0][1] + rows[1][1] * rhs[1][1] +
				rows[1][2] * rhs[2][1],
			rows[1][0] * rhs[0][2] + rows[1][1] * rhs[1][2] +
				rows[1][2] * rhs[2][2],
		},
		// m1 row 3 * m2 cols
		{
			rows[2][0] * rhs[0][0] + rows[2][1] * rhs[1][0] +
				rows[2][2] * rhs[2][0],
			rows[2][0] * rhs[0][1] + rows[2][1] * rhs[1][1] +
				rows[2][2] * rhs[2][1],
			rows[2][0] * rhs[0][2] + rows[2][1] * rhs[1][2] +
				rows[2][2] * rhs[2][2],
		},
	};
	return Mat3x3(arr);
}
EndMatrix;

MatrixOutput(Mat3x3, 3, 3);

MatrixBuilder(Mat2x3, 2, 3) Mat2x3 operator*(Mat3x3<T> rhs) {
	int arr[2][3] = {
		// m1 row 1 * m2 cols
		{
			rows[0][0] * rhs[0][0] + rows[0][1] * rhs[1][0] +
				rows[0][2] * rhs[2][0],
			rows[0][0] * rhs[0][1] + rows[0][1] * rhs[1][1] +
				rows[0][2] * rhs[2][1],
			rows[0][0] * rhs[0][2] + rows[0][1] * rhs[1][2] +
				rows[0][2] * rhs[2][2],
		},
		// m1 row 2 * m2 cols
		{
			rows[1][0] * rhs[0][0] + rows[1][1] * rhs[1][0] +
				rows[1][2] * rhs[2][0],
			rows[1][0] * rhs[0][1] + rows[1][1] * rhs[1][1] +
				rows[1][2] * rhs[2][1],
			rows[1][0] * rhs[0][2] + rows[1][1] * rhs[1][2] +
				rows[1][2] * rhs[2][2],
		},
	};
	return Mat2x3(arr);
}
EndMatrix;

MatrixOutput(Mat2x3, 2, 3);

MatrixBuilder(Mat2x2, 2, 2) Mat2x2 operator*(Mat2x2 rhs) {
	int arr[2][2] = {
		// m1 row 1 * m2 cols
		{
			rows[0][0] * rhs[0][0] + rows[0][1] * rhs[1][0],
			rows[0][0] * rhs[0][1] + rows[0][1] * rhs[1][1],
		},
		// m1 row 2 * m2 cols
		{
			rows[1][0] * rhs[0][0] + rows[1][1] * rhs[1][0],
			rows[1][0] * rhs[0][1] + rows[1][1] * rhs[1][1],
		},
	};
	return Mat2x2(arr);
}
Mat2x3<T> operator*(Mat2x3<T> rhs) {
	int arr[2][3] = {
		// m1 row 1 * m2 cols
		{
			rows[0][0] * rhs[0][0] + rows[0][1] * rhs[1][0],
			rows[0][0] * rhs[0][1] + rows[0][1] * rhs[1][1],
			rows[0][0] * rhs[0][2] + rows[0][1] * rhs[1][2],
		},
		// m1 row 2 * m2 cols
		{
			rows[1][0] * rhs[0][0] + rows[1][1] * rhs[1][0],
			rows[1][0] * rhs[0][1] + rows[1][1] * rhs[1][1],
			rows[1][0] * rhs[0][2] + rows[1][1] * rhs[1][2],
		},
	};
	return Mat2x3(arr);
}
EndMatrix;
MatrixOutput(Mat2x2, 2, 2);

template <typename T>
Mat2x2<T> operator*(Mat2x3<T> lhs, Mat2x2<T> rhs) {
	int arr[2][2] = {
		// m1 row 1 * m2 cols
		{
			lhs[0][0] * rhs[0][0] + lhs[0][1] * rhs[1][0],
			lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1],
		},
		// m1 row 2 * m2 cols
		{
			lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0],
			lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1],
		},
	};
	return Mat2x2(arr);
}
template <typename T>
Mat3x3<T> operator*(Mat3x3<T> lhs, Mat2x3<T> rhs) {
	int arr[3][3] = {
		// m1 row 1 * m2 cols
		{
			lhs[0][0] * rhs[0][0] + lhs[0][1] * rhs[1][0],
			lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1],
			lhs[0][0] * rhs[0][2] + lhs[0][1] * rhs[1][2],
		},
		// m1 row 2 * m2 cols
		{
			lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0],
			lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1],
			lhs[1][0] * rhs[0][2] + lhs[1][1] * rhs[1][2],
		},
		// m1 row 3 * m2 cols
		{
			lhs[2][0] * rhs[0][0] + lhs[2][1] * rhs[1][0],
			lhs[2][0] * rhs[0][1] + lhs[2][1] * rhs[1][1],
			lhs[2][0] * rhs[0][2] + lhs[2][1] * rhs[1][2],
		},
	};
	return Mat3x3(arr);
}