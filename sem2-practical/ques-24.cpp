#include <iostream>
#include <string>
using namespace std;

class Mangoes {
public:
	int calculate(string basket[10]) {
		int count = 0;
		for (int i = 0; i < 10; i++) {
			if (basket[i] == "mango") { count++; }
		}
		return count;
	}
};
class Apples {
public:
	int calculate(string basket[10]) {
		int count = 0;
		for (int i = 0; i < 10; i++) {
			if (basket[i] == "apple") { count++; }
		}
		return count;
	}
};
class Fruits {
public:
	int calculate(string basket[10]) {
		return Apples().calculate(basket) + Mangoes().calculate(basket);
	}
};
int main() {
	Fruits fruit;
	string basket[10] = {"apple", "poison", "apple", "mango", "cereals", "mango", "bread", "mango", "apple", "mango"};
	cout << "Total number of apples: " << Apples().calculate(basket) << endl;
	cout << "Total number of mangoes: " << Mangoes().calculate(basket) << endl;
	cout << "Total number of fruits: " << fruit.calculate(basket) << endl;
	return 0;
}
/*
Output:
Total number of apples: 3
Total number of mangoes: 4
Total number of fruits: 7
*/
