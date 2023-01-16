# include <iostream>
# include <string>
using namespace std;

void Pattern(int limit) {
    if (limit>0) {
        int i = 1;
        while (i<=limit) {
            int num = 1;
            while (num<=i) {
                std::cout << num;
                num++;
            }
            while (num>i) {
                std::cout << std::endl;
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
                std::cout << i;
                i++;
            }
            std::cout << space;
            space = space + " ";
            limit++;
        }
    }
    else {
        std::cout << "Please enter an integer except 0";
    }
}

int main() {
    int num;
    std::cout << "Hello World" << std::endl << "I am Jaipal" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter limit" << std::endl;
    cin >> num;
    std::cout << "Limit is " << num << std::endl;
    Pattern(num);
    std::cout << std::endl;
    return 0;
}
