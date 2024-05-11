#include <iostream>
using namespace std;

class SI {
public:
	SI(float p, float r, float t) {
		float si = (p * r * t) / 100;
		cout << "Simple Interest = " << si << endl;
	}
	SI(float p, float r) {
		float si = (p * r * 1) / 100;
		cout << "Simple Interest = " << si << endl;
	}
	SI(float p) {
		float si = (p * 10 * 1) / 100;
		cout << "Simple Interest = " << si << endl;
	}
};
int main() {
	SI *si = new SI(10000, 30);
	si = new SI(500, 20, 2);
	si = new SI(7000);
	delete si;
	return 0;
}
/*
Output:
Simple Interest = 3000
Simple Interest = 200
Simple Interest = 700
*/
