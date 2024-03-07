#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

class Node
{
	Node *next;

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
	std::string to_string()
	{
		return "{ data: " + std::to_string(this->data) + ", next: " + (this->next != NULL && this->next != 0 ? std::to_string(this->next->data) : "null") + " }";
	}
};
class SingleyLinkedList
{
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
	SingleyLinkedList(int head)
	{
		this->_size = 0;
		nodes.push_back(Node(head));
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
			this->nodes[index].setNext(isNodeNull(index + 1) ? NULL : &this->nodes[index + 1]);
			this->_size++;
		}
	}
	void push(int data)
	{
		nodes.push_back(Node(data));
		nodes.at(this->_size - 1).setNext(&nodes.at(this->_size));
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
		this->nodes.erase(this->nodes.begin() + index);
		this->_size--;
	}
};

int main()
{
	SingleyLinkedList linkedList(7);
	linkedList.push(1);
	linkedList.push(9);
	linkedList.push(4);
	linkedList.push(2);
	linkedList.insert(linkedList.size(), 3);
	linkedList.pop(1);
	linkedList.print();
	return 0;
}
