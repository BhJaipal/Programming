#include "matrices.hpp"

int main() {
	Mat3x3<int> mat1 = {4, 2, 6, 7, 2, 3, 5, 3, 6},
				mat2 = {8, 5, 2, 5, 3, 7, 7, 5, 2};
	Mat3x3<int> res = mat1 * mat2;

	Mat2x3<int> mat3 = {5, 3, 1, 7, 5, 8};
	std::cout << (mat3 * res);
	return 0;
}
