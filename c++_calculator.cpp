#include <iostream>
using namespace std;

void calculator(int num1,string operat,int num2) {
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
int main() {
    cout << "Hello World" << endl << "I am Jaipal" << endl;
    cout << endl;
    
    int num, num3;
    string opera;
    cout << "Starting Calculator" << endl << "Enter First number" << endl;
    cin >> num;
    cout << "Enter Second number" << endl;
    cin >> num3;
    cout << "Enter operator" << endl;
    cin >> opera;
    calculator(num,opera,num3);
    return 0;
}