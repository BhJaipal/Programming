# include <iostream>
# include <string>
using namespace std;

void Pattern(int limit) {
    if (limit>0) {
        int i = 1;
        while (i<=limit) {
            int num = 1;
            while (num<=i) {
                cout << num;
                num++;
            }
            while (num>i) {
                cout << endl;
                i++;
            }
        }
    }
    else if (limit<0) {
        int num = -1;
        string space="\n ";
        while (limit<=num) {
            int i = limit;
            while (i<=num) {
                cout << i;
                i++;
            }
            cout << space;
            space = space + " ";
            limit++;
        }
    }
    else {
        cout << "Please enter an integer except 0";
    }
}

int main() {
    int num;
    cout << "Hello World" << endl << "I am Jaipal" << endl;
    cout << endl;
    cout << "Enter limit" << endl;
    cin >> num;
    cout << "Limit is " << num << endl;
    Pattern(num);
    return 0;
}
