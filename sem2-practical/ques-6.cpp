#include <iostream>

class Time
{
	int hour, min, sec;

public:
	Time(int h = 0, int m = 0, int s = 0)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void copy(Time &t)
	{
		hour = t.hour;
		min = t.min;
		sec = t.sec;
	}
	void print() { std::cout << hour << ":" << min << ":" << sec << std::endl; }
};
int main()
{
	Time t1(10, 20, 30), t2;
	t2.copy(t1);
	t2.print();
	return 0;
}
/*
Output:
10:20:30
*/