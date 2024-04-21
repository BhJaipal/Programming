#include <iostream>

class Animal
{
public:
	virtual void makeSound() = 0;
};
class Cat : public Animal
{
public:
	void makeSound()
	{
		std::cout << "Meow" << std::endl;
	}
};
class Dog : public Animal
{
public:
	void makeSound()
	{
		std::cout << "Woof" << std::endl;
	}
};
int main()
{
	Animal *pets[2];
	pets[0] = new Cat();
	pets[1] = new Dog();
	for (int i = 0; i < 2; i++)
	{
		pets[i]->makeSound();
	}
	return 0;
}
