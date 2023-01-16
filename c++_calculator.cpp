#include <iostream>
using namespace std;

void Calculate(double num1,string operat,double num2) {
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
    Calculate Cal;
    Cal(7, "+=", 8);
    return 0;
}