#include <iostream>
using namespace std;

class Time {
	int hr, min;
public:
	Time(int mins) : hr(mins / 60), min(mins % 60) {}
	void display() { cout << (hr > 9 ? "" : "0") << hr << ":" << (min > 9 ? "" : "0") << min << endl; }
};
int main() {
	Time t1 = 100;
	t1.display();
	return 0;
}
/*
Output:
01:40
*/
