#ifndef CXX_MY_LINKEDLIST
#define CXX_MY_LINKEDLIST
#include <cstdlib>
#include <iostream>

namespace MyDSA {
/**
 * @brief One sided node of linked list
 *
 * @tparam T data type of node data
 */
template <class T = int> class SingleNode {
  public:
	T data;
	T next;
	SingleNode(int d = 0) : data(d), next(0) {}
};
/**
 * @brief Double Sided node of linked list
 *
 * @tparam T data type of node data
 */
template <class T = int> class DoubleNode {
  public:
	T data;
	T prev;
	T next;
	DoubleNode(int d = 0) : data(d), next(0), prev(0) {}
};
/**
 * @brief Singly linked list, each node points to next node data
 *
 * @tparam T Singly linked list nodes data type
 */
template <typename T> class SinglyLinkedList {
	SingleNode<T> *arr;
	int len;
	int isCircular;

  public:
	/**
	 * @brief Construct a new Singly Linked List object
	 * @param x first node value
	 */
	SinglyLinkedList(T x) {
		arr = new SingleNode<T>[1];
		arr[0] = SingleNode<T>(x);
		len = 1;
	}
	/**
	 * @brief Adds a node to end of linked list
	 * @param data value of the node
	 */
	void push(T data) {
		SingleNode<T> n(data);
		arr =
			(SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) * (++len));
		arr[len - 1] = n;
		arr[len - 2].next = n.data;
		if (isCircular) circular();
	}
	/**
	 * @brief Removes and returns node of last node
	 * @return last node, useless node if empty
	 */
	SingleNode<T> pop() {
		if (isEmpty()) return SingleNode<int>(-1);
		else {
			SingleNode<T> last = arr[len - 1];
			arr = (SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) *
														 (--len));
			if (len - 1 >= 0) arr[len - 1].next = 0;
			if (isCircular) circular();
			return last;
		}
	}
	/**
	 * @brief Removes and returns node of a certain node
	 * @param index index of node
	 * @return node of that index, useless node if empty
	 */
	SingleNode<T> pop(int index) {
		if (isEmpty()) return SingleNode<int>(-1);
		else if (index < 0) return pop(len + index + 1);
		else {
			if (index >= len - 1) {
				SingleNode<T> last = arr[len - 1];
				arr = (SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) *
															 (--len));
				if (len - 1 >= 0) arr[len - 1].next = 0;
				if (isCircular) circular();
				return last;
			} else {
				SingleNode<T> last = arr[index];
				for (int i = index; i < len - 1; i++) { arr[i] = arr[i + 1]; }
				arr = (SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) *
															 (--len));
				if (index - 1 >= 0) arr[index - 1].next = arr[index].data;
				return last;
			}
		}
	}
	/**
	 * @brief To print linked list in a array of objects format
	 * [] if linked list is empty
	 *	[
	 *		{ data: x, next: x1 },
	 *		{ data: x1, next: x2 }
	 *	]
	 */
	void toString() {
		if (isEmpty()) {
			std::cout << "[]";
		} else {
			std::cout << "[\n";
			for (int i = 0; i < len - 1; i++) {
				std::cout << "\t{ data: " << arr[i].data
						  << ", next: " << arr[i].next << " },\n";
			}
			std::cout << "\t{ data: " << arr[len - 1].data
					  << ", next: " << arr[len - 1].next << " }\n";
			std::cout << "]";
		}
	}
	/**
	 * @brief To add new node to linked list
	 * @param data value of node
	 * @param index index where node to be added
	 */
	void push(T data, int index) {
		if (index >= len) {
			push(data);
		} else if (index < 0) {
			push(data, len + index + 1);
		} else {
			SingleNode<T> n(data);
			arr = (SingleNode<T> *)std::realloc(arr, sizeof(SingleNode<T>) *
														 (++len));
			for (int i = index; i < len - 1; i++) { arr[i + 1] = arr[i]; }
			arr[index] = n;
			arr[index].next = arr[index + 1].data;
			if (index != 0) arr[index - 1].next = n.data;
		}
	}
	/**
	 * @brief Checks if linked list is empty or not
	 * @return 1 for empty, 0 for not empty
	 */
	int isEmpty() { return len == 0; }
	/**
	 * @brief Destroy the Singly Linked List object
	 */
	~SinglyLinkedList() { delete arr; }
	/**
	 * @brief To Set the isCircular property
	 * @param isYes whether to make linked list circular or not
	 */
	void setCircular(bool isYes = true) {
		isCircular = isYes ? 1 : 0;
		if (isCircular) circular();
	}
	/**
	 * @brief Makes linked list circular
	 */
	void circular() { arr[len - 1].next = arr[0].data; }
};
/**
 * @brief Double linked list, each node points to next and previous node data
 *
 * @tparam T Double linked list nodes data type
 */
