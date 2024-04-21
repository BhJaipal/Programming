#include <iostream>
class Matrix
{
	int arr[2][2];

public:
	Matrix(int a, int b, int c, int d)
	{
		arr[0][0] = a;
		arr[0][1] = b;
		arr[1][0] = c;
		arr[1][1] = d;
	}
	friend Matrix operator+(Matrix &mat1, Matrix &mat2);

	void display()
	{
		std::cout << "[ " << arr[0][0] << "  " << arr[0][1] << " ]\n";
		std::cout << "[ " << arr[1][0] << "  " << arr[1][1] << " ]\n";
	}
	Matrix operator*(int k)
	{
		Matrix temp(0, 0, 0, 0);
		temp.arr[0][0] = arr[0][0] * k;
		temp.arr[0][1] = arr[0][1] * k;
		temp.arr[1][0] = arr[1][0] * k;
		temp.arr[1][1] = arr[1][1] * k;
		return temp;
	}
};
Matrix operator+(Matrix &mat1, Matrix &mat2)
{
	Matrix temp(0, 0, 0, 0);
	temp.arr[0][0] = mat1.arr[0][0] + mat2.arr[0][0];
	temp.arr[0][1] = mat1.arr[0][1] + mat2.arr[0][1];
	temp.arr[1][0] = mat1.arr[1][0] + mat2.arr[1][0];
	temp.arr[1][1] = mat1.arr[1][1] + mat2.arr[1][1];
	return temp;
}
int main()
{
	Matrix mat1(1, 2, 3, 4), mat2(8, 3, 9, 4);
	Matrix sum = mat1 + mat2;
	std::cout << "Sum: \n";
	sum.display();
	Matrix mul = mat2 * 5;
	std::cout << "Product: \n";
	mul.display();
	return 0;
}
