#include <iostream>
#include <string>

/**
 * @brief Pair class
 * @tparam keyT key type
 * @tparam valueT value type
 */
template <typename keyT, typename valueT>
class Pair
{
public:
	keyT key_;
	valueT value_;
	Pair() {}
	Pair(keyT k, valueT v)
	{
		key_ = k;
		value_ = v;
	}
	void set(keyT k, valueT v)
	{
		key_ = k;
		value_ = v;
	}
	void set(valueT value)
	{
		value_ = value;
	}
	valueT get()
	{
		return value_;
	}
	keyT get_key()
	{
		return key_;
	}
};

int main(int argc, char const *argv[])
{
	Pair<std::string, int> p;
	p.set("Jaipal", 21);
	std::cout << "Name: " << p.get_key() << std::endl;
	std::cout << "Age: " << p.get() << std::endl;
	return 0;
}
