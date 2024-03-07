#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

class Node
{
	Node *next;
	Node *prev;

public:
	int data;
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
	Node *getNext()
	{
		return this->next;
	}
	void setNext(Node *node)
	{
		this->next = node;
	}
	Node *getPrev()
	{
		return this->prev;
	}
	void setPrev(Node *node)
	{
		this->prev = node;
	}
	std::string to_string()
	{
		return "{ data: " + std::to_string(this->data) + ", next: " + (this->next != NULL && this->next != 0 ? std::to_string(this->next->data) : "null") + ", previous: " + (this->prev != NULL && this->prev != 0 ? std::to_string(this->prev->data) : "null") + " }";
	}
};

class DoubleLinkedList
{
private:
	bool isNodeNull(int index)
	{
		if (&this->nodes[index] == NULL || &this->nodes[index] == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	std::vector<Node> nodes;
	int _size;

public:
	DoubleLinkedList(int head)
	{
		this->_size = 0;
		nodes.push_back(Node(head));
		nodes[0].setPrev(NULL);
		nodes[0].setNext(NULL);
		this->_size++;
	}
	int size()
	{
		return this->_size;
	}
	void insert(int index, int data)
	{
		if (index == 0)
		{
			this->push(data);
		}
		else
		{
			this->nodes.insert(this->nodes.begin() + index, Node(data));
			this->nodes[index - 1].setNext(&this->nodes[index]);
			this->nodes[index].setPrev(&this->nodes[index - 1]);
			this->nodes[index].setNext(isNodeNull(index + 1) ? NULL : &this->nodes[index + 1]);
			this->nodes[index + 1].setPrev(&this->nodes[index]);
			this->_size++;
		}
	}
	void push(int data)
	{
		nodes.push_back(Node(data));
		nodes.at(this->_size - 1).setNext(&nodes.at(this->_size));
		nodes.at(this->_size).setPrev(&nodes.at(this->_size - 1));
		nodes.at(this->_size).setNext(NULL);
		this->_size++;
	}
	int pop()
	{
		nodes[(this->_size - 2)].setNext(NULL);
		int last = nodes.at(this->_size - 1).data;
		nodes.pop_back();
		this->_size--;
		return last;
	}
	/**
	 * @brief Print the linked list
	 */
	void print()
	{
		cout << "[\n";
		for (int i = 0; i < this->_size; i++)
		{
			cout << "\t" << nodes[i].to_string() << "\n";
		}
		cout << "\n]\n";
	}
	void pop(int val)
	{
		int index = 0;
		for (int i = 0; i < this->_size; i++)
		{
			if (this->nodes[i].data == val)
			{
				index = i;
				break;
			}
		}
		this->nodes[index - 1].setNext(this->nodes[index].getNext());
		this->nodes[index + 1].setPrev(this->nodes[index].getPrev());
		this->nodes.erase(this->nodes.begin() + index);
		this->_size--;
	}
};

int main()
{
	DoubleLinkedList linkedList(7);
	linkedList.push(1);
	linkedList.push(9);
	linkedList.push(4);
	linkedList.pop();
	linkedList.push(2);
	linkedList.insert(linkedList.size(), 3);
	linkedList.print();
	return 0;
}
