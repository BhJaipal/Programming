/**
 * @file
 * @brief This file contains Array class 
 */
	
#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
using namespace std;

string types[]= {"i", "d"};

template <class T> class Array{
private:
	list<T> _list= {};
	int _length;
public:
	/**
	 * @description Initializes the array
	 */
	Array() {
		this->_list= {};
		this->_length= 0;
	}
	/**
	 * @return Checks if array is empty or not
	 */
	bool isEmpty() {
		return ((this->length()== 0) ? true : false);
	}
	T& operator[](int index) { return this->_list[index]; }

	void operator=(list<T> arr) {
		if (this->isEmpty()) {
			this->_list= arr;
			this->_length= this->_list.size();
		} else {}
	}
	/**
	 * @param elem Element whose value you want to find 
	 * @return { int } position of element in array, if not present, returns -1
	 */
	int indexOf(T elem) {
		int index= -1;
		for (int i = 0; i < this->length(); i++) {
			if (this->list[i] == elem) {
				index = i;
			} else {}
		}
		return index;
	}
	/**
	 * @param callback function runs on calling reducer 
	 * @param initialVai initial Value if accumulator
	 */
	T reduce(function<T(T, T)> callback, T initialVal) {
		T accumulator= initialVal;
		for(T currentVal : this->_list) {
			accumulator= callback(accumulator, currentVal);
		}
		return accumulator;
	}
	/**
	 * @return checks if Element is present or not
	 */
	bool includes(T elem) {
		return ((this->indexOf(elem) != -1 ) ? true : false);
	}
	Array<T> operator+(Array arr) {
		Array sum;
		for (int  i = 0; i < this->length(); i++) {
			sum.append(this->_list[i]);
		}
		for (int  i = 0; i< arr.length(); i++) {
			sum.append(arr[i]);
		}
		return sum;
	}
	bool operator==(Array arr) {
		return (arr.toList() == this->_list);
	}
	/**
	 * @return returns list 
	 */
	list<T> toList() {
		return this->_list;
	}
	/**
	 * @return returns printable string form of array
	 */
	string toString() {
		string listForm= "[";
		for(auto var: this->_list) {
			if (typeid(var).name() == types[0] || typeid(var).name() == types[1]) {
				listForm+= to_string(var);
				listForm+= ", ";
			} else {
				listForm+= var;
				listForm+= ", ";
			}
		}
		listForm.erase(listForm.size()-1);
		listForm.erase(listForm.size()-1);
		listForm+= ']';
		return listForm;
	}
	/**
	 * @return number of elements in Array
	 */
	int length() {
		return this->_length;
	}
	/**
	 * @return sorts the Array and returns it
	 */
	list<T> sort() {
		this->_list.sort();
		return this->_list;
	}

	void replace(T oldElem, T newElem) {
		this->_list[this->indexOf(oldElem)]= newElem;
	}
	/**
	 * @description reverses the Array 
	 */
	void reverse() {
		this->_list.reverse();
	}
	/**
	 * @param func takes a callback function as argument
	 */
	void forEach(function<void(T)> func) {
		for(T& elem : this->_list) {
			func(elem);
		}
	}
	/**
	 * @param index index of element to be removed 
	 * @return returns and removes element at index
	 */
	T popAtIndex(int index) {
		try {
			if (index < this->length()) {
				T findElem= this->_list[index];
				this->_list.erase(index);
				this->_length--;
				return findElem;
			} else {
				string err= (("IndexError: Index "+ to_string(index)) +" does not exist");
				throw err;
			}
		} catch (string err) {
			cout << err << endl;
		}
	}
	/**
	* @param { T } elem Element to be poped out of Array
	*/
	void popElem(T elem) {
		try {
		  if (this->includes(elem)) {
				this->popAtIndex(this->indexOf(elem));
			} else {
				string err= "Element does not exist";
				throw err;
			}
		} catch (string err) { cout << err << endl; }
	}
	/**
	 * @return returns and  removes last element of Array 
	 */
	T pop() {
		try {
			if (!this->isEmpty()) {
				T lastEl= this->last();
				this->_length--;
				this->_list.pop_back();
				return lastEl;
			}
			string err= "UnderflowError: Array is empty";
			throw err;
		} catch (string err) {
			cout << err << endl;
		}
	}
	/**
	 * @return returns a slice of Array 
	 */
	Array<T> slice(int start, int end, int iterStep=1) {
		Array<T> arr;
		if (iterStep < 0) {
			for (int i = start; i > end; i+= iterStep) {
				arr.append(this->_list[i]);
			}
		} else if (iterStep) {
		  for (int i = start;  i < end;  i+= iterStep) {
		  	arr.append(this->_list[i]);
			}
		} else {}
		return arr;
	}
	/**
	 * @description extends given Array to current Array 
	 */
	void extends(Array<T> arr) {
		for(T var : arr) {
			this->_list.append(var);
		}
	}
	/**
	 * @description Adds an element at the end of Array 
	 */
	void append(T elem) {
		this->_list.push_back(elem);
		this->_length++;
	}
	/**
	 * @description Adds element at the start of Array 
	 */
	void prepend(T elem) {
		this->_list.push_front(elem);
		this->_length++;
	}
	/**
	 * @param elem Element to be added 
	 * @param index position where element has to be added
	 * @description inserts element at a given position 
	 */
	void insert(T elem, int index) {
		this->_list.insert(index, elem);
	}
	/**
	* @return last element of Array
	*/
	T last() { return this->_list.back(); }

	/**
	* @desxription For using Array in foreach loop 
	*/
	class Iterator {
	private:
		T* ptr;

	public:
	  Iterator(T* p) : ptr(p) {}

	  // Overload the ++ operator for iterator
	  Iterator& operator++() {
			ptr++;
	    return *this;
	  }
	
	  // Overload the * operator to get the element
		T& operator*() {
			return *ptr;
		}
	
		// Overload the comparison operator
		bool operator!=(const Iterator& other) {
			return ptr != other.ptr;
		}
	};
	Iterator begin() {
	  return Iterator(this->_list);
	}

	Iterator end() {
		return Iterator(this->_list + this->_length);
	}
};

int main () {
	Array<int> arr;
	arr= {2, 4, 3, 9, 7, 5};
	arr.forEach([](int el) { cout << el << " "; });
	cout << endl;
	arr.pop();
	cout << arr.toString() << endl;
	return 0;
}
