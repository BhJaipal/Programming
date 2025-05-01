#include "Matrices.hpp"

int main() {
	Mat3x3<int> mat1 = {4, 2, 6, 7, 2, 3, 5, 3, 6},
				mat2 = {8, 5, 2, 5, 3, 7, 7, 5, 2};
	std::cout << mat1 << "\n";
	std::cout << mat2 << "\n";
	Mat3x3<int> res = mat1 * mat2;

	std::cout << res << "\n";
	return 0;
}
