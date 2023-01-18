# include <iostream>
# include <string>
using namespace std;

string name(string name1) {
    return name1;
}
string classe(string classes) {
    return classes;
}
void info() {
    string name2, class_no;
    std::cout << "Enter name: ";
    std::cin >> name2;
    std::cout << "Enter class: ";
    std::cin >> class_no;
    std::cout << "My name is " << name(name2) << std::endl;
    std::cout << "I am in " << classe(class_no) << "th class" << std::endl;
}
int main() {
    info();
    return 0;
}