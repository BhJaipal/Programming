# include <iostream>
# include <string>
using namespace std;

bool and_gate(bool bool1, bool bool2) {
    if (bool1 == true and bool2 == true) {
        return true;
    }
    else {return false;}
}
bool or_gate(bool bool1, bool bool2) {
    if (bool1 == false and bool2 == false) {
        return false;
    }
    else {return true;}
}
bool not_gate(bool bool1) {
    if (bool1 == true) {return false;}
    else {return true;}
}

bool nand_gate(bool bool1, bool bool2) {
    return not_gate(and_gate(bool1, bool2));
}
bool nor_gate(bool bool1, bool bool2) {
    return not_gate(or_gate(bool1, bool2));
}

int main() {
    std::cout << nor_gate(true, nand_gate(false, true)) << " and " << not_gate(or_gate(or_gate(true, false),not_gate(true)));
    return 0;
}