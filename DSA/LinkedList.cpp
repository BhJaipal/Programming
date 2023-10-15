#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T> class LinkedList{
private:
	list<T> _list= {};
	int _length;
public:
	LinkedList() {
		this->_list= {};
		this->_length= 0;
	}
	/**
	* @param { T } elem Push a element to end of Linked List
	*/
	void add(T elem) {
		this->_length++;
		this->_list.push_back(elem);
	}
	/**
	* @return { T } returns and removes first element of Linked List
	*/
	T pop_first() {
		try {
			if (!this->isEmpty()) {
			this->_length--;
			T front= this->_list.front();
			this->_list.pop_front();
			return front;
			} else {
				string error= "OverflowError: Linked List is empty";
				throw error;
			}
		} catch (string err) {
			cout << err << endl;
		}
	}
	/**
	* @return { T } returns and removes last element of Linked List
	*/
	T pop_last() {
		try {
			if (!this->isEmpty()) {
				this->_length--;
				T last= this->_list.back();
				this->_list.pop_back();
				return last;
			} else {
				throw "OverflowError: LinkedList is empty";
			}
		} catch (char *err) {
			cout << *err << endl;
		}
	}
	/**
	* @return { T } returns first element without removing it 
  */ 
	T peek() {
		return this->_list.front();
	}
	/**
	* @return { int } Number of elements in Linked List 
	*/
	int length() {
		return this->_length;
	}
	/**
	* @description Deletes first element of Linked List 
	*/
	void removeFirst() {
		this->pop_first();
	}
	/**
	* @description Deletes last element of Linked List
	*/
	void removeLast() {
		this->pop_last();
	}
	/**
	 * @description empties the Linked List
	 */
	void clear() {
		this->_list= {};
		this->_length= 0;
	}
	/**
	* @param { T } elem Element to be find
	* @return { int } index of element, if not present, returns -1
	*/
	int indexOf(T elem) {
		int index= -1;
		for(int i=0; i< this->_length; i++) {
			if (this->_list[i] == elem) {
				index= i;
			} else {
			}
		}
		return index;
	}
	/**
	 * @return { list<T> } returns Linked List in array form
	 */
	list<T> toArray() {
		return this->_list;
	}
	/**
	* @return checks if Linked list is empty 
	*/
	bool isEmpty() {
		if (this->length() == 0) {
			return true;
		} else {
			return false;
		}
	}
};

int main () {
	LinkedList<string> linkedList;
	linkedList.add("Vite");
	linkedList.add("Webpack");
	linkedList.add("Parcel");
	for(int over= 0; over <= 3; over++) {
		cout << "Poped element: " << linkedList.pop_first() << endl;
	}
	return 0;
}
