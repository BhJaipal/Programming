#include <iostream>
using namespace std;
# include <string>
class calculator;
calculator{
    public:
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
}}
int main() {
    calculator Cal;
    Cal.Calculate(7, "+=", 8);
    return 0;
}