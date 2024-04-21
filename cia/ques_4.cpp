#include <iostream>
#include <string>

class BankAccount
{
	int account_number;
	double balance;
	std::string name;

public:
	BankAccount(int account_number, double balance, std::string name)
	{
		this->account_number = account_number;
		this->balance = balance;
		this->name = name;
	}
	void display()
	{
		std::cout << "Account number: " << account_number << "\n";
		std::cout << "Holder Name: " << name << "\n";
		std::cout << "Balance: " << balance << "\n";
	}
	void deposit(double amount)
	{
		balance += amount;
		std::cout << "Amount deposited: " << amount << "\n";
	}
	void withdraw(double amount)
	{
		if (balance >= amount)
		{
			balance -= amount;
			std::cout << "Amount withdrawn: " << amount << "\n";
		}
		else
		{
			std::cout << "Insufficient balance" << std::endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	BankAccount acc(123456789, 1000, "Jaipal");
	acc.deposit(1000);
	acc.withdraw(500);
	acc.withdraw(6000);
	std::cout << "\n";
	acc.display();
	return 0;
}
