#include <iostream>
using namespace std;

class Time {
	int hr, min, sec;

public:
	Time(int h = 0, int m = 0, int s = 0) : hr(h), min(m), sec(s) {}
	void display() { cout << hr << ":" << min << ":" << sec << endl; }
	friend Time operator+(Time, Time);
};
Time operator+(Time t1, Time t2) {
	Time t3;
	t3.sec = t1.sec + t2.sec;
	t3.min = t1.min + t2.min + (t3.sec / 60);
	t3.sec %= 60;
	t3.hr = t1.hr + t2.hr + (t3.min / 60);
	t3.min %= 60;
	return t3;
}
int main() {
	Time t1(2, 53, 13), t2(3, 25, 42);
	Time t3 = t1 + t2;
	t3.display();
	return 0;
}
/*
Output:
6:18:55
*/
