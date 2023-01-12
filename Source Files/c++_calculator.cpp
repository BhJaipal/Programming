#include <Calculator.h>
using namespace std;

double Calculator::Calculate(double num1,string operat,double num2) {
    if (operat == "+") 
    {cout << num1 + num2 << endl;}
    
    else if (operat == "-") 
    {cout << num1 - num2 << endl;}
    
    else if (operat == "*") 
    {cout << num1 * num2 << endl;}
    
    else if (operat == "/") 
    {cout << num1 / num2 << endl;}
    
    else if (operat == "%") 
    {cout << num1 % num2 << endl;}
    
    else if (operat == "+=") {
        num1 += num2;
        cout << num1 << endl;
    }
    else if (operat == "-=") {
        num1 -= num2;
        cout << num1 << endl;
    }
    else if (operat == "*=") {
        num1 *= num2;
        cout << num1 << endl;
    }
    else if (operat == "/=") {
        num1 /= num2;
        cout << num1 << endl;
    }
    else if (operat == "%=") {
        num1 %= num2;
        cout << num1 << endl;
    }
    else if (operat == "&=") {
        num1 &= num2;
        cout << num1 << endl;
    }
    else if (operat == "|=") {
        num1 |= num2;
        cout << num1 << endl;
    }
    else if (operat == "^=") {
        num1 ^= num2;
        cout << num1 << endl;
    }
    else if (operat == ">>=") {
        num1 >>= num2;
        cout << num1 << endl;
    }
    else if (operat == "<<=") {
        num1 <<= num2;
        cout << num1 << endl;
    }
    else if (operat == "==") 
    {cout << (num1 == num2) << endl;}
    else if (operat == "!=") 
    {cout << (num1 != num2) << endl;}
    else if (operat == "<") 
    {cout << (num1 < num2) << endl;}
    else if (operat == ">") 
    {cout << (num1 > num2) << endl;}
    else if (operat == ">=") 
    {cout << (num1 >= num2) << endl;}
    else if (operat == "<=") 
    {cout << (num1 <= num2) << endl;}
    else {"Please check your input";}
}
