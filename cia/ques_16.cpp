#include <iostream>
#include <cstdlib>
#include <memory>

template <typename T>
class Array
{
	T *data;
	int _len;
	int capacity;

public:
	Array(int initial_capacity)
	{
		_len = 0;
		data = new T[initial_capacity];
		capacity = initial_capacity;
	}
	~Array()
	{
		delete[] data;
	}
	void add(T value)
	{
		if (_len < capacity)
		{
			data[_len] = value;
			_len++;
		}
		else
		{
			data = (T *)std::realloc(data, sizeof(T) * capacity + 1);
			data[_len] = value;
			_len++;
			capacity++;
		}
	}
	T operator[](int index)
	{
		try
		{
			if (index < _len)
			{
				return data[index];
			}
			else
			{
				throw 0;
			}
		}
		catch (int e)
		{
			std::cout << "RangeError: Index out of range\n";
			return -1;
		}
	}
	T remove()
	{
		try
		{
			if (_len > 0)
			{
				_len--;
				return data[_len];
			}
			else
			{
				throw 0;
			}
		}
		catch (int e)
		{
			std::cout << "UnderflowError: Array is empty\n";
			return -1;
		}
	}
	int length()
	{
		return _len;
	}
	void print()
	{
		for (int i = 0; i < _len; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	std::unique_ptr<Array<int>> arr(new Array<int>(10));
	std::cout << "Adding elements\n";
	arr->add(4);
	arr->add(7);
	arr->add(18);
	arr->add(9);
	arr->add(1);
	arr->print();
	std::cout << "Removed: " << arr->remove() << std::endl;
	std::cout << "Emptying array till underflow" << std::endl;
	int len = arr->length();
	for (int i = 0; i < len; i++)
	{
		std::cout << arr->remove() << " ";
	}
	std::cout << '\n';
	arr->remove();
	arr.get()->operator[](5);
	return 0;
}
