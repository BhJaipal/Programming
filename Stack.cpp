#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class type=string> 
class Stack{
private:
  vector<type> list;
  bool overflow() {
    if (this->list.size() == 0) {
      return true;
    } else {
      return false;
    }
  }
public:
  Stack() {
    this->list= {};
  }
  Stack(type elem) {
    this->list.push_back(elem);
  }
  Stack(type elem1, type elem2) {
    this->list.push_back(elem1);
    this->list.push_back(elem2);
  }
  Stack(type elem1, type elem2, type elem3, type elem4, type elem5) {
    this->list.push_back(elem1);
    this->list.push_back(elem2);
    this->list.push_back(elem3);
    this->list.push_back(elem4);
    this->list.push_back(elem5);
  }
  int length() {
    return this->list.size();
  }
  void print() {
    for (int i = 0; i < this->list.size(); i++) {
      cout << this->list[i] << " ";
    }
  }
  void push(type elem) {
    this->list.push_back(elem);
  }
  type pop() {
    if (!(this->overflow())) {
      type last= this->list[this->list.size()-1];
      this->list.pop_back();
      return last;
    } else {
      type elem;
      cout << "Please enter data: ";
      cin >> elem;
      return elem;
    }
  }
};

int main(void) {
  Stack<string> stack("JS", "TS", "Java", "C++", "Python");
  stack.print();
  cout << endl;
  cout << "Stack has " << stack.length() << " elements" << endl;
  stack.push("C#");
  stack.push("C");
  cout << "Poped element is " << stack.pop() << endl;
  stack.print();
  cout << endl;
}
