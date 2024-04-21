#include <iostream>

class Complex
{
	int real, imag;

public:
	Complex(int r = 0, int i = 0) : real(r), imag(i) {}
	Complex operator+(Complex &obj)
	{
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void operator<<(std::ostream &out)
	{
		if (imag >= 0)
		{
			out << "(" << real << "+" << imag << "i)" << std::endl;
		}
		else
		{
			out << "(" << real << imag << "i)" << std::endl;
		}
	}
};
int main(int argc, char const *argv[])
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
	c3 << std::cout;
	return 0;
}
