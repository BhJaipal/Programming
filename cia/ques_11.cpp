#include <iostream>
#include <cstdlib>

class DynamicArray
{
	int *arr;
	int _len;
	int _size;

public:
	DynamicArray(int size)
	{
		_len = 0;
		_size = size;
		arr = new int[size];
	}
	~DynamicArray()
	{
		delete[] arr;
		std::cout << "Array deleted" << std::endl;
	}
	void add(int val)
	{
		if (_len == _size)
		{
			arr = (int *)std::realloc(arr, (_size + 1) * sizeof(int));
			arr[_len] = val;
			_len++;
			_size++;
			std::cout << "Memory reallocated, 4 bits added\n";
		}
		else
		{
			arr[_len] = val;
			_len++;
		}
	}
	int length() { return _len; }
	int remove()
	{
		if (_len == 0)
		{
			std::cout << "Array is empty\n";
			return -1;
		}

		int val = arr[_size - 1];
		arr = (int *)std::realloc(arr, (_size - 1) * sizeof(int));
		_size--;
		_len--;
		return val;
	}
	int operator[](int index)
	{
		if (index > _len)
		{
			std::cout << "Index out of bound" << std::endl;
			return -1;
		}
		else
		{
			return arr[index];
		}
	}
};

int main(int argc, char const *argv[])
{
	DynamicArray da(3);
	da.add(1);
	da.add(7);
	da.add(4);
	da.add(3);
	da.add(9);
	for (int i = 0; i < 5; i++)
	{
		std::cout << da[i] << "\t";
	}
	std::cout << '\n';
	std::cout << "Removed element: " << da.remove() << '\n';
	std::cout << "4 bits Memory freed\n";

	return 0;
}
