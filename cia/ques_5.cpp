#include <iostream>
#include <string>

class Book
{
public:
	std::string title;
	std::string author;
	std::string ISBN;
};
class Library
{
	Book books[10];
	int numBooks;

public:
	Library() : numBooks(0) {}
	void add(std::string title, std::string author, std::string ISBN)
	{
		books[numBooks].title = title;
		books[numBooks].author = author;
		books[numBooks].ISBN = ISBN;
		numBooks++;
		std::cout << "Book added\n";
	}
	void remove(int index)
	{
		books[index].title = "";
		books[index].author = "";
		books[index].ISBN = "";
		for (int i = index; i < numBooks; i++)
		{
			books[i] = books[i + 1];
		}
		numBooks--;
		std::cout << "Book removed\n";
	}
	void display()
	{
		for (int i = 0; i < numBooks; i++)
		{
			std::cout << books[i].title << "    " << books[i].author << "    " << books[i].ISBN << std::endl;
		}
	}
};
int main(int argc, char const *argv[])
{
	Library lib;
	lib.add("One piece", "Oda", "1");
	lib.add("Alpha", "Author 1", "638252");
	lib.add("Jokes you can tell yourself", "Programmer", "73592651");
	lib.add("Harry Potter", "J.K. Rowling", "263");
	lib.remove(1);
	std::cout << "\n";
	lib.display();
	return 0;
}
