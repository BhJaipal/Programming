#include <iostream>
using namespace std;

class Time {
	int hr, min;

public:
	Time(int a, int b) : hr(a), min(b) {}
	operator int() { return (hr * 60) + min; }
};
int main() {
	Time t1(2, 30);
	int duration = t1;
	cout << duration << "\n";
	duration = t1.operator int();
	cout << duration << "\n";
	return 0;
}
/*
Output:
150
150
*/
