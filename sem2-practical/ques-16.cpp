#include <iostream>
#include <bitset>
using namespace std;

class BinOperator {
	int x;
	unsigned int y;
public:
	BinOperator(unsigned int _y, int _x) : y(_y), x(_x) {}
	void print() { cout << bitset<4>{y} << endl; }
	void operator<<(unsigned int _x) { y = y << _x; }
	void operator>>(unsigned int _x) { y = y >> _x; }
	int operator+(BinOperator b) { return x + b.x; }
	int operator||(BinOperator b) { return x || b.x; }
	int operator>=(BinOperator b) { return x >= b.x; }
};

int main() {
	BinOperator binOp(0b0101, 5), bin2(0b1010, 10);
	binOp << 2;
	binOp.print();
	binOp >> 1;
	binOp.print();
	cout << binOp + bin2 << endl;
	cout << (binOp || bin2) << endl;
	cout << (binOp >= bin2) << endl;
	return 0;
}
/*
Output:
0100
1010
15
1
0
*/
