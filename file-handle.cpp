#include <fstream>
#include <iostream>

int main() {
	char ch = 'J';
	int x = 7;
	float fl = 3.4;
	std::string str = "Jaipal\n";
	std::ofstream out("out.txt", std::ios::out);
	out << ch << " " << x << " " << fl << " " << str;
	out << "this is a line";
	out.close();

	std::ifstream in("out.txt", std::ios::in);
	in >> ch >> x >> fl >> str;
	std::string line;
	in.ignore();
	getline(in, line);
	std::cout << ch << " " << x << " " << fl << " ";
	std::cout << str << "\n" << line << "\n";
	return 0;
}