#include <iostream>
#include <string>
using namespace std;

class Account {
	string name, accType;
	double balance;
	string accNo;

public:
	Account() {}
	void initialize() {
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter Account Number: ";
		cin >> accNo;
		cout << "Enter Account Type: ";
		cin >> accType;
		cout << "Enter Initial Balance: ";
		cin >> balance;
	}
	void deposit(int amount) {
		balance += amount;
		cout << "Amount Deposited: " << amount << '\n';
	}
	void withdraw(int amount)
	{
		if (amount > balance) { cout << "Insufficient Balance" << '\n'; }
		else {
			cout << "Amount withdrawn: " << amount << '\n';
			balance -= amount;
		}
	}
	void display() { cout << "Balance: " << balance << '\n'; }
};
int main() {
	Account a;
	a.initialize();
	cout << "\n";
	a.withdraw(1000);
	a.withdraw(200);
	a.deposit(2000);
	a.display();
	return 0;
}
/*
Output:
Enter Name: Jaipal
Enter Account Number: 63784674563
Enter Account Type: Student
Enter Initial Balance: 500

Insufficient Balance
Amount withdrawn: 200
Amount Deposited: 2000
Balance: 2300
*/
