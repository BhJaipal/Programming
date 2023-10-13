#include <iostream>
#include <string>
using namespace std;

int main()
{
    while (true)
    {
        string input;
        cout << ">> ";
        cin >> input;

        if (input == "q")
        {
            cout << "Process exited" << endl;
            break;
        }
        if (input == "help")
        {
            cout << "q\texit calculator" << endl;
            continue;
        }

        string operators[] = {"+", "-", "/", "*", "%"};

        int found = 0;
        for (string operat : operators)
        {
            int opera_pos = input.find(operat);
            if (opera_pos != -1)
            {
                float a = stof(input.substr(0, opera_pos));
                float b = stof(input.substr(opera_pos + 1));

                if (operat == "+")
                {
                    cout << (a + b) << endl;
                }
                else if (operat == "-")
                {
                    cout << (a - b) << endl;
                }
                else if (operat == "*")
                {
                    cout << (a * b) << endl;
                }
                else if (operat == "/")
                {
                    cout << (a / b) << endl;
                }
                else if (operat == "%")
                {
                    cout << ((int)a % (int)b) << endl;
                }
                found = 1;
                break;
            }
        }
        if (!found)
        {
            cout << "No operator or Invalid operator" << endl;
        }
    }
    return 0;
}