template <typename T> class DoubleLinkedList {
	DoubleNode<T> *arr;
	int len;
	int isCircular;

  public:
	/**
	 * @brief Construct a new Double Linked List object
	 * @param x first node value
	 */
	DoubleLinkedList(T x) {
		arr = new DoubleNode<T>[1];
		arr[0] = DoubleNode<T>(x);
		isCircular = 0;
		len = 1;
	}
	/**
	 * @brief Adds a node to end of linked list
	 * @param data value of the node
	 */
	void push(T data) {
		DoubleNode<T> n(data);
		arr =
			(DoubleNode<T> *)std::realloc(arr, sizeof(DoubleNode<T>) * (++len));
		arr[len - 1] = n;
		arr[len - 2].next = n.data;
		arr[len - 1].prev = arr[len - 2].data;
		if (isCircular) circular();
	}
	/**
	 * @brief Removes and returns node of last node
	 * @return last node, useless node if empty
	 */
	DoubleNode<T> pop() {
		if (isEmpty()) return DoubleNode<int>(-1);
		else {
			DoubleNode<T> last = arr[len - 1];
			arr = (DoubleNode<T> *)std::realloc(arr, sizeof(DoubleNode<T>) *
														 (--len));
			if (len - 1 >= 0) arr[len - 1].next = 0;
			if (isCircular) circular();
			return last;
		}
	}
	/**
	 * @brief Removes and returns node of a certain node
	 * @param index index of node
	 * @return node of that index, useless node if empty
	 */
	DoubleNode<T> pop(int index) {
		if (isEmpty()) return DoubleNode<int>(-1);
		else if (index < 0) return pop(len + index + 1);
		else {
			if (index >= len - 1) {
				DoubleNode<T> last = arr[len - 1];
				arr = (DoubleNode<T> *)std::realloc(arr, sizeof(DoubleNode<T>) *
															 (--len));
				if (len - 1 >= 0) arr[len - 1].next = 0;
				if (isCircular) circular();
				return last;
			} else {
				DoubleNode<T> last = arr[index];
				for (int i = index; i < len - 1; i++) { arr[i] = arr[i + 1]; }
				arr = (DoubleNode<T> *)std::realloc(arr, sizeof(DoubleNode<T>) *
															 (--len));
				if (index - 1 >= 0) {
					arr[index - 1].next = arr[index].data;
					arr[index].prev = arr[index - 1].data;
				}
				return last;
			}
		}
	}
	/**
	 * @brief To print linked list in a array of objects format
	 * [] if linked list is empty
	 *	[
	 *		{ data: x0, next: x, previous: x1 },
	 *		{ data: x, next: x1, previous: x0 },
	 *		{ data: x1, next: x0, previous: x }
	 *	]
	 */
	void toString() {
		if (isEmpty()) {
			std::cout << "[]";
		} else {
			std::cout << "[\n";
			for (int i = 0; i < len - 1; i++) {
				std::cout << "\t{ data: " << arr[i].data
						  << ", next: " << arr[i].next
						  << ", previous: " << arr[i].prev << " },\n";
			}
			std::cout << "\t{ data: " << arr[len - 1].data
					  << ", next: " << arr[len - 1].next
					  << ", previous: " << arr[len - 1].prev << " }\n";
			std::cout << "]";
		}
	}
	/**
	 * @brief To add new node to linked list
	 * @param data value of node
	 * @param index index where node to be added
	 */
	void push(T data, int index) {
		if (index >= len) {
			push(data);
		} else if (index < 0) {
			push(data, len + index + 1);
		} else {
			DoubleNode<T> n(data);
			arr = (DoubleNode<T> *)std::realloc(arr, sizeof(DoubleNode<T>) *
														 (++len));
			for (int i = index; i < len - 1; i++) { arr[i + 1] = arr[i]; }
			arr[index] = n;
			arr[index].next = arr[index + 1].data;
			if (index != 0) {
				arr[index - 1].next = n.data;
				arr[index].prev = arr[index - 1].data;
			}
		}
	}
	/**
	 * @brief Checks if linked list is empty or not
	 * @return 1 for empty, 0 for not empty
	 */
	int isEmpty() { return len == 0; }
	/**
	 * @brief Destroy the Double Linked List object
	 */
	~DoubleLinkedList() { delete arr; }
	/**
	 * @brief To Set the isCircular property
	 * @param isYes whether to make linked list circular or not
	 */
	void setCircular(bool isYes = true) {
		isCircular = isYes ? 1 : 0;
		if (isCircular) circular();
	}
	/**
	 * @brief Makes linked list circular
	 */
	void circular() {
		arr[len - 1].next = arr[0].data;
		arr[0].prev = arr[len - 1].data;
	}
};
} // namespace MyDSA

#endif