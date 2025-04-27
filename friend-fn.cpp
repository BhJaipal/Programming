#include <iostream>
using namespace std;

class Time {
	int hr, min, sec;
public:
	Time(int h, int m, int s): hr(h), min(m), sec(s) {}
	void show() {
		cout << (hr < 10 ? "0" : "") << hr << ":"
			<< (min < 10 ? "0" : "") << min << ":"
			<< (sec < 10 ? "0" : "") << sec << endl;
	}
	friend Time add(Time, Time);
};

Time add(Time a, Time b) {
	int h = a.hr + b.hr;
	int m = a.min + b.min;
	int s = a.sec + b.sec;

	m += s / 60;
	s %= 60;

	h += m / 60;
	m %= 60;

	return Time(h, m, s);
}

int main() {
	Time a(4, 23, 36), b(3, 38, 46);
	Time c = add(a, b);
	c.show();
	return 0;
}
