#include <iostream>
using namespace std;
# include <string>

void Calculate(int num1,string operat,int num2) {
    if (operat == "+") 
    {std::cout << num1 + num2 << std::endl;}
    
    else if (operat == "-") 
    {std::cout << num1 - num2 << std::endl;}
    
    else if (operat == "*") 
    {std::cout << num1 * num2 << std::endl;}
    
    else if (operat == "/") 
    {std::cout << num1 / num2 << std::endl;}
    
    else if (operat == "%") 
    {std::cout << num1 % num2 << std::endl;}
    
    else if (operat == "+=") {
        num1 += num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "-=") {
        num1 -= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "*=") {
        num1 *= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "/=") {
        num1 /= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "%=") {
        num1 %= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "&=") {
        num1 &= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "|=") {
        num1 |= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "^=") {
        num1 ^= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == ">>=") {
        num1 >>= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "<<=") {
        num1 <<= num2;
        std::cout << num1 << std::endl;
    }
    else if (operat == "==") 
    {std::cout << (num1 == num2) << std::endl;}
    else if (operat == "!=") 
    {std::cout << (num1 != num2) << std::endl;}
    else if (operat == "<") 
    {std::cout << (num1 < num2) << std::endl;}
    else if (operat == ">") 
    {std::cout << (num1 > num2) << std::endl;}
    else if (operat == ">=") 
    {std::cout << (num1 >= num2) << std::endl;}
    else if (operat == "<=") 
    {std::cout << (num1 <= num2) << std::endl;}
    else {"Please check your input";}
}
int main() {
    int no1, no2;
    string opera;
    while (true) {
        std::cout << "Enter First number: ";
        std::cin >> no1;
        std::cout << "Enter operator: ";
        std::cin >> opera;
        std::cout << "Enter Second number:";
        std::cin >> no2;
        Calculate(no1,opera,no2);
        string cont;
        std::cout << "Do you want to continue[y/n]: ";
        std::cin >> cont;
        if (cont == "n" or cont == "N") {break;}
    }
    return 0;
}