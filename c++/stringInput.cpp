#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;

	std::cout << "Enter your name: ";
	getline (cin, name);

	cout << "Hello " + name + "!!\n";
	//cout << "Hello " << name << "!!\n";
}