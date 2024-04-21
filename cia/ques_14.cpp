#include <iostream>
using namespace std;

class String
{
	char *_str;

public:
	char *c_str()
	{
		return _str;
	}
	String(const char *val)
	{
		_str = new char[sizeof(val)];
		for (int i = 0; i < sizeof(val); i++)
		{
			_str[i] = val[i];
		}
	}
	String(String &str)
	{
		strcpy(str._str);
	}
	~String()
	{
		delete _str;
	}
	String operator=(const char *val)
	{
		return *this;
	}
	void strcpy(const char *val)
	{
		_str = new char[sizeof(val)];
		for (int i = 0; i < sizeof(val); i++)
		{
			_str[i] = val[i];
		}
	}
};
int main()
{
	String str = "Hello";
	str.strcpy("World");
	String str2 = str;
	cout << str2.c_str() << endl;
	return 0;
}
