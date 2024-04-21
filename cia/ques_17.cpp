#include <iostream>
#include <cstdlib>

class Array
{
	int *arr;
	int size;
	int _len;

public:
	Array(int capacity)
	{
		arr = new int[capacity];
		size = capacity;
		_len = 0;
	}
	void add(int val)
	{
		try
		{
			if (_len < size)
			{
				arr[_len] = val;
				_len++;
			}
			else
			{
				throw 0;
			}
		}
		catch (int e)
		{
			std::cout << "Array is full" << std::endl;
		}
	}
	int remove()
	{
		try
		{
			if (_len > 0)
			{
				_len--;
				return arr[_len];
			}
			else
			{
				throw 0;
			}
		}
		catch (int e)
		{
			std::cout << "Array is empty" << std::endl;
		}
	}
	void appendCapacity(int _size)
	{
		size += _size;
		arr = (int *)realloc(arr, sizeof(int) * size);
	}
	void resetCapacity(int _size)
	{
		size = _size;
		arr = (int *)realloc(arr, sizeof(int) * size);
		if (_len > size)
		{
			_len = size;
		}
	}
	void display()
	{
		for (int i = 0; i < _len; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	~Array()
	{
		delete[] arr;
	}
};
int main()
{
	Array a(3);
	a.add(3);
	a.add(8);
	a.add(2);
	a.appendCapacity(2);
	a.add(10);
	a.add(7);
	a.display();
	return 0;
}
