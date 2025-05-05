#include "matrices.hpp"

int main() {
	Mat3x3<int> mat1 = {4, 2, 6, 7, 2, 3, 5, 3, 6},
				mat2 = {8, 5, 2, 5, 3, 7, 7, 5, 2};
	Mat2x3<int> mat3 = {5, 3, 1, 7, 5, 8};
	Mat2x2<int> mat4 = {6, 2, 8, 3};

	Mat3x3<int> res = mat1 * mat2;
	Mat2x3<int> res2 = (mat3 * res);
	std::cout << mat4 << " * \n" << res2 << "\n";

	Mat2x3<int> out = mat4 * res2;
	std::cout << out << std::endl;
	return 0;
}
